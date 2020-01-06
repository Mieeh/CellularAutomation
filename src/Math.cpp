#include "Math.h"



static void FrameEnd() {
	shapesThisFrame.clear();
}

void Cell::prepareCellForDraw(unsigned int a_screenSize, unsigned int a_cellCount, Vector2 a_cellPosition)
{
	// Calculate cell size
	float cellSize = a_screenSize / a_cellCount;
	
	cellShape.setSize(sf::Vector2f(cellSize, cellSize));
	cellShape.setPosition(sf::Vector2f(a_cellPosition.x, a_cellPosition.y) * cellSize);

	cellShape.setFillColor(cellState == CellStates::ALIVE ? sf::Color::White : sf::Color::Black);
}
