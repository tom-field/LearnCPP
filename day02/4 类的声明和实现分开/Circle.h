#include "Point.h"

class Circle
{
public:
	Circle(int x, int y, int r);
	int getX();
	int getY();
	int getR();
	bool judgePoint(Point &p);
	~Circle();

private:
	int m_x;
	int m_y;
	int m_r;
};

