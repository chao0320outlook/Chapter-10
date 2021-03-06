// Chapter 10.1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> vec ;
	int in1,in2;
	cout << "输入计数元素:" << endl;
	cin >> in2;
	cout <<"输入数组:";
	while (cin >> in1)
		vec.push_back(in1);
	auto i = count(vec.begin(), vec.end(), in2);
	auto mun = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << i << endl<<mun;

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

