#include "Game.h"

void Game::InitWindow()
{
	this->videoMode.height = WINDOW_HEIGHT;
	this->videoMode.width = WINDOW_WIDTH;

	this->window = new sf::RenderWindow(this->videoMode, "Taiko No Tatsujin", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitStates()
{
	this->states.push(new StartPageState(this->window, &this->states));
}

Game::Game()
{
	this->InitWindow();
	this->InitStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateDt()
{
	/*update the delta time, to maintain constant framerate*/
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		if (!this->states.empty()) {
			this->states.top()->updateKeybinds(this->dt, this->sfEvent.type);
		}
	}

}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
			std::cout << "endState..." << std::endl;
		}
	}
	//Application end
	else {
		this->window->close();
	}
}
		

void Game::render()
{

	this->window->clear();
	
	if (!this->states.empty())
		this->states.top()->render(this->window);

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

