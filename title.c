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

void title() {
  char   key;
#ifdef ANNIV
#include "./Anniv25/title.c"
#else
  setcolor(14);
  gotoxy(38, 2); txt_write("Quest");
  setcolor(2);
  gotoxy(37, 4); txt_write("for the");
  setcolor(14);
  gotoxy(37, 6); txt_write("Unicorn");
  setcolor(4);
  gotoxy(37, 9); txt_write(VERSION);
  setcolor(9);
  gotoxy(34, 11); txt_write("by Mike Riley");
  setcolor(15);
#endif
  gotoxy(3, 17);
  txt_write("This program is copyright by Michael H. Riley and may be copied, modified,");
  gotoxy(3, 18);
  txt_write("and distributed so long as this title screen is not modified or removed.");
  gotoxy(3, 19);
  txt_write("This program may not be used for commercial purposes without the express");
  gotoxy(3, 20);
  txt_write("written permission from the author.");
  gotoxy(28, 24);
  txt_write("Press <ENTER> to continue");


  key = ' ';
  while (key != 13) {
    key = inkey();
    }
  }

