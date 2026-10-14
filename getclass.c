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

char* get_class() {
  static STRING32 ret;
  switch (player.class) {
    case 1:strcpy(ret,"Fighter"); break;
    case 2:strcpy(ret,"Paladin"); break;
    case 3:strcpy(ret,"Ranger"); break;
    case 4:strcpy(ret,"Cleric"); break;
    case 5:strcpy(ret,"Druid"); break;
    case 6:strcpy(ret,"Mage"); break;
    case 7:strcpy(ret,"Assassin"); break;
    case 8:strcpy(ret,"Hierophant"); break;
    case 9:strcpy(ret,"Cavalier"); break;
    case 10:strcpy(ret,"Monk"); break;
    case 11:strcpy(ret,"Noble"); break;
    }
  return ret;
  }

