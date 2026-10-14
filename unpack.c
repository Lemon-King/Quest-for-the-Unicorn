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

OBJECT_REC* unpack() {
  int i;
  char flag;
  char key;
  int  row;
  int  col;
  char buffer[80];
  textmode(3);
  row = 0;
  col = 0;
  textcolor(15); gotoxy(33,2); txt_write("Pack Inventory");
  gotoxy(17,4);
  textcolor(6);
  txt_write("<");
  textcolor(14); txt_write("ESC");
  textcolor(6); txt_write(">Exit, <");
  textcolor(14); txt_write("ENTER");
  textcolor(6); txt_write(">Take Item, <");
  textcolor(14); txt_write("Arrows");
  textcolor(6); txt_write(">Select Item");
  textcolor(3);
  for (i=1; i<=16; i++) {
    if (player.pack[i].otype != O_NONE) {
      gotoxy(3,i+5);
      sprintf(buffer,"%s",get_name(&(player.pack[i])));
      txt_write(buffer);
      }
    if (player.pack[i+16].otype != O_NONE) {
      gotoxy(43,i+5);
      sprintf(buffer,"%s",get_name(&(player.pack[i+16])));
      txt_write(buffer);
      }
    }
  flag = ' ';
  while (flag == ' ') {
    textcolor(14);
    gotoxy(1+col*40,row+6);
    txt_write("->");
    key = inkey();
    textcolor(14);
    gotoxy(1+col*40,row+6);
    txt_write("  ");
    if (key == 27) flag = 'N';
    if (key == 13 && player.pack[row+1+col*16].otype != O_NONE) flag = 'Y';
    if (key == '2' || key == '.' || key == '>') {
      row++;
      if (row > 15) row = 0;
      }
    if (key == '8' || key == ',' || key == '<') {
      row--;
      if (row < 0) row = 15;
      }
    if (key == '6' || key == '4') {
      col = (col == 0) ? 1 : 0;
      }
    }
  textmode(3);
  if (flag == 'Y') {
    return &(player.pack[row+1+col*16]);
    }
  else return NULL;
  }

