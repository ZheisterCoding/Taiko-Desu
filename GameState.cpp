#include "GameState.h"

//PUBLIC CONSTRUCTORS / DESTRUCTORS
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, GameData * data)
	: State(window, states)
{
	this->InitSoundBuffer();
	this->InitVariables();
	this->InitStaticObjects();
	this->InitText(data);
	this->InitMusicData(data);
	this->loadGraphics();
}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "quitting Game state... " << std::endl;
}

void GameState::InitSoundBuffer()
{
	if (!this->red_buffer.loadFromFile("Assets/Sound Effects/taiko bass.ogg")) {
		std::cout << "GAME_STATE::RED_SOUND_FAIL_TO_LOAD" << std::endl;
	}
	if (!this->gold_buffer.loadFromFile("Assets/Sound Effects/taiko bass.ogg")) {
		std::cout << "GAME_STATE::GOLD_SOUND_FAIL_TO_LOAD" << std::endl;
	}
	if (!this->blue_buffer.loadFromFile("Assets/Sound Effects/taiko rim.ogg")) {
		std::cout << "GAME_STATE::RED_SOUND_FAIL_TO_LOAD" << std::endl;
	}

	this->red_sound.setBuffer(this->red_buffer);
	this->blue_sound.setBuffer(this->blue_buffer);
	this->gold_sound.setBuffer(this->gold_buffer);

	this->gold_sound.setPitch(0.7F);

	this->red_sound_bool = this->blue_sound_bool = this->gold_sound_bool = false;
}

//PRIVATE CONSTRUCTORS / DESTRUCTORS
void GameState::InitVariables()
{
	//spawn position
	this->spawnPosition.x = WINDOW_WIDTH + TAP_RADIUS;
	this->spawnPosition.y = WINDOW_HEIGHT / 3;

	//game logic

	//cumulatives data
	this->points = 0;
	this->combo = 0;
	this->max_combo = 0;
	this->good = this->bad = this->ok = 0;

	//others
	this->tapsIndex = 0;
	this->pause_time = 0.F;
	this->playing = false;
	this->intersectObjRef = -1;
	
	this->comboStatus = false;
	this->gameOver = false;
	this->pause_menu_bool = false;

	//black screen alpha value
	this->b_screen_a = 255;
	this->b_screen_fade = true;
}

void GameState::InitText(GameData * data)
{
	if (!this->arialFont.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "GAME_STATE::ARIAL_FONT_FAIL_TO_LOAD" << std::endl;
	}


	if (!this->taikoFont.loadFromFile("Assets/Fonts/TaikoNoTatsujin.ttf")) {
		std::cout << "GAME_STATE::TAIKO_FONT_FAIL_TO_LOAD" << std::endl;
	}

	this->pointText.setFont(this->taikoFont);
	this->pointText.setString("00000000");
	this->pointText.setPosition(sf::Vector2f(eraseLine.getPosition().x - 100, WINDOW_HEIGHT / 3 + 100));
	this->pointText.setCharacterSize(20);
	this->pointText.setOutlineColor(sf::Color::Black);

	this->comboText.setFont(this->taikoFont);
	this->comboText.setString("0");
	this->comboText.setPosition(eraseLine.getPosition().x - 100, WINDOW_HEIGHT / 3);
	this->comboText.setCharacterSize(50);
	this->comboText.setFillColor(sf::Color::White);
	this->comboText.setOutlineColor(sf::Color::Black);
	this->comboText.setOutlineThickness(6);

	this->Title.setFont(this->taikoFont);
	this->Title.setString(data->songTitle);
	this->Title.setOutlineColor(sf::Color::Black);
	this->Title.setOutlineThickness(4);
	this->Title.setCharacterSize(30);
	this->Title.setFillColor(sf::Color::White);
	this->Title.setOrigin(this->Title.getGlobalBounds().width, 0);
	this->Title.setPosition(WINDOW_WIDTH * 8 / 9, WINDOW_HEIGHT / 8);
	
}

void GameState::InitMusicData(GameData * data)
{
	if (!this->track.openFromFile(data->songFilePath))
		std::cout << "GAME_STATE::MUSIC_DATA_FAIL_TO_LOAD" << std::endl;

	this->midiBeats = data->BeatData;
}

