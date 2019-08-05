#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define MAX 8
class Sprite {
private:
	sf::Font font;
	sf::Text text[MAX];
	sf::Texture StackText, BlockText, BgText, BlockAnimText[3];
	sf::Sprite StackSprite, BlockSprite[MAX], BgSprite;
public:
	Sprite();
	void displayPushAnimation();
	void displayPopAnimation();
};