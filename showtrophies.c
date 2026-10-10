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

void show_trophies() {
  int i;
  int key;
  int top;
  int bottom;
  textmode(3);
  textcolor(10); gotoxy(31,1); txt_write("Trophies Collected:");
  top = 0;
  bottom = top + 20;
  if (bottom > stats.num_trophies) bottom = stats.num_trophies;
  for (i=top; i<bottom; i++) {
    textcolor(10);
    gotoxy(1,i+3); txt_write(trophies[stats.trophies[i]].name);
    totoxy(20,i+3); txt_write(trophies[stats.trophies[i]].desc);
    }
  key = 0;
  while (key != 13 && key != 27) key = inkey();
  }


