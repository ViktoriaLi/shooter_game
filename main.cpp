#include "ft_retro.h"
#include "Window.hpp"
#include "FieldWindow.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>

void    init_info_window(Window *w) {
    w->PutStr("Game Info", 1, 15);
    w->PutStr("Controls: LEFT UP RIGHT DOWN arrows" , 3, 2);
    w->PutStr("to move and SPACE to shoot.", 4, 2);
    w->PutStr("Press ESC to exit", 5, 2);
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

void    init_stat_window(Window *w, Player *player) {
    w->PutStr("Game Stats", 1, 15);
    w->PutStr("Player name: ", 3, 2);
    w->PutStr(player->name, 3, 15);
    w->PutStr("Level: ", 5, 2);
    w->PutChar((player->level + '0') | A_BOLD | A_STANDOUT, 5, 15);
    w->PutStr("Lives: ", 7, 2);
    w->PutChar((player->lives + '0') | A_BOLD | A_STANDOUT, 7, 15);
    w->PutStr("Score: ", 9, 2);
    mvwprintw(w->getWindow(), 9, 15, "%d", player->score);
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

void fill_coords(Enemy &enemy)
{
  int i = 0;
  int j = 0;

  while (i < enemy.count)
  {
    j = 0;
    while (j < enemy.count)
    {
      enemy.group[i].rockets[j].rocketMoving(enemy.group[i].x, enemy.group[i].y);
      j++;
    }
    i++;
  }
}

int enemies_shooting(Player &player, Enemy &enemy, FieldWindow &gameWindow)
{
  int i = 0;
  int j = 0;
  while (i < 6)
  {
    if (enemy.group[i].x > 3)
      gameWindow.PutChar(enemy.group[i].symb | A_BOLD, enemy.group[i].y, enemy.group[i].x);
    if (enemy.group[i].rockets[0].x > 3)
      gameWindow.PutChar(enemy.group[i].rockets[0].symb | A_BOLD, enemy.group[i].rockets[0].y, enemy.group[i].rockets[0].x);
    else
    {
      j = 0;
      while (j < 6)
      {
        enemy.group[j].rockets[0].x = enemy.group[j].x;
        enemy.group[j].rockets[0].y = enemy.group[j].y;
        j++;
      }
    }
    if (player.x == enemy.group[i].rockets[j].x && player.y == enemy.group[i].rockets[j].y)
      player.lives--;
    if (player.lives == 0)
    {
      gameWindow.PutStr("GAME OVER: ", 29, 25);
      return (0);
    }
    if ((player.y == enemy.group[i].y && (player.x == enemy.group[i].x + 1 || player.x == enemy.group[i].x - 1))
    || ((player.y == enemy.group[i].y + 1 || player.y == enemy.group[i].y - 1) && player.x == enemy.group[i].x))
      player.lives--;
    if (player.lives == 0)
    {
      gameWindow.PutStr("GAME OVER: ", 29, 25);
      return (0);
    }
    enemy.group[i].rockets[j].x -= 2;
    enemy.group[i].x -= 1;
    i++;
  }
  return (1);
}

int	main(void)
{
	initscr();
    FieldWindow gameWindow = FieldWindow(32, 60);
    curs_set(0);
    start_color();
    noecho();
    Player player("nemesis");
    player.name = "nemesis";
    Enemy enemy(6, "zork");

    fill_coords(enemy);
    Window infoWindow = Window(15, 40, 17, 61);
    init_info_window(&infoWindow);
    Window statWindow = Window(16, 40, 0, 61);

    while (true) {
        init_stat_window(&statWindow, &player);
        halfdelay(2);
        gameWindow.GetChar();
        gameWindow.Clear();
        gameWindow.DrawBox('*' | A_BOLD, '*' | A_BOLD);
        gameWindow.drawField();
        gameWindow.PutChar(player.symb | A_BLINK, player.y, player.x);
        enemies_shooting(player, enemy, gameWindow);
        /*if (!enemies_shooting(player, enemy, gameWindow))
        {
          player("nemesis");
          enemy(6, "zork");
          fill_coords(player, enemy);
        }*/

        gameWindow.Refresh();
    }
    endwin();
    return 0;
}
