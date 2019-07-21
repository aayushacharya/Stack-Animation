#include<iostream>
#include<SFML/Graphics.hpp>
#include<Text.h>

Text::Text()
{
	
	if (!font.loadFromFile("resources/fonts/cambria.ttf"))
		std::cout << "Couldn't load font" << std::endl;

	text.setFont(font);
	
	text.setPosition(200.0f, 400.0f);

	text.setFillColor(sf::Color(17, 30, 108));

	text.setCharacterSize(30);

}

void Text::draw(sf::RenderWindow& window)
{

	window.draw(text);

}

std::string Text::getData()
{
	
	return text.getString();

}

void Text::setData(std::string data)
{

	text.setString(data);

}