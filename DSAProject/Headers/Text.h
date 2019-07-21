#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Text
{
private:
    sf::Font font;
    sf::Text text;
    
public:
    Text();
	void draw(sf::RenderWindow&);
    std::string getData();
	void setData(std::string);

};