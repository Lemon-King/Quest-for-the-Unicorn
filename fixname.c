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

char* fix_name(STRING32 name) {
  static STRING32 str_ret;
  strcpy(str_ret,name);
  while (strlen(str_ret) < 25) strcat(str_ret," ");
  if (strlen(str_ret) > 25) str_ret[25] = 0;
  return str_ret;
  }

