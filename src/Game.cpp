
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete[] animals;
	delete[] passports;
	delete character;
	delete passport;
}

bool Game::init()
{
	character = new sf::Sprite;
	passport = new sf::Sprite;

	if (!animals[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/elephant.png" << "\n";
		return false;
	}

	if (!animals[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/penguin.png" << "\n";
		return false;
	}
	
	if (!animals[2].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/moose.png" << "\n";
		return false;
	}

	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/elephant passport.png" << "\n";
		return false;
	}

	if (!passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/penguin passport.png" << "\n";
		return false;
	}

	if (!passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/moose passport.png" << "\n";
		return false;
	}
	
	newAnimal();

	return true;
}

void Game::update(float dt)
{
	dragSprite(dragged);
}

void Game::render()
{

	window.draw(*passport);
	window.draw(*character);
}

void Game::mouseButtonPressed(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		//get the click position
		sf::Vector2i click = sf::Mouse::getPosition(window);
		sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

		if (passport->getGlobalBounds().contains(clickf))
		{
			dragged = passport;
			drag_offset = dragged->getPosition() - clickf;
		}
		else if (character->getGlobalBounds().contains(clickf))
		{
			dragged = character;
			drag_offset = dragged->getPosition() - clickf;
		}

	}
}

void Game::mouseButtonReleased(sf::Event event)
{
	dragged = nullptr;
}

void Game::keyPressed(sf::Event event)
{

}

void Game::newAnimal()
{
	passport_accepted = false;
	passport_rejected = false;

	int rand_animal = rand() % 2;
	int rand_passport = rand() % 2;

	if (rand_animal == rand_passport)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}

	character->setTexture(animals[rand_animal], true);
	character->setScale(1.8, 1.8);
	character->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport->setTexture(passports[rand_passport]);
	passport->setScale(0.6, 0.6);
	passport->setPosition(window.getSize().x / 2, window.getSize().y / 3);

}

void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr)
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		sf::Vector2f drag_position = mouse_positionf + drag_offset;
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}
