#include "stdafx.h"
#include "Circle.h"
#include "Point.h"

Circle::Circle(int x, int y,int r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}
int Circle::getX()
{
	return m_x;
}
int Circle::getY()
{
	return m_y;
}
int Circle::getR()
{
	return m_r;
}
bool Circle::judgePoint(Point &p)
{
	int dd = (p.getX() - m_x) * (p.getX() - m_x) + (p.getY() - m_y) *(p.getY() - m_y);

	if (dd > m_r * m_r) {
		return false;
	}
	else {
		return true;
	}
}

Circle::~Circle()
{
}