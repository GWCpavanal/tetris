#pragma once
#include <vector>
#include "Canvas.h"

struct Point {
	int x;
	int y;
};

class Figure
{
public:
	Figure(Point position);

	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveR();
	void MoveL();
private:
	Point m_Position;
	double m_TimeFromLastUpdate = 0;
	std::vector<Point> m_Body;
};

