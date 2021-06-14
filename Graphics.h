#ifndef COMPONENT_DEF_H
#define COMPONENT_DEF_H

#include <string>
#include <vector>
#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include <SFML/Audio.hpp>

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1440

#pragma once

enum class BeatType{LEFT = 0, RIGHT = 1, BOTH = 2};

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };

enum class MenuSelection { IDLE, CONTINUE, EXIT };
//struct gameData {
//	std::string songTitle;
//	std::string fileName;
//	std::vector<Beats> beatInfo;
//};

class Button {
protected:
	short unsigned buttonState;

	sf::RectangleShape defaultShape;
	sf::Font* defaultFont;
	sf::Text centerText;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	friend class GameGraphics;
public:
	Button(float x_pos, float y_pos, float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//ACCESSORS
	const bool isPressed() const;

	//update
	virtual void update(const sf::Vector2f mousePos);
	
	//render
	virtual void render(sf::RenderTarget* target);
};

class Beats
{
	public:
		BeatType type;
		double timeStamp;
	public:
		Beats(BeatType _type = BeatType::LEFT, double _timeStamp = 0) : type(_type), timeStamp(_timeStamp) {};
};

class GameGraphics {
	public:
		//TapLane
		sf::RectangleShape TopLane;
		sf::RectangleShape BottomLane;
		sf::RectangleShape MiddleLane;

		sf::RectangleShape VertLine;
		sf::RectangleShape ScoreBox;
		sf::RectangleShape PointRect;

		sf::RectangleShape PauseScreen;
		Button *continue_btn;
		Button *quit_btn;
		sf::Font taikoFont;

		//Background
		sf::Texture bgTexture;
		sf::Sprite bgSprite;

	public:
		void Load(sf::RenderTarget& target);
		void drawLane(sf::RenderTarget& target);
		void drawBG(sf::RenderTarget& target);
		void drawScoreBox(sf::RenderTarget& target);
		void drawPauseMenu(sf::RenderTarget* target);
		MenuSelection updateMenu(sf::Vector2f mousePos);
};
#endif