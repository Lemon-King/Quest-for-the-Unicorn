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

void discover() {
  int i,j,color;
  int xmax,xmin;
  int ymax,ymin;
  char show_flag;
  show_flag = ' ';
  if (player.in_city == 'Y') show_flag = '*';
  if (player.effect[PE_LIGHT] != 0) show_flag = '*';
  if (player.gateway == '*' && player.d_level < 4) show_flag = ' ';
  if (player.gateway == '*' && has_intrinsic(A_GSEE)) show_flag = '*';
  xmax = player.x+1; xmin = player.x-1;
  ymax = player.y+1; ymin = player.y-1;
  if (has_intrinsic(A_XRAY)) {
    xmax = player.x+2; xmin = player.x-2;
    ymax = player.y+2; ymin = player.y-2;
    }
  xmax += player.skill[13] / 10;
  ymax += player.skill[13] / 10;
  xmin -= player.skill[13] / 10;
  ymin -= player.skill[13] / 10;
  if (xmax > player.map_x+15) xmax = player.map_x+15;
  if (xmin < player.map_x) xmin = player.map_x;
  if (ymax > player.map_y+15) ymax = player.map_y+15;
  if (ymin < player.map_y) ymin = player.map_y;
  for (i=xmin; i<=xmax; i++)
    for (j=ymin; j<=ymax; j++)
      if (i>0 && i<100 && j>0 && j<100 && player.known[i][j] == 0 &&
          show_flag == '*') {
        player.known[i][j] = 1;
        show_spot(i,j);
        color = 8;
        switch (player.map[i][j]) {
          case  21:color = 4; break;
          case   7:color = 8; break;
          case  22:color = 14; break;
          case  23:color = 14; break;
          case   1:color = 10; break;
          case   4:color = 1; break;
          case  24:color = 3; break;
          case  25:color = 11; break;
          case  41:color = 9; break;
          case  38:color = 12; break;
          case  39:color = 1; break;
          case  20:color = 2; break;
          case   3:color = 6; break;
          case   9:color = 5; break;
          case   2:color = 2; break;
          }
        putpixel(419+i*2,240+j*2,color);
        putpixel(420+i*2,240+j*2,color);
        putpixel(419+i*2,241+j*2,color);
        putpixel(420+i*2,241+j*2,color);
        }

  }

