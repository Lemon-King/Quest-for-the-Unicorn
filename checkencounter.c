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

void check_encounter() {
  int chance;
  chance = 3;
  switch (player.map[player.x][player.y]) {
    case 2:chance = 7; break;
    case 3:chance = 0; break;
    case 19:chance = 5; break;
    case 4:chance = 0; break;
    case 6:chance = 5; break;
    case 8:chance = 2; break;
    case 9:chance = 6; break;
    case 5:chance = 0; break;
    case 17:chance = 0; break;
    case 11:chance = 0; break;
    case 12:chance = 0; break;
    case 20:chance = 0; break;
    }
  if (u_random(200)<chance) {
    stock_encounter();
    arena(1,player.map[player.x][player.y]);
    show_screen();
    }
}

