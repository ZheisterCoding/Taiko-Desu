#pragma once
#include "State.h"

class GameEndState :
    public State
{
    private:
        //
        /*sf::RectangleShape Box;*/
        sf::Clock quitTimer;

        sf::RectangleShape BlackScreen;
        int screen_a;

        //Texture/Sprites
        sf::Texture screen_texture;
        sf::Sprite screen_sprite;
        
        //game logic
        PointData game_result;
        long int temp_points;
        int temp_combo, temp_good, temp_ok, temp_bad;
        enum layer_display { POINTS, COMMENT, COMBO, FADE, FINISH} current_dp;

        //Text
        sf::Font taikoFont;
        sf::Text PointText;
        sf::Text ComboText;
        sf::Text GoodText;
        sf::Text BadText;
        sf::Text OkText;

        void InitVariables();
        void InitFrame();
        void InitText();

    public:
        //Constructors
        GameEndState(sf::RenderWindow* window, std::stack<State*>* states, PointData  data);
        ~GameEndState();
        void endState();

        //Update
        void updateFadeOut();
        void updateKeybinds(const float& dt, sf::Event::EventType eventType);
        void update(const float& dt);
        void updateCommentPoints();
        void updateCombo();
        void updatePoints();
        void updateText();
        
        //Render
        void render(sf::RenderTarget* target = nullptr);
        void renderText(sf::RenderTarget* target);
};

