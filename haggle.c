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

void haggle(double price,OBJECT_REC item) {
  double oprice;
  double offer;
  char   buffer[80];
  oprice = price;
  while (price != 0) {
    gotoxy(15,23); textcolor(14); txt_write("Your offer ?          ");
    gotoxy(28,23);
    p_read(buffer);
    sscanf(buffer,"%lf",&offer);
    if (offer == 0) price = 0;
    if (offer>=(price-1) && price>0) {
      if (offer>player.gold) {
        gotoxy(15,21); textcolor(15);
        txt_write("But you do not have that much!!");
        price = 0;
        }
      else {
        player.gold -= offer;
        item.level = -1;                  /* Indicates object is known */
        inventory(&item);
        price = 0;
        }
      }
    else if (price>0) {
      if (price<=oprice*0.9) {
        gotoxy(15,21); textcolor(14);
        txt_write("                                                          ");
        gotoxy(15,21); textcolor(14);
        sprintf(buffer,"But I can go no lower than %.0f",price);
        txt_write(buffer);
        }
      else {
        price = price*(1-u_random(5)/100);
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
        sprintf(buffer,"%.0f",price);
        txt_write(buffer);
        }
      }
    }
  } /* void haggle(double price,int item) */

