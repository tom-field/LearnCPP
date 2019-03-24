#pragma once
class Point
{
public:
	Point(int x, int y);
	int getX();
	int getY();
	~Point();
private:
	int m_x;
	int m_y;
};

