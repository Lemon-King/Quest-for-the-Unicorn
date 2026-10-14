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

void enemy_missile(int ex,int ey) {
  char flag;
  int  x,y;
  int  xdir,ydir;
  int  mon;
  int  ring;
  int  i,j;
  mon = 0-player.map[ex][ey];
  xdir = 0;
  ydir = 0;
  if (ex < player.x) xdir = 1; else if (ex > player.x) xdir = -1;
  if (ey < player.y) ydir = 1; else if (ey > player.y) ydir = -1;
  x = ex;
  y = ey;
  flag = ' ';
  while (flag == ' ') {
    x += xdir;
    y += ydir;
    if (in_sight(x,y) == '*') {
      show_sprite(x-player.map_x,y-player.map_y,100);
      delay(100);
      show_spot(x,y);
      }
    if (player.map[x][y] == 21 || player.map[x][y] == 22) flag = '*';
    if (player.map[x][y] == 38) flag = '*';
    if (player.map[x][y] == 39) flag = '*';
    if (player.map[x][y] == 3) flag = '*';
    if (x == player.x && y == player.y) flag = '*';
    }
  if (x == player.x && y == player.y) {
    i = 90;
    if (u_random(100) < i) {
      clear_prompt();
      noise(1000,100);
      prompt("HIT !!!");
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(250);
        show_spot(x,y);
        show_player();
        }
      ring = 0;
      for (j=1; j<=19; j++) {
        if (player.invent[j].otype != O_NONE &&
            player.invent[j].effect == E_INTR &&
            player.invent[j].control == A_REFL) { ring = j; j=99; }
        }
      if (ring == 0) {
        i = u_random(player.monster[1][mon].mana / 4 + 1);
        j = intrinsic_count(A_RFIR);
        while (j > 0) { i /= 2; j--; }
        j = intrinsic_count(A_RELE);
        while (j > 0) { i /= 2; j--; }
        player.chp -= i;
        show_player();
        }
      if (ring != 0) {
        r_missile(player.monster[1][mon].mana / 4 + 1);
        i = player.skill[8] + (player.level - player.monster[1][mon].level);
        i += player.ability[10] * 5;
        if (i > 0) i = 75 + i;
        if (i > 98) i = 98;
        if (i < 0) {
          player.invent[ring].otype = O_NONE;
          clear_prompt();
          prompt("Ring Melted!!!");
          delay(1000);
          }
        if (u_random(101) > i) {
          player.invent[ring].otype = O_NONE;
          clear_prompt();
          prompt("Ring Melted!!!");
          delay(1000);
          }
        }
      show_player();
      show_side();
      }
    else {
      clear_prompt();
      prompt("Fizzle. . .");
      show_player();
      }
    }
  }
