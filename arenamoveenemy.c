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

void arena_move_enemy(int x,int y) {
  int xdir,ydir;
  int ox,oy;
  int monster;
  int targetx;
  int targety;
  int dist;
  int spd;

  char valid(int x,int y) {
    char flag;
#ifdef DEBUG
  printf("%*sEntering: valid(%d,%d)\n",debug_tab,"",x,y);
  debug_tab += 2;
#endif
    flag = '*';
    if (player.map[x][y] < 0) flag = ' ';
    if (player.map[x][y] == 21) flag = ' ';
    if (player.map[x][y] == 22) flag = ' ';
    if (player.map[x][y]>300 && player.map[x][y]<500) flag = ' ';
    if (x == player.x && y == player.y) flag = ' ';
    if (player.map[x][y] < 255) {
      if (player.map[x][y] == 143) flag = ' ';
      if (player.map[x][y] == 20) flag = ' ';
      if (player.map[x][y] == 18) flag = ' ';
      if (player.map[x][y] == 16) flag = ' ';
      if (player.map[x][y] == 4) flag = ' ';
      if (player.map[x][y] == 176) flag = ' ';
      if (player.map[x][y] == 3) flag = ' ';
      if (player.map[x][y] == 178) flag = ' ';
      }
#ifdef DEBUG
  printf("%*sExiting: valid()\n",debug_tab,"");
  debug_tab -= 2;
#endif
    return flag;
    }

  void find_target() {
    int x1,y1;
#ifdef DEBUG
  printf("%*sEntering: find_target()\n",debug_tab,"");
  debug_tab += 2;
#endif
    dist = (sqr(player.x-x) + sqr(player.y-y));
    targetx = player.x;
    targety = player.y;
    for (x1=10; x1<=26; x1++)
      for (y1=10; y1<=26; y1++)
        if (player.map[x1][y1]>300 && player.map[x1][y1]<400 &&
            (sqr(x1-x)+sqr(y1-y)) < dist) {
          targetx = x1;
          targety = y1;
          dist = (sqr(x1-x)+sqr(y1-y));
          }
#ifdef DEBUG
  printf("%*sExiting: find_target()\n",debug_tab,"");
  debug_tab -= 2;
#endif
    }

#ifdef DEBUG
  printf("%*sEntering: arena_move_enemy(%d,%d)\n",debug_tab,"",x,y);
  debug_tab += 2;
#endif
  monster = player.map[x][y];
  for (spd=1; spd<=player.monster[monster-400][a_mon].speed; spd++) {
      find_target();
      xdir = 0;
      ydir = 0;
      ox = x;
      oy = y;
      if (x < targetx && y < targety) { xdir = 1; ydir = 1; }
      if (x > targetx && y < targety) { xdir = -1; ydir = 1; }
      if (x < targetx && y > targety) { xdir = 1; ydir = -1; }
      if (x > targetx && y > targety) { xdir = -1; ydir = -1; }
      if (x == targetx && y < targety) ydir = 1;
      if (x == targetx && y > targety) ydir = -1;
      if (x < targetx && y == targety) xdir = 1;
      if (x > targetx && y == targety) xdir = -1;
      if (player.monster[monster-400][a_mon].special > 9 ||
          player.monster[monster-400][a_mon].confused > 0)
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
      if (abs(x-targetx) > 1 || abs(y-targety)>1) {
        if (valid(x+xdir,y+ydir) == '*') { x+=xdir; y+=ydir; }
        else if (valid(x+xdir,y) == '*') x+=xdir;
        else if (valid(x,y+ydir) == '*') y+=ydir;
        else if (xdir == 0 && valid(x+1,y+ydir) == '*') { x++; y+=ydir; }
        else if (xdir == 0 && valid(x-1,y+ydir) == '*') { x--; y+=ydir; }
        else if (ydir == 0 && valid(x+xdir,y-1) == '*') { x+=xdir; y--; }
        else if (ydir == 0 && valid(x+xdir,y+1) == '*') { x+=xdir; y++; }
        }
      player.map[ox][oy] = player.monster[monster-400][a_mon].prev;
      player.monster[monster-400][a_mon].prev = player.map[x][y];
      player.map[x][y] = monster;
      if (in_sight(ox,oy) == '*') show_spot(ox,oy);
      if (ox == player.x && oy == player.y) show_player();
      if (in_sight(x,y) == '*') show_spot(x,y);
      }
  player.monster[monster-400][a_mon].special += 100;
#ifdef DEBUG
  printf("%*sExiting: arena_move_enemy()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }
