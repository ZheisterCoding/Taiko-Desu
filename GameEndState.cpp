#include "GameEndState.h"

void GameEndState::InitVariables()
{
	this->temp_points = 0;
	this->temp_combo = 0;
	this->temp_good = this->temp_bad = this->temp_ok = 0;
	this->current_dp = POINTS;
	this->screen_a = 0;
}

void GameEndState::InitFrame()
{
	if (!this->screen_texture.loadFromFile("Assets/Images/game end page v1.png")) {
		std::cout << "GAMEENDSTATE::SCREEN_TEXTURE_FAIL_TO_LOAD" << std::endl;
	}
	this->screen_sprite.setTexture(this->screen_texture);

	this->BlackScreen.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, 0));
}

void GameEndState::InitText()
{
	if (!taikoFont.loadFromFile("Assets/Fonts/TaikoNoTatsujin.ttf")) {
		std::cout << "GAMEENDSTATE::INIT_TEXT::FAIL_TO_LOAD_TAIKONOTATSUJIN_FONT" << std::endl;
	}

	this->PointText.setString("NONE");
	this->PointText.setFont(this->taikoFont);
	this->PointText.setCharacterSize(30);
	this->PointText.setPosition(sf::Vector2f(530, 350));

	this->ComboText.setString("NONE");
	this->ComboText.setFont(this->taikoFont);
	this->ComboText.setCharacterSize(30);
	this->ComboText.setPosition(sf::Vector2f(1090, 350));

	this->GoodText.setString("NONE");
	this->GoodText.setFont(this->taikoFont);
	this->GoodText.setCharacterSize(25);
	this->GoodText.setPosition(sf::Vector2f(850, 270));
	this->GoodText.setFillColor(sf::Color::Black);

	this->BadText.setString("NONE");
	this->BadText.setFont(this->taikoFont);
	this->BadText.setCharacterSize(25);
	this->BadText.setPosition(sf::Vector2f(850, 420));
	this->BadText.setFillColor(sf::Color::Black);

	this->OkText.setString("NONE");
	this->OkText.setFont(this->taikoFont);
	this->OkText.setCharacterSize(25);
	this->OkText.setPosition(sf::Vector2f(850, 340));
	this->OkText.setFillColor(sf::Color::Black);

}


//CONSTRUCTORS
GameEndState::GameEndState(sf::RenderWindow* window, std::stack<State*>* states, PointData data)
	: State(window, states)
{
	this->InitVariables();
	this->InitFrame();
	this->InitText();
	this->game_result = data;
}

GameEndState::~GameEndState()
{
}

void GameEndState::endState()
{
	std::cout << "quitting Game Over Screen... " << std::endl;
}


void GameEndState::updateFadeOut()
{
	if (this->current_dp == FADE && this->quitTimer.getElapsedTime().asSeconds() > 3.f) {
		this->screen_a += 8;
		if (this->screen_a < 255) {
			this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, this->screen_a));
		}
		else {
			this->current_dp = FINISH;
		}
	}
}

//UPDATE
void GameEndState::updateKeybinds(const float& dt, sf::Event::EventType eventType)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}*/
}

void GameEndState::update(const float& dt)
{

	this->updatePoints();
	this->updateCommentPoints();
	this->updateCombo();
	this->updateText();
	this->updateFadeOut();

	if (this->current_dp == FINISH) {
		this->quit = true;
	}
}

void GameEndState::updateCommentPoints()
{
	if (this->current_dp == COMMENT) {
		if (this->temp_good < this->game_result.good
			|| this->temp_bad < this->game_result.bad
			|| this->temp_ok < this->game_result.ok) 
		{
			if (this->temp_good < this->game_result.good)
				this->temp_good++;
			if (this->temp_ok < this->game_result.ok)
				this->temp_ok++;
			if (this->temp_bad < this->game_result.bad)
				this->temp_bad++;
		}
		else {
			this->current_dp = COMBO;
		}

	}
}

void GameEndState::updateCombo()
{
	if (this->current_dp == COMBO) {
		if (this->temp_combo < this->game_result.long_combo) {
			this->temp_combo += 1;
		}
		else {
			this->current_dp = FADE;
			this->quitTimer.restart();
		}
		
	}
}

void GameEndState::updatePoints()
{
	if (this->current_dp == POINTS) {
		if (this->temp_points < this->game_result.points && this->current_dp == POINTS) {
			this->temp_points += 250;
		}
		else
			this->current_dp = COMMENT;
	}
}

void GameEndState::updateText()
{
	std::stringstream ss_points, ss_combo, ss_good, ss_bad, ss_ok;
	ss_points << std::setfill('0') << std::setw(7) << this->temp_points;
	this->PointText.setString(ss_points.str());

	ss_combo << std::setfill('0') << std::setw(3) << this->temp_combo;
	this->ComboText.setString(ss_combo.str());

	ss_good << std::setfill('0') << std::setw(3) << this->temp_good;
	this->GoodText.setString(ss_good.str());

	ss_ok << std::setfill('0') << std::setw(3) << this->temp_ok;
	this->OkText.setString(ss_ok.str());

	ss_bad << std::setfill('0') << std::setw(3) << this->temp_bad;
	this->BadText.setString(ss_bad.str());
}


//RENDER
void GameEndState::render(sf::RenderTarget* target)
{
	target->draw(screen_sprite);
	this->renderText(target);

	if (this->current_dp == FADE) {
		target->draw(this->BlackScreen);
	}
}

void GameEndState::renderText(sf::RenderTarget* target)
{
	target->draw(PointText);

	target->draw(ComboText);

	target->draw(GoodText);

	target->draw(BadText);

	target->draw(OkText);
}
