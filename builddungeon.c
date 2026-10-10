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

void build_dungeon(int floor,int dn) {
  int i;
  int j;
  int tx;
  int ty;
  int upx,upy;
  int downx,downy;
  u_int32_t seed;
  currentFloor = floor;
  if (current_dungeon.dungeon_number == dn) return;
  current_dungeon.dungeon_number = dn;
  current_dungeon.num_levels = player.effect[PE_DEPTH];
  if (player.gateway == '*') current_dungeon.num_levels = 5;
  for (i=0; i<10; i++) current_dungeon.level[i].cleared = -1;
  for (i=0; i<current_dungeon.num_levels; i++) {
    seed = player.effect[PE_WORLDSEED];
    Rcs_Seed(seed);
    Shift(dn*10);
    Shift(i+1);
    mapgen(i+1,floor,&tx,&ty,&upx,&upy,&downx,&downy,
           &(current_dungeon.level[i].map),
           &(current_dungeon.level[i].known));
    if (i < current_dungeon.num_levels-1) {
      tx = -1;
      ty = -1;
      }
    current_dungeon.level[i].upx = upx;
    current_dungeon.level[i].upy = upy;
    current_dungeon.level[i].downx = downx;
    current_dungeon.level[i].downy = downy;
    current_dungeon.level[i].cleared = 0;
    current_dungeon.treasurex = tx;
    current_dungeon.treasurey = ty;
    stock_monsters(i+1,tx,ty,&(current_dungeon.level[i].map),
                         &(current_dungeon.level[i].monsters));
    for (j=0; j<1000; j++) current_dungeon.level[i].objects[j].otype = O_NONE;
    }
  }

