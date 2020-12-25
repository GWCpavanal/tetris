#include "Tetris.h"
#include <string>

Tetris::Tetris() : m_Figure(Point(5, 1)), m_NextFigure(Point(16, 1))
{
	m_GameField.Resize(14, 26);// размер игрового поля
	m_Canvas.Resize(26, 20);// размер консольного окна
}

void Tetris::OnKeyPressed(int btnCode){
	switch (btnCode) 
	{
	case 72: // стрелка вверх, поворот фигуры
		m_Figure.Rotate();
		break;

	case 75: // стрелка влево
		m_Figure.MoveL();
		break;

	case 77: // стрелка вправо
		m_Figure.MoveR();
		break;

	case 80: // стрелка вниз
		m_Figure.Boost();
		return;

	default:
		break;
	}
	
	//если фигура вышла на границу вернуться в предыдущее положение
	if (m_GameField.MasCollision(m_Figure)) 
	{
		m_Figure.Restore();
	}
}

void Tetris::Update(double dt) 
{
	m_Figure.BackUp();// запоминает положение
	m_Figure.Update(dt);// опускается
	if (m_GameField.MasCollision(m_Figure)) // когда заполнена горизонтальная линия
	{
		m_Figure.Restore(); // убрать ее
		m_Score += m_GameField.Merge(m_Figure);
		if (m_Score > 999999) m_Score = 999999; //что бы не было переполнения рисования
		m_Figure = m_NextFigure;// след фигура стала текущей
		m_Figure.SetPosition(Point(5, 1));// начальная точка откуда появляются фигуры
		m_NextFigure = Figure(Point(15, 1));// генерация следующая фигура
		// когда уровень постройки достиг вершины - проиграл
		if (m_GameField.MasCollision(m_Figure))
		{
			m_End = true;
		}
	}
	
	m_Canvas.Clear(); // очистить консоль
	m_GameField.Draw(m_Canvas); // нарисовать поле
	m_Figure.Draw(m_Canvas); // падающую
	m_NextFigure.Draw(m_Canvas); // следующую
	DrawScore(m_Canvas); // очки
	m_Canvas.Render(); // рендер
}

bool Tetris::End() //конец игры - проигрыш
{
	return m_End;
}

void Tetris::DrawScore(Canvas& canvas) // нарисовать счет
{
	std::string score = std::to_string(m_Score);
	
	m_Canvas.SetChar(14, 4, 'S');
	m_Canvas.SetChar(15, 4, 'C');
	m_Canvas.SetChar(16, 4, 'O');
	m_Canvas.SetChar(17, 4, 'R');
	m_Canvas.SetChar(18, 4, 'E');
	m_Canvas.SetChar(19, 4, ':');
	for (size_t i = 0; i < score.size(); ++i)
	{
		m_Canvas.SetChar(14 + i, 5, score[i]);
	}
}