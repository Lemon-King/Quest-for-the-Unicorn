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

void school(char* name) {
  int option;
  double price;
  int i;
  char buffer[80];

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    gotoxy(5,3); textcolor(14);
    txt_writeln("1> Archery               5,000   9> Medical Practices          7,500");
    txt_writeln("    2> Edge Weaponry         5,000  10> Alchemy                    9,750");
    txt_writeln("    3> Pole Weaponry         5,000  11> Horsemanship               2,500");
    txt_writeln("    4> Hunting               4,000  12> Nautical Navigation        4,500");
    txt_writeln("    5> Scouting              3,500  13> Psychic Awareness         25,000");
    txt_writeln("    6> Communication         2,500  14> Public Relations           3,250");
    txt_writeln("    7> Magical Incantation  20,000  15> Wilderness Survival        3,500");
    txt_writeln("    8> The Art of Wizardry  20,000  16> Combat Techniques          5,000");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,17); textcolor(10);
    txt_write("Which course would you like to take (0 to leave) ?        ");
    gotoxy(66,17); textcolor(15);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    for (i=17; i<=22; i++) {
      gotoxy(10,i); txt_write("                                                          ");
      }
    if (option>0 && option<17) {
      switch (option) {
        case  1:price = 5000; break;
        case  2:price = 5000; break;
        case  3:price = 5000; break;
        case  4:price = 4000; break;
        case  5:price = 3500; break;
        case  6:price = 2500; break;
        case  7:price = 20000; break;
        case  8:price = 20000; break;
        case  9:price = 7500; break;
        case 10:price = 9750; break;
        case 11:price = 2500; break;
        case 12:price = 4500; break;
        case 13:price = 25000; break;
        case 14:price = 3250; break;
        case 15:price = 3500; break;
        case 16:price = 5000; break;
        }
      if (price>player.gold) {
        gotoxy(15,19); textcolor(12);
        txt_write("But you do not have enough gold for that course!");
        }
      else {
        player.gold -= price;
        gotoxy(15,19); textcolor(15);
        txt_write("Course Taken!!");
        delay(1000);
        player.skill[option]++;
        show_top();
        }
      }
    }
  } /* void school(char* name) */
