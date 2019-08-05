#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Cursor{

    private:
        sf::Texture cursorText;
        sf::Sprite cursorSprite;
		sf::RenderWindow* window;
    public:
        Cursor();
        void draw();
        void move(float offsetX);
        void reset();
		void display();
		void setWindow(sf::RenderWindow*);
};