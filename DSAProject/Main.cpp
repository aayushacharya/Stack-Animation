#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Header.h>
#define MAX 8
using namespace std;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1366, 768), "Stack Animation: ");
	window.setFramerateLimit(60);

	Stack stack;

	Button push, pop;
	pop.setButtonPosition(1150.0f, 350.0f);
	push.setButtonLabel("PUSH");
	pop.setButtonLabel("POP");

	Text textField;

	Cursor cursor;

	sf::Music buttonClick;
	if (!buttonClick.openFromFile("resources/audio/ButtonClick.wav"))
		std::cout << "Couldn't open sound" << std::endl;
	

	

	bool intro = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (intro)
		{

			stack.introAnimation(window);
			intro = false;

		}

	if (push.cursorHover(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{



			if (event.mouseButton.button==sf::Mouse::Left)
			{

				push.press();
				cursor.display();
				buttonClick.stop();
				buttonClick.play();

			}



		}

	}

		
			
			
		

		if (pop.cursorHover(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
		{


			if (event.type = sf::Event::MouseButtonPressed)
			{

				if (event.mouseButton.button == sf::Mouse::Left)
				{

					pop.press();
					buttonClick.stop();
					buttonClick.play();

				}

			}

		}

		if (push.isPressed())
		{
			
			if (event.type == sf::Event::TextEntered)
			{
				
				if (event.key.code == 13)		//ASCII code of carriage return, i.e. ENTER key 
				{

					push.unpress();
					cursor.reset();
					stack.push(textField.getData(), window);
					textField.setData("");
				
				}
				else if (event.key.code == 8)	//ASCII code for BACKSPACE key 
				{
					if (textField.getData().length() != 0)
					{

						std::string data=textField.getData();
						data.erase(data.end() - 1);
						textField.setData(data);
						cursor.move(false);
						sf::Clock keyBuffer;
						while (keyBuffer.getElapsedTime().asMilliseconds() < 200.0f) {}

					}
				}
				else
				{
					if (textField.getData().length() < 10)
					{

						textField.setData(textField.getData() + static_cast<char>(event.text.unicode));
						cursor.move();
						sf::Clock keyBuffer;
						while (keyBuffer.getElapsedTime().asMilliseconds() < 200.0f) {}

					}
					

				}

			}


		}
		
		if (pop.isPressed())
		{
			sf::Clock clk;
			while (clk.getElapsedTime().asMilliseconds() < 300.0f) {}
			stack.pop(window);
			pop.unpress();

		}

		window.clear();

		stack.drawSprite(window);
		push.drawButton(window);
		pop.drawButton(window);
		cursor.draw(window);
		textField.draw(window);

		window.display();
		
	}

	return 0;
}