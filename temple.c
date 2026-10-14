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

void temple(char* name) {
  double cost;
  char   buffer[80];
  char   key;
  OBJECT_REC* item;

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    gotoxy(27,3); txt_write("1> Healing"); gotoxy(51,3); txt_write("  100");
    gotoxy(27,4); txt_write("2> Prayer");  gotoxy(51,4); txt_write("  500");
    gotoxy(27,5); txt_write("3> Restore allignment");
    cost = player.align;
    cost = 500*(100-cost);
    sprintf(buffer,"%5.0f",cost);
    gotoxy(51,5); txt_write(buffer);
    gotoxy(27,6); txt_write("4> Remove Curse");
    if (player.class == 5 && player.level > 31) {
      gotoxy(27,7); txt_write("5 > Become a Hierophant");
      }
    gotoxy(27,9); txt_write("0> Leave");
    gotoxy(30,11); txt_write("Option ?");
    textcolor(15); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  show_top();
  key = ' ';
  while (key != '0') {
    key = inkey();
    if (key == '1' && player.gold>=100) {
      if (player.class != 5) player.chp = player.mhp;
      if (player.class == 5) player.chp = player.mhp * 2;
      player.gold = player.gold-100;
      textcolor(11);
      gotoxy(27,12); txt_write("Healed");
      delay(1000);
      }
    if (key == '2' && player.gold>=500) {
      if (player.class != 5) player.cmana = player.mmana;
      if (player.class == 5) player.cmana = player.mmana * 2;
      if (player.class == 8) player.cmana = player.mmana * 2;
      player.gold = player.gold-500;
      if (player.mmana != 0) {
        textcolor(11);
        gotoxy(27,12); txt_write("Mana Increased");
        delay(1000);
        }
      }
    if (key == '3' && player.gold>cost) {
      player.gold = player.gold-cost;
      player.align = 100;
      textcolor(11);
      gotoxy(27,12); txt_write("Alignment Restored");
      delay(1000);
      }
    if (key == '4') {
      item = inventory(NULL);
      show_top();
      if (item->plus >= 0) {
        gotoxy(27,13); textcolor(9); txt_write("That Item is not cursed");
        delay(1000);
        } else {
        cost = abs(item->plus) * 1000;
        sprintf(buffer,"Item will cost %.0f gold to uncurse",cost);
        gotoxy(27,13); textcolor(15); txt_write(buffer);
        if (cost > player.gold) {
          gotoxy(27,14); textcolor(12); txt_write("You do not have enough gold!!!");
          } else {
          gotoxy(27,15); textcolor(11); txt_write("Do you wish to uncurse it? (Y/N)");
          while (key != 'Y' && key != 'N') {
            key = inkey();
            if (key == 'n') key = 'N';
            if (key == 'y') key = 'Y';
            }
          if (key == 'Y') {
            item->plus = 0;
            player.gold -= cost;
            gotoxy(27,16); textcolor(9); txt_write("Curse has been removed.");
            } else {
            gotoxy(27,16); textcolor(15); txt_write("Maybe next time.");
            }
          }
        delay(2500);
        }
      }
    if (player.class == 5 && player.level>31 && key == '5') {
      make_h();
      textcolor(11);
      gotoxy(27,12); txt_write("Now a Hierophant");
      delay(1000);
      }
    show_top();
    }
  } /* void temple(char* name) */
