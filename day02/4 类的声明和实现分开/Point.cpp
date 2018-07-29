#include "stdafx.h"
#include "Point.h"


Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}

Point::~Point()
{
}
