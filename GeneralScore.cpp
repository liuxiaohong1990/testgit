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
    //��ȡ����
    reslt.push_back( str.substr(0, ipos));
    
    str = str.substr(ipos + 1);
    ipos = str.find(cmark);
    while (ipos != string::npos)
    {
        string tmp = str.substr(0, ipos);
        //tmp == "�����" || tmp == "δ���"||
            //tmp == "δ����" || tmp.find("����") != string::npos
        if (tmp.size() > 0 && (tmp[0] <'0' || tmp[0] > '9'))
            reslt.push_back(tmp);
        str = str.substr(ipos + 1);
        ipos = str.find(cmark);
    }
    return reslt;
}
//ǩ����Ϣ���������
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
            cout <<"��"<<k<<"�г�����"<< * ia << endl;
            continue;
        }
        for (auto it = mq.begin(); it != mq.end(); ++it)
        {
            int ipos = rslt[0].find(it->second);
            if (ipos != string::npos)
            {//0 2 2 2 2 5 5 2 5 2 5 2 
                for (int i = 1; i < rslt.size(); ++i)
                {
                    if(rslt[i]=="δ���"|| rslt[i] == "δ��"
                        || rslt[i] == "δ����" || rslt[i].find("����") != string::npos)
                        mpnum[it->first] = mpnum[it->first] + score[i] + "\t";
                } 
                jcount++; 
            }
        } 
    }

    cout << "�� ��ҵ " << k << "�� ������" << jcount << endl;
    
    //�����д�뵽�ĵ���
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