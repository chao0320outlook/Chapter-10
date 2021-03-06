// Chapter 10.13.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool compareSize(string & s)
{
	return s.size() >= 5 ? true : false;
}

int main()
{
	vector <string> str = { "chao","ronger","yuqiu","i love you " };
	auto itr1 = partition(str.begin(), str.end(), compareSize);
	for (auto itr2 = str.begin(); itr2 != itr1; ++itr2)
	{
		cout << *itr2 << " ";
	}
	cout << endl;

	for_each(str.begin(),itr1, [](const string &s) {cout << s << " "; });

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

