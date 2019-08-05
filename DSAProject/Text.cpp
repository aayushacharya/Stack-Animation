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

void Text::draw()
{

	window->draw(text);

}

std::string Text::getData()
{
	
	return text.getString();

}

void Text::setData(std::string data)
{

	text.setString(data);

}

void Text::setWindow(sf::RenderWindow* Window)
{

	window = Window;

}

float Text::getWidth()
{
	static float prevLength = 0.0f;
	if (text.getCharacterSize() == 0.0f) {
		prevLength = 0.0f;
		
		return prevLength;
	}
	float temp = prevLength;
	
	prevLength = text.getGlobalBounds().width;
	
	return text.getGlobalBounds().width - temp;
	
}