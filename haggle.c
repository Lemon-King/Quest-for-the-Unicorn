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

int haggle(double price,OBJECT_REC item) {
  int32_t oprice;
  int32_t offer;
  int32_t lowest;
  int32_t merchant;
  int32_t lastoffer;
  double sk;
  int32_t diff;
  char   buffer[80];
  oprice = price;
  sk = get_skill(SK_CHARM);
  sk /= 200.0;
  lowest = price * (.9 - sk);
  merchant = price;
  lastoffer = 0;
  offer = price;
  while (price != 0) {
    gotoxy(15,23); textcolor(14); txt_write("Your offer ?          ");
    gotoxy(28,23);
    sprintf(buffer,"%d",offer);
    if (p_read(buffer) == 0) {
      sscanf(buffer,"%d",&offer);
      } else offer = 0;
    if (offer == 0) price = 0;
    if (offer > 0 && offer>get_gold()) {
      gotoxy(15,21); textcolor(15);
      txt_write("But you do not have that much!!");
      }
    else if (offer >= merchant && price>0) {
      if (offer < oprice) add_skill(SK_CHARM,2); else add_skill(SK_CHARM,1);
      sub_gold(offer);
      item.level = -1;                  /* Indicates object is known */
      inventory(&item);
      return -1;
      price = 0;
      }
    else if (price>0) {
      if (offer<lowest) {
        gotoxy(15,21); textcolor(14);
        txt_write("                                                          ");
        gotoxy(15,21); textcolor(14);
        sprintf(buffer,"Please do not insult me!");
        txt_write(buffer);
        sprintf(buffer,"%d",offer);
        }
      else if (offer<=lastoffer) {
        gotoxy(15,21); textcolor(14);
        txt_write("                                                          ");
        gotoxy(15,21); textcolor(14);
        sprintf(buffer,"You do know how to negotiate?");
        txt_write(buffer);
        sprintf(buffer,"%d",offer);
        }
      else {
        lastoffer = offer;
        diff = 0.10 * merchant;
        diff = u_random(diff);
        if (diff < 1) diff = 1;
        merchant = merchant - diff;
        if (merchant < lowest) merchant = lowest;
        if (merchant  <= lastoffer) {
          if (offer < oprice) add_skill(SK_CHARM,2); else add_skill(SK_CHARM,1);
          sub_gold(offer);
          item.level = -1;                  /* Indicates object is known */
          inventory(&item);
          return -1;
          } else {
          gotoxy(15,21); textcolor(14);
          txt_write("                                                          ");
          gotoxy(15,21); textcolor(14);
          switch (u_random(5)) {
            case 0:txt_write("Don't you think that a little low, how about ");
                   break;
            case 1:txt_write("I have a wife & kids to feed, how about ");
                   break;
            case 2:txt_write("But look at the workmanship, say ");
                   break;
            case 3:txt_write("But there is none better anywhere, say ");
                   break;
            case 4:txt_write("Must I starve to serve thee, For you ");
                   break;
            }
          sprintf(buffer,"%d",merchant);
          txt_write(buffer);
          }
        }
      }
    }
    return 0;
  } /* void haggle(double price,int item) */

