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

void pawn(char* name, byte city) {
  double mul;
  int option;
  double price;
  OBJECT_REC item;
  OBJECT_REC* pItem;
  int j,i;
  char buffer[80];
  char key;

  void show_top() {
    int j;
    char buffer2[80];
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    for (i=1; i<=10; i++) {
      gotoxy(22,i+2);
      strcpy(buffer2,player.pawn[city][i].name);
      for (j=0; j<strlen(buffer2); j++)
        if (buffer2[j] == '_') buffer2[j] = ' ';
      sprintf(buffer,"%2d  %s",i,buffer2);
      txt_write(buffer);
      gotoxy(50,i+2);
      sprintf(buffer,"%6.0f",item_cost(&(player.pawn[city][i])) * mul);
      txt_write(buffer);
      }
    gotoxy(22,14); txt_write("11  Sell an item");
    gotoxy(22,15); txt_write("12  Identify an item");
    gotoxy(22,16); txt_write("13  Sell from Pack");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
  }

  pItem = &item;
  mul = 1;
  if (player.sex == 'F') mul = mul-0.10;
  mul = mul-(player.skill[14]/100);
  if (player.stat[6] >= 0 && player.stat[6] <= 7) mul += .16;
  if (player.stat[6] >= 8 && player.stat[6] <= 11) mul += .10;
  if (player.stat[6] >= 12 && player.stat[6] <= 14) mul += .06;
  if (player.stat[6] >= 17 && player.stat[6] <= 18) mul -= .08;
  if (player.stat[6] >= 19 && player.stat[6] <= 20) mul -= .12;
  if (player.stat[6] >= 21 && player.stat[6] <= 23) mul -= .15;
  if (player.stat[6] >= 24 && player.stat[6] <= 99) mul -= .2;
  if (player.class == 11) mul -= 0.2;
  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,18); textcolor(10);
    txt_write("Which item would you like (0 to leave) ?        ");
    gotoxy(56,18); textcolor(15);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    for (i=17; i<=22; i++) {
      gotoxy(10,i); txt_write("                                                             ");
      }
    if (option>0 && option<11) {
      item = player.pawn[city][option];
      gotoxy(15,18); textcolor(12);
      sprintf(buffer,"Ah, a %s A fine selection!",item.name);
      txt_write(buffer);
      price = item_cost(&item)*mul;
      haggle(price,item);
      show_top();
      }
    if (option == 12) {
      pItem = inventory(0);
      show_top();
      if (pItem != NULL) {
        gotoxy(15,18); textcolor(12);
        price = trunc(item_cost(pItem) * 0.08);
        sprintf(buffer,"To identify a %s",get_name(pItem));
        txt_write(buffer);
        gotoxy(15,19); textcolor(14);
        sprintf(buffer," will cost %.0f Gold",price);
        txt_write(buffer);
        if (price>player.gold) {
          gotoxy(15,20);
          txt_write("You do not have that much!!");
          delay(5000);
          }
        else {
          gotoxy(15,20); textcolor(10);
          txt_write("Do you wish to identify it ? ");
          key = inkey();
          if (key == 'y' || key == 'Y') {
            player.gold = player.gold-price;
            pItem->level = -1;
            gotoxy(15,21); textcolor(15);
            sprintf(buffer,"It is a %s",get_name(pItem));
            txt_write(buffer);
            delay(1000);
            }
          }
        }
      show_top();
      }
    if (option == 13)
      for (i=1; i<=32; i++)
        if (player.pack[i].otype != O_NONE) {
          if (player.pack[i].otype == O_JEWL)
            price = item_cost(&(player.pack[i])) * .95 / mul;
          else {
            price = item_cost(&(player.pack[i])) * .08 / mul;
            if (player.pack[i].level >= 0) price /= 2;
            }
          textcolor(11); gotoxy(22,18);
          sprintf(buffer,"You have %s",get_name(&(player.pack[i])));
          txt_write(buffer);
          gotoxy(22,19);
          sprintf(buffer,"I offer you %.0f",price);
          txt_write(buffer);
          gotoxy(22,20); textcolor(15);
          txt_write("Do you wish to sell ?");
          key = inkey();
          while (key != 'Y' && key != 'y' &&
                 key != 'N' && key != 'n') key = inkey();
          if (key == 'Y' || key == 'y') {
            player.pack[i].otype = O_NONE;
            player.gold = player.gold+price;
            }
          textcolor(14); gotoxy(35,24);
          sprintf(buffer,"Gold = %.0f",player.gold);
          txt_write(buffer);
          for (j=17; j<=22; j++) {
            gotoxy(10,j); txt_write("                                                              ");
            }
          option = 13;
        }
    if (option == 11) {
      pItem = inventory(0);
      show_top();
      if (pItem != NULL) {
        if (pItem->otype == O_JEWL)
          price = item_cost(pItem)*.95/mul;
        else {
          price = item_cost(pItem)*.08/mul;
          if (pItem->level >= 0) price /= 2;
          }
        gotoxy(15,18); textcolor(12);
        sprintf(buffer,"Ah, a %s",get_name(pItem));
        txt_write(buffer);
        gotoxy(15,20); textcolor(9);
        switch (u_random(5)) {
          case 0:txt_write("Its pretty dirty, I will give you ");
                 break;
          case 1:txt_write("It looks well used, I will give you ");
                 break;
          case 2:txt_write("It look pretty old, I will give you ");
                 break;
          case 3:txt_write("It looks pretty battered, I will give you ");
                 break;
          case 4:txt_write("There is not much market for that, I will give you ");
                 break;
          }
        sprintf(buffer,"%.0f",price);
        txt_write(buffer);
        gotoxy(15,21); txt_write("Do you wish to sell it ?");
        key = inkey();
        if (key == 'Y' || key == 'y') {
          player.gold = player.gold+price;
          if (inv_item != 0) player.invent[inv_item].otype = O_NONE;
          }
        }
      show_top();
      }
    }
  } /* void pawn(char* name, byte city) */
