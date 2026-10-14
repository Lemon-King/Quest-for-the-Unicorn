/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void move_enemy(int x,int y) {
  int xdir,ydir;
  int ox,oy;
  int monster;
  int spd;
  int i;
  char fflag;

  char valid(int x,int y) {
    char flag;
    flag = '*';
    if (x<1 || y<1 || x>99 || y>99) flag = ' ';
    if (flag == '*') {
      if (player.map[x][y] < 0) flag = ' ';
      if (player.map[x][y] == 21) flag = ' ';
      if (player.map[x][y] == 22 && u_random(100) < 75)
        player.map[x][y] = 23;
      else if (player.map[x][y] == 22) flag = ' ';
      if (player.map[x][y] == 33 && u_random(100) < 10)
        player.map[x][y] = 23;
      else if (player.map[x][y] == 33) flag = ' ';
      if (x == player.x && y == player.y) flag = ' ';
      if (x<2 || y<2 || x>98 || y>98) flag = ' ';
      if (player.map[x][y] == 4) flag = ' ';
      if (player.map[x][y] == 41) flag = ' ';
      if (player.map[x][y] == 38) flag = ' ';
      if (player.map[x][y] == 39) flag = ' ';
      if (player.map[x][y] == 3) flag = ' ';
      }
    return flag;
    }

  monster = player.map[x][y];
  fflag = ' ';
  for (spd=1; spd<=player.monster[1][0-monster].speed; spd++)
    if (fflag != '*') {
      xdir = 0;
      ydir = 0;
      ox = x;
      oy = y;
      if (x < player.x && y < player.y) { xdir = 1; ydir = 1; }
      if (x > player.x && y < player.y) { xdir = -1; ydir = 1; }
      if (x < player.x && y > player.y) { xdir = 1; ydir = -1; }
      if (x > player.x && y > player.y) { xdir = -1; ydir = -1; }
      if (x == player.x && y < player.y) ydir = 1;
      if (x == player.x && y > player.y) ydir = -1;
      if (x < player.x && y == player.y) xdir = 1;
      if (x > player.x && y == player.y) xdir = -1;
      if (player.monster[1][0-monster].special > 9 ||
          player.monster[1][0-monster].confused > 0)
        switch (u_random(9)) {
          case 0:xdir = 1; break;
          case 1:xdir = -1; break;
          case 2:ydir = 1; break;
          case 3:ydir = -1; break;
          case 4:xdir = 1; ydir = 1; break;
          case 5:xdir = 1; ydir = -1; break;
          case 6:xdir = -1; ydir = 1; break;
          case 7:xdir = -1; ydir = -1; break;
          case 8:xdir = 0; ydir = 0; break;
          }
      if (abs(x-player.x) > 1 || abs(y-player.y)>1) {
        if (valid(x+xdir,y+ydir) == '*') { x+=xdir; y+=ydir; }
        else if (valid(x+xdir,y) == '*') x+=xdir;
        else if (valid(x,y+ydir) == '*') y+=ydir;
        else if (xdir == 0 && valid(x+1,y+ydir) == '*') { x++; y+=ydir; }
        else if (xdir == 0 && valid(x-1,y+ydir) == '*') { x--; y+=ydir; }
        else if (ydir == 0 && valid(x+xdir,y-1) == '*') { x+=xdir; y--; }
        else if (ydir == 0 && valid(x+xdir,y+1) == '*') { x+=xdir; y++; }
        }
      player.map[ox][oy] = player.monster[1][0-monster].prev;
      player.monster[1][0-monster].prev = player.map[x][y];
      player.map[x][y] = monster;
      if (in_sight(ox,oy) == '*') show_spot(ox,oy);
      if (ox == player.x && oy == player.y) show_player();
      if (in_sight(x,y) == '*') show_spot(x,y);
      if (player.monster[1][0-monster].prev>599 &&
          player.monster[1][0-monster].prev<700) {
        noise(1000,100);
        i = (player.monster[1][0-monster].prev - 600) * 4;
        player.monster[1][0-monster].hp -= i;
        if (player.monster[1][0-monster].hp <= 0) {
          fflag = '*';
          player.monster[1][0-monster].hp = 0;
          player.exp += player.monster[1][0-monster].exp;
          if (u_random(20) < (player.monster[1][0-monster].level - player.level))
            player.map[x][y] = 7;
          else
            player.map[x][y] = player.monster[1][0-monster].prev;
          show_side();
          }
        if (in_sight(x,y) == '*') show_spot(x,y);
        }
      }
  player.monster[1][0-monster].special += 100;
  }
