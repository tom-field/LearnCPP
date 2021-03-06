// 2 构造函数的分类和析构顺序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Test
{
public:
	
	Test() {
		m_x = 0;
		m_y = 0;
		cout << "调用了无参数的构造函数" << endl;
	}

	Test(int x, int y)
	{

		m_x = x;
		m_y = y;
		cout << "调用了有参数的构造函数" << endl;
	}

	~Test() 
	{
		cout << "~Test（）析构函数被执行了" << endl;
		cout << "(" << m_x << ", " << m_y << ")" << "被析构了" << endl;
	};

	//拷贝构造函数
	Test(const Test &another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
		cout << "调用了拷贝构造函数" << endl;
	}

	// 等号操作符
	void operator = (const Test &another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
		cout << "调用了=操作函数" << endl;
	}

	void printT()
	{
		cout << "x : " << m_x << ", y : " << m_y << endl;
	}

private:
	int m_x;
	int m_y;
};

int main()
{
	Test t1; //调用无参的构造函数
	Test t2(10, 20);
	//Test t3(10, 20, 30);
	t2.printT();

	Test t3(t2); //调用t3的拷贝构造函数  //调用拷贝构造函数的方式
	Test t4 = t3; // 注意: 这地方调用的是拷贝构造函数  这两中写法一样

	Test t5;
	t5 = t3;     // 这里才是调用的 赋值操作符

				 //析构函数的调用顺序， 跟对象的构造顺序相反， 谁先构造，谁最后一个被析构。

    return 0;
}

