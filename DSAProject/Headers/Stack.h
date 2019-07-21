#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<SFML/Graphics.hpp>
#define MAX 8
class Stack
{
private:
	int top;
	std::string data[MAX];
	sf::Font font;
	sf::Text text[MAX];
	sf::Texture StackText, BlockText, BgText, BlockAnimText[3];
	sf::Sprite StackSprite, BlockSprite[MAX], BgSprite;
public:
	Stack();
	void drawSprite(sf::RenderWindow&);
	void setBlockPosition(float, float);
	void moveBlock(float, float);
	void push(std::string,sf::RenderWindow&);
	void pop(sf::RenderWindow&);
	void introAnimation(sf::RenderWindow&);
	void setAnimatedTexture();
	void setAnimatedTexture(int);	//For Overloading
	void setNormalTexture();
	sf::Vector2f getBlockPosition();
	sf::Vector2f getStackPosition();
	sf::Vector2f getBlockSize();
};
