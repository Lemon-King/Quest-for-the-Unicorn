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

int auto_target_x;
int auto_target_y;

int dist(int x1,int y1, int x2, int y2) {
  return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
  }

int attempt_auto_target() {
  int x,y;
  NPC_REC* mob;
  auto_target_x = 999;
  auto_target_y = 999;
  for (y=player.y-30; y<=player.y+30; y++)
    for (x=player.x-30; x<=player.x+30; x++)
      if (los(player.x,player.y,x,y,'Y')) {
        mob = get_monster(x,y);
        if (mob != NULL && (mob->special & MS_FRIENDLY) != MS_FRIENDLY) {
          if (dist(player.x,player.y,x,y) < dist(player.x,player.y,auto_target_x,auto_target_y)) {
            auto_target_x = x;
            auto_target_y = y;
            }
          }
        }
  return (auto_target_x != 999) ? -1 : 0;
  }

void target(int sprt,int stop_at_target,int show_path) {
  int x,y;
  char mflag;
  double fx,fy;
  int key;
  auto_target_x = 999;
  auto_target_y = 999;
  prompt("Select target");
  x = player.x - player.map_x;
  y = player.y - player.map_y;
  if (auto_target == 'Y') {
    if (attempt_auto_target()) {
      x = auto_target_x - player.map_x;
      y = auto_target_y - player.map_y;
      if (x > TILES_X || y > TILES_Y || x < 1 || y < 1) {
        auto_target_x = 999;
        auto_target_y = 999;
        }
      }
    else {
      auto_target_x = 999;
      auto_target_y = 999;
      }
    }
  if (auto_target_x == 999) {
    x = player.x - player.map_x;
    y = player.y - player.map_y;
    x += last_target_x;
    y += last_target_y;
    }
  show_sprite(x,y,100);
  key = ' ';
  while (key != 13 && key != 27) {
    key = inkey();
    show_spot(x + player.map_x,y + player.map_y);
    show_player();
    switch (key) {
      case '2': y++;
                if (y>TILES_Y) y = TILES_Y;
                break;
      case '8': y--;
                if (y < 1) y = 1;
                break;
      case '6': x++;
                if (x>TILES_X) x = TILES_X;
                break;
      case '4': x--;
                if (x < 1) x = 1;
                break;
      case '7': x--; y--;
                if (x < 1) x = 1;
                if (y < 1) y = 1;
                break;
      case '9': x++; y--;
                if (x>TILES_X) x = TILES_X;
                if (y < 1) y = 1;
                break;
      case '1': x--; y++;
                if (x < 1) x = 1;
                if (y>TILES_Y) y = TILES_Y;
                break;
      case '3': x++; y++;
                if (x>TILES_X) x = TILES_X;
                if (y>TILES_Y) y = TILES_Y;
                break;
      case 'f': key = 13;
      }
    show_sprite(x,y,100);
    }
    show_spot(x + player.map_x,y + player.map_y);
    show_player();
    target_x = x + player.map_x;
    target_y = y + player.map_y;
    dir_x = target_x - player.x;
    dir_y = target_y - player.y;
    if (key == 27) {
      dir_x = 0;
      dir_y = 0;
      }
    if (dir_x != 0 || dir_y != 0) {
      last_target_x = target_x - player.x;
      last_target_y = target_y - player.y;
      if (abs(target_x - player.x) >= abs(target_y - player.y)) {
        dir_y = dir_y / abs(dir_x);
        if (dir_x > 0) dir_x = 1;
        if (dir_x < 0) dir_x = -1;
        } else {
        dir_x = dir_x / abs(dir_y);
        if (dir_y > 0) dir_y = 1;
        if (dir_y < 0) dir_y = -1;
        }
      fx = player.x + 0.5;
      fy = player.y + 0.5;
      mflag = ' ';
      if (sprt < 0) {
#ifdef ASCII
        sprt = 100;
#else
        if (dir_x <  0 && dir_y >  0) sprt = 98;
        if (dir_x == 0 && dir_y >  0) sprt = 92;
        if (dir_x >  0 && dir_y >  0) sprt = 97;
        if (dir_x <  0 && dir_y == 0) sprt = 94;
        if (dir_x == 0 && dir_y == 0) sprt = 100;
        if (dir_x >  0 && dir_y == 0) sprt = 93;
        if (dir_x <  0 && dir_y <  0) sprt = 96;
        if (dir_x == 0 && dir_y <  0) sprt = 91;
        if (dir_x >  0 && dir_y <  0) sprt = 95;

#endif
        }
      while (mflag == ' ') {
        fx += dir_x;
        fy += dir_y;
        x = fx;
        y = fy;
        if (player.map[x][y] == 3) mflag = '*';
        if (player.map[x][y] == 38) mflag = '*';
        if (player.map[x][y] == 39) mflag = '*';
        if (player.map[x][y] == 21) mflag = '*';
        if (player.map[x][y] == 22) mflag = '*';
        if (player.map[x][y] == 41) mflag = '*';
        if (player.map[x][y] < 0) mflag = '*';
        if (player.map[x][y]>400 && player.map[x][y]<500) mflag = '*';
        if (player.map[x][y]>=600 && player.map[x][y]<700) mflag = '*';
        if (in_sight(x,y) == '*' && show_path) {
          show_sprite(x-player.map_x,y-player.map_y,sprt);
          delay(delay_ranged);
          flush();
          show_spot(x,y);
          flush();
          }
        if (x == target_x && y == target_y) mflag = '*';
        }
      target_x = x;
      target_y = y;
      }
  }


