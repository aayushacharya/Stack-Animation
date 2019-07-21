#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Cursor{

    private:
        sf::Texture cursorText;
        sf::Sprite cursorSprite;
    public:
        Cursor();
        void draw(sf::RenderWindow&);
        void move(bool forward = true);
        void reset();
		void display();
};