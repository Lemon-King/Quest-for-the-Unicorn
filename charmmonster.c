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

void charmmonster() {
  int  x,y;
  int  xdir,ydir;
  int  mon;
  get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  if (player.map[x][y] < 0 || (player.map[x][y]>400 && player.map[x][y]<500)) {
    if (in_arena == 'Y') mon = player.map[x][y] - 400;
      else mon = 0 - player.map[x][y];
    clear_prompt();
    noise(1000,100);
    if (in_arena != 'Y' && (player.monster[1][mon].special & MS_FRIENDLY) == MS_FRIENDLY) {
      prompt("Fizzle");
      return;
      }
    if (in_arena == 'Y' && (player.monster[mon][a_mon].special & MS_FRIENDLY) == MS_FRIENDLY) {
      prompt("Fizzle");
      return;
      }
    prompt("Charmed");
    if (in_arena == 'Y') player.monster[mon][a_mon].special |= MS_FRIENDLY;
      else player.monster[1][mon].special |= MS_FRIENDLY;
    }
  else
    prompt("Fizzle");
  }
