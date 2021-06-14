#pragma once

#ifndef STATE_H
#define STATE_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
#include <map>

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "GameData.h"

//WINDOW SIZE DEFINITIONS
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1440

class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool quit;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();
	
	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;

	virtual void updateMousePosition();
	virtual void updateKeybinds(const float& dt, sf::Event::EventType eventType) = 0;
	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget*target = nullptr) = 0;
};

#endif