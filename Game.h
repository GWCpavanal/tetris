#pragma once
#include <Windows.h>
#include <chrono>

#include "Canvas.h"

class Game
{
	using Clock = std::chrono::system_clock; // таймер
	using Time = std::chrono::time_point<Clock>; // момент времени

public:
	Game();

	virtual void OnKeyPressed(int btnCode) = 0; //нажатие клавиши
	virtual void Update(double dt) = 0; // обновление состояния игры
	virtual bool End() = 0; //конец игры

	void Run(); //работать игре
private:
	HANDLE m_ConsoleIn;
};