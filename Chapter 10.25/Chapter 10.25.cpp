// Chapter 10.25.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <functional>                  //包含  bind

using namespace std;
using namespace std::placeholders;     //使用 占位词 需要

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());             //sort排序
	auto str = unique(s.begin(), s.end());           //unique排序
	s.erase(str, s.end());               //erase()操作	
}
bool chack_size(string & s, string::size_type sz)
{
	return s.size() <= sz;
}
void biggis(vector<string> &s, vector<string>::size_type sz)
{
	elimDups(s);//字典排序、删除重复
	stable_sort(s.begin(), s.end(), [](const string &a, const string &b) {return a.size()<b.size(); });//按长度排序
	auto it1 = partition(s.begin(), s.end(), bind(chack_size, _1, sz));                                           //[sz](const string &s) {return s.size() <= sz; });
	for_each(it1, s.end(), [](const string & s) {cout << s << " "; });
}
int main(int argc, char**argv)
{
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	biggis(vec1, 4);//找出长度大于4的字符串

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}


