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

void combat_help() {
  char key;
  textmode(3);
  textcolor(12); gotoxy(31,1);
  txt_writeln("Combat Commands:");
  txt_writeln("");
  textcolor(14);
  txt_writeln("           8 - Move Up                        7 - Move Up Left");
  txt_writeln("           2 - Move Down                      9 - Move Up Right");
  txt_writeln("           4 - Move Left                      1 - Move Down Left");
  txt_writeln("           6 - Move Right                     3 - Move Down Right");
  txt_writeln("           f - Fire Weapon                    q - Quaff a Potion");
  txt_writeln("           g - Get Item                       r - Read a scroll");
  txt_writeln("           H - Show Icons                     R - Show Player Record");
  txt_writeln("           i - Inventory                      T - Throw item");
  txt_writeln("           m - Cast a Magic Spell             u - Use an item");
  txt_writeln("           p - Party Commands                 v - View a direction");
  txt_writeln("           ? - Show list of Commands          V - Sound on/off");
  txt_writeln("           P - Pick up and pack               z - Zap a want");
  txt_writeln("           h - Healing");
  gotoxy(28,24); textcolor(10);
  txt_write("Press any key to continue");
  key = inkey();
  show_screen();
  }

