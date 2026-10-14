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

void dungeon_help() {
  char key;
  textmode(3);
  textcolor(12); gotoxy(32,1);
  txt_writeln("Dungeon Commands:");
  textcolor(14);
  txt_writeln("           8 - Move Up                        7 - Move Up Left");
  txt_writeln("           2 - Move Down                      9 - Move Up Right");
  txt_writeln("           4 - Move Left                      1 - Move Down Left");
  txt_writeln("           6 - Move Right                     3 - Move Down Right");
  txt_writeln("           b - Buy from a merchant            q - Quest Log");
  txt_writeln("           c - Close Door                     Q - Quit, NO SAVE");
  txt_writeln("           E - Enter/Exit a ship              R - Show Player Record");
  txt_writeln("           f - Fire Weapon                    s - Search");
  txt_writeln("           g - Get Item                       S - Save and Resume");
  txt_writeln("           H - Show Icons                     t - Talk");
  txt_writeln("           i - Inventory                      T - Throw item");
  txt_writeln("           j - Join a new member              u - Use an item");
  txt_writeln("           J - Jam a door closed              v - View a Direction");
  txt_writeln("           l - Light a Torch                  V - Sound on/off");
  txt_writeln("           L - Show Message Log               w - Say word of Power");
  txt_writeln("           m - Cast a Magic Spell             X - Exit, with SAVE");
  txt_writeln("           n - Take a Nap                                   ");
  txt_writeln("           o - Open a door                    h - Healing");
  txt_writeln("           p - Party commands                 > - Down a level");
  txt_writeln("           P - Pick up and pack               < - Up a level");
  txt_writeln("           a - Attack                         ? - Show list of commands");
  gotoxy(28,24); textcolor(10);
  txt_write("Press any key to continue");
  key = inkey();
  show_screen();
  }

