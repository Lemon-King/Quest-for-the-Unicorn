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

void show_side() {
  char buffer[80];
  setfillstyle(1,0);
  bar(520,10,640,100);
  settextstyle(0,0,1);
  setcolor(14);
  outtextxy(520,10,make_str(player.d_level));
  sprintf(buffer,"%2d/%2d  %2d:%2d",player.month,player.day,player.hour,player.min);
  outtextxy(520,20,buffer);
  sprintf(buffer,"%d/%d",player.chp,player.mhp);
  outtextxy(520,30,buffer);
  sprintf(buffer,"%d/%d",player.cmana,player.mmana);
  outtextxy(520,40,buffer);
  outtextxy(520,50,make_str(player.level));
  sprintf(buffer,"(%s)",make_str(player.exp));
  outtextxy(550,50,buffer);
  if (player.health >= 101 && player.health <=999) outtextxy(520,60,"Satiated");
  if (player.health >= 50 && player.health <=85) outtextxy(520,60,"Hungry");
  if (player.health >= 25 && player.health <=49) outtextxy(520,60,"Starving");
  if (player.health >= 1 && player.health <=24) outtextxy(520,60,"Faint");
  if (player.health == 0) outtextxy(520,60,"DEAD!!");
/*  show_sprite(22,2,((player.fire != 0)?44:10)); */
/*  show_sprite(20,2,((player.giant != 0)?45:10)); */
/*  show_sprite(17,2,((player.haste != 0)?50:10)); */
/*  show_sprite(19,2,((player.prot != 0)?47:10)); */
/*  show_sprite(23,2,((player.light != 0)?43:10)); */
/*  show_sprite(18,2,((player.poison != 0)?46:10)); */
  putimage(5,453,select_sprite((player.effect[PE_LIGHT] != 0)?43:10),0);
  putimage(40,453,select_sprite((player.effect[PE_PROT] != 0)?47:10),0);
  putimage(75,453,select_sprite((player.effect[PE_POISON] != 0)?46:10),0);
  putimage(110,453,select_sprite((player.effect[PE_HASTE] != 0)?50:10),0);
  putimage(145,453,select_sprite((player.effect[PE_GIANT] != 0)?45:10),0);
  putimage(180,453,select_sprite((player.effect[PE_FIRE] != 0)?44:10),0);

  if (player.effect[PE_ETHER] > 10) show_sprite(21,2,49);
    else if (player.effect[PE_ETHER] > 0) show_sprite(21,2,48);
      else show_sprite(21,2,10);
  }

