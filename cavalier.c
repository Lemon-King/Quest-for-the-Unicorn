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

void cavalier(char* name) {
  char flag;
  char key;
  char buffer[80];
  double paid;
  textmode(3); gotoxy(27,1); textcolor(11);
  sprintf(buffer,"Welcome to %s",name);
  txt_write(buffer);
  if (player.class>3 && player.class<9) {
    gotoxy(14,4); textcolor(10);
    txt_write("Your class is not permitted into the Cavalier's Guild");
    gotoxy(14,6); textcolor(14);
    txt_write("Press any key to continue");
    key = inkey();
    }
  if (player.class == 9) {
    if (player.month == 1 && player.cav_paid == 'Y') {
      gotoxy(18,4); textcolor(10);
      txt_writeln("You have already been paid this year!!");
      }
    if (player.month == 1 && player.cav_paid != 'Y') {
      paid = player.level;
      player.gold = player.gold+1000.0*paid;
      gotoxy(18,4); textcolor(10);
      sprintf(buffer,"Salary of %.0f Gold Paid",paid * 1000.0);
      txt_writeln(buffer);
      player.cav_paid = 'Y';
      }
    if (player.month != 1) {
      gotoxy(18,4); textcolor(10);
      txt_writeln("Paychecks are only issued the first month of the year!!");
      }
    gotoxy(18,6); textcolor(14);
    txt_write("Press any key to continue");
    key = inkey();
    }
  flag = ' ';
  if (player.class == 1 && player.level>16) flag = '*';
  if (player.class == 2 && player.level>16) flag = '*';
  if (player.class == 3 && player.level>19) flag = '*';
  if (player.class<4 && flag == ' ') {
    gotoxy(22,4); textcolor(10);
    txt_write("You have not yet proven your worth!!");
    gotoxy(22,6); textcolor(14);
    txt_write("Press any key to continue");
    key = inkey();
    }
  if (player.class<4 && flag == '*') {
    gotoxy(22,4); textcolor(10);
    txt_write("Do you wish to join the Cavaliers ? ");
    key = inkey();
    if (key == 'y') key = 'Y';
    if (key == 'Y') {
      make_c();
      gotoxy(22,4); textcolor(10);
      txt_write("Welcome into the Brotherhood of the Cavaliers");
      delay(1000);
      }
    }
  } /* void cavalier(char* name) */

