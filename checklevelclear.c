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

int check_level_cleared(int lvl) {
    int x,y;
    if (lvl >= current_dungeon.num_levels) return -1;
    y = 0;
    for (x=1; x<=60; x++)
      if (current_dungeon.level[lvl].monsters[1][x].hp > 0 && (current_dungeon.level[lvl].monsters[1][x].special & MS_FRIENDLY) == 0) y++;
    return (y > 0) ? 0 : -1;
    }

