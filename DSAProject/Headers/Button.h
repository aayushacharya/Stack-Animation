
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Button{

    private:
        sf::Font font;
        sf::Text text;
        sf::Texture buttonText;
        sf::Sprite buttonSprite;
        bool isClicked;
        
    public:
        Button();
        void drawButton(sf::RenderWindow&);
        void setButtonPosition(float,float);
        void press();
        void unpress();
		void setButtonLabel(std::string);
		bool cursorHover(float, float);
        bool isPressed();

};