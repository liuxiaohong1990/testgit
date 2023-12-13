#pragma once
#include <map>
#include <set>
#include <list>
#include<vector>
#include<string>
using namespace std;
class GeneralScore
{
public :
	int  getMark();

	int getExpr(std::map<string, string>mq,std::string str_name);
};

