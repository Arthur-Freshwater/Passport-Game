
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
	character->setTexture(animals[0]);

	if (!animals[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/penguin.png" << "\n";
		return false;
	}
	character->setTexture(animals[1]);
	
	if (!animals[2].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/moose.png" << "\n";
		return false;
	}
	character->setTexture(animals[2]);

	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/elephant passport.png" << "\n";
		return false;
	}
	passport->setTexture(animals[0]);

	if (!passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/penguin passport.png" << "\n";
		return false;
	}
	passport->setTexture(animals[1]);

	if (!passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "Error loading file: " << "Data/Images/Critter Crossing Customs/moose passport.png" << "\n";
		return false;
	}
	passport->setTexture(animals[2]);
	
	return true;
}

void Game::update(float dt)
{

}

void Game::render()
{

}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


