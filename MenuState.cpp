#include "MenuState.h"

//PUBLIC CONSTRUCTORS DESTRUCTORS


MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{	
	this->how_to_screen = false;
	this->InitGameData();
	this->InitBackground();
	this->InitFont();
	this->InitButtons();
}

MenuState::~MenuState()
{
	auto it = this->MenuItems.begin();
	for (it = this->MenuItems.begin(); it != this->MenuItems.end(); ++it) {
		delete it->second;
	}
}

void MenuState::endState()
{
	std::cout << "End Menu State!" << std::endl;
}

void MenuState::InitGameData()
{
	float sec_note = 0.51725;
	this->gameData["TIAN TIAN DE"] = new GameData
	(
		"Tian Tian De",
		"Jay Chou",
		"Assets/Music/Tian Tian De short ver.ogg",
		std::vector<Beats>{
			//Intro
			Beats(BeatType::BOTH, 8.105), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note/2), Beats(BeatType::LEFT, sec_note/2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.100), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.100), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			
			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			
			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),


			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),

			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),


			Beats(BeatType::BOTH, sec_note - 0.150), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
			Beats(BeatType::BOTH, sec_note), Beats(BeatType::RIGHT, sec_note), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::LEFT, sec_note / 2), Beats(BeatType::RIGHT, sec_note),
		}
	);

	float note = 0.7795;
	this->gameData["BLUE BIRD"] = new GameData
	(
		"Blue Bird",
		"Ikimino Gakari",
		"Assets/Music/Blue Bird.ogg",
		std::vector<Beats>{
			//opening
			Beats(BeatType::BOTH, 6.130), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note), 
			Beats(BeatType::BOTH, note * 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note),
			Beats(BeatType::BOTH, note * 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note),
			Beats(BeatType::BOTH, note * 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note), 

			//instrumental
			Beats(BeatType::BOTH, note * 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note),
			Beats(BeatType::BOTH, note * 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note),
			
			//verse
			Beats(BeatType::BOTH, note * 2 - 0.050), Beats(BeatType::RIGHT, note/2), Beats(BeatType::RIGHT, note/2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), 
			Beats(BeatType::BOTH, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),

			Beats(BeatType::BOTH, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::BOTH, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),

			//pre-chorus
			Beats(BeatType::LEFT, note / 2 - 0.100), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3  /4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),

			Beats(BeatType::LEFT, note / 2 - 0.100), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::BOTH, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::RIGHT, note / 2),
			Beats(BeatType::BOTH, note / 2), Beats(BeatType::RIGHT, note), Beats(BeatType::LEFT, note),

			//chorus
			Beats(BeatType::LEFT, note * 2 - 0.070), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2 - 0.025), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),

			Beats(BeatType::LEFT, note / 2 - 0.045), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2 - 0.025), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),

			Beats(BeatType::LEFT, note / 2 - 0.080), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2 - 0.025), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),

			Beats(BeatType::LEFT, note / 2 - 0.05), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),
			Beats(BeatType::LEFT, note / 2), Beats(BeatType::RIGHT, note / 2), Beats(BeatType::BOTH, note * 3 / 4), Beats(BeatType::RIGHT, note / 4),


			Beats(BeatType::BOTH, note / 2)
		}
	);
}


void MenuState::InitBackground()
{
	if (!this->bg_texture.loadFromFile("Assets/Images/menu start bg purple.png")) {
		std::cout << "MENU_STATE::BG_TEXTURE_FAIL_TO_LOAD" << std::endl;
	}

	if (!this->HowTo_texture.loadFromFile("Assets/Images/controls menu.png")) {
		std::cout << "MENU_STATE::HOW_TO_TEXTURE_FAIL_TO_LOAD" << std::endl;
	}

	this->bg_sprite.setTexture(this->bg_texture);
	this->HowTo_Sprite.setTexture(this->HowTo_texture);
	this->HowTo_Sprite.setPosition(sf::Vector2f
	(
		WINDOW_WIDTH / 2 - HowTo_Sprite.getGlobalBounds().width / 2,
		WINDOW_HEIGHT / 2 - HowTo_Sprite.getGlobalBounds().height / 2
	)
	);

	this->BlackScreen.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, 180));
}

//INITIALIZING FUNCTIONS
void MenuState::InitFont()
{
	if (!taikoFont.loadFromFile("Assets/Fonts/TaikoNoTatsujin.ttf")) {
		std::cout << "TAIKO FONT FILE CANNOT BE LOADED: ERROR" << std::endl;
	}

	this->HowToText.setString("Press Esc: How To Play");
	this->HowToText.setFont(taikoFont);
	this->HowToText.setPosition(sf::Vector2f(10, 660));
	this->HowToText.setCharacterSize(30);
	this->HowToText.setOutlineColor(sf::Color::Black);
	this->HowToText.setOutlineThickness(4);
}

void MenuState::InitButtons()
{
	this->MenuItems["BLUE BIRD"] = new MenuButton(this->gameData["BLUE BIRD"], 
		&this->taikoFont, WINDOW_HEIGHT / 4);

	this->MenuItems["TIAN TIAN DE"] = new MenuButton(this->gameData["TIAN TIAN DE"],
		&this->taikoFont, WINDOW_HEIGHT * 3/ 4);
}


