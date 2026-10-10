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

void help_item(char* msg,int col_width,int num_rows,int indent) {
  gotoxy(indent+col*col_width,row);
  txt_write(msg);
  row++;
  if (row == num_rows) {
    col++;
    row = 3;
    }
  }

void dungeon_help() {
  textmode(3);
  textcolor(12); gotoxy(32,1);
  txt_writeln("Dungeon Commands:");
  textcolor(14);
  col = 0;
  row = 3;
  help_item("1 - Move down left",26,23,4);
  help_item("2 - Move down",26,23,4);
  help_item("3 - Move down right",26,23,4);
  help_item("4 - Move left",26,23,4);
  help_item("5 - Run",26,23,4);
  help_item("6 - Move right",26,23,4);
  help_item("7 - Move up left",26,23,4);
  help_item("8 - Move up",26,23,4);
  help_item("9 - Move up right",26,23,4);
  help_item("a - Attack",26,23,4);
  help_item("A - Activate",26,23,4);
  help_item("b - Buy from merchant",26,23,4);
  help_item("c - Close door",26,23,4);
  help_item("C - Crafting",26,23,4);
  help_item("E - Enter/exit ship",26,23,4);
  help_item("f - Fire weapon",26,23,4);
  help_item("g - Get item",26,23,4);
  help_item("h - Healing",26,23,4);
  help_item("H - Show icons",26,23,4);
  help_item("i - inventory",26,23,4);
  help_item("j - Join member",26,23,4);
  help_item("J - Jam door closed",26,23,4);
  help_item("l - Light torch",26,23,4);
  help_item("L - Message log",26,23,4);
  help_item("m - Cast magic spell",26,23,4);
#ifdef ASCII
  help_item("M - Mini map",26,23,4);
#endif
  help_item("n - Nap",26,23,4);
  help_item("o - Open door",26,23,4);
  help_item("p - Party commands",26,23,4);
  help_item("P - Pick up and pack",26,23,4);
  help_item("q - Quest log",26,23,4);
  help_item("Q - Quit, NO SAVE",26,23,4);
  help_item("R - Record sheet",26,23,4);
  help_item("s - Search",26,23,4);
  help_item("S - Save and resume",26,23,4);
  help_item("t - Talk",26,23,4);
  help_item("T - Throw",26,23,4);
  help_item("u - Use item",26,23,4);
  help_item("v - View mode",26,23,4);
  help_item("w - Say word of power",26,23,4);
  help_item("x - Transcribe spell",26,23,4);
  help_item("X - Exit with save",26,23,4);
  help_item("> - Down a level",26,23,4);
  help_item("< - Up a level",26,23,4);
  help_item("{ - Save weapon set",26,23,4);
  help_item("[ - Load weapon set",26,23,4);
  help_item("} - Save gear set",26,23,4);
  help_item("] - Load gear set",26,23,4);
  help_item("- - Throw left hand",26,23,4);
  help_item("= - Throw right hand",26,23,4);
  help_item("? - List of commands",26,23,4);
  help_item("",26,23,4);
  help_item("Any other key acts as",26,23,4);
  help_item("rest 1 turn command",26,23,4);

  gotoxy(28,24); textcolor(10);
  txt_write("Press any key to continue");
  inkey();
  show_screen();
  }

