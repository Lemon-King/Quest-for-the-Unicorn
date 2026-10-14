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

char* get_race() {
  static STRING32 ret;
  switch (player.race) {
    case 1:strcpy(ret,"Human"); break;
    case 2:strcpy(ret,"Elf"); break;
    case 3:strcpy(ret,"Half-Elf"); break;
    case 4:strcpy(ret,"Dwarf"); break;
    case 5:strcpy(ret,"Hobbit"); break;
    }
  return ret;
  }

