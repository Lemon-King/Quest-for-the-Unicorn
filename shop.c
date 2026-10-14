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

void shop(char* name,int shop_type) {
  double mul;
  int option;
  double price;
  OBJECT_REC item;
  int i;
  char buffer[80];

  void show_top() {
    int j;
    int line,col;
    char buffer2[80];
    line = 3;
    col = 2;
    if (n_shop_items < 17) col = 22;
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    for (i=0; i<n_shop_items; i++) {
      gotoxy(col,line);
      strcpy(buffer2,shop_items[i].name);
      for (j=0; j<strlen(buffer2); j++)
        if (buffer2[j] == '_') buffer2[j] = ' ';
      sprintf(buffer,"%2d  %s",i+1,buffer2);
      txt_write(buffer);
      gotoxy(col+30,line);
      sprintf(buffer,"%6.0f",item_cost(&(shop_items[i]))*mul);
      txt_write(buffer);
      line++;
      if (line > 20) {
        line = 3;
        col = 42;
        }
      }
    textcolor(14); gotoxy(35,25);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  switch (shop_type) {
    case SHOP_ALCH: get_shop_items(O_POTN,0,0,0,10); break;
    case SHOP_ARMR: get_shop_items(O_ARMR,O_SHLD,O_HELM,0,100); break;
    case SHOP_BOOK: get_shop_items(O_SCRL,O_BOOK,0,0,10); break;
    case SHOP_ROBE: get_shop_items(O_ROBE,0,0,0,10); break;
    case SHOP_JEWL: get_shop_items(O_RING,O_NECK,0,0,10); break;
    case SHOP_MAGC: get_shop_items(O_WAND,O_MISC,0,0,10); break;
    case SHOP_WEAP: get_shop_items(O_EDGE,O_POLE,O_DAGR,O_BOW,100); break;
    case SHOP_FOOD: get_shop_items(O_FOOD,0,0,0,30); break;
    }

  mul = 1; 
  if (player.sex == 'F') mul = mul-0.05;
  mul = mul-(player.skill[14]/100);
  if (player.stat[6] >= 0 && player.stat[6] <= 7) mul += .08;
  if (player.stat[6] >= 8 && player.stat[6] <= 11) mul += .05;
  if (player.stat[6] >= 12 && player.stat[6] <= 14) mul += .01;
  if (player.stat[6] >= 17 && player.stat[6] <= 18) mul -= .02;
  if (player.stat[6] >= 19 && player.stat[6] <= 20) mul -= .03;
  if (player.stat[6] >= 21 && player.stat[6] <= 23) mul -= .05;
  if (player.stat[6] >= 24 && player.stat[6] <= 99) mul -= .1;
  if (player.class == 11) mul -= 0.2;
  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,22); textcolor(10);
    txt_write("Which item would you like (0 to leave) ?        ");
    gotoxy(56,22); textcolor(15);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    for (i=20; i<=24; i++) {
      gotoxy(10,i); txt_write("                                                ");
      }
    if (option>0) {
      item = shop_items[option-1];
      gotoxy(15,22); textcolor(12);
      sprintf(buffer,"Ah, a %s A fine selection!",item.name);
      txt_write(buffer);
      price = item_cost(&item)*mul;
      haggle(price,item);
      show_top();
      }
    }
  } /* void shop(char* name) */
