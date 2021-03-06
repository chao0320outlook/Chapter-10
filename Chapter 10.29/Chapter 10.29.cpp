// Chapter 10.29.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
#include<fstream>
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<ctime>

using namespace std;
using namespace placeholders;//占位符的命名空间

int main(int argc, char**argv)
{
	vector<string> vec1;

	ifstream in1("1.txt");                   //不允许使用不完整类型，是因为没有头文件~~
	istream_iterator<string> str(in1), end;  //尾后迭代器
	ostream_iterator<string> os(cout, " ");

	copy(str, end, back_inserter(vec1));  //存入vec1
	copy(vec1.begin(), vec1.end(), os);   //输出

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}

