#include "Application.h"

#include"Math.h"

#include<map>
#include<random>
#include<iostream>

/* MOVES THIS TO SOME SFML_UTILITY.H FILE!!! */
static std::vector<sf::RectangleShape> shapesThisFrame = {};
static void drawCell(Vector2 windowSize, Vector2 gridSize, int cellValue,
	sf::RenderWindow& renderWindow) {

	// Caches the shape in our static vector since sfml takes references to drawable objects ):
	sf::RectangleShape rect;
	// Setup the shape! @@ 
	shapesThisFrame.push_back(rect);
	renderWindow.draw(shapesThisFrame.back());
}

Application::Application(unsigned int a_size, unsigned int a_cellCount, bool a_fullscreen) 
{
	sf::RenderWindow window(sf::VideoMode(a_size, a_size), "Cellular Aumation");

	static int SIZE = 6;

	// 6 by 6 cell grid
	std::vector<std::vector<int>> cellGrid = {
		{ 0, 0, 0, 0, 1, 1 },
	    { 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 }
	};

	// cellGrid[y, x];

	srand(time(NULL));

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			int cellState = (rand() % 100) > 30 ? 0 : 1;
			cellGrid[y][x] = cellState;
		}
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Process events here
		}
		
		
		// Process logic here
		

		window.clear();

		// Render here
		// Draw all the cells
		for (int y = 0; y < SIZE; y++) {
			for (int x = 0; x < SIZE; x++) {
				drawCell
			}
		}


		//sf::sleep(sf::seconds(0.2));
		window.display();
	}

	// DOne
}

Application::~Application()
{
}
