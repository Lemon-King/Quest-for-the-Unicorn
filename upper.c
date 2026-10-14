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

void upper(char* buffer) {
  int i;
  for (i=0; i<strlen(buffer); i++)
    if (buffer[i] >= 'a' && buffer[i] <= 'z') buffer[i] -= 32;
  }

