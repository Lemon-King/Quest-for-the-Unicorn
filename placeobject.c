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

int place_object(int level) {
  int j;
  int s;
  int pls;
  j = u_random(NO_OF_OBJECTS) + 1;
  while (objects[j].level > level ||
         u_random(200) >= objects[j].rarity)
     j = u_random(NO_OF_OBJECTS) + 1;
  s = find_item_slot();
  if (s >= 0) {
    player.map_objects[s] = objects[j];
    if (player.map_objects[s].charges > 0)
      player.map_objects[s].charges = u_random(player.map_objects[s].charges) + 1;
    if (player.map_objects[s].otype == O_ARMR ||
        player.map_objects[s].otype == O_SHLD ||
        player.map_objects[s].otype == O_HELM ||
        player.map_objects[s].otype == O_BOOT ||
        player.map_objects[s].otype == O_DAGR ||
        player.map_objects[s].otype == O_EDGE ||
        player.map_objects[s].otype == O_POLE ||
        player.map_objects[s].otype == O_BOW) {
      if (u_random(100)<20) {
        pls = u_random(player.diff/4+1+player.d_level/7);
        if (pls != 0 && u_random((pls * pls) + 1) == 0) {
          player.map_objects[s].plus = pls;
          }
        else {
          player.map_objects[s].plus = 0 - pls;
          }
        }
      }
/*
printf("diff=%d d_level=%d ",player.diff,player.d_level);
printf("%s (%+0d)\n",player.map_objects[s].name,player.map_objects[s].plus);
*/
    }
  return s;
  }

