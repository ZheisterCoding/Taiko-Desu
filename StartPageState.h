#pragma once
#include "State.h"
#include "MenuState.h"

class StartPageState :
    public State
{
private:
	//Enum
	enum pageState {
		FadeIn, Running, FadeOut, NextPage, ShutDown
	};
	short unsigned pageStatus, btnStatus;

	//Objects
	sf::RectangleShape BlackScreen;

	sf::Texture bg_texture, continue_texture;
	sf::Sprite bg_sprite, continue_sprite;

	//sounds
	sf::SoundBuffer enterBuffer;
	sf::Sound enterSound;

	//Music
	sf::Music openingMusic;

	//Variables
	int opacity, btn_opacity;

	void InitVariables();
	void InitScreen();
public:
	StartPageState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~StartPageState();

	const bool& getQuit() const;

	void endState();

	void btnFade();
	void FadingIn();
	void FadingOut();
	void updateKeybinds(const float& dt, sf::Event::EventType eventType);
	void update(const float& dt);

	void render(sf::RenderTarget* target);
};

