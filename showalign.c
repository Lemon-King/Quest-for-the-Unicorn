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

char* show_align() {
  static STRING32 ret;
  gotoxy(10,10);
  if (player.align >= 85) txt_write("Lawfull Good");
  else if (player.align >= 70) txt_write("Chaotic Good");
  else if (player.align >= 55) txt_write("Chaotic Neutral");
  else if (player.align >= 40) txt_write("Neutral");
  else if (player.align >= 30) txt_write("Lawfull Neutral");
  else if (player.align >= 20) txt_write("Lawfull Evil");
  else if (player.align >= 1) txt_write("Chaotic Evil");
  else txt_write("The Essence of Evil!!");
  return ret;
  }

