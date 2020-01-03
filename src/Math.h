#pragma once

#include<SFML/Graphics.hpp>

#include<cmath>

struct Vector2 {
	int x = 0;
	int y = 0;

	bool operator<(const Vector2& b) const {
		if (y < b.y)
		{
			return true;
		}
		else if (y == b.y)
		{
			if (x < b.x)
			{
				return true;
			}
			else if (x == b.x)
			{
				// completely equal
				return false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};

enum CellStates {
	ALIVE = 1,
	DEAD = 0
};

struct Cell {
	CellStates cellState;
	CellStates newCellState;

	sf::RectangleShape cellShape; 
	void prepareCellForDraw(unsigned int a_screenSize, unsigned int a_cellCount, Vector2 a_cellPosition);
};