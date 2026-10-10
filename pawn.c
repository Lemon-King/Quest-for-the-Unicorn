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

void pawn(char* name, byte city) {
  int option;
  double price;
  OBJECT_REC item;
  OBJECT_REC* pItem;
  int j,i;
  char buffer[80];
  char key;

  void show_top() {
    int j;
    int pos;
    char buffer2[80];
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    pos = 1;
    for (i=1; i<=10; i++) {
      if (player.pawn[city][i].otype != O_NONE) {
        gotoxy(22,pos+2);
        strcpy(buffer2,player.pawn[city][i].name);
        for (j=0; j<strlen(buffer2); j++)
          if (buffer2[j] == '_') buffer2[j] = ' ';
        sprintf(buffer,"%2d  %s",pos,buffer2);
        txt_write(buffer);
        gotoxy(50,i+2);
        sprintf(buffer,"%6.0f",buy_price(item_cost(&(player.pawn[city][i]))));
        txt_write(buffer);
        pos++;
        }
      }
    gotoxy(22,14); txt_write("11  Sell an item");
    gotoxy(22,15); txt_write("12  Identify an item");
    gotoxy(22,16); txt_write("13  Sell from Pack");
    gotoxy(22,17); txt_write("14  Identify from Pack");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %d",get_gold());
    txt_write(buffer);
  }

  double sell_price(OBJECT_REC* item) {
    double price;
    double discount;
    price = item_cost(item);
    if (item->otype == O_JEWL) {
      price *= 0.95;
      return price;
      }
    price *= 0.08;
    if (item->level > 0) price /= 2.0;
    discount = 30.0 * (get_skill(SK_CHARM)/100.0);
    discount = 1.0 + (discount / 100.0);
    if (player.sex == 'F') discount += 0.02;
    if (player.stat[6] >= 0 && player.stat[6] <= 7) discount -= .16;
    if (player.stat[6] >= 8 && player.stat[6] <= 11) discount -= .10;
    if (player.stat[6] >= 12 && player.stat[6] <= 14) discount -= .06;
    if (player.stat[6] >= 17 && player.stat[6] <= 18) discount += .02;
    if (player.stat[6] >= 19 && player.stat[6] <= 20) discount += .04;
    if (player.stat[6] >= 21 && player.stat[6] <= 23) discount += .06;
    if (player.stat[6] >= 24 && player.stat[6] <= 99) discount += .10;
    if (classes[player.class-1].flags & CF_NOBLE) discount += 0.15;
    price = price * discount;
    return price;
    }

  pItem = &item;
  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,19); textcolor(10);
    txt_write("Which item would you like (<ESC> to leave) ?        ");
    gotoxy(60,19); textcolor(15);
    strcpy(buffer,"");
    if (p_read(buffer) == 0) {
      sscanf(buffer,"%d",&option);
      } else option = 0;
    for (i=18; i<=23; i++) {
      gotoxy(10,i); txt_write("                                                                    ");
      }
    if (option>0 && option<11 && player.pawn[city][option].otype != O_NONE) {
      item = player.pawn[city][option];
      gotoxy(15,19); textcolor(12);
      sprintf(buffer,"Ah, a %s A fine selection!",item.name);
      txt_write(buffer);
      price = buy_price(item_cost(&item));
      if (haggle(price,item)) {
        for (i=option; i<10; i++) player.pawn[city][i] = player.pawn[city][i+1];
        player.pawn[city][10].otype = O_NONE;
        }
      show_top();
      }
    if (option == 12) {
      pItem = inventory(0);
      show_top();
      if (pItem != NULL && pItem->otype != O_NONE) {
        gotoxy(15,19); textcolor(12);
        price = rcs_trunc(item_cost(pItem) * 0.08);
        sprintf(buffer,"To identify a %s",get_name(pItem));
        txt_write(buffer);
        gotoxy(15,20); textcolor(14);
        sprintf(buffer," will cost %.0f Gold",price);
        txt_write(buffer);
        if (price>get_gold()) {
          gotoxy(15,21);
          txt_write("You do not have that much!! (press a key)");
          key = inkey();
          }
        else {
          gotoxy(15,21); textcolor(10);
          txt_write("Do you wish to identify it ? ");
          key = inkey();
          if (key == 'y' || key == 'Y') {
            sub_gold(price);
            pItem->level = -1;
            if (pItem->effect == E_MUTA) mutable_set_name(pItem);
            gotoxy(15,22); textcolor(15);
            sprintf(buffer,"It is a %s (press a key)",get_name(pItem));
            txt_write(buffer);
            key = inkey();
            }
          }
        }
      show_top();
      }
    if (option == 13)
      for (i=1; i<=32; i++)
        if (player.pack[i].otype != O_NONE) {
          price = sell_price(&(player.pack[i]));
	  if (price < 1) price = 1;
          textcolor(11); gotoxy(22,19);
          sprintf(buffer,"You have ");
          txt_write(buffer);
          itemColor(&(player.pack[i]));
          sprintf(buffer,"%s",get_name(&(player.pack[i])));
          txt_write(buffer);
          textcolor(11);
          gotoxy(22,20);
          sprintf(buffer,"I offer you %.0f",price);
          txt_write(buffer);
          gotoxy(22,21); textcolor(15);
          txt_write("Do you wish to sell ?");
          key = inkey();
          while (key != 'Y' && key != 'y' &&
                 key != 'N' && key != 'n') key = inkey();
          if (key == 'Y' || key == 'y') {
            player.pack[i].otype = O_NONE;
            add_gold(price);
            stats.counts[STAT_ITEMS_SOLD]++;
            stats.counts[STAT_SOLD_GOLD] += price;
            if (price > stats.counts[STAT_LARGEST_SALE]) stats.counts[STAT_LARGEST_SALE] = price;
            }
          textcolor(14); gotoxy(35,24);
          sprintf(buffer,"Gold = %d",get_gold());
          txt_write(buffer);
          for (j=18; j<=23; j++) {
            gotoxy(10,j); txt_write("                                                                    ");
            }
          option = 13;
        }
    if (option == 14)
      for (i=1; i<=32; i++)
        if (player.pack[i].otype != O_NONE && player.pack[i].level >= 0) {
          gotoxy(15,19); textcolor(12);
          price = rcs_trunc(item_cost(&(player.pack[i])) * 0.08);
          sprintf(buffer,"To identify a %s",get_name(&(player.pack[i])));
          txt_write(buffer);
          gotoxy(15,20); textcolor(14);
          sprintf(buffer," will cost %.0f Gold",price);
          txt_write(buffer);
          if (price>get_gold()) {
            gotoxy(15,21);
            txt_write("You do not have that much!! (press a key)");
            key=inkey();
            }
          else {
            gotoxy(15,21); textcolor(10);
            txt_write("Do you wish to identify it ? ");
            key = inkey();
            if (key == 'y' || key == 'Y') {
              sub_gold(price);
              player.pack[i].level = -1;
              if (player.pack[i].effect == E_MUTA) mutable_set_name(&(player.pack[i]));
              gotoxy(15,22); textcolor(15);
              sprintf(buffer,"It is a %s (press a key)",get_name(&(player.pack[i])));
              txt_write(buffer);
              key = inkey();
              }
            }
          textcolor(14); gotoxy(35,24);
          sprintf(buffer,"Gold = %d",get_gold());
          txt_write(buffer);
          for (j=18; j<=23; j++) {
            gotoxy(10,j); txt_write("                                                                    ");
            }
          option = 14;
        }
    if (option == 11) {
      pItem = inventory(0);
      show_top();
      if (pItem != NULL && pItem->otype != O_NONE) {
        price = sell_price(pItem);
	if (price < 1) price = 1;
        gotoxy(15,19); textcolor(12);
        sprintf(buffer,"Ah, a %s",get_name(pItem));
        txt_write(buffer);
        gotoxy(15,21); textcolor(9);
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
        gotoxy(15,22); txt_write("Do you wish to sell it ?");
        key = inkey();
        if (key == 'Y' || key == 'y') {
          add_gold(price);
          pItem->otype = O_NONE;
          stats.counts[STAT_ITEMS_SOLD]++;
          stats.counts[STAT_SOLD_GOLD] += price;
          if (price > stats.counts[STAT_LARGEST_SALE]) stats.counts[STAT_LARGEST_SALE] = price;
          }
        }
      show_top();
      }
    }
  } /* void pawn(char* name, byte city) */
