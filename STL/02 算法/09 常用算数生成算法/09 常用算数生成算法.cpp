#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm> //不好使
#include <numeric> //好使
#include <iterator>

using namespace std;

/*
accumulate算法 计算容器元素累计总和
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value累加值
*/
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}


	//0~100累积和  5050
	//第三个参数  起始累加值
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "总和为：" << sum << endl;

}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
*/

void test02()
{
	vector<int>v;

	v.resize(10);

	fill(v.begin(), v.end(), 1000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

}

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}