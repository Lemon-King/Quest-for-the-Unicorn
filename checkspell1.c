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

int check_spell_1(char* spell_name,int level,int allign,int first) {
  int i;
  int count;
  int found = 0;
  int newone;
  byte key;
  count = 0;
  newone = 0;
  for (i=1; i<=NO_OF_SPELLS; i++)
    if (spells[i].level <= level && has_spell(i) == 0 &&
        spells[i].allign == allign) {
      if (strncasecmp(spell_name,spells[i].name,strlen(spell_name)) == 0) {
        count++;
        found = i;
        }
      }
  if (count != 1) newone = 0;
  else {
    gotoxy(first,1); txt_write(spells[found].name);
    key = inkey();
    if (key == 8) {
      gotoxy(first,1); txt_write("                                        ");
      gotoxy(first,1); txt_write(spell_name); txt_write("_");
      }
    if (key == 13) newone = found;
    if (key == 161) strcpy(player.fspell[1],spells[found].name);
    if (key == 192) strcpy(player.fspell[2],spells[found].name);
    if (key == 163) strcpy(player.fspell[3],spells[found].name);
    if (key == 164) strcpy(player.fspell[4],spells[found].name);
    if (key == 165) strcpy(player.fspell[5],spells[found].name);
    if (key == 222) strcpy(player.fspell[6],spells[found].name);
    if (key == 166) strcpy(player.fspell[7],spells[found].name);
    if (key == 170) strcpy(player.fspell[8],spells[found].name);
    if (key == 168) strcpy(player.fspell[9],spells[found].name);
    if (key == 169) strcpy(player.fspell[10],spells[found].name);
    }
  return newone;
  }

