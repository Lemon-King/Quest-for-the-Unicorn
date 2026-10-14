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

int castspell(int spell_num) {
  int col,row;
  char flag;
  int  newone;
  int  allign;
  int  level;

  int get_spell_name(int column,int search) {
    byte key;
    char buffer[80];
    char spell_name[33];
    int first;

    void check_spell_1() {
      int i;
      int count;
      int found = 0;
      byte key;
      char buffer[80];
      count = 0;
      newone = 0;
      for (i=1; i<=NO_OF_SPELLS; i++)
        if (has_spell(i) != 0)
          if (strncasecmp(spell_name,spells[i].name,strlen(spell_name))  == 0) {
            count++;
            found = i;
            }
      if (count != 1) newone = 0;
      else {
        clear_prompt();
        sprintf(buffer,"Spell ? %s_",spells[found].name);
        prompt(buffer);
        key = inkey();
        if (key == 8) {
          clear_prompt();
          sprintf(buffer,"Spell ? %s_",spell_name);
          prompt(buffer);
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
      }

    void show_list() {
      int  i;
      char key;
      char buffer[80];
      textmode(3);
      col = 1;
      row = 3;
      gotoxy(1,2); textcolor(2);
      txt_write("Lvl Mana Name");
      gotoxy(40,2);
      txt_write("Lvl Mana Name");
      textcolor(14);
      for (i=1; i<=NO_OF_SPELLS; i++)
        if (has_spell(i) != 0) {
          gotoxy(col,row);
          sprintf(buffer,"%3d %4d %s",spells[i].level,spells[i].mana,
                  spells[i].name);
          txt_write(buffer);
          row++;
          if (row == 25) {
            row = 3;
            col = 40;
            }
          }
      key = inkey();
      graphmode();
      show_map();
      show_sm_map();
      show_side();
      show_player();
      }

    newone = 0;
    first = column;
    textcolor(15);
    strcpy(spell_name,"");
    if (spell_num != 0) strcpy(spell_name,player.fspell[spell_num]);
    key = 0;
    while (key != 13) {
      if (spell_num == 0) key = inkey();
        else spell_num = 0;
      if (key == '?') {
        show_list();
        key = 3;
        clear_prompt();
        sprintf(buffer,"Spell ? %s_",spell_name);
        prompt(buffer);
        }
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
          spell_name[strlen(spell_name) + 1] = 0;
          spell_name[strlen(spell_name)] = key;
          sprintf(buffer,"Spell ? %s_",spell_name);
          prompt(buffer);
          }
        if (search == 1) check_spell_1();
        if (newone != 0) key = 13;
        }
      if (key == 8 && strlen(spell_name) > 0) {
        spell_name[strlen(spell_name) - 1] = 0;
          clear_prompt();
          sprintf(buffer,"Spell ? %s_",spell_name);
          prompt(buffer);
        }
      }
    return newone;
    }

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
  if (player.class == 2) {
    allign = 4;
    level = player.level - 8;
    }
  if (player.class == 3) {
    allign = 5;
    level = player.level - 7;
    }
  flag = ' ';
  while (flag == ' ') {
    clear_prompt();
    prompt("Spell ? _");
    newone = get_spell_name(22,1);
    flag = '*';
    }
  if (newone != 0) strcpy(player.fspell[1],spells[newone].name);
  clear_prompt();
  return newone;
  }

