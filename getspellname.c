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

int get_spell_name(int column,int search,int level,int allign) {
  char spell_name[33];
  char buffer[80];
  int  first;
  int  newone;
  byte key;
  first = column;
  textcolor(15);
  strcpy(spell_name,"");
  newone = 0;
  key = ' ';
  while (key != 13) {
    key = inkey();
    if (key > 31) {
      if (key == 161) strcpy(spell_name,player.fspell[1]);
      if (key == 192) strcpy(spell_name,player.fspell[2]);
      if (key == 163) strcpy(spell_name,player.fspell[3]);
      if (key == 164) strcpy(spell_name,player.fspell[4]);
      if (key == 165) strcpy(spell_name,player.fspell[5]);
      if (key == 222) strcpy(spell_name,player.fspell[6]);
      if (key == 166) strcpy(spell_name,player.fspell[7]);
      if (key == 170) strcpy(spell_name,player.fspell[8]);
      if (key == 168) strcpy(spell_name,player.fspell[9]);
      if (key == 169) strcpy(spell_name,player.fspell[10]);
      if (key < 127) {
        buffer[0] = key;
        buffer[1] = 0;
        gotoxy(column,1); txt_write(buffer); txt_write("_");
        spell_name[strlen(spell_name)+1] = 0;
        spell_name[strlen(spell_name)] = key;
        column++;
        }
      if (search == 1) newone = check_spell_1(spell_name,level,allign,first);
      if (newone != 0) key = 13;
      }
    if (key == 8 && strlen(spell_name) > 0) {
      gotoxy(column-1,1); txt_write(" "); gotoxy(column-1,1);
      column--;
      spell_name[strlen(spell_name)-1] = 0;
      }
    }
  return newone;
  }

