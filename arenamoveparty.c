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

void arena_move_party(int x,int y) {
  int xdir,ydir;
  int ox,oy;
  int monster;
  int targetx;
  int targety;
  int dist;
  int spd;

  char valid(int x,int y) {
    char flag;
    flag = '*';
    if (player.map[x][y] < 0) flag = ' ';
    if (player.map[x][y] == 21) flag = ' ';
    if (player.map[x][y] == 22) flag = ' ';
    if (player.map[x][y]>300 && player.map[x][y]<500) flag = ' ';
    if (x == player.x && y == player.y) flag = ' ';
    if (x<10 || x>25 || y<10 || y>25) flag = ' ';
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
    return flag;
    }

  void find_target() {
    int x1,y1;
    dist = 32767;
    targetx = player.x;
    targety = player.y;
    for (x1=10; x1<=26; x1++)
      for (y1=10; y1<=26; y1++)
        if (player.map[x1][y1]>400 && player.map[x1][y1]<500 &&
            (sqr(x1-x)+sqr(y1-y)) < dist) {
          targetx = x1;
          targety = y1;
          dist = (sqr(x1-x)+sqr(y1-y));
          }
    }

  monster = player.map[x][y];
  for (spd=1; spd<=player.party[monster-300].speed; spd++) {
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
      if (player.party[monster-300].special>19 && dist<32767) {
        xdir = -xdir;
        ydir = -ydir;
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
      player.map[ox][oy] = player.party[monster-300].prev;
      player.party[monster-300].prev = player.map[x][y];
      player.map[x][y] = monster;
      if (in_sight(ox,oy) == '*') show_spot(ox,oy);
      if (ox == player.x && oy == player.y) show_player();
      if (in_sight(x,y) == '*') show_spot(x,y);
      }
  player.party[monster-300].special += 100;
  }
