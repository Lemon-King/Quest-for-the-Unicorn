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

void crafting() {
  int i;
  int tmp;
  int line;
  char flag;
  char key;
  int  recipe_book[1000];
  int  num_recipes;
  int  current_recipe;
  OBJECT_REC* pItem;
  OBJECT_REC* craft;
  OBJECT_REC* ing[10];
  OBJECT_REC  item;
  char name1[1024];
  char name2[1024];

  int already_taken(OBJECT_REC* item) {
    int i;
    for (i=0; i<10; i++) 
      if (ing[i] != NULL && ing[i] == item) return -1;
    return 0;
    }

  OBJECT_REC* get_item(int link) {
    int i;
    for (i=1; i<20; i++)
      if (player.invent[i].otype != O_NONE &&
          player.invent[i].link == link &&
          already_taken(&(player.invent[i])) == 0)
        return &(player.invent[i]);
    for (i=1; i<33; i++)
      if (player.pack[i].otype != O_NONE &&
          player.pack[i].link == link &&
          already_taken(&(player.pack[i])) == 0)
        return &(player.pack[i]);
    return NULL;
    }

  void auto_add() {
    int recipe;
    recipe = recipe_book[current_recipe];
    craft = (recipes[recipe].craft_item > 0) ? get_item(recipes[recipe].craft_item) : NULL;
    ing[0] = (recipes[recipe].object1 > 0) ? get_item(recipes[recipe].object1) : NULL;
    ing[1] = (recipes[recipe].object2 > 0) ? get_item(recipes[recipe].object2) : NULL;
    ing[2] = (recipes[recipe].object3 > 0) ? get_item(recipes[recipe].object3) : NULL;
    ing[3] = (recipes[recipe].object4 > 0) ? get_item(recipes[recipe].object4) : NULL;
    ing[4] = (recipes[recipe].object5 > 0) ? get_item(recipes[recipe].object5) : NULL;
    ing[5] = (recipes[recipe].object6 > 0) ? get_item(recipes[recipe].object6) : NULL;
    ing[6] = (recipes[recipe].object7 > 0) ? get_item(recipes[recipe].object7) : NULL;
    ing[7] = (recipes[recipe].object8 > 0) ? get_item(recipes[recipe].object8) : NULL;
    ing[8] = (recipes[recipe].object9 > 0) ? get_item(recipes[recipe].object9) : NULL;
    ing[9] = (recipes[recipe].object10 > 0) ? get_item(recipes[recipe].object10) : NULL;
    }

  char* next_nl(char* buffer) {
    while (*buffer != 0 && *buffer != '\n') buffer++;
    return buffer;
    }

  void show_recipe() {
    int i;
    char buffer[1024];
    char *pChar1;
    char *pChar2;
    if (num_recipes == 0) return;
    recipe_string(recipe_book[current_recipe],buffer);
    for (i=1; i<20; i++) {
      gotoxy(40,i); txt_write("                                        ");
      }
    textcolor(15); gotoxy(46,2); txt_write("Recipe");
    textcolor(3);
    if (num_recipes > 0) {
      gotoxy(46,4);
      strcpy(buffer,buffer+8);
      pChar2 = next_nl(buffer);
      if (*pChar2 == 0) return;
      *pChar2 = 0;
      pChar2++;
      txt_write(buffer);
      textcolor(2); gotoxy(46,6); txt_write("Craft Item:");
      pChar1 = next_nl(pChar2);
      if (*pChar1 == 0) return;
      pChar1++;
      pChar2 = next_nl(pChar1);
      if (*pChar2 == 0) return;
      *pChar2 = 0;
      pChar2++;
      textcolor(3); gotoxy(46,7); txt_write(pChar1);
      textcolor(2); gotoxy(46,9); txt_write("Ingredients:");
      pChar1 = next_nl(pChar2);
      if (*pChar1 == 0) return;
      pChar1++;
      pChar2 = next_nl(pChar1);
      i = 10;
      while (*pChar2 != 0) {
        *pChar2++ = 0;
        textcolor(3); gotoxy(46,i++); txt_write(pChar1);
	pChar1 = pChar2;
	pChar2 = next_nl(pChar1);
        }
      gotoxy(46,i); txt_write(pChar1);
      }
    }

  void show_screen() {
    int i;
    textmode(3);
    textcolor(15); gotoxy(10,4); txt_write("Crafting");
    textcolor(2); gotoxy(10,6); txt_write("Craft Item:");
    if (craft != NULL && craft->otype != O_NONE) {
      textcolor(3); gotoxy(10,7); txt_write(get_name(craft));
      }
    textcolor(2); gotoxy(10,9); txt_write("Ingredients:");
    for (i=0; i<10; i++) {
      textcolor(3); gotoxy(10,i+10);
      if (ing[i] != NULL && ing[i]->otype != O_NONE)
        txt_write(get_name(ing[i]));
      }

    textcolor(10);
    gotoxy(28,21);
    sprintf(buffer,"Recipes known : %d of %d",num_recipes,recipe_count);
    txt_write(buffer);

    textcolor(6);
    gotoxy(10,23);
    txt_write("<");
    textcolor(14); txt_write("ESC");
    textcolor(6); txt_write(">quit, <");
    textcolor(14); txt_write("ENTER");
    textcolor(6); txt_write(">Select Craft Item/Ingredient, <");
    textcolor(14); txt_write("M");
    textcolor(6); txt_write(">ake Item");
    gotoxy(10,24);
    textcolor(6);
    txt_write("<");
    textcolor(14); txt_write("PGUP");
    textcolor(6); txt_write("> and <");
    textcolor(14); txt_write("PGDN");
    textcolor(6); txt_write("> will scroll through known recipes, <");
    textcolor(14); txt_write("A");
    textcolor(6); txt_write(">uto");
    show_recipe();
    }

  char check_recipe(RECIPE rec) {
    int i;
    int j;
    int l;
    char flag;
    char used[10];
    l = 0;
    if (rec.craft_item != 0) {
      if (craft == NULL) return 'N';
      if (craft->link != rec.craft_item) return 'N';
      }
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

  void next_recipe() {
    if (num_recipes == 0) return;
    current_recipe++;
    if (current_recipe >= num_recipes) current_recipe = 0;
    }

  void prev_recipe() {
    if (num_recipes == 0) return;
    current_recipe--;
    if (current_recipe < 0) current_recipe = num_recipes-1;
    }

  num_recipes = 0;
  for (i=0; i<recipe_count; i++)
    if (player.lore[i+RECIPE_BASE] != 0) recipe_book[num_recipes++] = i;
  if (num_recipes > 2) {
    flag = '*';
    while (flag == '*') {
      flag = ' ';
      for (i=0; i<num_recipes-1; i++) {
        recipe_string(recipe_book[i],name1);
        recipe_string(recipe_book[i+1],name2);
        if (strcmp(name1,name2) > 0) {
          tmp = recipe_book[i];
          recipe_book[i] = recipe_book[i+1];
          recipe_book[i+1] = tmp;
          flag = '*';
          }
        }
      }
    }
  for (i=0; i<10; i++) ing[i] = NULL;
  craft = NULL;
  current_recipe = 0;
  show_screen();
  line = 5;
  flag = ' ';
  textcolor(14);
  gotoxy(2,line+2); txt_write("->");
  while (flag == ' ') {
    key = inkey();
    if (key == '2' || key == '.' || key == '>') {
      textcolor(14);
      gotoxy(2,line+2); txt_write("  ");
      line++;
      if (line == 6) line = 8;
      if (line > 17) line = 5;
      gotoxy(2,line+2); txt_write("->");
      }
    if (key == '8' || key == ',' || key == '<') {
      textcolor(14);
      gotoxy(2,line+2); txt_write("  ");
      line--;
      if (line == 7) line = 5;
      if (line < 5) line = 17;
      gotoxy(2,line+2); txt_write("->");
      }
    if (key == '3') {
      next_recipe();
      show_recipe();
      }
    if (key == '9') {
      prev_recipe();
      show_recipe();
      }
    if ((key == 'a' || key == 'A') && num_recipes > 0) {
      auto_add();
      show_screen();
      textcolor(14);
      gotoxy(2,line+2); txt_write("->");
      }
    if (key == 'M') flag = 'Y';
    if (key == 'm') flag = 'Y';
    if (key == 13) {
      pItem = unpack(-1);
      if (pItem != NULL) {
        for (i=0; i<10; i++)
          if (pItem == ing[i]) ing[i] = NULL;
        if (pItem == craft) craft = NULL;
        if (line == 5) craft = pItem;
          else ing[line-8] = pItem;
        }
      show_screen();
      textcolor(14);
      gotoxy(2,line+2); txt_write("->");
      }
    if (key == 27) {
      flag = '*';
      }
    }
  if (flag == 'Y' && num_recipes > 0) {
    line = find_recipe();
    if (line >= 0) {
      for (i=0; i<10; i++) if (ing[i] != NULL) ing[i]->otype = O_NONE;
      pItem = find_linked_item(recipes[line].object);
      if (pItem != NULL) {
        item = *pItem;
        item.level = -1;
        inventory(&item);
	stats.counts[STAT_ITEMS_CRAFTED]++;
        }
      } else {
      textcolor(12);
      gotoxy(20,21);
      txt_write("Failed!!!");
      delay(5000);
      }
    }

  }
