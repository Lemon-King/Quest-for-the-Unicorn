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

void crafting() {
  int i;
  int line;
  char flag;
  char key;
  OBJECT_REC* pItem;
  OBJECT_REC* craft;
  OBJECT_REC* ing[10];
  OBJECT_REC  item;

  void show_screen() {
    int i;
    textmode(3);
    textcolor(15); gotoxy(36,2); txt_write("Crafting");
    textcolor(2); gotoxy(35,4); txt_write("Craft Item:");
    if (craft != NULL && craft->otype != O_NONE) {
      textcolor(3); gotoxy(35,5); txt_write(get_name(craft));
      }
    textcolor(2); gotoxy(34,7); txt_write("Ingredients:");
    for (i=0; i<10; i++) {
      textcolor(3); gotoxy(30,i+8);
      if (ing[i] != NULL && ing[i]->otype != O_NONE)
        txt_write(get_name(ing[i]));
      }

    textcolor(6);
    gotoxy(10,19);
    txt_write("<");
    textcolor(14); txt_write("ESC");
    textcolor(6); txt_write(">quit, <");
    textcolor(14); txt_write("ENTER");
    textcolor(6); txt_write(">Select Craft Item/Ingredient, <");
    textcolor(14); txt_write("M");
    textcolor(6); txt_write(">ake Item");
    }

  char check_recipe(RECIPE rec) {
    int i;
    int j;
    int l;
    char flag;
    char used[10];
    l = 0;
    if (craft->link != rec.craft_item) return 'N';
    for (i=0; i<10; i++)
      if (ing[i] != NULL) used[i] = 'N';
        else used[i] = '-';
    for (i=0; i<10; i++) {
      switch (i) {
        case 0:l = rec.object1; break;
        case 1:l = rec.object2; break;
        case 2:l = rec.object3; break;
        case 3:l = rec.object4; break;
        case 4:l = rec.object5; break;
        case 5:l = rec.object6; break;
        case 6:l = rec.object7; break;
        case 7:l = rec.object8; break;
        case 8:l = rec.object9; break;
        case 9:l = rec.object10; break;
        }
      flag = 'N';
      j = 0;
      while (j < 10) {
        if (used[j] == 'N' && ing[j]->link == l) {
          used[j] = 'Y';
          j = 11;
          flag = 'Y';
          }
        j++;
        }
      if (l != 0 && flag == 'N') return 'N';
      }
    flag = 'Y';
    for (i=0; i<10; i++)
      if (used[i] == 'N') return 'N';
    return 'Y';
    }

  int find_recipe() {
    int i;
    i = 0;
    while (recipes[i].craft_item != 999) {
      if (check_recipe(recipes[i]) == 'Y') return i;
      i++;
      }
    return -1;
    }

  for (i=0; i<10; i++) ing[i] = NULL;
  craft = NULL;
  show_screen();
  line = 5;
  flag = ' ';
  textcolor(14);
  gotoxy(22,line); txt_write("->");
  while (flag == ' ') {
    key = inkey();
    if (key == '2' || key == '.' || key == '>') {
      textcolor(14);
      gotoxy(22,line); txt_write("  ");
      line++;
      if (line == 6) line = 8;
      if (line > 17) line = 5;
      gotoxy(22,line); txt_write("->");
      }
    if (key == '8' || key == ',' || key == '<') {
      textcolor(14);
      gotoxy(22,line); txt_write("  ");
      line--;
      if (line == 7) line = 5;
      if (line < 5) line = 17;
      gotoxy(22,line); txt_write("->");
      }
    if (key == 'M') flag = 'Y';
    if (key == 'm') flag = 'Y';
    if (key == 13) {
      pItem = unpack();
      if (pItem != NULL) {
        for (i=0; i<10; i++)
          if (pItem == ing[i]) ing[i] = NULL;
        if (pItem == craft) craft = NULL;
        if (line == 5) craft = pItem;
          else ing[line-8] = pItem;
        }
      show_screen();
      textcolor(14);
      gotoxy(22,line); txt_write("->");
      }
    if (key == 27) {
      flag = '*';
      }
    }
  if (flag == 'Y') {
    line = find_recipe();
    if (line >= 0) {
      for (i=0; i<10; i++) if (ing[i] != NULL) ing[i]->otype = O_NONE;
      pItem = find_linked_item(recipes[line].object);
      if (pItem != NULL) {
        item = *pItem;
        item.level = -1;
        inventory(&item);
        }
      } else {
      textcolor(12);
      gotoxy(20,21);
      txt_write("KABBBBBOOOOOOOOOOOOOOOOOOOOOOOMMMMMMMMMM");
      delay(5000);
      player.chp -= u_random(player.mhp);
      }
    }

  }
