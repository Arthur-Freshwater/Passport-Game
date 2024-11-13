
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;

  sf::Sprite* character;
  sf::Sprite* passport;
  sf::Sprite* dragged = nullptr;

  sf::Vector2f drag_offset;

  sf::Texture* animals = new sf::Texture[3];
  sf::Texture* passports = new sf::Texture[3];

  bool passport_accepted;
  bool passport_rejected;
  bool should_accept;

  int dragged_item;



};

#endif // PLATFORMER_GAME_H
