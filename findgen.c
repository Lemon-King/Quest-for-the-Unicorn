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

int find_gen(char* search) {
  int x;
  char flag;
  MESSAGE general;
  upper(search);
  flag = ' ';
  x = 0;
  while (flag == ' ') {
    general = gen[x];
    upper(general.message);
    if (strstr(general.message,search) != NULL) flag = '*';
    if (player.gen[x]) flag = ' ';
    x++;
    if (flag != '*' && x == NO_OF_GENS) flag = '#';
    }
  return (flag == '*') ? x : 0;
  }

