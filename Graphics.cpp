#include "Graphics.h"

//Button Class Functions
Button::Button(float x_pos, float y_pos, float width, float height, 
	sf::Font* font, std::string text, 
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->defaultShape.setPosition(sf::Vector2f(x_pos, y_pos));
	this->defaultShape.setSize(sf::Vector2f(width, height));

	this->defaultFont = font;
	this->centerText.setFont(*this->defaultFont);
	this->centerText.setString(text);
	this->centerText.setFillColor(sf::Color::White);
	this->centerText.setOutlineThickness(8);
	this->centerText.setCharacterSize(12);
	this->centerText.setPosition(
		this->defaultShape.getPosition().x + this->defaultShape.getGlobalBounds().width / 2 - this->centerText.getGlobalBounds().width / 2,
		this->defaultShape.getPosition().y + this->defaultShape.getGlobalBounds().height / 2 - this->centerText.getGlobalBounds().height / 2
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->buttonState = BTN_IDLE;
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}

void Button::update(const sf::Vector2f mousePos)
{

	this->buttonState = BTN_IDLE;

	if (this->defaultShape.getGlobalBounds().contains(mousePos)) {
		//Hover
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_PRESSED;
		}
	}

	switch (buttonState) 
	{
		case BTN_IDLE:
			this->defaultShape.setFillColor(this->idleColor);
			break;
		case BTN_HOVER:
			this->defaultShape.setFillColor(this->hoverColor);
			break;
		case BTN_PRESSED:
			this->defaultShape.setFillColor(this->activeColor);
			break;
		default:
			this->defaultShape.setFillColor(sf::Color::Red);

			break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->defaultShape);
	target->draw(this->centerText);
}



//general Graphics Functions
void GameGraphics::Load(sf::RenderTarget& target)
{
	drawBG(target);
	drawLane(target);
}

void GameGraphics::drawLane(sf::RenderTarget& target)
{

	TopLane.setPosition(sf::Vector2f(0, WINDOW_HEIGHT / 3 - 50));
	TopLane.setSize(sf::Vector2f(WINDOW_WIDTH, 4));
	TopLane.setFillColor(sf::Color::Black);

	BottomLane.setPosition(sf::Vector2f(0, WINDOW_HEIGHT / 3 + 150));
	BottomLane.setSize(sf::Vector2f(WINDOW_WIDTH, 4));
	BottomLane.setFillColor(sf::Color::Black);

	MiddleLane.setPosition(0, TopLane.getPosition().y + 4);
	MiddleLane.setSize(sf::Vector2f(WINDOW_WIDTH , BottomLane.getPosition().y - TopLane.getPosition().y - 4));
	MiddleLane.setFillColor(sf::Color::Color(80,100,140));

	target.draw(TopLane);
	target.draw(BottomLane);
	target.draw(MiddleLane);
}

void GameGraphics::drawBG(sf::RenderTarget& target)
{
	if (!bgTexture.loadFromFile("Assets/Images/red_background.png")) {
		std::cout << "bg load fail" << std::endl;
	}
	bgSprite.setTexture(bgTexture);
	target.draw(bgSprite);
}

void GameGraphics::drawScoreBox(sf::RenderTarget& target)
{
	ScoreBox.setPosition(sf::Vector2f(0, TopLane.getPosition().y + 4));
	ScoreBox.setSize(sf::Vector2f(VertLine.getPosition().x, BottomLane.getPosition().y - TopLane.getPosition().y - 4));
	ScoreBox.setFillColor(sf::Color::Red);

	PointRect.setPosition(sf::Vector2f(0, WINDOW_HEIGHT / 3 + 95));
	PointRect.setSize(sf::Vector2f(VertLine.getPosition().x, 40));
	PointRect.setFillColor(sf::Color::Color(0, 0, 0, 150));

	VertLine.setPosition(sf::Vector2f(WINDOW_WIDTH / 7 + 75, TopLane.getPosition().y + 4));
	VertLine.setSize(sf::Vector2f(4, BottomLane.getPosition().y - TopLane.getPosition().y - 4));
	VertLine.setFillColor(sf::Color::Black);

	target.draw(ScoreBox);
	target.draw(PointRect);
	target.draw(VertLine);
}

void GameGraphics::drawPauseMenu(sf::RenderTarget* target)
{
	if (!taikoFont.loadFromFile("Assets/Fonts/TaikoNoTatsujin.ttf")) {
		std::cout << "TAIKO_FONT::FAILED_TO_LOAD" << std::endl;
	}

	this->PauseScreen.setFillColor(sf::Color::Color(0, 0, 0, 80));
	this->PauseScreen.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

	this->continue_btn = new Button(WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 3, 100,
		&this->taikoFont, "CONTINUE",
		sf::Color::White, sf::Color(150, 140, 140), sf::Color(210, 210, 210));
	this->continue_btn->centerText.setCharacterSize(40);

	this->quit_btn = new Button(WINDOW_WIDTH / 3, WINDOW_HEIGHT * 2 / 3, WINDOW_WIDTH / 3, 100,
		&this->taikoFont, "QUIT",
		sf::Color(100, 100, 100), sf::Color(150, 140, 140), sf::Color(210, 210, 210));
	this->quit_btn->centerText.setCharacterSize(40);

	target->draw(this->PauseScreen);
	this->continue_btn->render(target);
	this->quit_btn->render(target);
}

MenuSelection GameGraphics::updateMenu(sf::Vector2f mousePos)
{
	if (this->continue_btn != NULL && this->quit_btn != NULL) {
		this->continue_btn->update(mousePos);
		this->quit_btn->update(mousePos);

		if (this->continue_btn->isPressed()) {
			return MenuSelection::CONTINUE;
		}
		else if (this->quit_btn->isPressed()) {
			return MenuSelection::EXIT;
		}
	}

	return MenuSelection::IDLE;
}

