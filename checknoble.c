/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
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
  int  class;
  int  i;
  class = -1;
  for (i=0; i<NUM_CLASSES; i++)
    if (classes[i].flags & CF_NOBLE) class = i+1;
  if (class < 0) return;
  flag = ' ';
  if (check_class_change(class)) flag = '*';
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

