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

void new_spell() {
  int i;
  int col,row;
  char flag;
  int  newone;
  int  allign = 0;
  int  level = 0;
  int  no_spells;
  char buffer[80];
  no_spells = 0;
  if (player.class == 6) {
    allign = 6;
    level = player.level;
    }  
  if (player.class == 4) {
    allign = 4;
    level = player.level;
    } 
  if (player.class == 5) {
    allign = 5;
    level = player.level;
    }
  if (player.class == 8) {
    allign = 5;
    level = player.level;
    }
  if (player.class == 2) {
    allign = 4;
    level = player.level - 8;
    }
  if (player.class == 3) {
    allign = 5; 
    level = player.level - 7;
    }
  textmode(3);
  col = 1;
  row = 3;
  gotoxy(1,2); textcolor(2); 
  txt_write("Lvl Mana Name");
  gotoxy(40,2);
  txt_write("Lvl Mana Name"); 
  textcolor(14);
  for (i=1; i<=NO_OF_SPELLS; i++)
    if (spells[i].level <= level && has_spell(i) == 0 &&
        spells[i].allign == allign) {
      no_spells++;
      gotoxy(col,row);
      sprintf(buffer,"%3d %4d %s",spells[i].level,mana_cost(spells[i].mana),
              spells[i].name);
      txt_write(buffer);
      row++;
      if (row == 25) {
        row = 2;
        col = 40;
        }
      }
  if (no_spells != 0) { 
    flag = ' '; 
    while (flag == ' ') {
      gotoxy(1,1); textcolor(11); txt_write("Select which spell ?          ");
      gotoxy(22,1); txt_write("_");
      newone = get_spell_name(22,1,level,allign);
      if (newone != 0) flag = '*';
      }
    i = 1;
    while (player.spell[i] != 0) i++;
    player.spell[i] = newone;
    }
  }

