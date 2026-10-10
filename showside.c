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

void show_time() {
  setfillstyle(1,0);
  bar(screen_width-130,12,screen_width,23);
  setcolor(14);
  sprintf(buffer,"%02d/%02d  %02d:%02d",player.month,player.day,player.hour,player.min);
  outtext_xy(TEXT_GRID_WIDTH - 15,2,buffer);
  }

void show_side() {
  char buffer[80];
/*
  int statusLine;
  int statusCol;
#ifdef ASCII
  statusLine = 280;
  statusCol = 1450;
#else
  statusLine = 453;
  statusCol = 5;
#endif
*/
  setfillstyle(1,0);
  bar(screen_width - 130,10,screen_width,100);
  settextstyle(0,0,1);
  if (player.effect[PE_HEROIC] < 0) {
    setcolor(10);
    outtext_xy(TEXT_GRID_WIDTH - 10,0,"Casual");
    }
  if (player.effect[PE_HEROIC] == 2) {
    setcolor(12);
    outtext_xy(TEXT_GRID_WIDTH - 10,0,"Heroic");
    }
  if (player.effect[PE_HEROIC] == 4) {
    setcolor(13);
    outtext_xy(TEXT_GRID_WIDTH - 10,0,"EPIC");
    }
  show_time();
  setcolor(14);
  outtext_xy(TEXT_GRID_WIDTH - 15,1,make_str(player.d_level));
  show_time();
  sprintf(buffer,"%d/%d    ",player.chp,get_mhp());
  outtext_xy(TEXT_GRID_WIDTH - 15,3,buffer);
  sprintf(buffer,"%d/%d    ",player.cmana,get_mmana());
  outtext_xy(TEXT_GRID_WIDTH - 15,4,buffer);
  outtext_xy(TEXT_GRID_WIDTH - 15,5,make_str(player.level));
  sprintf(buffer,"(%s)",make_str(player.exp));
  outtext_xy(TEXT_GRID_WIDTH - 12,5,buffer);
  if (player.health >= 101 && player.health <=999) {
    setcolor(CLR_LIGHTGREEN);
    outtext_xy(TEXT_GRID_WIDTH - 15,6,"Satiated");
    }
  if (player.health >= 75  && player.health <=100) {
    outtext_xy(TEXT_GRID_WIDTH - 15,6,"        ");
    }
  if (player.health >= 50 && player.health <=74) {
      setcolor(CLR_YELLOW);
      outtext_xy(TEXT_GRID_WIDTH - 15,6,"Hungry  ");
    }
  if (player.health >= 25 && player.health <=49) {
      setcolor(CLR_LIGHTRED);
      outtext_xy(TEXT_GRID_WIDTH - 15,6,"Starving");
    }
  if (player.health >= 1 && player.health <=24) {
      setcolor(CLR_LIGHTPURPLE);
       outtext_xy(TEXT_GRID_WIDTH - 15,6,"Faint   ");
    }
  if (player.health <= 0) {
    outtext_xy(TEXT_GRID_WIDTH - 15,6,"DEAD!!");
    }
  setcolor(CLR_YELLOW);
/*  show_sprite(22,2,((player.fire != 0)?44:10)); */
/*  show_sprite(20,2,((player.giant != 0)?45:10)); */
/*  show_sprite(17,2,((player.haste != 0)?50:10)); */
/*  show_sprite(19,2,((player.prot != 0)?47:10)); */
/*  show_sprite(23,2,((player.light != 0)?43:10)); */
/*  show_sprite(18,2,((player.poison != 0)?46:10)); */
/*
  putimage(statusCol,statusLine,select_sprite((player.effect[PE_LIGHT] != 0)?43:10),0);
  putimage(statusCol+35,statusLine,select_sprite((player.effect[PE_PROT] != 0)?47:10),0);
  putimage(statusCol+70,statusLine,select_sprite((player.effect[PE_POISON] != 0)?46:10),0);
  putimage(statusCol+105,statusLine,select_sprite((player.effect[PE_HASTE] != 0)?50:10),0);
  putimage(statusCol+140,statusLine,select_sprite((player.effect[PE_GIANT] != 0)?45:10),0);
  putimage(statusCol+175,statusLine,select_sprite((player.effect[PE_FIRE] != 0)?44:10),0);
  putimage(statusCol+210,statusLine,select_sprite((player.effect[PE_LEV] != 0)?325:10),0);
*/
  setcolor(7);
  if (can_see())                     outtext_xy(TEXT_GRID_WIDTH - 24,8,"L"); else outtext_xy(TEXT_GRID_WIDTH - 24,8," ");
  if (player.effect[PE_PROT] != 0)   outtext_xy(TEXT_GRID_WIDTH - 22,8,"S"); else outtext_xy(TEXT_GRID_WIDTH - 22,8," ");
  if (player.effect[PE_POISON] != 0) outtext_xy(TEXT_GRID_WIDTH - 20,8,"P"); else outtext_xy(TEXT_GRID_WIDTH - 20,8," ");
  if (has_intrinsic(A_SPD))          outtext_xy(TEXT_GRID_WIDTH - 18,8,"H"); else outtext_xy(TEXT_GRID_WIDTH - 18,8," ");
  if (player.effect[PE_GIANT] != 0)  outtext_xy(TEXT_GRID_WIDTH - 16,8,"G"); else outtext_xy(TEXT_GRID_WIDTH - 16,8," ");
  if (has_intrinsic(A_LEV))          outtext_xy(TEXT_GRID_WIDTH - 14,8,"V"); else outtext_xy(TEXT_GRID_WIDTH - 14,8," ");
  if (has_intrinsic(A_RFIR))         outtext_xy(TEXT_GRID_WIDTH - 12,8,"F"); else outtext_xy(TEXT_GRID_WIDTH - 12,8," ");
  if (has_intrinsic(A_RCLD))         outtext_xy(TEXT_GRID_WIDTH - 10,8,"C"); else outtext_xy(TEXT_GRID_WIDTH - 10,8," ");
  if (has_intrinsic(A_RELC))         outtext_xy(TEXT_GRID_WIDTH -  8,8,"Z"); else outtext_xy(TEXT_GRID_WIDTH -  8,8," ");
  if (has_intrinsic(A_RDRK))         outtext_xy(TEXT_GRID_WIDTH -  6,8,"A"); else outtext_xy(TEXT_GRID_WIDTH -  6,8," ");
  if (player.effect[PE_MIND] != 0)   outtext_xy(TEXT_GRID_WIDTH -  4,8,"M"); else outtext_xy(TEXT_GRID_WIDTH -  4,8," ");
  if (player.effect[PE_ETHER] > 0) {
    if (player.effect[PE_ETHER] > 10) outtext_xy(TEXT_GRID_WIDTH - 2,8,"E"); else outtext_xy(TEXT_GRID_WIDTH - 2,8,"e");
    } else outtext_xy(TEXT_GRID_WIDTH - 2,8," ");
  /*
  if (player.effect[PE_ETHER] > 10) show_sprite(21,2,49);
    else if (player.effect[PE_ETHER] > 0) show_sprite(21,2,48);
      else show_sprite(21,2,10);
      */
#ifndef ASCII
  putimage(tile_width*0,screen_height-tile_height,select_sprite(can_see() ? 43 : 10),0);
  putimage(tile_width*1,screen_height-tile_height,select_sprite((player.effect[PE_PROT] != 0) ? 47 : 10),0);
  putimage(tile_width*2,screen_height-tile_height,select_sprite((player.effect[PE_POISON] != 0) ? 46 : 10),0);
  putimage(tile_width*3,screen_height-tile_height,select_sprite((has_intrinsic(A_SPD)) ? 50 : 10),0);
  putimage(tile_width*4,screen_height-tile_height,select_sprite((player.effect[PE_GIANT] != 0) ? 45 : 10),0);
  putimage(tile_width*5,screen_height-tile_height,select_sprite((has_intrinsic(A_LEV)) ? 325 : 10),0);
  putimage(tile_width*6,screen_height-tile_height,select_sprite((has_intrinsic(A_RFIR)) ? 44 : 10),0);
  putimage(tile_width*7,screen_height-tile_height,select_sprite((has_intrinsic(A_RCLD)) ? 354 : 10),0);
  putimage(tile_width*8,screen_height-tile_height,select_sprite((has_intrinsic(A_RELC)) ? 355 : 10),0);
  putimage(tile_width*9,screen_height-tile_height,select_sprite((has_intrinsic(A_RDRK)) ? 356 : 10),0);
  putimage(tile_width*10,screen_height-tile_height,select_sprite((player.effect[PE_MIND] != 0) ? 357 : 10),0);
  if (player.effect[PE_ETHER] > 0) {
    if (player.effect[PE_ETHER] > 10)  putimage(tile_width*11,screen_height-tile_height,select_sprite(48),0);
    else if (player.effect[PE_ETHER] > 0)  putimage(tile_width*11,screen_height-tile_height,select_sprite(49),0);
    else putimage(tile_width*11,screen_height-tile_height,select_sprite(10),0);

    }
#endif
  }