void GameState::InitStaticObjects()
{

	//cursor line initialization
	this->cursorLine.setSize(sf::Vector2f(3, WINDOW_HEIGHT));
	this->cursorLine.setPosition(sf::Vector2f(2 * WINDOW_WIDTH / 7, WINDOW_HEIGHT / 3));
	this->cursorLine.setFillColor(sf::Color::Color(0, 0, 0, 0));

	//target tap, area to hit the taps
	this->targetTap.setRadius((double)TAP_RADIUS);
	this->targetTap.setPosition(sf::Vector2f(2 * WINDOW_WIDTH / 7 - TAP_RADIUS, WINDOW_HEIGHT / 3));
	this->targetTap.setFillColor(sf::Color::Color(0,0,0,0));
	this->targetTap.setOutlineThickness(7);
	this->targetTap.setOutlineColor(sf::Color::Color(0,0,0));

	//erase line initialization
	this->eraseLine.setSize(sf::Vector2f(3, WINDOW_HEIGHT));
	this->eraseLine.setPosition(sf::Vector2f(1 * WINDOW_WIDTH / 7 + 50, 0));
	this->eraseLine.setFillColor(sf::Color::Color(0, 0, 0, 0));

	//BlackScreen
	this->BlackScreen.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, 255));

}


//LOAD GRAPHICS

void GameState::loadGraphics()
{
	//Load Textures
	if (!redTaiko.loadFromFile("Assets/Images/red taiko.png")) {
		std::cout << "GAME_STATE::RED_TAIKO_SPRITE_FAIL_TO_LOAD" << std::endl;
	}
	if (!blueTaiko.loadFromFile("Assets/Images/blue taiko.png")) {
		std::cout << "GAME_STATE::BLUE_TAIKO_SPRITE_FAIL_TO_LOAD" << std::endl;
	}
	if (!goldenTaiko.loadFromFile("Assets/Images/golden taiko.png")) {
		std::cout << "GAME_STATE::GOLD_TAIKO_SPRITE_FAIL_TO_LOAD" << std::endl;
	}


	if (!GOOD_texture.loadFromFile("Assets/Images/GOOD!.png")) {
		std::cout << "GAME_STATE::GOOD_SPRITE_FAIL_TO_LOAD" << std::endl;
	}
	if (!OK_texture.loadFromFile("Assets/Images/OK!.png")) {
		std::cout << "GAME_STATE::OK_SPRITE_FAIL_TO_LOAD" << std::endl;
	}
	if (!BAD_texture.loadFromFile("Assets/Images/BAD!.png")) {
		std::cout << "GAME_STATE::BAD_SPRITE_FAIL_TO_LOAD" << std::endl;
	}

	this->comment_sprite.setPosition(sf::Vector2f(WINDOW_WIDTH / 7 + 83, WINDOW_HEIGHT / 3 - 43));
	this->comment_alpha = 0;
	return;
}


//GENERAL FUNCTIONS

void GameState::spawnTap(Beats _info)
{
	/**
	@ return void

	spawn taps and positions
	*/

	//Spawn the taps
	BeatTaps newTap;

	newTap.info = _info;

	switch (newTap.info.type) {
	case BeatType::LEFT:
		newTap.tap_sprite.setTexture(redTaiko);
		newTap.tap_sprite.setPosition(this->spawnPosition);
		newTap.tap_sprite.setScale(0.5, 0.5);
		break;
	case BeatType::RIGHT:
		newTap.tap_sprite.setTexture(blueTaiko);
		newTap.tap_sprite.setPosition(this->spawnPosition);
		newTap.tap_sprite.setScale(0.5, 0.5);
		break;
	case BeatType::BOTH:
		newTap.tap_sprite.setTexture(goldenTaiko);
		newTap.tap_sprite.setPosition(sf::Vector2f(this->spawnPosition.x, this->spawnPosition.y - 15));
		newTap.tap_sprite.setScale(0.45, 0.45);
		break;
	}

	this->taps.push_back(newTap);
	this->intersecting.push_back(false);
}

float GameState::spawnToCursor_TimeInSeconds()
{
	/**
	@ return void

	calculates the time from spawn position to cursorLine position in seconds
	*/

	float length = WINDOW_WIDTH - cursorLine.getPosition().x + TAP_RADIUS;
	float speed = 60 * TAP_SPEED;
	return length / speed;
}

int GameState::pointAlloc(sf::Sprite _tap)
{
	float distance = _tap.getPosition().x - cursorLine.getPosition().x;
	/*float relative_pos = _tap.getTexture()->getSize().x;*/
	if (distance > -65 && distance < -40) {
		this->good++;
		comment_bool = COMMENT::GOOD;
		return 750;
	}
	else if (distance > -95 && distance < -5) {
		this->ok++;
		comment_bool = COMMENT::OK;
		return 500;
	}
	else {
		this->bad++;
		comment_bool = COMMENT::BAD;
		return 250;
	}
	return 0;
}


