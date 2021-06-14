#pragma once
#ifndef GAME_H
#define GAME_H

//static definitions
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1440

#include "GameState.h"
#include "MenuState.h"
#include "StartPageState.h"

class Game
{

private:
    //Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    //Initialization
    void InitWindow();
    void InitStates();
public:
    //Constructors - Destructors
    Game();
    virtual ~Game();

    //functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

#endif

