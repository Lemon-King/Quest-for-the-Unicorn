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

int get_city() {
  int i;
  i = 0;
  while (cities[i].citynum < 999) {
    if (player.region == cities[i].region &&
        player.land_x == cities[i].rx &&
        player.land_y == cities[i].ry) return cities[i].citynum;
    i++;
    }
  return 1;
  }

