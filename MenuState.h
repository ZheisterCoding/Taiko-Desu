#pragma once
#include "State.h"
#include "Graphics.h"
#include "GameState.h"
#include "GameData.h"



class MenuButton
{
public:
    static int idk;
    short unsigned buttonState;
    sf::RectangleShape Border;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;

    //SoundBuffer
    sf::SoundBuffer menuSelBuffer; //click sound
    sf::SoundBuffer menuHovBuffer; //hover sound
    sf::Sound menuBtnSound;
    bool btn_hover;
    sf::Music tempMusic;
    std::string songPath;

    void InitButton(int height);
    void InitText(GameData* data, sf::Font* font);
    void InitMusic(GameData* data);
    void InitSound();
public:
    MenuButton(GameData * data, sf::Font * font, int height);
    ~MenuButton();
    const bool isPressed() const;
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

};

class MenuState :
    public State
{
    private:
        //Objects
        std::map<std::string, MenuButton*> MenuItems;

        //Font
        sf::Font taikoFont;

        //Background
        sf::Texture bg_texture;
        sf::Sprite bg_sprite;

      

        //How To Screen
        sf::RectangleShape BlackScreen;
        bool how_to_screen;
        sf::Text HowToText;
        sf::Texture HowTo_texture;
        sf::Sprite HowTo_Sprite;

        //Constructors;
        void InitBackground();
        void InitFont();
        void InitButtons();
    public:
        std::map<std::string, GameData*> gameData;

        //PUBLIC CONSTRUCTORS DESTRUCTORS
        MenuState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~MenuState();
        void endState();

        void InitGameData();

        //UPDATE
        void updateKeybinds(const float& dt, sf::Event::EventType eventType);
        void update(const float& dt);
        void updateButtons();

        //RENDER
        void render(sf::RenderTarget* target = NULL);
        void renderButtons(sf::RenderTarget* target = NULL);
};

