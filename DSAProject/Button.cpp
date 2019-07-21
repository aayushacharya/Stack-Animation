#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Button.h>

Button::Button()
{

	this->isClicked = false;

	if (!buttonText.loadFromFile("resources/imgs/Button.png"))
		std::cout << "Couldn't load button" << std::endl;

	if (!font.loadFromFile("resources/fonts/cambria.ttf"))
		std::cout << "Couldn't load font" << std::endl;

	buttonSprite.setTexture(buttonText);

	buttonSprite.setOrigin(buttonText.getSize().x / 2, buttonText.getSize().y / 2);
	buttonSprite.setPosition(250.0f, 350.0f);

	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(-100.0f, -100.0f);

}

bool Button::cursorHover(float xPos, float yPos)
{
	if (buttonSprite.getPosition().x - buttonText.getSize().x / 2 < xPos && buttonSprite.getPosition().x + buttonText.getSize().x / 2 > xPos)
	{

		if (buttonSprite.getPosition().y - buttonText.getSize().y / 2 < yPos && buttonSprite.getPosition().y + buttonText.getSize().y / 2 > yPos)
		{

			buttonSprite.setScale(1.2f, 1.2f);
			text.setScale(1.2f, 1.2f);
			return true;
			
		}

	}

	buttonSprite.setScale(1.0f, 1.0f);
	text.setScale(1.0f, 1.0f);
	return false;


}

bool Button::isPressed()
{
	
	return this->isClicked;

}

void Button::press()
{

	buttonSprite.setScale(1.0f, 1.0f);
	this->isClicked = true;
	

}

void Button::unpress()
{

	this->isClicked = false;

}

void Button::setButtonPosition(float xPos,float yPos)
{

	buttonSprite.setPosition(xPos, yPos);

}

void Button::drawButton(sf::RenderWindow& window)
{

	window.draw(buttonSprite);
	window.draw(text);

}

void Button::setButtonLabel(std::string label)
{

	text.setPosition(buttonSprite.getPosition().x - 35.0f, buttonSprite.getPosition().y - 25.0f);
	text.setString(label);

}