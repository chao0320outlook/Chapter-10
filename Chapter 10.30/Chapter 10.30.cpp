// Chapter 10.30.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <ctime>
#include <vector>
#include <algorithm>  
#include <numeric>  
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
	istream_iterator<int> iter1(cin), end;
	ostream_iterator<int> os(cout, " ");

	vector<int> vec;
	copy(iter1, end, back_inserter(vec));
	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), os);
	cout << endl;
	copy(vec.begin(), vec.end(), os);

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

