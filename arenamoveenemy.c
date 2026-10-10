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

void arena_move_enemy(int x,int y) {
  int xdir,ydir;
  int ox,oy;
  int monster;
  int targetx;
  int targety;
  int dist;
  int spd;

  char valid(int x,int y) {
    int i;
    char flag;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sEntering: valid(%d,%d)\n",debug_tab,"",x,y);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
    flag = '*';
    if (player.map[x][y] < 0) flag = ' ';
    if (player.map[x][y] == 21) flag = ' ';
    if (player.map[x][y] == 22) flag = ' ';
    if (player.map[x][y]>300 && player.map[x][y]<500) flag = ' ';
    if (x == player.x && y == player.y) flag = ' ';
    if (x<offset_x || x>offset_x+ARENA_SIZE_X || y<offset_y || y>offset_y+ARENA_SIZE_Y) flag = ' ';
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
      if (player.map[x][y] >= 600 && player.map[x][y] < 700) {
        i = player.monster[monster-400][a_mon].level / 4;
        if (i < 1) i = 1;
        player.map[x][y] -= i;
        if (player.map[x][y] < 600) {
          player.map[x][y] = currentFloor;
          }
        else flag = ' ';
        }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting: valid()\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
    return flag;
    }

  void find_target() {
    int x1,y1;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sEntering: find_target()\n",debug_tab,"");
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
    dist = (sqr(player.x-x) + sqr(player.y-y));
    targetx = player.x;
    targety = player.y;
    for (x1=offset_x; x1<=offset_x+16; x1++)
      for (y1=offset_y; y1<=offset_y+16; y1++)
        if (player.map[x1][y1]>300 && player.map[x1][y1]<400 &&
            (sqr(x1-x)+sqr(y1-y)) < dist) {
          targetx = x1;
          targety = y1;
          dist = (sqr(x1-x)+sqr(y1-y));
          }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting: find_target()\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
    }

#ifdef DEBUG
  sprintf(debugbuffer,"%*sEntering: arena_move_enemy(%d,%d)\n",debug_tab,"",x,y);
  debug_tab += 2;
  debugLog(debugbuffer);
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
      if ((player.monster[monster-400][a_mon].special & MS_FRIENDLY) == MS_FRIENDLY ||
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
      if (abs(x-targetx) > 1 || abs(y-targety)>1 || player.monster[monster-400][a_mon].fear > 0) {
        if (player.monster[monster-400][a_mon].fear > 0) { xdir = -xdir; ydir = -ydir; }
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
      if (player.monster[monster-400][a_mon].prev>=950 &&
          player.monster[monster-400][a_mon].prev<970) {
        trigger_trap(x,y,player.monster[monster-400][a_mon].prev);
        }
      }
  player.monster[monster-400][a_mon].special |= MS_MOVED;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting: arena_move_enemy()\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  }
