
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Button{

    private:
        sf::Font font;
        sf::Text text;
        sf::Texture buttonText;
        sf::Sprite buttonSprite;
		sf::RenderWindow* window;
        bool isClicked;
        
    public:
        Button();
        void drawButton();
        void setButtonPosition(float,float);
        void press();
        void unpress();
		void setButtonLabel(std::string);
		bool cursorHover(float, float);
        bool isPressed();
		void setWindow(sf::RenderWindow*);

};