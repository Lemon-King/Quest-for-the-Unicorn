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

char* get_align() {
  static STRING32 ret;
  if (player.align >= 85) strcpy(ret,"Lawfull Good");
  else if (player.align >= 70) strcpy(ret,"Chaotic Good");
  else if (player.align >= 55) strcpy(ret,"Chaotic Neutral");
  else if (player.align >= 40) strcpy(ret,"Neutral");
  else if (player.align >= 30) strcpy(ret,"Lawfull Neutral");
  else if (player.align >= 20) strcpy(ret,"Lawfull Evil");
  else if (player.align >= 1) strcpy(ret,"Chaotic Evil");
  else strcpy(ret,"The Essence of Evil!!");
  return ret;
  }

