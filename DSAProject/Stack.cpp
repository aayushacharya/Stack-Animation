#include<iostream>
#include<ctime>
#include<cstdlib>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<string>
#include<Header.h>
#define MAX 8
Stack::Stack()
{
	top = -1;

	if (!font.loadFromFile("resources/fonts/cambria.ttf"))
		std::cout << "Couldn't load font" << std::endl;

	if (!StackText.loadFromFile("resources/imgs/Stack.png") || !BlockText.loadFromFile("resources/imgs/Block188.png"))
		std::cout << "Couldn't load image:" << std::endl;
	
	if (!BgText.loadFromFile("resources/imgs/Background.png") || !BlockAnimText[0].loadFromFile("resources/imgs/BlockNoChuteFire188.png"))
		std::cout << "Couldn't load from file: " << std::endl;

	if(!BlockAnimText[1].loadFromFile("resources/imgs/BlockChuteFire188.png") || !BlockAnimText[2].loadFromFile("resources/imgs/BlockChuteNoFire188.png"))
		std::cout << "Couldn't load from file: " << std::endl;

	
	


	
	
	StackSprite.setTexture(StackText);
	BgSprite.setTexture(BgText);


	sf::Vector2u Stack=StackText.getSize();

	StackSprite.setOrigin(Stack.x, Stack.y);
	for (int i = 0;i < MAX;i++)
	{

		text[i].setFont(font);
		text[i].setFillColor(sf::Color::Black);
		text[i].setPosition(-300.0f, -300.0f);
		text[i].setCharacterSize(18);

		BlockSprite[i].setTexture(BlockText);
		BlockSprite[i].setOrigin(94.0f, 17.0f);
		BlockSprite[i].setPosition(-300.0f, -300.0f);

	}

}
void Stack::drawSprite(sf::RenderWindow &window)
{

	
	window.draw(BgSprite);
	window.draw(StackSprite);
	for (int i = 0;i < MAX;i++) 
	{

		window.draw(BlockSprite[i]);
		window.draw(text[i]);

	}

	

}
void Stack::setBlockPosition(float xPos, float yPos)
{
	
	this->BlockSprite[this->top].setPosition(xPos, yPos);
	
}
void Stack::moveBlock(float xOffset, float yOffset)
{

	this->BlockSprite[this->top].move(xOffset, yOffset);

}
sf::Vector2f Stack::getBlockPosition()
{

	return this->BlockSprite[this->top].getPosition();

}
sf::Vector2f Stack::getStackPosition()
{

	return StackSprite.getPosition();

}
void Stack::setAnimatedTexture()
{

	this->BlockSprite[this->top].setTexture(BlockAnimText[0]);

}
void Stack::setAnimatedTexture(int index)
{

	if (top > -1 && top < MAX)
	{

		srand(time(0));
		int Random = (rand() % 2 + 1);
		BlockSprite[index].setTexture(BlockAnimText[Random],true);
		BlockSprite[index].setOrigin(94.0f, 128.0f);
			

	}

}
void Stack::setNormalTexture()
{
	
	if (top > -1 && top < MAX)
	{

		this->BlockSprite[this->top].setTexture(BlockText,true);
		BlockSprite[this->top].setOrigin(BlockText.getSize().x/2,BlockText.getSize().y/2);

	}

}

