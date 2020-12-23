#include "GameField.h"

void GameField::Resize(int width, int height) {
	m_Width = width;
	m_Height = height;
}

void GameField::Draw(Canvas& canvas) {
	for (int i = 1; i < m_Width - 1; ++i) {
		canvas.SetChar(i, 0, 0x2550);
		canvas.SetChar(i, m_Height - 1, 0x2550);
	}

	for (int i = 1; i < m_Width - 1; ++i) {
		canvas.SetChar(0, i, 0x2550);
		canvas.SetChar(m_Width - 1, i, 0x2551);
	}

	canvas.SetChar(0, 0, 0x2554);
	canvas.SetChar(m_Width - 1, 0, 0x2557);
	canvas.SetChar(0, m_Height - 1, 0x255A);
	canvas.SetChar(m_Width - 1, m_Height - 1, 0x255D);

	for (int y = 1; y < m_Height - 1; ++y) {
		for (int x = 1; x < m_Height - 1; ++x) {
			canvas.SetChar(x, y, 0x0387);
		}
	}
}