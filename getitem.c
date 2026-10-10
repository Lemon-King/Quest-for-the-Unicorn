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

OBJECT_REC* get_item(int x,int y) {
  OBJECT_REC* ret;
  ret = NULL;
  if (x < 1 || y < 1 || x > 100 || y > 100) return ret;
  if (player.map[x][y] < 1000) return ret;
  ret = &(player.map_objects[player.map[x][y] - 1000]);
  return ret;
  }

