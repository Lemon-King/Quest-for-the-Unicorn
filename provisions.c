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

void provisions(char* name) {
  int option;
  double price;
  int item;
  int qty;
  int i;
  char buffer[80];

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    for (i=1; i<=5; i++) {
      gotoxy(22,i+2);
      sprintf(buffer,"%2d  %s",i,objects[i + 162].name);
      txt_write(buffer);
      gotoxy(50,i+2);
      sprintf(buffer,"%6.0f",objects[i + 162].cost);
      txt_write(buffer);
      }
    gotoxy(22,8); txt_write(" 6  Torch");
    gotoxy(50,8); txt_write("     1");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  void pack_it() {
    char flag;
    int slot;
    int pitem;
    slot = 1;
    pitem = item;
    flag = ' ';
    while (flag == ' ') {
      if (player.pack[slot] == pitem) flag = '*';
      if (player.pack[slot] == 0) flag = '*';
      if (flag != '*') slot = slot+1;
      if (slot == 33) flag = '#';
      }
    if (flag != '#') {
      player.pack_q[slot] = player.pack_q[slot]+qty;
      player.pack[slot] = pitem;
      }
    }

  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,17); textcolor(10);
    txt_write("Which item would you like (0 to leave) ?        ");
    gotoxy(56,17); textcolor(15);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    for (i=17; i<=22; i++) {
      gotoxy(10,i); txt_write("                                                              ");
      }
    if (option>0) {
      gotoxy(15,18);
      txt_write("How many would you like ? ");
      gotoxy(41,18);
      p_read(buffer);
      sscanf(buffer,"%d",&qty);
      if (option<6) item = option+162;
        else item = 8;
      gotoxy(15,18); textcolor(12);
      sprintf(buffer,"Ah, a %s A fine selection!",objects[item].name);
      txt_write(buffer);
      if (option<6) price = objects[item].cost*qty;
        else price = qty;
      if (price>player.gold) {
        gotoxy(15,19); textcolor(12);
        txt_write("But you do not have enough gold !!");
        }
      else {
        player.gold = player.gold-price;
        if (option<6) pack_it();
          else player.torch = player.torch+qty;
        gotoxy(15,19); textcolor(15);
        txt_write("Bought && Packed.");
        }
      show_top();
      }
    }
  } /* void provisions(char* name) */
