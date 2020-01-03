#pragma once

#include<SFML/Graphics.hpp>

class Application {
public:
	Application(unsigned int a_size, unsigned int a_cellCount, bool a_fullscreen); // Constructor
	Application(const Application& other) = delete; // No copies of application should be made

	~Application(); // Destructor

};