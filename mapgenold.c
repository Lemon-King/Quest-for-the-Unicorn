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

void mapgen_old(int floor) {
  byte basex,basey;
  byte rooms;
  int  roomx,roomy;
  int  x1,x2,y1,y2;
  byte exits,segs;
  byte lng;
  byte length;
  byte dir;
  int  i,j,x,y;
  char inter;
  char exit_flag;
  char door;
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
  }
