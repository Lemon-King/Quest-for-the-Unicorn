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

void house_inventory(int hnum) {
  int i;
  char flag;
  char key;
  int  row;
  int  col;
  char buffer[80];
  int  base;
  OBJECT_REC  it;
  OBJECT_REC* item;

  void show_inventory() {
    textmode(3);
    textcolor(15); gotoxy(33,1); txt_write("House Inventory");
    sprintf(buffer,"     Page %d of 12",base/40+1);
    txt_write(buffer);
    gotoxy(17,3);
    textcolor(6);
    txt_write("<");
    textcolor(14); txt_write("ESC");
    textcolor(6); txt_write(">Exit, <");
    textcolor(14); txt_write("ENTER");
    textcolor(6); txt_write(">Transfer Item, <");
    textcolor(14); txt_write("Arrows");
    textcolor(6); txt_write(">Select Item");
    textcolor(3);
    for (i=0; i<20; i++) {
      if (player.houses[hnum].inventory[i+base].otype != O_NONE) {
        gotoxy(3,i+5);
        sprintf(buffer,"%s",get_name(&(player.houses[hnum].inventory[i+base])));
        txt_write(buffer);
        }
      if (player.houses[hnum].inventory[i+base+20].otype != O_NONE) {
        gotoxy(43,i+5);
        sprintf(buffer,"%s",get_name(&(player.houses[hnum].inventory[i+base+20])));
        txt_write(buffer);
        }
      }
    }

  row = 0;
  col = 0;
  base = 0;
  show_inventory();
  flag = ' ';
  while (flag == ' ') {
    textcolor(14);
    gotoxy(1+col*40,row+5);
    txt_write("->");
    key = inkey();
    textcolor(14);
    gotoxy(1+col*40,row+5);
    txt_write("  ");
    if (key == 27) flag = 'N';
    if (key == 'i' || key == 'I' || key == 13) {
      it = player.houses[hnum].inventory[base+row+col*20];
      player.houses[hnum].inventory[base+row+col*20].otype = O_NONE;
      if (it.otype != O_NONE) item = inventory(&it);
        else item = inventory(NULL);
      if (item != NULL &&
        player.houses[hnum].inventory[base+row+col*20].otype == O_NONE) {
        player.houses[hnum].inventory[base+row+col*20] = *item;
        item->otype = O_NONE;
        }
      show_inventory();
      }
    if (key == '3') {
      base += 40;
      if (base > 440) base = 0;
      show_inventory();
      }
    if (key == '9') {
      base -= 40;
      if (base < 0) base = 440;
      show_inventory();
      }
    if (key == '2' || key == '.' || key == '>') {
      row++;
      if (row > 19) row = 0;
      }
    if (key == '8' || key == ',' || key == '<') {
      row--;
      if (row < 0) row = 19;
      }
    if (key == '6' || key == '4') {
      col = (col == 0) ? 1 : 0;
      }
    }
  textmode(3);
  }

