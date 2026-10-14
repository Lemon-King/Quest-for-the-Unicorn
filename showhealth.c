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

char* show_health() {
  static STRING32 ret;
  gotoxy(10,9);
  if (player.health >= 101) txt_write("Satiated");
  else if (player.health >= 85) txt_write("Healthy");
  else if (player.health >= 50) txt_write("Hungry");
  else if (player.health >= 25) txt_write("Starving");
  else if (player.health >= 1) txt_write("Faint");
  else txt_write("DEAD!!");
  return ret;
  }