//UPDATE

void GameState::updateComment(COMMENT _state)
{
	switch (_state) {
		case COMMENT::GOOD:
			this->comment_sprite.setTexture(GOOD_texture, true);
			this->comment_sprite.setPosition(sf::Vector2f(
				cursorLine.getPosition().x - this->comment_sprite.getGlobalBounds().width/2, 
				WINDOW_HEIGHT / 3 - 40));
			this->comment_alpha = 0;
			this->comment_timer.restart();
			this->comment_bool = COMMENT::RUNNING;
			break;

		case COMMENT::OK:
			this->comment_sprite.setTexture(OK_texture, true);
			this->comment_sprite.setPosition(sf::Vector2f(
				cursorLine.getPosition().x - this->comment_sprite.getGlobalBounds().width / 2, 
				WINDOW_HEIGHT / 3 - 40));
			this->comment_alpha = 0;
			this->comment_timer.restart();
			this->comment_bool = COMMENT::RUNNING;
			break;

		case COMMENT::BAD:
			this->comment_sprite.setTexture(BAD_texture, true);
			this->comment_sprite.setPosition(sf::Vector2f(
				cursorLine.getPosition().x - this->comment_sprite.getGlobalBounds().width / 2, 
				WINDOW_HEIGHT / 3 - 40));
			this->comment_alpha = 0;
			this->comment_timer.restart();
			this->comment_bool = COMMENT::RUNNING;
			break;

		case COMMENT::RUNNING:
			this->comment_alpha += 25;
			if (this->comment_alpha < 255) {
				this->comment_sprite.setColor(sf::Color::Color(255, 255, 255, this->comment_alpha));
			}

			if (this->comment_timer.getElapsedTime().asSeconds() > 2.F)
				this->comment_bool = COMMENT::EMPTY;
			break;

		case COMMENT::EMPTY:
			break;
		default:
			break;
	}
}

void GameState::updatePauseMenu()
{
	if (this->gameStatus == Pause) {
		this->track.pause();
		
	}
}

void GameState::updateFadeIn()
{
	if (this->BlackScreen.getFillColor().a > 5) {
		this->b_screen_a -=2 ;
		this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, this->b_screen_a));
	}
	else {
		this->b_screen_fade = false;
	}
}

void GameState::updateFadeOut()
{
	if (this->BlackScreen.getFillColor().a < 250) {
		this->b_screen_a += 2;
		this->BlackScreen.setFillColor(sf::Color::Color(0, 0, 0, this->b_screen_a));
	}
	else {
		this->b_screen_fade = false;
	}
}

void GameState::updateTaps()
{
	/**
		@return void

		//updating timer for spawning
		//spawn and reset the timer
	*/
	

	if ((float)this->trackClock.getElapsedTime().asSeconds() > this->spawnToCursor_TimeInSeconds() && this->playing == false) {
		this->track.play();
		playing = true;
	}

	if (tapsIndex < midiBeats.size()) {
		
		if ((double)this->spawnClock.getElapsedTime().asSeconds() > this->midiBeats[tapsIndex].timeStamp - this->pause_time) {
			this->pause_time = 0;
			this->spawnTap(midiBeats[tapsIndex]);
			this->tapsIndex++;
			this->spawnClock.restart();
		}
	}

	//Move the taps sideways
	for (int i = 0; i < taps.size(); i++) {

		//Move the taps sideways
		this->taps[i].tap_sprite.move((float)(TAP_SPEED * -1), 0.f);

		//checking if any taps are intersecting with the target tap
		if (this->targetTap.getGlobalBounds().intersects(this->taps[i].tap_sprite.getGlobalBounds()))
		{
			this->intersecting[i] = true;
			this->intersectObjRef = i;
			if (gameStatus == preStart)
				gameStatus = Running;
		}
		else {
			if (this->comboStatus == true && this->intersecting[i] == true) {
				if (this->combo > this->max_combo)
					this->max_combo = this->combo;
				this->combo = 0;
				this->comboStatus = false;
			}
			this->intersecting[i] = false;
		}

		//Erase taps after exceeding boundary
		if (this->taps[i].tap_sprite.getPosition().x < this->eraseLine.getPosition().x - 100) {
			this->taps.erase(this->taps.begin() + i);
		}
	}
}

void GameState::updateText()
{
	std::stringstream ss, ss2;
	ss << std::setfill('0') << std::setw(8) << this->points;
	this->pointText.setString(ss.str());

	ss2 << this->combo;
	this->comboText.setString(ss2.str());
}

