#pragma once
#include <iostream>

using namespace std;

class MyArray
{
public:
	//�޲ι��캯��
	MyArray();

	//�ڸ������ʼ����ʱ�򣬿��ٶ��ٸ�Ԫ�ؿռ�
	MyArray(int len);

	//�������캯��
	MyArray(const MyArray& another);

	int getLen();

	//index ����Ҫ��ֵ��������±�, data ����
	void setData(int index, int data);

	int getData(int index);

	~MyArray();

private:
	int length; //����Ŀǰ��Ԫ�ظ���
	int *space; //space ���ڶ��Ͽ�������ռ����Ԫ�ص�ַ��
};

