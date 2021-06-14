#include "StartPageState.h"

//INITIALIZATION
void StartPageState::InitVariables()
{
	this->opacity = 255;
	this->btn_opacity = 255;
	this->btnStatus = FadeIn;
	this->pageStatus = FadeIn;
}

void StartPageState::InitScreen()
{
	this->BlackScreen.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, 255));

	if (!this->bg_texture.loadFromFile("Assets/Images/start page wallpaper.png")) {
		std::cout << "START_PAGE::BACKGROUND_FAIL_TO_LOAD" << std::endl;
	}
	this->bg_sprite.setTexture(this->bg_texture);

	if (!this->continue_texture.loadFromFile("Assets/Images/enter continue btn.png")) {
		std::cout << "START_PAGE::BACKGROUND_FAIL_TO_LOAD" << std::endl;
	}
	this->continue_sprite.setTexture(this->continue_texture);
	this->continue_sprite.setColor(sf::Color::Color(255, 255, 255, 255));
	this->continue_sprite.setPosition(sf::Vector2f(800, 600));

	if(!this->enterBuffer.loadFromFile("Assets/Sound Effects/taiko rim.ogg")) {
		std::cout << "START_PAGE::SOUND_FAIL_TO_LOAD" << std::endl;
	}
	this->enterSound.setBuffer(this->enterBuffer);

	if (!this->openingMusic.openFromFile("Assets/Music/start opening theme.ogg")) {
		std::cout << "START_PAGE::OPENING_MUSIC_FAIL_TO_LOAD" << std::endl;
	}

	this->openingMusic.setLoop(true);
}


//CONSTRUCTORS
StartPageState::StartPageState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->InitScreen();
	this->InitVariables();
}

StartPageState::~StartPageState()
{
}


//FUNCTIONS
const bool& StartPageState::getQuit() const
{
	return this->quit;
}

void StartPageState::endState()
{
}

void StartPageState::btnFade()
{
	if (this->btnStatus == FadeIn) {
		this->btn_opacity -= 5;
		if (this->btn_opacity > 0) {
			this->continue_sprite.setColor(sf::Color::Color(255, 255, 255, this->btn_opacity));
		}
		else {
			this->btn_opacity = 0;
			this->btnStatus = FadeOut;
		}
	}
	else {
		this->btn_opacity += 5;
		if (this->btn_opacity < 255) {
			this->continue_sprite.setColor(sf::Color::Color(255, 255, 255, this->btn_opacity));
		}
		else {
			this->btn_opacity = 255;
			this->btnStatus = FadeIn;
		}
	}
}

void StartPageState::FadingIn()
{
	if (this->pageStatus == FadeIn) {
		if (this->openingMusic.getStatus() == sf::Music::Stopped)
			this->openingMusic.play();

		this->opacity -= 2 ;
		if (this->opacity > 0) {
			this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, this->opacity));
		}
		else {
			this->pageStatus = Running;
		}
	}
}

void StartPageState::FadingOut()
{
	if (this->pageStatus == FadeOut) {

		this->opacity += 2;
		if (this->opacity < 255) {
			this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, this->opacity));
		}
		else {
			this->pageStatus = NextPage;
		}
	}
}

void StartPageState::updateKeybinds(const float& dt, sf::Event::EventType eventType)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (this->pageStatus == Running) {
			this->pageStatus = FadeOut;
			this->enterSound.play();
		}
	}
}

void StartPageState::update(const float& dt)
{
	
	this->btnFade();

	if (this->pageStatus == Running) {
		/*this->updateKeybinds(dt);*/
	}

	switch (this->pageStatus) {
		case FadeIn: this->FadingIn(); break;
		case FadeOut: 
			if (this->openingMusic.getStatus() == sf::Music::Playing)
				this->openingMusic.stop();
			this->FadingOut();break;
		case NextPage:
			this->pageStatus = ShutDown;
			this->states->push(new MenuState(this->window, this->states));
			break;
		case ShutDown:
			this->quit = true;
			break;
		default:
			break;
	}
}

void StartPageState::render(sf::RenderTarget* target)
{
	target->draw(this->bg_sprite);

	if (this->pageStatus == Running)
		target->draw(this->continue_sprite);

	if (this->pageStatus != Running) {
		target->draw(this->BlackScreen);
	}

}
