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

char* get_health() {
  static STRING32 ret;
  if (player.health >= 101) strcpy(ret,"Satiated");
  else if (player.health >= 85) strcpy(ret,"Healthy");
  else if (player.health >= 50) strcpy(ret,"Hungry");
  else if (player.health >= 25) strcpy(ret,"Starving");
  else if (player.health >= 1) strcpy(ret,"Faint");
  else strcpy(ret,"DEAD!!");
  return ret;
  }

