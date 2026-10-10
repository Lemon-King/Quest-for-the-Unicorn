/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void move_snake(int x,int y,int floor) {
  int xdir,ydir;
  int ox,oy;
  int targetx;
  int targety;
  int dist;
  int i;
  int target;

  char valid(int x,int y) {
    char flag;
    flag = '*';
    if (player.map[x][y] != floor) flag = ' ';
    if (x == player.x && y == player.y) flag = ' ';
    if (player.map[x][y]>399 && player.map[x][y]<500) flag = '*';
    return flag;
    }

  void find_target() {
    int x1,y1;
    dist = 32767;
    targetx = player.x;
    targety = player.y;
    for (x1=offset_x; x1<=offset_x+16; x1++)
      for (y1=offset_y; y1<=offset_y+16; y1++)
        if (player.map[x1][y1]>399 && player.map[x1][y1]<500 &&
            (sqr(x1-x)+sqr(y1-y)) < dist) {
          targetx = x1;
          targety = y1;
          dist = (sqr(x1-x)+sqr(y1-y));
          }
    }

  find_target();
  xdir = 0;
  ydir = 0;
  ox = x; oy = y;
  if (x < targetx && y < targety) { xdir = 1; ydir = 1; }
  if (x > targetx && y < targety) { xdir = -1; ydir = 1; }
  if (x < targetx && y > targety) { xdir = 1; ydir = -1; }
  if (x > targetx && y > targety) { xdir = -1; ydir = -1; }
  if (x == targetx && y < targety) ydir = 1;
  if (x == targetx && y > targety) ydir = -1;
  if (x < targetx && y == targety) xdir = 1;
  if (x > targetx && y == targety) xdir = -1;
  if (dist == 32767) { xdir = 0; ydir = 0; }
  if (valid(x+xdir,y+ydir) == '*') { x+=xdir; y+=ydir; }
  else if (valid(x+xdir,y) == '*') x+=xdir;
  else if (valid(x,y+ydir) == '*') y += ydir;
  player.map[ox][oy] = floor;
  if (in_sight(ox,oy) == '*') show_spot(ox,oy);
  if (player.map[x][y] == floor) {
    player.map[x][y] = 143;
    if (in_sight(x,y) == '*') show_spot(x,y);
    player.map[x][y] = 144;
    }
  if (player.map[x][y]>399 && player.map[x][y]<500) {
    snakes--;
    target = player.map[x][y] - 400;
    i = get_skill(SK_MAGIC);
    noise(1000,100);
    prompt("HIT !!!");
    if (in_sight(x,y) == '*') {
      show_sprite(x-player.map_x,y-player.map_y,100);
      delay(delay_hit);
      show_spot(x,y);
      }
    player.monster[target][a_mon].hp -= i;
    dead_monster(&(player.monster[target][a_mon]),'Y',x,y);
    }
  }
