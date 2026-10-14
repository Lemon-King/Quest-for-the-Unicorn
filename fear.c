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

void fear() {
  char mflag;
  char key;
  int  x,y;
  int  xdir,ydir;
  int  mon;
  int  i;
  key = get_dir(&xdir,&ydir);
  x = player.x;
  y = player.y;
  mflag = ' ';
  while (mflag == ' ') {
    x += xdir;
    y += ydir;
    if (player.map[x][y] == 3) mflag = '*';
    if (player.map[x][y] == 38) mflag = '*';
    if (player.map[x][y] == 39) mflag = '*';
    if (player.map[x][y] == 21) mflag = '*';
    if (player.map[x][y] < 0) mflag = '*';
    if (player.map[x][y]>400 && player.map[x][y]<500) mflag = '*';
    if (in_sight(x,y) == '*') {
      show_sprite(x-player.map_x,y-player.map_y,80);
      delay(100);
      show_spot(x,y);
      }
    }
  if (player.map[x][y] < 0 || (player.map[x][y]>400 && player.map[x][y]<500)) {
    if (in_arena == 'Y') mon = player.map[x][y] - 400;
      else mon = player.map[x][y];
    if (in_arena == 'Y') i=50+5*(player.level-player.monster[mon][a_mon].level);
      else i=50+5*(player.level-player.monster[1][mon].level);
    if (in_arena == 'Y' && player.monster[mon][a_mon].special == 1) i=0;
    if (in_arena != 'Y' && player.monster[1][mon].special == 1) i=0;
    if (u_random(100) < i) {
      clear_prompt();
      prompt("SCARED !!!");
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,80);
        delay(250);
        show_spot(x,y);
        }
      if (in_arena != 'Y')
        player.monster[1][mon].fear=u_random(5*(player.level-player.monster[1][mon].level));
      if (in_arena == 'Y')
        player.monster[mon][a_mon].fear=u_random(5*(player.level-player.monster[mon][a_mon].level));
      }
    else {
      clear_prompt();
      prompt("Fizzle. . . ");
      }
    }
  }


