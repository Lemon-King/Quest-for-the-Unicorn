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

void fire(int damage,OBJECT_REC* weapon) { 
  char mflag;
  char key;
  byte sprt = 0;
  int  x,y;
  int  xdir,ydir; 
  int  mon;
  int  i;
  NPC_REC* npc;
  key = get_dir(&xdir,&ydir);
  switch (key) {
    case '2':sprt = 92; break;
    case '8':sprt = 91; break;
    case '6':sprt = 93; break;
    case '4':sprt = 94; break;
    case '7':sprt = 96; break;
    case '9':sprt = 95; break;
    case '1':sprt = 98; break;
    case '3':sprt = 97; break;
    }
  if (weapon != NULL && weapon->otype != O_BOW)
    sprt = weapon->sprite;
  x = player.x;
  y = player.y;
  mflag = ' ';
  while (mflag == ' ') {
    x += xdir;
    y += ydir;
    if (player.map[x][y] == 3) mflag = '*';
    if (player.map[x][y] == 38) mflag = '*';
    if (player.map[x][y] == 39) mflag = '*';
    if (player.map[x][y] == 21) mflag = '*';
    if (player.map[x][y] == 41) mflag = '*';
    if (player.map[x][y] < 0) mflag = '*';
    if (player.map[x][y]>400 && player.map[x][y]<500) mflag = '*'; 
    if (in_sight(x,y) == '*') {
      show_sprite(x-player.map_x,y-player.map_y,sprt);
      delay(100);
      show_spot(x,y);
      }
    }
  if (player.map[x][y] < 0 || (player.map[x][y]>400 && player.map[x][y]<500)) {
    if (in_arena == 'Y') {
      mon = player.map[x][y] - 400;
      npc = &(player.monster[abs(player.map[x][y]) - 400][a_mon]);
      }
    else {
      mon = player.map[x][y];
      npc = &(player.monster[1][abs(player.map[x][y])]);
      }
    if (mon < 0) mon = -mon;
    i = 10 + player.skill[1] * 10;
    if (u_random(100) < i) {
      if (weapon != NULL && weapon->otype == O_POTN) {
        if (weapon->user_hp != 0) {
          npc->hp += weapon->charges * abs(u_random(weapon->user_hp));
          prompt("Healed !!!");
          }
        if (weapon->effect == E_DAMG) {
          npc->hp -= u_random(weapon->control);
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 60) {
          npc->sleep = weapon->charges * u_random(1024);
          prompt("Slept !!!");
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 61) {
          npc->fear = weapon->charges * u_random(1024);
          prompt("Scared !!!");
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 62) {
          npc->blind = weapon->charges * u_random(1024);
          prompt("Blinded !!!");
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 63) {
          npc->confused = weapon->charges * u_random(1024);
          prompt("Confused !!!");
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 64) {
          npc->confused = 0;
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 65) {
          npc->fear = 0;
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 66) {
          npc->blind = 0;
          }
        if (weapon->effect == E_SPCL &&
            weapon->control == 67) {
          npc->blind = 0;
          npc->fear = 0;
          npc->confused = 0;
          npc->poison = 0;
          }
        if (weapon->effect == E_POSN) {
          npc->poison = weapon->charges * u_random(1024);
          prompt("Poisoned !!!");
          }
        }
      clear_prompt();
      noise(1000,100);
      prompt("HIT !!!");
      if (in_arena != 'Y' && player.monster[1][mon].special > 9) {
        player.align -= 20;
        player.monster[1][mon].special -= 10;
        if (player.align < 0) player.align = 0;
        }
      if (in_arena == 'Y' && player.monster[mon][a_mon].special > 9) {
        player.align -= 20;
        player.monster[mon][a_mon].special -= 10;
        if (player.align < 0) player.align = 0;
        }
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,80);
        delay(250);
        show_spot(x,y);
        }
      i = u_random(damage) + 1;
      if (in_arena == 'Y') player.monster[mon][a_mon].hp -= i;
        else player.monster[1][mon].hp -= i;
      if (in_arena == 'Y') i=player.monster[mon][a_mon].hp;
        else i=player.monster[1][mon].hp;
      if (i <= 0) {
        clear_prompt();
        if (in_arena != 'Y') {
/*
          sprintf(buffer,"Exp=%.0f",player.monster[1][mon].exp);
          prompt(buffer);
*/
          gain_exp(player.monster[1][mon].exp);
/*          player.exp += player.monster[1][mon].exp; */
          player.map[x][y] = player.monster[1][mon].prev;
          }
        if (in_arena == 'Y') {
/*
          sprintf(buffer,"Exp=%.0f",player.monster[mon][a_mon].exp);
          prompt(buffer);
*/
          gain_exp(player.monster[mon][a_mon].exp);
/*          player.exp += player.monster[mon][a_mon].exp; */
          player.map[x][y] = player.monster[mon][a_mon].prev;
          }
        show_spot(x,y);
        if (in_arena != 'Y' && player.monster[1][mon].special > 9) {
          player.align -= 20;
          if (player.align < 0) player.align = 0;
          }
        if (in_arena == 'Y' && player.monster[mon][a_mon].special > 9) {
          player.align -= 20;
          if (player.align < 0) player.align = 0;
          }
        show_side();
        }
      }
    else {
      clear_prompt();
      prompt("Missed. . .");
      }
    }
  else if (weapon != NULL) {
    i = find_item_slot();
    if (i>=0) {
      player.map[x-xdir][y-ydir] = i + 1000;
      player.map_objects[i] = *weapon;
      if (in_sight(x-xdir,y-ydir) == '*') show_spot(x-xdir,y-ydir);
      }
    }
  }
