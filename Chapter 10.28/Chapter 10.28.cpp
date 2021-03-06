// Chapter 10.28.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>  
#include <list>
#include <string>  
#include <vector>  
#include <algorithm>
#include <numeric>  
#include <functional>
#include <iterator>
#include <ctime>

using namespace std;
using namespace placeholders;//占位符的命名空间

int main(int argc, char**argv)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> vec1(a, a + 9);//利用数组初始化vector  
	vector<int> vec2;
    list<int> vec3;
	vector<int> vec4;

	//实现包含头文件iterator
	copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));
	copy(vec1.cbegin(), vec1.cend(), front_inserter(vec3));               //不支持push_front?,vector这个容器不支持
	copy(vec1.cbegin(), vec1.cend(), inserter(vec4, vec4.begin()));

	ostream_iterator <int> out_iter(cout, " ");
	for (auto &i : vec1)
	{
		*out_iter++ = i;
	}
	cout << endl<< "vec2字符为：";
	for (auto & i:vec2)
	{
		cout << i << " ";
	}
	cout << endl << "vec3字符为：";
	for (auto & i:vec3)
	{
		cout << i << " ";
	}
	cout << endl << "vec4字符为：";
	
	for_each(vec4.begin(), vec4.end(), [](const int &a) {cout << a << " "; });
	cout << endl;
	copy(vec4.begin(), vec4.end(), out_iter);

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}