//UPDATE
void MenuState::updateKeybinds(const float& dt, sf::Event::EventType eventType)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->how_to_screen = true;
		this->HowToText.setString("Press Enter to Go Back");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (this->how_to_screen) {
			this->how_to_screen = false;
		}
		this->HowToText.setString("Press Esc: How To Play");
	}
}

void MenuState::update(const float& dt)
{
	/*this->updateKeybinds(dt);*/

	this->updateMousePosition();

	if(!this->how_to_screen)
		this->updateButtons();
}

void MenuState::updateButtons()
{
	for (auto& it : this->MenuItems) {
		it.second->update(this->mousePosView);
	}

	if (this->MenuItems["BLUE BIRD"]->isPressed()) {
		this->states->push(new GameState(this->window, this->states, this->gameData["BLUE BIRD"] ));
	}
	if (this->MenuItems["TIAN TIAN DE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->states, this->gameData["TIAN TIAN DE"] ));
	}
}


//RENDER

void MenuState::render(sf::RenderTarget* target)
{
	target->draw(this->bg_sprite);
	this->renderButtons(target);

	if (this->how_to_screen) {
		target->draw(this->BlackScreen);
		target->draw(this->HowTo_Sprite);
	}

	target->draw(this->HowToText);
}

void MenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->MenuItems) {
		it.second->render(target);
	}
}

// MENU ITEM FUNCTIOSN
MenuButton::MenuButton(GameData* data, sf::Font* font, int height)
{
	this->InitButton(height);
	this->InitText(data, font);
	this->InitMusic(data);
	this->InitSound();

	this->btn_hover = false;
}

MenuButton::~MenuButton()
{
	//delete this;
}

void MenuButton::InitButton(int height)
{
	if (!this->texture.loadFromFile("Assets/Images/menu item button.png")) {
		std::cout << "MENU_STATE::MENU_ITEM_LOAD_ERROR" << std::endl;
	}

	this->sprite.setTexture(this->texture);

	this->sprite.setPosition(sf::Vector2f(
		WINDOW_WIDTH / 2 - this->sprite.getGlobalBounds().width / 2,
		height - this->sprite.getGlobalBounds().height / 2
	));



}

void MenuButton::InitText(GameData* data, sf::Font* font)
{
	this->text.setFont(*font);
	this->text.setString(data->songTitle);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(5);
	this->text.setPosition(sf::Vector2f(
		this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2 - this->text.getGlobalBounds().width / 2,
		this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2 - this->text.getGlobalBounds().height / 2
	));
}

void MenuButton::InitSound()
{
	if (!this->menuSelBuffer.loadFromFile("Assets/Sound Effects/main menu select.ogg")) {
		std::cout << "MENU_STATE::MENU_BTN_SOUND_BUFFER_FAIL_TO_LOAD" << std::endl;
	}


	if (!this->menuHovBuffer.loadFromFile("Assets/Sound Effects/taiko rim.ogg")) {
		std::cout << "MENU_STATE::MENU_HOV_SOUND_BUFFER_FAIL_TO_LOAD" << std::endl;
	}
}


void MenuButton::InitMusic(GameData* data)
{
	this->songPath = data->songFilePath;
	if (!this->tempMusic.openFromFile(this->songPath)) {
		std::cout << "START_PAGE::MENU_BUTTON_MUSIC_FAIL_TO_LOAD" << std::endl;
	}
}

const bool MenuButton::isPressed() const
{
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}

void MenuButton::update(const sf::Vector2f mousePos)
{
	if (this->sprite.getTexture() != NULL) {
		this->buttonState = BTN_IDLE;

		if (this->sprite.getGlobalBounds().contains(mousePos)) {
			//Hover
			this->buttonState = BTN_HOVER;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->buttonState = BTN_PRESSED;
			}
		}

		switch (buttonState)
		{
		case BTN_IDLE:
			this->btn_hover = false;
			this->sprite.setColor(sf::Color::Color(100, 100, 100, 255));
			if (this->tempMusic.getStatus() == sf::Music::Playing) {
				this->tempMusic.stop();
			}
			break;

		case BTN_HOVER:
			if (!this->btn_hover) {
				this->menuBtnSound.setBuffer(this->menuHovBuffer);
				this->menuBtnSound.play();
				this->btn_hover = true;
			}

			this->sprite.setColor(sf::Color::Color(255, 255, 255, 255));
			if (this->tempMusic.getStatus() == sf::Music::Stopped) {
				this->tempMusic.setPlayingOffset(sf::seconds(50));
				this->tempMusic.play();
			}
			break;

		case BTN_PRESSED:
			this->menuBtnSound.setBuffer(this->menuSelBuffer);
			this->menuBtnSound.play();

			this->sprite.setColor(sf::Color::Color(255, 255, 255, 255));
			this->tempMusic.stop();
			break;
		default:
			break;
		}
	}
}



void MenuButton::render(sf::RenderTarget* target)
{
	if (this->sprite.getTexture() != NULL) {
		target->draw(this->sprite);
		target->draw(this->text);
	}
}
