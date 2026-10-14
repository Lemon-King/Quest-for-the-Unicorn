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

void make_map() {
  byte basex,basey;
  byte rooms;
  int  roomx,roomy;
  int  x1,x2,y1,y2;
  byte exits,segs;
  byte lng;
  byte length;
  byte dir;
  int  i,j,x,y;
  byte floor;
  char inter;
  char exit_flag;
  char door;
  char flag;
  OBJECT_REC* item;
  prompt("Generating Map...");
  floor = 7;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      player.map[x][y] = 21;
      player.known[x][y] = 0;
      }
  basex = 10; basey = 10;
  for (rooms=1; rooms<=25; rooms++) {
    inter = ' ';
    roomx = basex + u_random(10) - u_random(10);
    roomy = basey + u_random(10) - u_random(10);
    x1 = roomx - u_random(7); x2 = roomx + u_random(7);
    y1 = roomy - u_random(7); y2 = roomy + u_random(7);
    for (x=x1; x<=x2; x++)
      for (y=y1; y<=y2; y++)
        if (x>0 && x<101 && y>0 && y<101) {
          if (player.map[x][y] == floor) inter = '*';
          player.map[x][y] = 99;
          }
    exits = u_random(5);
    if (exits < 1) exits = 1;
    exit_flag = ' ';
    i = 0;
    while (exit_flag == ' ') {
      door = ' ';
      i++;
      x = x1 + u_random(x2 - x1);
      y = y1 + u_random(y2 - y1);
      segs = u_random(5); if (segs < 1) segs = 1;
      for (j=1; j<=segs; j++) {
        dir = u_random(5); if (dir < 1) dir = 1;
        if (dir > 4) dir = 4;
        length = u_random(25) + 5;
        for (lng=1; lng<=length; lng++) {
          switch (dir) {
            case 1:x++; break;
            case 2:x--; break;
            case 3:y++; break;
            case 4:y--; break;
            }
          if (x>1 && x<100 && y>1 && y<100) {
            if (player.map[x][y] == floor) inter = '*';
            if (player.map[x][y] != 22) player.map[x][y] = 99;
            if (j == 1 && door == ' ')
              switch (dir) {
                case 1:if (player.map[x][y-1] == 21 &&
                           player.map[x][y+1] == 21) player.map[x][y] = 22;
                       break;
                case 2:if (player.map[x][y-1] == 21 &&
                           player.map[x][y+1] == 21) player.map[x][y] = 22;
                       break;
                case 3:if (player.map[x-1][y] == 21 &&
                           player.map[x+1][y] == 21) player.map[x][y] = 22;
                       break;
                case 4:if (player.map[x-1][y] == 21 &&
                           player.map[x+1][y] == 21) player.map[x][y] = 22;
                       break;
                }
            if (player.map[x][y] == 22) door = '*';
            }
          }
        if (i > exits) exit_flag = '*';
        if (rooms > 1 && inter == ' ') exit_flag = ' ';
        }

      }
    for (x=1; x<=100; x++)
      for (y=1; y<=100; y++)
        if (player.map[x][y] == 99) player.map[x][y] = floor;
    basex += 20;
    if (basex > 100) {
      basex = 10;
      basey += 20;
      }
    if (basey > 100) basey = 10;
    }
  if (player.gateway == '*' && player.d_level < 5) {
    for (i=1; i<=2; i++) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      while (player.map[x][y] != floor) {
        x = u_random(80) + 10;
        y = u_random(80) + 10;
        }
      player.map[x][y] = S_DNSTAIR;
      }
    }
  if (player.gateway != '*' && player.d_level < bottom) {
    for (i=1; i<=2; i++) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      while (player.map[x][y] != floor) {
        x = u_random(80) + 10;
        y = u_random(80) + 10;
        }
      player.map[x][y] = S_DNSTAIR;
      }
    }
  if (player.gateway != '*') {
    if (links[player.dungeon_number].treasure < 1000)
      if (player.d_level == bottom && player.quests[player.dungeon_number] == 'N') {
        x = u_random(80) + 10;
        y = u_random(80) + 10;
        while (player.map[x][y] != floor) {
          x = u_random(80) + 10;
          y = u_random(80) + 10;
          }
        for (i=x-1; i<=x+1; i++)
          for (j=y-1; j<=y+1; j++)
            player.map[i][j] = 41;
        item = find_linked_item(links[player.dungeon_number].treasure);
        if (item != NULL) {
          player.map_objects[0] = *item;
          player.map[x][y] = 1000;
          }
        }
    if (links[player.dungeon_number].treasure > 1000 && player.d_level == bottom) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      while (player.map[x][y] != floor) {
        x = u_random(80) + 10;
        y = u_random(80) + 10;
        }
      for (i=x-1; i<=x+1; i++)
        for (j=y-1; j<=y+1; j++)
          player.map[i][j] = 41;
      player.map[x][y] = links[player.dungeon_number].treasure + 1000;
      }
    }
  if (player.gateway != '*') {
    for (i=1; i<=2; i++) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      while (player.map[x][y] != floor) {
        x = u_random(80) + 10;
        y = u_random(80) + 10;
        }
      player.map[x][y] = S_UPSTAIR;
      }
    }
  for (i=1; i<=(player.d_level / 3 + player.diff * 2 + 5); i++) {
    x = u_random(80) + 10;
    y = u_random(80) + 10;
    while (player.map[x][y] != floor) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      }
    player.map[x][y] = 800 + u_random(4) + 1;
    }
  for (x=1; x<=100; x++) {
    player.map[x][1] = 21;
    player.map[x][2] = 21;
    player.map[x][99] = 21;
    player.map[x][100] = 21;
    }
  for (y=1; y<=100; y++) {
    player.map[1][y] = 21;
    player.map[2][y] = 21;
    player.map[99][y] = 21;
    player.map[100][y] = 21;
    }
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.map[x][y] == 22) {
        flag = ' ';
        if (player.map[x-1][y] != floor && player.map[x+1][y] != floor)
          flag = '*';
        if (player.map[x][y-1] != floor && player.map[x][y+1] != floor)
          flag = '*';
        if (flag == ' ') player.map[x][y] = floor;
        }
  stock_treasure();
  stock_monsters();
  if (player.gateway == '*') {
    if (player.d_level == 1) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 39;
      }
    if (player.d_level == 2) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 38;
      }
    if (player.d_level == 3) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 41;
      }
    if (player.d_level == 4) {
      player.diff = 30;
      strcpy(player.d_name,"Realm of Eshter");
      copyMap(&player.map,18);
      player.x = 78;
      player.y = 89;
      stock_monsters();
      player.map_x = player.x-8;
      player.map_y = player.y-8;
      if (player.map_x<1) player.map_x = 1;
      if (player.map_y<1) player.map_y = 1;
      if (player.map_x>84) player.map_x = 84;
      if (player.map_y>84) player.map_y = 84;
      }
    if (player.d_level == 5) {
      strcpy(player.d_name,"Castle Eshter");
      }
    }
  }
