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

void upland_help() {
  char key;
  textmode(3);
  textcolor(12); gotoxy(31,1);
  txt_writeln("Upland Commands:");
  txt_writeln("");
  textcolor(14);
  txt_writeln("                           8 - Move Up");
  txt_writeln("                           2 - Move Down");
  txt_writeln("                           4 - Move Left");
  txt_writeln("                           6 - Move Right");
  txt_writeln("                           7 - Move Up Left");
  txt_writeln("                           9 - Move Up Right");
  txt_writeln("                           1 - Move Down Left");
  txt_writeln("                           3 - Move Down Right");
  txt_writeln("                           e - Eat");
  txt_writeln("                           E - Enter/Exit a ship");
  txt_writeln("                           h - Hunt");
  txt_writeln("                           H - Show Icons");
  txt_writeln("                           R - Show player record");
  txt_writeln("                           Q - Quit, NO SAVE");
  txt_writeln("                           v - View a direction");
  txt_writeln("                           X - Exit, with SAVE");
  txt_writeln("                           > - Enter town, Dungeon");
  txt_writeln("                           ? - Show list of Commands");
  if (has_intrinsic(A_TARD)) {
      txt_writeln("                           T - Tardis Destination Log");
      txt_writeln("                    F1 - F10 - Program Tardis Destination");
      txt_writeln("            <SHIFT> F1 - F10 - Go to Tardis Destination");
    }
  gotoxy(28,24); textcolor(10);
  txt_write("Press any key to continue");
  key = inkey();
  graphmode();
  show_land();
  show_sm_land();
  show_side();
  show_land_player();
  }

