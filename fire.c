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

void fire(int damage,OBJECT_REC* weapon) { 
  int sprt = 0;
  int  x,y;
  double fx,fy;
  int  i;
  int exact;
  int skill;
  NPC_REC* monster;
  OBJECT_REC* item;
  sprt = -1;
#ifdef ASCII
  sprt = 100;
#endif
  if (weapon != NULL && weapon->otype == O_BOW) stats.counts[STAT_ARROWS_FIRED]++;
  if (weapon != NULL && weapon->otype != O_BOW)
    sprt = weapon->sprite;
  if (weapon != NULL && weapon->otype == O_WAND) sprt = 100;
  exact = (weapon == NULL) ? 0 : -1;
  target(sprt,exact,-1);
  x = target_x;
  y = target_y;
  monster = get_monster(x,y);
  item = get_item(x,y);
  if (monster != NULL) {
    skill = (weapon != NULL && weapon->otype == O_BOW) ? weapon->skill : SK_THROWN;
    if (weapon != NULL && weapon->otype == O_WAND) skill = SK_MAGIC;
    i = 10;
    i += 2 * (player.level - monster->level);
    if (i < -50) i = -50;
    i += get_hit() * 2.5;
    i += get_skill(SK_COMBAT) / 2;
    if (get_skill(skill) >= 5) i += get_skill(skill) / 2;
    if (get_skill(skill) < 5) {
      if (get_skill(skill) == 0) i = (int)(i * 0.16);
      if (get_skill(skill) == 1) i = (int)(i * 0.32);
      if (get_skill(skill) == 2) i = (int)(i * 0.48);
      if (get_skill(skill) == 3) i = (int)(i * 0.64);
      if (get_skill(skill) == 4) i = (int)(i * 0.80);
      }
    if (monster->fear > 0) i += 10;
    if (monster->confused > 0) i += 10;
    if (monster->sleep > 0) i += 75;
    if (i>90) i = 90;
    if (i<10) i = 10;
    if (u_random(100) < i) {
      if (weapon != NULL && weapon->otype == O_POTN)
        aoe(x,y,weapon->effect,weapon->control,weapon->damage,0,0,0,-100);
      clear_prompt();
      noise(1000,100);
      prompt("HIT !!!");
      if (weapon != NULL && weapon->otype == O_BOW) add_skill(weapon->skill,1);
      else add_skill(SK_THROWN,1);
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(delay_hit);
        show_spot(x,y);
        }
      i = max_damage(weapon,monster,damage) / 2;
      i = (i/2) + u_random(i/2);
      if (i < 1) i = 1;
      if (u_random(100) < get_crit()) {
        i *= 2;
        stats.counts[STAT_CRITS]++;
        }
      stats_do_damage(i);
      aoe(x,y,E_DAMG,0,-i,0,0,0,-100);
      }
    else {
      clear_prompt();
      prompt("Missed. . .");
      stats.counts[STAT_MISSES]++;
      }
    }
  else if (player.map[x][y] >= 950 && player.map[x][y] < 970) {
    trigger_trap(x,y,player.map[x][y]);
    player.map[x][y] = currentFloor;
    show_spot(x,y);
    }
  else if (item != NULL && weapon->otype == O_BOW) {
    if (item->otype == O_POTN) {
      player.map[x][y] = currentFloor;
      show_spot(x,y);
      aoe(x,y,item->effect,item->control,item->damage,0,1,0,-100);
      }
    if (strcmp(item->name,"Flask_of_Oil") == 0) {
      player.map[x][y] = currentFloor;
      show_spot(x,y);
      aoe(x,y,E_DAMG,0,8,MS_FIRE_ATK,1,0,-100);
      }
    }
  else if (weapon != NULL && weapon->otype != O_BOW) {
    i = find_item_slot();
    fx = x + 0.5;
    fy = y + 0.5;
    if (player.map[(int)fx][(int)fy] != 7) {
      fx -= dir_x;
      fy -= dir_y;
      }
    x = fx;
    y = fy;
    if (i>=0) {
      player.map[x][y] = i + 1000;
      player.map_objects[i] = *weapon;
      if (in_sight(x,y) == '*') show_spot(x,y);
      }
    }
  }
