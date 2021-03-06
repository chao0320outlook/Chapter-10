// Chapter 10.33.cpp: 定义控制台应用程序的入口点。
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
	ifstream in("1.txt");                   //导入第一个参数，作为输入文件
	istream_iterator<int> it1(in), end;     //定义流迭代器，输入流，和输入流的尾迭代器

	vector<int> vec1;                     //存储用vector
	copy(it1,end,back_inserter(vec1));     //将流中数据存入vector
    /*while (it1 != end)
	{
		vec1.push_back(*it1);
		++it1;
	}*/
	ofstream out("2.txt");
	ofstream out2("3.txt");                 //目标写文件
	ostream_iterator<int> it2(out, " ");    //定义流迭代器，输出流，每行加空格
	ostream_iterator<int> it3(out2, "\n");  //定义流迭代器，输出流，每行结尾换行
	for (auto &i:vec1)
	{
		if (i % 2 == 0)//偶数
		{
			*it2++=i;                        //偶数放在2.txt中   或  it2=i;
		}
		else
		{
			*it3++ = i;                      //奇数放在3.txt中   或   it3=i
		}
	}

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}
