#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Graphics.h"
#include "GameData.h"
#include "GameEndState.h"

#define TAP_RADIUS 50
#define TAP_SPEED 20 //framerate

struct BeatTaps {
    sf::Sprite tap_sprite;
    Beats info;
};

class GameState :
    public State
{
private:
    //Variables
    sf::Music track;
    GameGraphics gameGraphics;

    //Sound Buffers
    sf::SoundBuffer red_buffer, blue_buffer, gold_buffer;
    sf::Sound red_sound, blue_sound, gold_sound;
    bool red_sound_bool, blue_sound_bool, gold_sound_bool;

    //spawnPosition
    sf::Vector2f spawnPosition;

    //Clock
    sf::Clock spawnClock;
    sf::Clock trackClock;

    //Game Logic // boolean
    long int points;
    int combo, good, bad, ok;
    int max_combo;
    int tapsIndex;
    int intersectObjRef;

    std::vector<bool> intersecting;
    bool playing;
    bool comboStatus;
    bool gameOver; 
    bool pause_menu_bool;
    float pause_time;
    enum GameStatus { preStart, Running, Pause, End } gameStatus;

    //Game objects
    std::vector<BeatTaps> taps;
    sf::RectangleShape cursorLine, eraseLine;
    sf::CircleShape targetTap;
    sf::Texture redTaiko, blueTaiko, goldenTaiko;

    enum class COMMENT{EMPTY, RUNNING, GOOD, OK, BAD};
    COMMENT comment_bool;

    sf::Texture GOOD_texture, BAD_texture, OK_texture;
    int comment_alpha;
    sf::Sprite comment_sprite;
    sf::Clock comment_timer;


    //BlackScreen logic
    sf::RectangleShape BlackScreen;
    int b_screen_a;
    bool b_screen_fade;
 
    //Game Data 
    std::vector<Beats> midiBeats;

    //Fonts and Text
    sf::Text Title;
    sf::Text pointText;
    sf::Text comboText;
    sf::Font arialFont;
    sf::Font taikoFont;

    //Private Constructors
    void InitSoundBuffer();
    void InitVariables();
    void InitText(GameData * data);
    void InitMusicData(GameData * data);
    void InitStaticObjects();

    //Load graphics
    void loadGraphics();
public:
    /*Constructors Destructors*/
    GameState(sf::RenderWindow* window, std::stack<State*>* states, GameData * data);
    virtual ~GameState();
    void endState();

    //functions
    void spawnTap(Beats _info);
    float spawnToCursor_TimeInSeconds();
    int pointAlloc(sf::Sprite _tap);

    //update
    void updateComment(COMMENT _state);
    void updatePauseMenu();
    void updateFadeIn();
    void updateFadeOut();
    void updateTaps();
    void updateText();
    void updateKeybinds(const float& dt, sf::Event::EventType eventType);
    void update(const float &dt);

    //render
    void renderFadeInOut(sf::RenderTarget& target);
    void renderTaps(sf::RenderTarget& target);
    void renderText(sf::RenderTarget& target);
    void renderComment(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

    //draw in-game class objects
    void drawObjects(sf::RenderTarget& target);

};


#endif