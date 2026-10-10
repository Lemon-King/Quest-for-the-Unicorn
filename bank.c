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

void bank(char* name) {
  double amt;
  char   buffer[80];
  char   key;

  char* find_name(int r,int x,int y) {
    int i;
    i = 0;
    while (i >= 0) {
      if (links[i].region == r &&
          links[i].x == x &&
          links[i].y == y) return links[i].name;
      i++;
      if (links[i].region > 90) i = -1;
      }
    return NULL;
    }

  void show_top() {
    int i;
    int l;
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    sprintf(buffer,"Your account contains %d gold",player.bank);
    gotoxy(25,4); txt_write(buffer);
    sprintf(buffer,"Interest paid last period: %d gold",player.interest);
    gotoxy(25,5); txt_write(buffer);
    textcolor(11); gotoxy( 15,7);
    txt_write("House               Principle    Interest    Payment");
    l = 8; textcolor(2);
    for (i=0; i<5; i++) {
      if (player.houses[i].region != 0) {
        gotoxy(15,l); txt_write(find_name(player.houses[i].region,
                                          player.houses[i].rx,
                                          player.houses[i].ry));
        sprintf(buffer,"%.0f",player.houses[i].mortgage);
        gotoxy(35,l); txt_write(buffer);
        sprintf(buffer,"%.0f",player.houses[i].interest);
        gotoxy(48,l); txt_write(buffer);
        sprintf(buffer,"%.0f",player.houses[i].payment);
        gotoxy(60,l); txt_write(buffer);
        }
      }
    textcolor(14);
    gotoxy(34,14); txt_write("1> Deposit");
    gotoxy(34,15); txt_write("2> Withdrawal");
    gotoxy(34,16); txt_write("<ESC> Leave");
    gotoxy(37,17); txt_write("Option ?");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %d",get_gold());
    txt_write(buffer);
    }

  show_top();
  key = ' ';
  while (key != '0') {
    key = inkey();
    if (key == 27) key = '0';
    if (key == '1' && get_gold() > 0) {
      gotoxy(30,19); textcolor(14);
      txt_write("How much to deposit ?");
      strcpy(buffer,"");
      if (p_read(buffer) == 0) {
        sscanf(buffer,"%lf",&amt);
        } else amt = 0;
      if (amt <= get_gold()) {
        player.bank += amt;
        sub_gold(amt);
        show_top();
        } else {
        gotoxy(30,20); textcolor(12);
        txt_write("You do not have that much!!!");
        delay(5000);
        show_top();
        }
      }
    if (key == '2' && player.bank > 0) {
      gotoxy(30,19); textcolor(14);
      txt_write("How much to withdraw ?");
      strcpy(buffer,"");
      if (p_read(buffer) == 0) {
        sscanf(buffer,"%lf",&amt);
        } else amt = 0;
      if (amt <= player.bank) {
        player.bank -= amt;
        add_gold(amt);
        show_top();
        } else {
        gotoxy(25,20); textcolor(12);
        txt_write("Your account does not have that much!!!");
        delay(5000);
        show_top();
        }
      }
    show_top();
    }
  } /* void temple(char* name) */
