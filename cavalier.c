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

void cavalier(char* name) {
  char flag;
  char key;
  char buffer[80];
  int  class;
  char allowed;
  int  i;
  double paid;

  textmode(3); gotoxy(40 - (5 + strlen(name) / 2),1); textcolor(11);
  sprintf(buffer,"Welcome to %s",name);
  txt_write(buffer);

  if (classes[player.class-1].flags & CF_CAVALIER) {
    if (player.month == 1 && player.cav_paid == 'Y') {
      gotoxy(18,4); textcolor(10);
      txt_writeln("You have already been paid this year!!");
      }
    if (player.month == 1 && player.cav_paid != 'Y') {
      paid = player.level;
      add_gold(1000.0*paid);
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
    return;
    }

  class = -1;
  for (i=0; i<NUM_CLASSES; i++)
    if (classes[i].flags & CF_CAVALIER) class = i+1;
  if (class < 0) return;

  allowed = 'N';
  i = 0;
  while (class_changes[i].from != 99) {
    if (class_changes[i].from == player.class && class_changes[i].to == class) allowed = 'Y';
    i++;
    }

  if (allowed == 'N') {
    gotoxy(14,4); textcolor(10);
    txt_write("Your class is not permitted into the Cavalier's Guild");
    gotoxy(14,6); textcolor(14);
    txt_write("Press any key to continue");
    key = inkey();
    }

  flag = ' ';
  if (check_class_change(class)) flag = '*';
  if (allowed == 'Y' && flag == ' ') {
    gotoxy(22,4); textcolor(10);
    txt_write("You have not yet proven your worth!!");
    gotoxy(22,6); textcolor(14);
    txt_write("Press any key to continue");
    key = inkey();
    }
  if (allowed == 'Y' && flag == '*') {
    textcolor(12);
    gotoxy(35,10); txt_write("WARNING!!!");
    textcolor(10);
    gotoxy(10,12); txt_write("Joining the Cavaliers will change your class.  Refer to the");
    gotoxy(10,13); txt_write("documentation on the pros and cons of changing class before");
    gotoxy(10,14); txt_write("selectiong 'Y'es.");
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

