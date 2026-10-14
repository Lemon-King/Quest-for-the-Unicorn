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

int exist(char* filename) {
  FILE *file;
  if ((file=fopen(filename,"r"))==NULL) return 0;
  fclose(file);
  return -1;
  }

