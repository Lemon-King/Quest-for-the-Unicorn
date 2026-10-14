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

char* yes_no(int input) {
  static STRING32 ret;
  if (input == 1) strcpy(ret,"Yes"); else strcpy(ret,"No");
  return ret;
  }

