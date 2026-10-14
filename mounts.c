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

void mounts(char* name) {
  double cost = 0;
  int item = 0;
  int slot;
  int i;
  char key =' ';
  char buffer[80];

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    gotoxy(27,3); txt_write("1> Horse"); gotoxy(51,3); txt_write("  1000");
    gotoxy(27,4); txt_write("2> Centaur"); gotoxy(51,4); txt_write(" 75000");
    gotoxy(27,5); txt_write("3> Pegasus"); gotoxy(51,5); txt_write("125000");
    gotoxy(27,6); txt_write("4> Nightmare"); gotoxy(51,6); txt_write("160000");
    gotoxy(27,7); txt_write("5> Green Dragon"); gotoxy(51,7); txt_write("450000");
    gotoxy(27,8); txt_write("6> Platinum Dragon"); gotoxy(51,8); txt_write("750000");
    gotoxy(27,10); txt_write("0> Leave");
    gotoxy(30,12); txt_write("Option ?");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  show_top();
  while (key != '0') {
    gotoxy(30,12); textcolor(14); txt_write("Option ?");
    key = inkey();
    if (key>='1' && key<='6') {
      switch (key) {
        case '1':item = 121; cost = 1000; break;
        case '2':item = 95;  cost = 75000; break;
        case '3':item = 72;  cost = 125000; break;
        case '4':item = 64;  cost = 160000; break;
        case '5':item = 109; cost = 450000; break;
        case '6':item = 113; cost = 750000; break;
        }
      if (cost>player.gold) {
        gotoxy(30,14); textcolor(4);
        txt_write("You do not have enough gold!!!!");
        delay(1500);
        }
      else {
       slot = 0;
       for (i=1; i<=5; i++)
         if (slot == 0 && player.party[i].hp == 0) slot = i;
       if (slot != 0) {
         player.party[slot] = monsters[item];
         player.party[slot].hp = u_random(player.party[slot].hp)+1;
         player.party[slot].time = 255;
         player.party[slot].exp = needed(player.party[slot].level)*10;
         player.gold = player.gold-cost;
         gotoxy(30,14); textcolor(11);
         txt_write("Mount Obtained.");
         delay(1500);
         }
       else {
         gotoxy(30,14); textcolor(11);
         txt_write("No room in party for mount.");
         delay(1500);
         }
       }
      }
      show_top();
    }
  player.mount = 0; player.peg = 0;
  for (i=1; i<=5; i++)
    if (player.party[i].hp>0) {
      if (player.party[i].sprite == 133) player.peg = 1;
      if (player.party[i].sprite == 148) player.mount = 1;
      if (player.party[i].sprite == 131) player.mount = 1;
      if (player.party[i].sprite == 132) player.mount = 1;
      if (player.party[i].sprite == 138) player.mount = 1;
      if (player.party[i].sprite == 155) player.peg = 1;
      if (player.party[i].sprite == 159) player.peg = 1;
      if (player.peg == 1) player.mount = 1;
    }
  }
