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

void show_f_keys() {
  int i;
  for (i=18; i<23; i++) {
    gotoxy(1,i); txt_write("                                       ");
    gotoxy(40,i); txt_write("                                       ");
    }
  textcolor(9);
  gotoxy(1,18); txt_write("F1 - "); txt_write(player.fspell[1]);
  gotoxy(1,19); txt_write("F3 - "); txt_write(player.fspell[3]);
  gotoxy(1,20); txt_write("F5 - "); txt_write(player.fspell[5]);
  gotoxy(1,21); txt_write("F7 - "); txt_write(player.fspell[7]);
  gotoxy(1,22); txt_write("F9 - "); txt_write(player.fspell[9]);
  gotoxy(40,18); txt_write("F2 - "); txt_write(player.fspell[2]);
  gotoxy(40,19); txt_write("F4 - "); txt_write(player.fspell[4]);
  gotoxy(40,20); txt_write("F6 - "); txt_write(player.fspell[6]);
  gotoxy(40,21); txt_write("F8 - "); txt_write(player.fspell[8]);
  gotoxy(39,22); txt_write("F10 - "); txt_write(player.fspell[10]);
  }


