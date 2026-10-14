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

void show_log() {
  int x;
  MESSAGE general;
  char key;
  int  lin;
  saveScreen();
  textmode(3);
  textcolor(3);
  lin = 2;
  for (x=1; x<=NO_OF_GENS; x++)
    if (player.gen[x] != 0) {
      general = gen[x];
      gotoxy(1,lin); txt_write(general.message);
      lin++;
      if (lin == 23) {
        gotoxy(28,24); textcolor(14);
        txt_write("Press any key to continue");
        key = inkey();
        textcolor(3);
        lin = 2;
        clrscr();
        }
      }
  textcolor(11);
  for (x=1; x<=NO_OF_LORE; x++) {
    if (player.lore[x] != 0) {
      general = lore[x];
      gotoxy(1,lin); txt_write(general.message);
      lin++;
      if (lin == 23) {
        gotoxy(28,24); textcolor(14);
        txt_write("Press any key to continue");
        key = inkey();
        textcolor(11);
        lin = 2;
        clrscr();
        }
      }
    }
  gotoxy(28,24); textcolor(14);
  txt_write("Press any key to continue");
  key = inkey();
  restoreScreen();
  }

