#pragma once
#include "Game.h"
#include "GameField.h"
#include "Canvas.h"

class Tetris : public Game 
{
public:
	void OnKeyPressed(int btnCode) override;
	void Update(double dt) override;
	bool End() override;

private:
	GameField m_GameField;
	Canvas m_Canvas;
};