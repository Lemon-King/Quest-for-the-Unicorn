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

double needed(int x) {
  double i;
  int j;
  i = 100;
  for (j=1; j<=x; j++)
    if (i<100000) i*=2;
      else i *= 1.2;
  return i;
  }