void GameState::updateKeybinds(const float &dt, sf::Event::EventType eventType)
{

	switch (eventType) {
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->red_sound_bool) {
				this->red_sound.play();
				this->red_sound_bool = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && !this->blue_sound_bool) {
				this->blue_sound.play();
				this->blue_sound_bool = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->gold_sound_bool) {
				this->gold_sound.play();
				this->gold_sound_bool = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->pause_menu_bool) {
				this->gameStatus = Pause;
				this->pause_menu_bool = true;
				this->pause_time = this->spawnClock.getElapsedTime().asSeconds();
				return;
			}
			break;
		case sf::Event::KeyReleased:
			this->red_sound_bool = false;
			this->blue_sound_bool = false;
			this->gold_sound_bool = false;
			this->pause_menu_bool = false;
			break;
		default:
			break;
	}

	if (this->gameStatus == Running && !this->taps.empty() && !this->intersecting.empty()) {
		bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->intersecting[intersectObjRef] == true && this->taps[intersectObjRef].info.type == BeatType::LEFT;
		bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::L) && this->intersecting[intersectObjRef] == true && this->taps[intersectObjRef].info.type == BeatType::RIGHT;
		bool both = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->intersecting[intersectObjRef] == true && this->taps[intersectObjRef].info.type == BeatType::BOTH;

		if (left || right || both ) {
			this->points += this->pointAlloc(this->taps[intersectObjRef].tap_sprite);
			this->taps.erase(this->taps.begin() + intersectObjRef);
			this->intersecting.erase(this->intersecting.begin() + intersectObjRef);
			this->combo++;

			if (!this->comboStatus) {
				this->comboStatus = true;
			}
		}
	}

}

void GameState::update(const float& dt)
{
	
	this->updateComment(this->comment_bool);

	if (this->gameStatus != End && this->gameStatus != Pause) {
		if (this->b_screen_fade) {
			this->updateFadeIn();
		}

		this->updateTaps();

		this->updateText();
	}
	else if (this->gameStatus == Pause) {
		/*
		function for pause menu
		*/
		this->track.pause();

		this->updateMousePosition();

		
		MenuSelection menuState = gameGraphics.updateMenu(this->mousePosView);

		if (menuState == MenuSelection::CONTINUE) {
			this->gameStatus = Running;
			if (this->track.getStatus() == sf::Music::Paused) 
				this->track.play();
			this->spawnClock.restart();
		}
		else if (menuState == MenuSelection::EXIT) {
			this->gameStatus = End;
			this->gameOver = true;
			this->b_screen_fade = true;
		}
	}
	else {
		/*
		function for end screen here
		*/
		this->updateFadeOut();
		if (!this->b_screen_fade) {
			if (!this->gameOver) 
			{
				PointData temp(this->points, this->max_combo, this->good, this->bad, this->ok);
				this->states->push(new GameEndState(this->window, this->states, temp));
				this->gameOver = true;
			}
			else {
				this->quit = true;
			}
		}
	}

	if (this->playing == true && track.getStatus() == sf::SoundSource::Status::Stopped) {
		this->b_screen_fade = true;
		this->gameStatus = End;
	}
	
}



//RENDER

void GameState::renderFadeInOut(sf::RenderTarget& target)
{
	target.draw(this->BlackScreen);
}

void GameState::renderTaps(sf::RenderTarget& target)
{
	for (auto& e : taps) {
		target.draw(e.tap_sprite);
	}
}

void GameState::renderText(sf::RenderTarget& target)
{
	target.draw(this->pointText);
	target.draw(this->comboText);
	target.draw(this->Title);
}

void GameState::renderComment(sf::RenderTarget& target)
{
	if (this->comment_bool != COMMENT::EMPTY) {
		target.draw(this->comment_sprite);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	/*
		-clear old grame
		-render objects
		-display frame in window

		Render Game objects
	*/

	//Draw game objects, draw based on layer order
	

	this->gameGraphics.Load(*target);
	this->drawObjects(*target);

	this->renderTaps(*target);
	this->gameGraphics.drawScoreBox(*target);

	this->renderText(*target);

	if (this->b_screen_fade) {
		this->renderFadeInOut(*target);
	}

	if (this->gameStatus == Pause) {
		gameGraphics.drawPauseMenu(target);
	}

	this->renderComment(*target);
}



// DRAW IN GAMESTATE CLASS OBJECTS

void GameState::drawObjects(sf::RenderTarget& target)
{
	target.draw(cursorLine);
	target.draw(targetTap);
	target.draw(eraseLine);
}
