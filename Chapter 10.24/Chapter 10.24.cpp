// Chapter 10.24.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#include<functional>//必须

using namespace std;
using namespace std::placeholders;                       //必须  占位符需要

bool check_size(const int &s, string::size_type sz)
{
	return s > sz;
}

int main(int argc, char**argv)
{
	string _string = "MyLove";                          //给定一个string
	int a[10] = { 5,5,6,8,5,4,9,5,2,4 };
	vector<int> vec1(a, a + 10);                        //利用数组初始化vector  

	auto _length = _string.size();

	//使用bind不仅需要头文件，还需要声明命名空间
	auto str=find_if(vec1.begin(), vec1.end(), bind(check_size, _1, _length));
	cout << *str << endl;
	

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}

