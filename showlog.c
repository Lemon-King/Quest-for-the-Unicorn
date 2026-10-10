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

int write_message(char* msg,int line) {
  int pos;
  while (strlen(msg) > 0) {
    if (strlen(msg) < 80) {
      gotoxy(1,line); txt_write(msg);
      msg[0] = 0;
      }
    else {
      pos = 79;
      while (msg[pos] != ' ') pos--;
      msg[pos] = 0;
      gotoxy(1,line); txt_write(msg);
      strcpy(msg,msg+pos+1);
      }
    line++;
    }
  return line;
  }

void show_log() {
  int x;
  char msg[1024];
  MESSAGE general;
  int  lin;
  saveScreen();
  textmode(3);
  textcolor(3);
  lin = 2;
  x = 0;
  while (gen[x].link < 900) {
    if (player.gen[x] != 0) {
      general = gen[x];
      strcpy(msg,general.message);
      lin = write_message(msg, lin);
      if (lin >= 22) {
          gotoxy(28,24); textcolor(14);
          txt_write("Press any key to continue");
          inkey();
          textcolor(3);
          lin = 2;
          clrscr();
          }
        }
      x++;
    }
  textcolor(11);
  x = 0;
  while (lore[x].link != 999) {
      if (player.lore[x] != 0) {
        general = lore[x];
        strcpy(msg, general.message);
        lin = write_message(msg, lin);
        if (lin == 23) {
          gotoxy(28,24); textcolor(14);
          txt_write("Press any key to continue");
          inkey();
          textcolor(11);
          lin = 2;
          clrscr();
          }
        }
    x++;
    }
  gotoxy(28,24); textcolor(14);
  txt_write("Press any key to continue");
  inkey();
  restoreScreen();
  }

