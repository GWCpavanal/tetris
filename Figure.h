#pragma once
#include <vector>
#include "Canvas.h"

struct Point {// структура, новый тип данных
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	int x;
	int y;
};

class Figure
{
public:
	Figure(Point position);// конструктор

	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveR();
	void MoveL();
	void Rotate();

	const std::vector<Point>& GetBody() const;
	Point GetPosition() const;
	void SetPosition(Point position);
	void Boost();

	void BackUp();
	void Restore();

private:
	Point m_Position;
	Point m_PositionBackUp;

	double m_TimeFromLastUpdate = 0;
	double m_TimeForUpdate = 500;
	std::vector<std::vector<Point>> m_Body;// массив фигур упавших
	size_t m_CurrentRotate = 0;//индекс текущего поворота
	size_t m_CurrentRotateBackUp = 0;
};

