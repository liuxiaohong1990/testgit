#include <iostream>
#include <fstream>
#include "GeneralScore.h"
#include<stdlib.h>
#include<algorithm>
#include <list>
#include <vector>
//#include "Phone.h"

int  GeneralScore::getMark()
{
    return 1;
}
vector<string> strToVec(string str,char cmark)
{
    vector<string> reslt;
    int ipos = str.find(cmark);
    if (ipos == string::npos)
    {
        return reslt;
    }
    //获取名字
    reslt.push_back( str.substr(0, ipos));
    
    str = str.substr(ipos + 1);
    ipos = str.find(cmark);
    while (ipos != string::npos)
    {
        string tmp = str.substr(0, ipos);
        //tmp == "已完成" || tmp == "未完成"||
            //tmp == "未参与" || tmp.find("过期") != string::npos
        if (tmp.size() > 0 && (tmp[0] <'0' || tmp[0] > '9'))
            reslt.push_back(tmp);
        str = str.substr(ipos + 1);
        ipos = str.find(cmark);
    }
    return reslt;
}
//签到信息放在最后面
int GeneralScore::getExpr(std::map<string, string>mq, std::string str_name)
{
    string score[16] = { "0", "-2" ,"-2" ,"-2" ,"-2" ,"-5", "-5" ,"-2" ,"-5" ,"-2",
        "-5" ,"-2", "-2" ,"-2" ,"-2" ,"-2" };
    ifstream a, b;
    list<string> bb;
    b.open(str_name.c_str()); 
    while (!b.eof())
    {
        char buffer[500];
        b.getline(buffer, 500);
        bb.push_back(string(buffer));
    }
    b.close();
    if (bb.size() < mq.size())
        return 0;

    map<string, string> mpnum;
    int jcount = 0;
    for (auto it = mq.begin(); it != mq.end(); ++it)
        mpnum[it->first] = it->second+'\t';
   
    int k = 0;
    for (auto ia = bb.begin(); ia != bb.end(); ++ia,k++)
    {
        vector<string> rslt = strToVec(*ia, '\t');
        if (rslt.size() < 12)
        {
            cout <<"第"<<k<<"行出错了"<< * ia << endl;
            continue;
        }
        for (auto it = mq.begin(); it != mq.end(); ++it)
        {
            int ipos = rslt[0].find(it->second);
            if (ipos != string::npos)
            {//0 2 2 2 2 5 5 2 5 2 5 2 
                for (int i = 1; i < rslt.size(); ++i)
                {
                    if(rslt[i]=="未完成"|| rslt[i] == "未交"
                        || rslt[i] == "未参与" || rslt[i].find("过期") != string::npos)
                        mpnum[it->first] = mpnum[it->first] + score[i] + "\t";
                } 
                jcount++; 
            }
        } 
    }

    cout << "， 作业 " << k << "， 总人数" << jcount << endl;
    
    //将结果写入到文档中
    ofstream ddd;
    ddd.open(str_name + "1.txt");
    for (auto aa = mpnum.begin(); aa != mpnum.end(); ++aa)
    {
       // cout << aa->first << "    " << aa->second << endl;
        ddd<< aa->first << "    " << aa->second << endl;
    }
    ddd.close();
    return 1;
}