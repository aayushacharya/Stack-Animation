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
	sf::Text warning, text[MAX];
	sf::Texture StackText, BlockText, BgText, BlockAnimText[3];
	sf::Sprite StackSprite, BlockSprite[MAX], BgSprite;
	sf::RenderWindow *window;
public:
	Stack();
	void drawSprite();
	void setBlockPosition(float, float);
	void moveBlock(float, float);
	void push(std::string);
	void pop();
	void introAnimation();
	void setAnimatedTexture();
	void setAnimatedTexture(int);	//Overloaded
	void setNormalTexture();
	void setWindow(sf::RenderWindow*);
	sf::Vector2f getBlockPosition();
	sf::Vector2f getStackPosition();
};
