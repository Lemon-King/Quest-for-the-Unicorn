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

int targets[256];
int target_count;

void sort_targets() {
  int i;
  char flag;
  int tmp;
  flag = 'N';
  while (flag != 'Y') {
    flag = 'Y';
    for (i=0; i<target_count-1; i++)
      if (links[targets[i]].quest > links[targets[i+1]].quest) {
        flag = 'N';
        tmp = targets[i];
        targets[i] = targets[i+1];
        targets[i+1] = tmp;
        }
    }
  }

void use_compass() {
  int  i;
  int  row;
  int  col;
  int  dungeon;
  int  msg;
  char key;
  saveScreen();
  textmode(3);
  textcolor(15);
  gotoxy(33,1); txt_write("Compass Target");
  row = 4;
  col = 3;
  target_count = 0;
  i = 0;
  while (compass_points[i].quest < 99) {
    dungeon = get_dungeon(compass_points[i].quest);
    msg = get_linked_msg(compass_points[i].message);
    if (player.quests[dungeon] != 'N') targets[target_count++] = dungeon;
    else if (player.gen[msg] != 0) targets[target_count++] = dungeon;
    i++;
    }
  sort_targets();
  for (i=0; i<target_count; i++) {
    if (player.quests[targets[i]] == 'Y') textcolor(9);
    else if (links[targets[i]].diff > player.level) textcolor(12);
      else textcolor(10);
    if (player.effect[PE_COMPASS] == links[targets[i]].quest) textcolor(14);
    gotoxy(col,row);
    txt_write(links[targets[i]].name);
    row++;
    if (row == 24) {
      row = 4;
      col += 26;
      }
    }
  gotoxy(14,25); textcolor(14);
  txt_write("<Enter> to set target, <q>uest target, <Esc> to abort");
  key = 0;
  row = 0;
  col = 0;
  while (key != 13 && key != 27 && key != 'q' && key != 'Q') {
    gotoxy(col*26+1,row+4); textcolor(15); txt_write("->");
    key = inkey();
    if (target_count == 0 && key != 13 && key != 27) key = ' ';
    gotoxy(col*26+1,row+4); textcolor(15); txt_write("  ");
    if (key == '2') {
      row++;
      if (row == 20) row = 0;
      if (((col * 20) + row) >= target_count) row = 0;
      }
    if (key == '8') {
      row--;
      if (row == -1) row = 19;
      if (((col * 20) + row) >= target_count) row = (target_count - 1) % 20;
      }
    if (key == '6') {
      col++;
      if (col == 3) col = 0;
      if ((col * 20) >= target_count) col = 0;
      if (((col * 20) + row) >= target_count) row = (target_count - 1) % 20;
      }
    if (key == '4') {
      col--;
      if (col == -1) col = 2;
      if ((col * 20) >= target_count) col = 0;
      if (((col * 20) + row) >= target_count) row = (target_count - 1) % 20;
      }
    }
  if (key == 'q' || key == 'Q') player.effect[PE_COMPASS] = 0;
  if (key == 13) {
    if ((col * 20) + row < target_count) player.effect[PE_COMPASS] = links[targets[(col * 20) + row]].quest;
    }
  restoreScreen();
  }