void Stack::push(std::string elem,sf::RenderWindow& window)
{
	
	sf::Music land,hovering;
	if (!land.openFromFile("resources/audio/Land.wav") || !hovering.openFromFile("resources/audio/Hovering.wav"))
		std::cout << "Couldn't open music" << std::endl;
	
	if (top == MAX - 1)
		std::cout << "Cannot Insert more:" <<std::endl;
	else 
	{
		
		data[++top] = elem;
		std::cout << elem << " is inserted: " << std::endl;
		bool condition;
		static int initSound = 0;
		float offsetX = this->getStackPosition().x - 702.0f-151.0f;
		this->setBlockPosition(702.0f + offsetX, 100.0f);	//set xPos according to stackPos
		this->text[top].setString(elem);
		text[top].setPosition(BlockSprite[top].getPosition().x-25.0f, BlockSprite[top].getPosition().y-13.0f);
		if (elem.length() > 5)
			text[top].setScale(0.7f-(elem.length()-5)/10, 1.0f);
		
		else
			text[top].setScale(1.0f, 1.0f);
		sf::Clock clock;
		clock.restart();
		hovering.play();

		do
		{

			float milliSec = 0.0f;
			if (clock.getElapsedTime().asMilliseconds() > milliSec) {
				if ((BlockSprite[top - 1].getPosition().y - this->getBlockPosition().y) > 150.0f)
				{
					this->setAnimatedTexture(top);
					milliSec += 50;
					hovering.setLoop(true);
				}
				else {
					this->setNormalTexture();
					hovering.stop();
					if (initSound == 0) {
						land.play();
						initSound=1;
					}
				}
				
			}
			this->moveBlock(0.0f, 3.0f);
			
			this->text[top].move(0.0f,3.0f);
			window.clear();
			this->drawSprite(window);
			window.display();
			if (top == 0)
				condition = this->getBlockPosition().y < (this->getStackPosition().y - 72.0f);
			else
				condition = this->getBlockPosition().y < (this->getStackPosition().y - 72.0f - (top * BlockText.getSize().y));
		} while (condition);

		initSound = 0;
		clock.restart();
		while(clock.getElapsedTime().asMilliseconds()<750.0f){}
		

	}


}
void Stack::pop(sf::RenderWindow& window)
{

	sf::Music launch;
	if (!launch.openFromFile("resources/audio/Launch.wav"))
		std::cout << "Music cannot opened: " << std::endl;
	if (top == -1)
		std::cout << "Stack Empty: " << std::endl;
	else
	{
		
		std::cout << data[top] << " is popped: " << std::endl;
		do
		{
			
			if (top != 0)
			{
				if ((BlockSprite[top - 1].getPosition().y - this->getBlockPosition().y) > 100.0f)
				{
					this->BlockSprite[top].setTexture(BlockAnimText[0], true);
					this->BlockSprite[top].setOrigin(94.0f,17.0f);
				}
				else {
					this->setNormalTexture();
					launch.play();
				}
			}
			else
			{
				static float originalYPos = this->getBlockPosition().y;
				if ((originalYPos - this->getBlockPosition().y) > 100.0f)
				{
					this->BlockSprite[top].setTexture(BlockAnimText[0], true);
					this->BlockSprite[top].setOrigin(94.0f,17.0f);
				}
				else {
					this->setNormalTexture();
					launch.play();
				}

			}

			
			this->moveBlock(0.0f, -5.0f);
			this->text[top].move(0.0f, -5.0f);
			window.clear();
			this->drawSprite(window);
			window.display();
			
			
			
		} while (this->getBlockPosition().y>-300);

		launch.stop();
		--top;

	}

}
void Stack::introAnimation(sf::RenderWindow& window)
{
	
	float xPos = 0.0f, yPos = 637.0f;
	float initialVelocityX = 1660.0f/ (60.0f*2.0f*0.5f);
	float finalVelocityX = initialVelocityX;
	float accelerationX = -1.0f/0.5f;
	StackSprite.setPosition(xPos, yPos);
	StackSprite.setRotation(30.0f);
	sf::Music swoosh;
	if (!swoosh.openFromFile("resources/audio/Swooshing.ogg"))
		std::cout << "Couldn't load sound" << std::endl;
	sf::Clock clk;
	clk.restart();
	swoosh.play();
	while (clk.getElapsedTime().asSeconds()<0.5f)
	{
		finalVelocityX = initialVelocityX + 0.5f*accelerationX;
		StackSprite.move(finalVelocityX, 0);
		window.clear();
		this->drawSprite(window);
		window.display();
	}
	StackSprite.setRotation(0.0f);

}