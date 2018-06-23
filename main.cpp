#include <iostream>
#include "GameEntity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main(void)
{
  int maxLevel = 0;
  int maxScore = 0;

  Player User("user");
  Enemy Enemi("enemy");
  Enemy Enemies(3, "enemy");

  std::cout << "Your max level is " << maxLevel << std::endl;
  std::cout << "Your max score is " << maxScore << std::endl;
  /*
  int i = 0;
  std::cout << User.score << ' ' << User.scoreOnLevel << ' ' << User.maxScoreOnLevel
  << ' ' << User.level << ' ' << User.lives << ' ' << User.symb << ' '  << User.type
  << ' ' << User.name << ' ' << User.current_bullet << ' ' << User.bullets << ' '
  << User.x << ' ' << User.y << ' ' << std::endl;
  while (i < 100)
  {
    User.makeShooting();
    std::cout << User.score << ' ' << User.scoreOnLevel << ' ' << User.maxScoreOnLevel
    << ' ' << User.level << ' ' << User.lives << ' ' << User.symb << ' '  << User.type
    << ' ' << User.name << ' ' << User.current_bullet << ' ' << User.bullets << ' '
    << User.x << ' ' << User.y << ' ' << User.rockets->x << User.rockets->y << std::endl;

    i++;
  }
  if (User.level > maxLevel)
    maxLevel = User.level;
  if (User.score > maxScore)
    maxScore = User.score;
  i = 0;

  std::cout << Enemi.lives << ' ' << Enemi.symb << ' '  << Enemi.type
  << ' ' << Enemi.current_bullet << ' ' << Enemi.bullets << ' '
  << Enemi.x << ' ' << Enemi.y << ' ' << Enemi.rockets->x << ' ' << Enemi.rockets->y<< std::endl;
  while (i < 101)
  {
    Enemi.makeShooting();
    std::cout << Enemi.lives << ' ' << Enemi.symb << ' '  << Enemi.type
    << ' ' << Enemi.current_bullet << ' ' << Enemi.bullets << ' '
    << Enemi.x << ' ' << Enemi.y << ' ' << Enemi.rockets->x << ' ' << Enemi.rockets->y << ' ' << std::endl;
    i++;
  }
  i = 0;

  while (i < 3)
  {
    std::cout << Enemies.group[i].lives << ' ' << Enemies.group[i].symb << ' '  << Enemies.group[i].type
    << ' ' << Enemies.group[i].current_bullet << ' ' << Enemies.group[i].bullets << ' '
    << Enemies.group[i].x << ' ' << Enemies.group[i].y << ' ' << Enemies.group[i].rockets->x << ' '
    << Enemies.group[i].rockets->y << std::endl;
    i++;
  }
  int j = 0;
  while (j < 3)
  {
    i = 0;
    while (i < 20)
    {
      std::cout << Enemies.group[j].lives << ' ' << Enemies.group[j].symb << ' '  << Enemies.group[j].type
      << ' ' << Enemies.group[j].current_bullet << ' ' << Enemies.group[j].bullets << ' '
      << Enemies.group[j].x << ' ' << Enemies.group[j].y << ' ' << Enemies.group[j].rockets->x
      << ' ' << Enemies.group[j].rockets->y << std::endl;
      i++;
    }
    j++;
  }
  */
  return 0;
}
