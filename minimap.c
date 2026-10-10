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

void miniMap() {
  char key;
  int  x,y;
  int  x1,y1;
  char cell[2];
  cell[1] = 0;
  textmode(3);
  textcolor(15);
  for (y=0; y<25; y++)
    for (x=0; x<50; x++) {
        cell[0] = 127;
        for (x1=0; x1<2; x1++)
          for (y1=0; y1<4; y1++)
            if (player.known[x*2+x1+1][y*4+y1+1]) {
              if (cell[0] == 127) cell[0] = ' ';
              if (player.map[x*2+x1+1][y*4+y1+1] < 0 && cell[0] == ' ') cell[0] = '.';
              if (player.map[x*2+x1+1][y*4+y1+1] > 300 && cell[0] == ' ') cell[0] = '.';
              if (player.map[x*2+x1+1][y*4+y1+1] == 7 && cell[0] == ' ') cell[0] = '.';
              if (player.map[x*2+x1+1][y*4+y1+1] == 24 && cell[0] != '@') cell[0] = '>';
              if (player.map[x*2+x1+1][y*4+y1+1] == 25 && cell[0] != '@') cell[0] = '<';
              if (x*2+x1+1 == player.x && y*4+y1+1 == player.y) cell[0] = '@';
              }
        if (cell[0] != 127) {
          setcolor(1);
          if (cell[0] == '.') setcolor(7);
          if (cell[0] == '>') setcolor(12);
          if (cell[0] == '<') setcolor(10);
          if (cell[0] == '@') setcolor(15);
          gotoxy(x+1,y+1); txt_write(cell);
          }
    }
  setcolor(15);
  gotoxy(52,13); txt_write("Press <ESC> to exit");

  key = ' ';
  while (key != 13 && key != 27) {
    key = inkey();
    }
  }

