#include<iostream>
#include<SFML/Graphics.hpp>
#include<Cursor.h>

Cursor::Cursor()
{

	if (!cursorText.loadFromFile("resources/imgs/Cursor.png"))
		std::cout << "Couldn't load image" << std::endl;

	cursorSprite.setTexture(cursorText);

	cursorSprite.setPosition(-100.0f, 400.0f);

	
}

void Cursor::display()
{

	cursorSprite.setPosition(200.0f, 400.0f);

}

void Cursor::reset()
{

	cursorSprite.setPosition(-100.0f, 400.0f);

}

void Cursor::move(float offsetX)	
{
		std::cout << offsetX << std::endl;
		cursorSprite.move(offsetX, 0.0f);

}

void Cursor::draw()
{
	static sf::Clock clk;
	
	if (clk.getElapsedTime().asMilliseconds() < 1050.0f)
	{
		
		if (clk.getElapsedTime().asMilliseconds() > 750.0f)
		{

			window->draw(cursorSprite);

		}
		
		
	}
	else
	{

		clk.restart();

	}

}

void Cursor::setWindow(sf::RenderWindow* Window)
{
	
	window = Window;

}