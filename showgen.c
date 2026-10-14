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

void show_gen(int item) {
  int i;
  int x,y;
  int space;
  int size;
  char key;
  MESSAGE general;
  i = item;
  general = gen[i];
  player.gen[i] = -1;
  graphmode();
  display_scroll();
  x = 120; y = 160; space = 25; size = 30;
  setcolor(0);
  show_message(general.message);
/*
  while (strlen(general.message) != 0) {
    if (strlen(general.message) < size) {
      write_font(x,y,0,general.message);
      strcpy(general.message,"");
      }
    else {
      i = size;
      while (i > 0 && general.message[i] != ' ') i--;
      last = general.message[i];
      general.message[i] = 0;
      write_font(x,y,0,general.message);
      general.message[i] = last;
      i++;
      y += 19;
      strcpy(general.message,general.message+i);
      }
    }
*/
  key = inkey();
  }

