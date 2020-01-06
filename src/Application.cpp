#include "Application.h"

#include"Math.h"

#include<map>
#include<random>
#include<iostream>

Application::Application(unsigned int a_size, unsigned int a_cellCount, bool a_fullscreen) 
{
	sf::RenderWindow window(sf::VideoMode(a_size, a_size), "Cellular Aumation");

	std::map<Vector2, Cell> cellList;

	srand(time(NULL));

	for (int x = 0; x < a_cellCount; x++) {
		for (int y = 0; y < a_cellCount; y++) {
			Cell cell;
			//cell.cellState = (rand() % 100) > 30 ? CellStates::DEAD : CellStates::ALIVE;
			cell.cellState = CellStates::DEAD;
			cellList.insert(std::pair<Vector2, Cell>({ x, y }, cell));
		}
	}

	cellList[{0, 0}].cellState = CellStates::ALIVE;
	cellList[{1, 1}].cellState = CellStates::ALIVE;
	//cellList[{0, 1}].cellState = CellStates::ALIVE;
	//cellList[{1, 0}].cellState = CellStates::ALIVE;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Process events here
		}
		
		
		//// Process logic here
		//std::for_each(cellList.begin(), cellList.end(), [&](auto& p) {
		//	// Get the neighbours
		//	int numberOfAliveNeighbours = 0;
		//	for (int x = -1; x <= 1; x++) {
		//		for (int y = -1; y <= 1; y++) {
		//			if (x != 0 && y != 0) {
		//				if (cellList.find({ p.first.x + x, p.first.y + y }) != cellList.end()) {
		//					if (cellList.at({ p.first.x + x, p.first.y + y }).cellState == CellStates::ALIVE)
		//						numberOfAliveNeighbours++;
		//				}
		//			}
		//		}
		//	}

		//	//std::cout << numberOfAliveNeighbours;
		//	
		//	/* Check with the rules taken from [https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life] */

		//	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
		//	// Any live cell with two or three live neighbours lives on to the next generation.
		//	if (p.second.cellState == CellStates::ALIVE && (numberOfAliveNeighbours < 2 || numberOfAliveNeighbours > 3)) {
		//		p.second.newCellState = CellStates::DEAD;
		//	}
		//	// Any live cell with two or three live neighbours lives on to the next generation.
		//	if (p.second.cellState == CellStates::ALIVE && (numberOfAliveNeighbours == 2 || numberOfAliveNeighbours == 3)) {
		//		p.second.newCellState = CellStates::ALIVE;
		//	}
		//	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
		//	if (p.second.cellState == CellStates::DEAD && numberOfAliveNeighbours == 3) {
		//		p.second.newCellState = CellStates::ALIVE;
		//	}
		//});
		//

		//std::for_each(cellList.begin(), cellList.end(), [](auto& p) {
		//	p.second.cellState = p.second.newCellState;
		//});
		

		window.clear();

		// Render here
		// Draw all the cells
		std::for_each(cellList.begin(), cellList.end(), [&](auto& p) {
			p.second.prepareCellForDraw(a_size, a_cellCount, p.first);
			window.draw(p.second.cellShape);
		});

		//sf::sleep(sf::seconds(0.2));
		window.display();
	}

	// DOne
}

Application::~Application()
{
}
