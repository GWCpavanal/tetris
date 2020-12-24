#pragma once
#include "Game.h"
#include "GameField.h"
#include "Canvas.h"

class Tetris : public Game //наследование от класса Game
{
public:
	Tetris();
	void OnKeyPressed(int btnCode) override;
	void Update(double dt) override;
	bool End() override;

	void DrawScore(Canvas& canvas);

private:
	GameField m_GameField;
	Canvas m_Canvas;
	Figure m_Figure;
	Figure m_NextFigure;
	size_t m_Score = 0;
	bool m_End = false;
};