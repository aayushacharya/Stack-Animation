#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Text
{
private:
    sf::Font font;
    sf::Text text;
	sf::RenderWindow* window;
public:
    Text();
	void draw();
    std::string getData();
	void setData(std::string);
	void setWindow(sf::RenderWindow*);
	float getWidth();

};