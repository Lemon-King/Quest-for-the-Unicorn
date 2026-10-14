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

void tavern(char* name) {
  int option;
  double price;
  int  i;
  char buffer[80];

  void move_player() {
    switch (player.city) {
      case 14:
           if (player.x>51 && player.x<55 && player.y>15 && player.y<19)
             switch (u_random(5)) {
               case 0:
                   player.x = 40;
                   player.y = 17+2*u_random(4);
                   break;
               case 1:
                   player.x = 61;
                   player.y = 17+2*u_random(4);
                   break;
               case 2:
                   player.y = 33;
                   player.x = 41+2*u_random(11);
                   break;
               case 3:
                   player.y = 25;
                   player.x = 40+2*u_random(5);
                   break;
               case 4:
                   player.y = 25;
                   player.x = 53+2*u_random(5);
                   break;
               }
           break;
      case 13:
           if (player.x>57 && player.x<61 && player.y>11 && player.y<15)
             switch (u_random(3)) {
               case 0:
                   player.y = 18;
                   player.x = 52+3*u_random(5);
                 break;
               case 1:
                   player.y = 24;
                   player.x = 52+3*u_random(5);
                 break;
               case 2:
                   player.y = 26;
                   player.x = 52+3*u_random(5);
                 break;
               }
           break;
      case 17:
           if (player.x>41 && player.x<45 && player.y>20 && player.y<24) {
             player.y = 22;
             player.x = 12+2*u_random(12);
             }
           break;
      case 16:
           if (player.x>26 && player.x<30 && player.y>52 && player.y<56)
             switch (u_random(2)) {
               case 0:
                   player.y = 62;
                   player.x = 9+2*u_random(8);
                 break;
               case 1:
                   player.y = 70;
                   player.x = 9+2*u_random(10);
                 break;
               }
           if (player.x>18 && player.x<22 && player.y>82 && player.y<86)
             switch (u_random(4)) {
               case 0:
                   player.y = 74;
                   player.x = 18+2*u_random(7);
                 break;
               case 1:
                   player.y = 82;
                   player.x = 22+2*u_random(5);
                 break;
               case 2:
                   player.x = 9;
                   player.y = 74+2*u_random(10);
                 break;
               case 3:
                   player.x = 17;
                   player.y = 86+2*u_random(4);
                 break;
               }
           break;
         }
    player.map_x = player.x-8;
    player.map_y = player.y-8;
    if (player.map_x<1) player.map_x = 1;
    if (player.map_y<1) player.map_y = 1;
    if (player.map_x>84) player.map_x = 84;
    if (player.map_y>84) player.map_y = 84;
    restoreScreen();
    show_screen();
    saveScreen();
    }

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    gotoxy(5,3); textcolor(14);
    txt_writeln("1> Merchants Meal            4   7> Room, 1 night                 20");
    txt_writeln("    2> Rich Meal                 6   8> Room, 1 Week                 120");
    txt_writeln("    3> Beer                      2   9> Room, 1 Month                500");
    txt_writeln("    4> Ale                       2  10> Gamble                          ");
    txt_writeln("    5> Mead                      2                                      ");
    txt_writeln("    6> Wine                      2                                      ");
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
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
      gotoxy(10,i); txt_write("                                                                ");
      }
    if (option == 10) { 
      gamble(); 
      show_top(); 
      }
    if (option>0 && option<10) {
      switch (option) {
        case 1:price = 4; break;
        case 2:price = 6; break;
        case 3:price = 2; break;
        case 4:price = 2; break;
        case 5:price = 2; break;
        case 6:price = 2; break;
        case 7:price = 20; break;
        case 8:price = 120; break;
        case 9:price = 500; break;
        }
      if (price>player.gold) {
        gotoxy(15,19); textcolor(12);
        txt_write("But you do not have enough gold!");
        }
      else {
        player.gold -= price;
        switch (option) {
          case 1:
                if (player.health<100) player.health = player.health+10;
                if (player.chp<player.mhp) player.chp = player.chp+10;
                 break;
          case 2:
                 if (player.health<100) player.health = player.health+20;
                 if (player.chp<player.mhp) player.chp = player.chp+20;
                 break;
          case 3:
                 if (player.health<100) player.health = player.health+3;
                 if (player.chp<player.mhp) player.chp = player.chp+1;
                 break;
          case 4:
                 if (player.health<100) player.health = player.health+3;
                 if (player.chp<player.mhp) player.chp = player.chp+1;
                 break;
          case 5:
                 if (player.health<100) player.health = player.health+3;
                 if (player.chp<player.mhp) player.chp = player.chp+1;
                 break;
          case 6:
                 if (player.health<100) player.health = player.health+3;
                 if (player.chp<player.mhp) player.chp = player.chp+1;
                 break;
          case 7:
                 if (player.health<100) player.health = 100;
                 if (player.chp<player.mhp) player.chp = player.mhp;
                 if (player.cmana<player.mmana) player.cmana = player.mmana;
                 move_player();
                 player.day = player.day+1;
                 if (player.day>31) {
                   new_month();
/*
                   player.day = player.day-31;
                   player.month = player.month+1;
                   player.interest = player.bank * .005;
                   player.bank += player.interest;
                   if (player.month == 13) {
                     player.month = 1;
                     player.age = player.age+1;
                     player.cav_paid = 'N';
                     }
*/
                   }
                 option = 0;
                 break;
          case 8:
                 if (player.health<100) player.health = 100;
                 player.chp = player.mhp*2;
                 if (player.cmana<player.mmana) player.cmana = player.mmana;
                 move_player();
                 player.day = player.day+7;
                 if (player.day>31) {
                   new_month();
/*
                   player.day = player.day-31;
                   player.month = player.month+1;
                   player.interest = player.bank * .005;
                   player.bank += player.interest;
                   if (player.month == 13) {
                     player.month = 1;
                     player.age = player.age+1;
                     player.cav_paid = 'N';
                     }
*/
                   }
                   option = 0;
                 break;
          case 9:
                 if (player.health<100) player.health = 100;
                 player.chp = player.mhp*3;
                 if (player.cmana<player.mmana) player.cmana = player.mmana;
                 move_player();
                 player.day = player.day+31;
                 if (player.day>31) {
                   new_month();
/*
                   player.day = player.day-31;
                   player.month = player.month+1;
                   player.interest = player.bank * .005;
                   player.bank += player.interest;
                   if (player.month == 13) {
                     player.month = 1;
                     player.age = player.age+1;
                     player.cav_paid = 'N';
                     }
*/
                   }
                 option = 0;
                 break;
          }
        show_top();
        }
      }
    }
  } /* void tavern(char* name) */
