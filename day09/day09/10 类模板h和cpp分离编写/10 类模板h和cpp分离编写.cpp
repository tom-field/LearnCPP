// 10 类模板h和cpp分离编写.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#include "Person3.hpp"

using namespace std;

int main()
{
	Person3<int> p(10);
	p.Show();
    return 0;
}

