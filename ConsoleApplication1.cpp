// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include "GeneralScore.h"
//#include "Phone.h"
using namespace std;

//1.泛化关系
class Animal {
public:
    Animal(int i=0,int j=0):posX(i),posY(j) {}
    void move(int dx, int dy) {
        posX += dx, posY += dy;
    }
    void getPos() {
        cout << "x=" << posX << ", y=" << posY << endl;
    }
private:
    int posX, posY;
};

//class Tiger :public Animal {
//public:
//    Tiger() {
//        this->name = "Tiger";
//    }
//    string name;
//};



////2.实现
class Climb {
public:
    Climb(int i=0):posZ(i){}
    virtual void GoClimb(int dz) = 0;
    void getHeight() {
        cout << "z=" << posZ << endl;
    }
protected:
    int posZ;
};

//class Tiger :public Animal, public Climb {
//public:
//    Tiger() {
//        this->name = "Tiger";
//    }
//    string name;
//    void GoClimb(int dz) {
//        posZ += dz;
//    } 
//}; 


//3.组合
class Leg {
protected:
    int len;
};
class Head {
protected:
    int size;
};

class Tiger {
public:
    Tiger() {
        this->name = "Tiger";
    }
private:
    string name;
    Leg leg[4];
    Head head;
}; 
 
//聚合
class TigerGroup {
private:
    vector<Tiger*> vtiger;
};

//关联
class Food {
protected:
    string foodName;
    string foodColor;
};

//class Tiger {
//public:
//    Tiger() {
//        this->name = "Tiger";
//    }
//private:
//    string name;
//    Leg leg[4];
//    Head head;
//    vector<Food> food;
//};

//依赖  

class Water {
private:
    float weight;
};

//class Tiger {
//public:
//    Tiger() {
//        this->name = "Tiger";
//    }
//    void Drink(Water water) {
//        return;
//    }
//private:
//    string name;
//    Leg leg[4];
//    Head head;
//    vector<Food> food;
//}; 

class classB {
    class classA {/*内容省略*/};
private:
    int ival;
};
class RareClass
{
private:
    int attr_3;
    int attr_4;
    int attr_5;
};
class RegularClass
{
private:
    int attr_1;
    int attr_2;
    RareClass* rareClass;
};
 
int main()
{
    
    GeneralScore gener;
    while (1) {
        string strName1, strName2;
        cout << "分别输入 点名册，作业" << endl;
        cin >> strName1 >> strName2;
        ifstream quan,a,b,c;
        char buffer[100];
       
        //1.教务系统名单
        map<string, string> mq;//教务系统名单
        quan.open(strName1.c_str());
        while (!quan.eof())
        {
            quan.getline(buffer, 100);
            string tmp(buffer);
            int ppp = tmp.find('\t');
            if (ppp != string::npos)
                mq[tmp.substr(0, ppp)] = tmp.substr(ppp + 1);
        }
        if (1!=gener.getExpr(mq, strName2))
        {
            cout << "数据有误" << endl;
        }
          
    }

}

/*
int main()
{
    while (1) {
        string strName1, strName2;
        cout << "分别输入学习通和点名册" << endl;
        cin >> strName1 >> strName2;
        set<string> ll;//学习通的名单
        map<string, string> mq;//教务系统名单
        ifstream a, quan;// ("C:\Users\刘晓红\Desktop\11quan.txt");
        a.open(strName1.c_str());
        char buffer[100];
        while (!a.eof())
        {
            a.getline(buffer, 100);
            ll.insert(string(buffer));
        }
        a.close();

        quan.open(strName2.c_str());
        while (!quan.eof())
        {
            quan.getline(buffer, 100);
            string tmp(buffer);
            int ppp = tmp.find('\t');
            if (ppp!=string::npos)
                mq[tmp.substr(0, ppp)] = tmp.substr(ppp+1);
        }
        quan.close();
        cout << "学习通里没有的" << endl;
        for (auto i = mq.begin(); i != mq.end(); ++i)
        {
            bool bfind = false;
            for (auto tt = ll.begin(); tt != ll.end(); ++tt)
            {
                if (tt->find(i->second) != string::npos)
                {
                    bfind = true;
                    ll.erase(tt);
                    break;
                }
            }
            if (!bfind)
            {
                cout << i->first << "    " << i->second << endl;
            }
        }
        cout << "学习通里面多出来的" << endl;
        for (auto i = ll.begin(); i != ll.end(); ++i)
            cout << *i << endl;
    } 
     
} 
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
 
class Person {
public:
    void copy(const Person& s) {
        this->m_age = s.m_age;
        //其余操作省略
    }
private:
    int m_age;
};
 