// 3 this指针.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int k)
	{
		this->m_k = k;
		this->m_q = 0;
	}

	Test(int k, int q)
	{
		this->m_k = k;
		this->m_q = q;
	}
	
	#if 0
	void getK() {
		cout << this->m_k << endl;
	}
	#endif // 0

	#if 1
	void getK(Test *pthis) {
		cout << pthis->m_k << endl;
	}
	#endif // 0

	#if 2
	void getK2(Test *pthis) {
		pthis++;
		cout << pthis->m_k << endl;
	}
	#endif // 0
	
private:
	int m_k;
	int m_q;
};

int main()
{
	Test t1(10);  //  Test t1(&t1, 10)
	Test t2(20);

	t1.getK(&t1);

	t2.getK2(&t2); // t2.getK(&t2)
    return 0;
}

