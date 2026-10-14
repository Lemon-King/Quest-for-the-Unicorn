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

void show_quest() {
  char key;
  int  i;
  int  row;
  int  col;
  int  suggest;
  int  sug_level;
  saveScreen();
  textmode(3);
  textcolor(15);
  gotoxy(35,1); txt_write("Quest Log");
  row = 4;
  col = 1;
  i = 0;
  suggest = 0;
  sug_level = 999;
  textcolor(14); gotoxy(32,3); txt_write("Completed Quests:");
  while (i >= 0) {
    if (player.quests[i] == 'Y') {
      textcolor(9);
      gotoxy(col,row);
      txt_write(links[i].name);
      row++;
      if (row == 25) {
        row = 4;
        col += 33;
        }
      }
    else if (links[i].quest > 0) {
      if (links[i].quest < sug_level) {
        suggest = i;
        sug_level = links[i].quest;
        }
      }
    i++;
    if (links[i].region > 90) i = -1;
    }
  if (sug_level < 999) {
    col = 16 + strlen(links[suggest].name);
    col /= 2;
    gotoxy(40-col,2); textcolor(3); txt_write("Suggested quest:");
    textcolor(2); txt_write(links[suggest].name);
    }
  gotoxy(28,25); textcolor(14);
  txt_write("Press any key to continue");
  key = inkey();
  restoreScreen();
  }

