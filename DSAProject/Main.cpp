#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Header.h>
#define MAX 8
using namespace std;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1366, 768), "Stack Animation: ", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
		
	sf::Event event;

	Stack stack;
	stack.setWindow(&window);

	Button push, pop;
	push.setWindow(&window);
	pop.setWindow(&window);
	
	pop.setButtonPosition(1100.0f, 350.0f);
	push.setButtonLabel("PUSH");
	pop.setButtonLabel("POP");

	Text textField;
	textField.setWindow(&window);

	Cursor cursor;
	cursor.setWindow(&window);

	sf::Music buttonClick;
	if (!buttonClick.openFromFile("resources/audio/ButtonClick.wav"))
		std::cout << "Couldn't open sound" << std::endl;
	

	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
			{

				if (event.key.code == 27)
					window.close();

			}
		}


		stack.introAnimation();
			

		
		
		
	if (push.cursorHover(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
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


			if (event.type == sf::Event::MouseButtonPressed)
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
					stack.push(textField.getData());
					textField.setData("");
					textField.getWidth();
				
				}
				else if (event.key.code == 8)	//ASCII code for BACKSPACE key 
				{
					if (textField.getData().length() != 0)
					{

						std::string data=textField.getData();
						data.erase(data.end() - 1);
						textField.setData(data);
						cursor.move(textField.getWidth());
						sf::Clock keyBuffer;
						while (keyBuffer.getElapsedTime().asMilliseconds() < 200.0f) {}

					}
				}
				else
				{
					if (textField.getData().length() < 10)
					{

						textField.setData(textField.getData() + static_cast<char>(event.text.unicode));
						cursor.move(textField.getWidth());
						sf::Clock keyBuffer;
						while (keyBuffer.getElapsedTime().asMilliseconds() < 200.0f) {}

					}
					

				}

			}


		}
		
		if (pop.isPressed())
		{
			pop.unpress();
			sf::Clock buttonClickBuffer;
			while (buttonClickBuffer.getElapsedTime().asMilliseconds() < 200.0f) {}
			stack.pop();

		}

		window.clear();

		stack.drawSprite();
		push.drawButton();
		pop.drawButton();
		cursor.draw();
		textField.draw();

		window.display();
		
	}

	return 0;
}