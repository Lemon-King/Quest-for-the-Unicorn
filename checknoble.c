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

void check_noble() {
  char flag;
  char key;
  flag = ' ';
  if (player.class == 4 && player.level >= 23) flag = '*';
  if (player.class == 6 && player.level >= 38) flag = '*';
  if (player.class == 8 && player.level >= 31) flag = '*';
  if (player.class == 9 && player.level >= 26) flag = '*';
  if (player.class == 10 && player.level >= 44) flag = '*';
  if (flag == '*') {
    textmode(3);
    textcolor(2);
    gotoxy(25,5); txt_write("You have been offered Nobility");
    gotoxy(25,7); txt_write("Do you accept (Y/N) ?");
    key = ' ';
    while (key != 'Y' && key != 'N') {
      key = inkey();
      if (key == 'y') key = 'Y';
      if (key == 'n') key = 'N';
      }
    if (key == 'Y') make_n();
    }
  }

