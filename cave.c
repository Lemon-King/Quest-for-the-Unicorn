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

void cave() {
  char haste_flag;
  int  i;
  int  m_file = 0;
  int  x,y;
  int  sx,sy;
  double d;
  byte key;

  void take_time() {
    player.min++;
    if (player.min > 59) {
      player.min = 0;
      player.hour++;
      player.health--;
      show_side();
      if (player.hour == 24) {
        player.hour = 0;
        player.day++;
        if (player.day == 32) {
          new_month();
/*
          player.day = 1;
          player.month++;
          new_pawn();
          player.interest = player.bank * .005;
          player.bank += player.interest;
          if (player.month == 13) {
            player.month = 1;
            player.cav_paid = 'N';
            player.age++;
            }
*/
          }
        }
      }
    } /* void take_time() */

  void enemy_hit(int x,int y) {
    int i,j;
    int hit;
    int mon;
    mon = 0 - player.map[x][y];
    i = 25 + (player.monster[1][mon].level * 2) +
             (player.monster[1][mon].attack / 2);
    i = i - player.armour - (player.ability[2] * 4);
    if (player.effect[PE_PROT] > 0) i -= player.effect[PE_APROT];
    for (j=13; j<=16; j++)
      if (player.invent[j].otype != O_NONE &&
          player.invent[j].effect == E_PROT) i -= player.invent[j].control;
    for (j=5; j<=6; j++) {
      if (player.invent[j].otype != O_NONE &&
          player.invent[j].effect == E_PROT) i -= player.invent[j].control;
      }
    if (player.invent[17].otype != O_NONE &&
        player.invent[17].effect == E_PROT) i -= player.invent[17].control;
    if (player.effect[PE_FEAR] > 0) i += 10;
    if (player.effect[PE_SLEEP] > 0) i += 50;
    if (player.effect[PE_BLIND] > 0) i += 25;
    if (player.monster[1][mon].blind > 0) i -= 25;
    if (player.monster[1][mon].fear > 0) i -= 10;

    if (i < 10) i = 10;
    if (i > 90) i = 90;
    clear_prompt();
    if (u_random(100) < i) {
      msg("OUCH!!!",12);
      noise(750,100);
      i = player.monster[1][mon].attack;
      i = u_random(i) + 1;
      switch (player.monster[1][mon].special) {
        case 2:if (player.class != 8 && player.effect[PE_SLEEP] == 0) {
                 hit = 50 + ((player.monster[1][mon].level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_NOSL)) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Slept!!!",9);
                   if (player.effect[PE_SLEEP] == 0)
                     player.effect[PE_SLEEP] = u_random(player.monster[1][mon].level);
                   if (player.effect[PE_SLEEP] < 0) player.effect[PE_SLEEP] = 0;
                   show_player();
                   }
                   show_side();
                 }
               break;
        case 3:if (player.class != 8) {
                 hit = 50 + ((player.monster[1][mon].level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_NOPS)) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Poisoned!!!",9);
                   player.effect[PE_POISON] += u_random(player.monster[1][mon].attack) * 10;
                   if (player.effect[PE_POISON] < 0) player.effect[PE_POISON] = 0;
                   show_side();
                   }
                 }
               break;
        case 5:if (player.class != 8) {
                 hit = 50 + ((player.monster[1][mon].level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_RSFR)) hit /= 2;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Scared!!!",9);
                   player.effect[PE_FEAR] += u_random((player.monster[1][mon].level)) * 10;
                   if (player.effect[PE_FEAR] < 0) player.effect[PE_FEAR] = 0;
                   show_side();
                   }
                 }
               break;
        } /* switch */
      player.chp -= i;
      if (player.chp < 0) player.chp = 0;
      show_side();
      }
    else {
      msg("Missed . . .",1);
      noise(100,100);
      }
    } /* void enemy_hit(int x,int y) */

  void hit_enemy() {
    int i;
    int j;
    int mon;
    i = 25 + (player.weapon / 2) + (player.skill[16] * 2) +
             (player.ability[1] * 4);
    i += player.level;
    if (player.invent[2].otype == O_EDGE) i += (player.skill[2] * 2);
    if (player.invent[2].otype == O_POLE) i += (player.skill[3] * 2);
    for (j=1; j<=10; j++) {
      if (player.invent[j].otype != O_NONE && player.invent[j].effect == E_INHT)
        i+= player.invent[j].control;
      }
    mon = 0- player.map[player.x][player.y];
    if (player.monster[1][mon].special > 9) {
      player.align -= 20;
      player.monster[1][mon].special -= 10;
      if (player.align < 0) player.align = 0;
      }
    i -= (player.monster[1][mon].defense * 3);
    if (player.monster[1][mon].fear > 0) i += 10;
    if (player.monster[1][mon].sleep > 0) i += 25;
    if (i < 10) i = 10;
    if (i > 90) i = 90;
    clear_prompt();
    if (u_random(100) < i) {
      msg("HIT!!",4);
      noise(1000,100);
      if ((player.invent[2].otype == O_DAGR ||
           player.invent[2].otype == O_EDGE ||
           player.invent[2].otype == O_POLE) &&
          player.invent[2].effect == E_POSN) {
        player.monster[1][mon].poison += player.invent[2].damage;
        prompt("Poisoned !!!");
        }

      if (player.class == 10) {
        if (u_random(100) < player.level*2) {
          msg("Paralyzed!",14); noise(1000,100); delay(500);
          player.monster[1][mon].sleep = u_random(2*(player.level - player.monster[1][mon].level));
          show_spot(player.x,player.y);
          if (u_random(500) < player.level) {
            msg("Killed!",15); noise(1000,100); delay(500);
            player.monster[1][mon].hp = 0;
            }
          }
        }
      if (player.monster[1][mon].special > 9) {
        player.align -= 5;
        if (player.align < 0) player.align = 0;
        }
      i = 3 + (player.weapon / 2) + (player.ability[3] * 3);
      if (player.effect[PE_GIANT] > 0) i += (player.weapon / 2);
      i = u_random(i) + 1;
      player.monster[1][mon].hp -= i;
      dead_monster(&(player.monster[1][mon]),'Y');
      }
    else {
      msg("Miss . . .",9);
      noise(200,100);
      }
    } /* void hit_enemy() */

  void search() {
    int x,y;
    int px,py;
    px = player.x;
    py = player.y;
    for (x=player.x-1; x<= player.x+1; x++)
      for (y=player.y-1; y<= player.y+1; y++)
        if (player.map[x][y]>=800 && player.map[x][y]<900) {
          player.map[x][y] = 40;
          player.known[x][y] = 0;
        }
    if (player.map[px][py-1] == 21 && player.map[px][py-2] != 21 &&
        player.map[px-1][py-1] == 21 && player.map[px+1][py-1] == 21) {
      player.map[px][py-1] = 22;
      player.known[px][py-1] = 0;
      }
    if (player.map[px][py+1] == 21 && player.map[px][py+2] != 21 &&
        player.map[px-1][py+1] == 21 && player.map[px+1][py+1] == 21) {
      player.map[px][py+1] = 22;
      player.known[px][py+1] = 0;
      }
    if (player.map[px-1][py] == 21 && player.map[px-2][py] != 21 &&
        player.map[px-1][py-1] == 21 && player.map[px+1][py+1] == 21) {
      player.map[px-1][py] = 22;
      player.known[px-1][py] = 0;
      }
    if (player.map[px+1][py] == 21 && player.map[px+2][py] != 21 &&
        player.map[px+1][py-1] == 21 && player.map[px+1][py+1] == 21) {
      player.map[px+1][py] = 22;
      player.known[px+1][py] = 0;
      }
    discover();
    } /* void search() */
 
  char valid(int x,int y) {
    char flag;
    flag = '*';
    if (player.map[x][y] == 21) flag = ' ';
    if (player.map[x][y] == 22) flag = ' ';
    if (player.map[x][y] == 30) flag = ' ';
    if (player.map[x][y] == 33) flag = ' ';
    if (player.map[x][y] == 3) flag = ' ';
    if (x<1 || x>100 || y<1 || y>100) flag = ' ';
    if (player.map[x][y] == 4) flag = ' ';
    if (player.inship != ' ') {
      flag = ' ';
      if (player.map[x][y] == 4) flag = '*';
      }
    return flag;
    } /* char valid(int x,int y) */

  void attack() {
    int xdir,ydir;
    char key;
    clear_prompt();
    prompt("Attack who ?");
    key = inkey();
    xdir = 0;
    ydir = 0;
    switch (key) {
      case '8':ydir = -1; break;
      case '2':ydir = 1; break;
      case '4':xdir = -1; break;
      case '6':xdir = 1; break;
      case '1':ydir = 1; xdir = -1; break;
      case '3':ydir = 1; xdir = 1; break;
      case '7':ydir = -1; xdir = -1; break;
      case '9':ydir = -1; xdir = 1; break;
      }
    player.x += xdir;
    player.y += ydir;
    if (player.map[player.x][player.y] < 0) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      }
    player.x -= xdir;
    player.y -= ydir;
    } /* void attack() */

  void move_up() {
    remove_player();
    player.y--;
    if (valid(player.x,player.y) == ' ') player.y++;
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.y++;
      }
    if (player.y - player.map_y < 1) {
      player.map_y = player.y - 13;
      if (player.map_y < 1) player.map_y = 1;
      show_map();
      }
    show_player();
    } /* void move_up() */

  void move_down() {
    remove_player();
    player.y++;
    if (valid(player.x,player.y) == ' ') player.y--;
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.y--;
      }
    if (player.y - player.map_y > 14) {
      player.map_y = player.y - 2;
      if (player.map_y > 85) player.map_y = 85;
      show_map();
      }
    show_player();
    } /* void move_down() */

  void move_left() {
    remove_player();
    player.x--;
    if (valid(player.x,player.y) == ' ') player.x++;
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x++;
      }
    if (player.x - player.map_x < 1) {
      player.map_x = player.x - 13;
      if (player.map_x < 1) player.map_x = 1;
      show_map();
      }
    show_player();
    } /* void move_left() */

  void move_right() {
    remove_player();
    player.x++;
    if (valid(player.x,player.y) == ' ') player.x--;
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x--;
      }
    if (player.x - player.map_x > 14) {
      player.map_x = player.x - 2;
      if (player.map_x > 85) player.map_x = 85;
      show_map();
      }
    show_player();
    } /* void move_right() */

  void move_up_left() {
    remove_player();
    player.y--;
    player.x--;
    if (valid(player.x,player.y) == ' ') {
      player.x++;
      player.y++;
      }
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x++;
      player.y++;
      }
    if ((player.x-player.map_x<1) || (player.y-player.map_y<1)) {
      player.map_x = player.x - 13;
      if (player.map_x < 1) player.map_x = 1;
      player.map_y = player.y - 13;
      if (player.map_y < 1) player.map_y = 1;
      show_map();
      }
    show_player();
    } /* void move_up_left() */

  void move_up_right() {
    remove_player();
    player.y--;
    player.x++;
    if (valid(player.x,player.y) == ' ') {
      player.x--;
      player.y++;
      }
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x--;
      player.y++;
      }
    if ((player.x-player.map_x>14) || (player.y-player.map_y<1)) {
      player.map_x = player.x - 2;
      if (player.map_x > 85) player.map_x = 85;
      player.map_y = player.y - 13;
      if (player.map_y < 1) player.map_y = 1;
      show_map();
      }
    show_player();
    } /* void move_up_right() */

  void move_down_left() {
    remove_player();
    player.y++;
    player.x--;
    if (valid(player.x,player.y) == ' ') {
      player.x++;
      player.y--;
      }
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x++;
      player.y--;
      }
    if ((player.x-player.map_x<1) || (player.y-player.map_y>14)) {
      player.map_x = player.x - 13;
      if (player.map_x < 1) player.map_x = 1;
      player.map_y = player.y - 2;
      if (player.map_y > 85) player.map_y = 85;
      show_map();
      }
    show_player();
    } /* void move_down_left() */

  void move_down_right() {
    remove_player();
    player.y++;
    player.x++;
    if (valid(player.x,player.y) == ' ') {
      player.x--;
      player.y--;
      }
    if (player.map[player.x][player.y] < 0 &&
        player.monster[1][0-player.map[player.x][player.y]].special < 10) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0))
        arena(0-player.map[player.x][player.y],7);
      else hit_enemy();
      player.x--;
      player.y--;
      }
    if ((player.x-player.map_x>14) || (player.y-player.map_y>14)) {
      player.map_x = player.x - 2;
      if (player.map_x > 85) player.map_x = 85;
      player.map_y = player.y - 2;
      if (player.map_y > 85) player.map_y = 85;
      show_map();
      }
    show_player();
    } /* void move_down_right() */

  void remove_bones() {
    }

  void down_level() {
    if (player.map[player.x][player.y] == 24 ||
        player.map[player.x][player.y] == 5) {
      player.d_level++;
      make_map();
      player.x = u_random(80) + 10;
      player.y = u_random(80) + 10;
      while (player.map[player.x][player.y] != 7)  {
        player.x = u_random(80) + 10;
        player.y = u_random(80) + 10;
        }
      if (player.gateway != '*') player.map[player.x][player.y] = 25;
      player.map_x = player.x - 8;
      player.map_y = player.y - 8;
      if (player.map_x < 1) player.map_x = 1;
      if (player.map_y < 1) player.map_y = 1;
      if (player.map_x > 84) player.map_y = 84;
      if (player.map_y > 84) player.map_y = 84;
      show_screen();
      }
    } /* void down_level() */

  void up_level() {
    if (player.map[player.x][player.y] == 25) {
      player.d_level--;
      if (player.d_level != 0) make_map();
      player.x = u_random(80) + 10;
      player.y = u_random(80) + 10;
      while (player.map[player.x][player.y] != 7)  {
        player.x = u_random(80) + 10;
        player.y = u_random(80) + 10;
        }
      if (player.gateway != '*') player.map[player.x][player.y] = 24;
      player.map_x = player.x - 8;
      player.map_y = player.y - 8;
      if (player.map_x < 1) player.map_x = 1;
      if (player.map_y < 1) player.map_y = 1;
      if (player.map_x > 84) player.map_y = 84;
      if (player.map_y > 84) player.map_y = 84;
      if (player.d_level != 0) show_screen();
      }
    } /* void up_level() */

  void do_inventory() {
    OBJECT_REC* item;
/*
    int i;
*/
    saveScreen();
    item = inventory(NULL);
    restoreScreen();
    auto_detect();
/*
    if (item != NULL) {
      i = find_item_slot();
      player.map[player.x][player.y] = i + 1000;
      show_spot(player.x,player.y);
      show_player();
      }
*/
    } /* void do_inventory() */

/*
  void do_quaff() { 
    OBJECT_REC *item;
    int src;
    item = NULL;
    inv_item = 0;
    src = -1;
    if (player.map[player.x][player.y]>=1000 &&
        player.map[player.x][player.y]<2000) {
      src = player.map[player.x][player.y] - 1000;
      item = &(player.map_objects[src]);
      }
    if (item == NULL) {
      saveScreen();
      item = inventory(0); 
      restoreScreen();
      src = -1;
      }
    if (item != NULL && item->otype == O_POTN) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        if (src >= 0) player.map[player.x][player.y] = 7;
        }
      perform_effect(item);
      }
    if (clair == ' ') show_screen();
    clair = ' ';
    }
*/

/*
  void eat() {
    OBJECT_REC* item;
    int src;
    inv_item = 0;
    item = NULL;
    if (player.health > 100) {
      clear_prompt();
      msg("Too full to eat any more",14);
      return;
      }
    src = -1;
    if (player.map[player.x][player.y] >= 1000 &&
        player.map[player.x][player.y] < 2000) {
      src = player.map[player.x][player.y] - 1000;
      item = &(player.map_objects[src]);
      }
    if (item == NULL) {
      saveScreen();
      item = inventory(NULL);
      restoreScreen();
      }
    if (item != NULL && item->otype == O_FOOD) {
      if (item->charges != -1 && item->charges != 0) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        if (src >= 0) player.map[player.x][player.y] = 7;
        }
      perform_effect(item);
      }
    show_spot(player.x,player.y);
    show_player();
    show_side();
    }
*/

/*
  void zap_a_wand() {
    OBJECT_REC* item;
    item = inventory(NULL);
    show_screen();
    if (item != NULL && item->otype == O_WAND) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) item->otype = O_NONE;
      perform_effect(item);
      }
    show_side();
    }
*/

  void use_item() { 
    OBJECT_REC  it;
    OBJECT_REC* item;
    item = NULL;
    if (player.map[player.x][player.y] >= 1000 &&
        player.map[player.x][player.y] < 2000) {
      it = player.map_objects[player.map[player.x][player.y] - 1000];
      player.map_objects[player.map[player.x][player.y] - 1000].otype = O_NONE;
      item = &it;
      player.map[player.x][player.y] = 7;
      show_spot(player.x,player.y);
      }
    saveScreen();
    item = inventory(item);
    restoreScreen();
    show_spot(player.x,player.y);
    show_player();
    if (item != NULL) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) item->otype = O_NONE;
      perform_effect(item);
      }
    graphmode();
    if (clair == ' ') show_map();
    show_sm_map();
    discover();
    show_side();
    show_player();
    show_messages();
    clair = ' ';
    } /* void use_item() */

/*
  void do_read() {
    int src;
    OBJECT_REC* item;
    item = NULL;
    inv_item = 0;
    src = -1;
    if (player.map[player.x][player.y] >= 1000 &&
        player.map[player.x][player.y] < 2000) {
      src = player.map[player.x][player.y] - 1000;
      item = &(player.map_objects[src]);
      }
    if (item == NULL) {
      saveScreen();
      item = inventory(0); 
      restoreScreen();
      }
    if (item != NULL && (item->otype == O_SCRL ||
                         item->otype == O_BOOK)) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        if (src >= 0) player.map[player.x][player.y] = 7;
        }
      perform_effect(item);
      }
    show_spot(player.x,player.y);
    show_player();
    show_side();
    if (clair != ' ') show_screen();
    clair = ' ';
    } 
*/

  void do_get() {
    int i;
    OBJECT_REC* item;
    char buffer[80];
    if (player.map[player.x][player.y] >= 2000 &&
        player.map[player.x][player.y] < 3000) {
      saveScreen();
      i = 0;
      while (i < NO_OF_LORE) {
        if (lore[i].link == player.map[player.x][player.y]-1000) {
          show_lore(i);
          player.quests[player.dungeon_number] = 'Y';
          } 
        i++;
        }
      restoreScreen();
      }
    else if (player.map[player.x][player.y] >= 1000 &&
        player.map[player.x][player.y] < 2000) {
      item=&(player.map_objects[player.map[player.x][player.y] - 1000]);
      player.map[player.x][player.y] = 7;
      saveScreen();
      inventory(item);
      restoreScreen();
      item->otype = O_NONE;
      }
    else if (player.map[player.x][player.y] == 84) {
      player.torch++;
      player.map[player.x][player.y] = 7;
      i = 0;
      show_spot(player.x,player.y);
      show_player();
      }
    else if (player.map[player.x][player.y] == 79) {
      i = u_random(player.diff * 10 + player.d_level)+1;
      clear_prompt(); 
      sprintf(buffer,"Found %d Gold Pieces",i);
      msg(buffer,14);
      player.map[player.x][player.y] = 7;
      player.gold += i;
      i = 0;
      show_spot(player.x,player.y);
      show_player();
      }
    else {
      saveScreen();
      inventory(NULL);
      restoreScreen();
      }
    show_spot(player.x,player.y);
    show_player();
    auto_detect();
    } /* void do_get() */

  void fire_weapon() {
    if (player.invent[2].otype == O_BOW)
      fire(player.invent[2].damage,NULL);
    if (player.invent[2].otype == O_PROJ)
      missile(player.invent[2].damage);
    } /* void fire_weapon() */

  void throw() {
    int hand;
    int damage;
    hand = 0;
    clear_prompt();
    prompt("<L>eft, or <R>ight hand ?");
    key = inkey();
    if (key == 'l' || key == 'L') hand = 1;
    if (key == 'r' || key == 'R') hand = 2;
    if (hand != 0) {
      if (player.invent[hand].otype == O_DAGR) damage = objects[1].damage * 4;
      else damage = 8;
      fire(damage,&(player.invent[hand]));
      if (hand == 2) player.weapon = 0;
      player.invent[hand].otype = O_NONE;
      }
    } /* void throw() */

  void talk() {
    char key;
    char flag;
    int  mon;
    int  xdir,ydir;
    clear_prompt();
    prompt("Talk to who?");
    flag = ' ';
    while (flag == ' ') {
      key = inkey();
      if (key >= '1' && key < '5') flag = '*';
      if (key > '5' && key <= '9') flag = '*';
      }
    xdir = 0;
    ydir = 0;
    switch (key) {
      case '2':ydir = 1; break;
      case '8':ydir = -1; break;
      case '4':xdir = -1; break;
      case '6':xdir = 1; break;
      case '1':xdir = -1; ydir = 1; break;
      case '3':xdir = 1; ydir = 1; break;
      case '7':xdir = -1; ydir = -1; break;
      case '9':xdir = 1; ydir = -1; break;
      }
    mon = player.map[player.x + xdir][player.y + ydir];
    if (mon >= 0) {
      clear_prompt();
      msg("No one there ! ! !",14);
      }
    if (mon < 0) {
      mon = 0 - mon;
      if (player.monster[1][mon].special < 10) {
        clear_prompt();
        prompt("Die Scum!!!");
        }
      else {
        if (player.monster[1][mon].special < 20) {
          player.monster[1][mon].special += 10;
          if (player.in_city == 'Y' && player.city == 17) special(51);
            else special(20);
/*          show_screen(); */
          }
        else {
          clear_prompt();
          msg("Hello!!",9);
          }
        }
      }
    } /* void talk() */

  void make_assassin() {
    player.class = 7;
    strcpy(player.title,"Rogue");
    player.exp = 0;
    player.exp_next = 1e5;
    player.align = 0;
    } /* void make_assassin() */

  void light_torch() {
    if (player.torch > 0) {
      player.torch--;
      player.effect[PE_LIGHT] = 2000;
      show_side();
      }
    } /* void light_torch() */

  void cast_spell(int number) {
    int spell;
    int am,mn;
    spell = castspell(number);
    if (spell != 0 && player.cmana >= mana_cost(spells[spell].mana)) {
      player.cmana -= mana_cost(spells[spell].mana);
      if (spells[spell].user_hp != 0) {
        mn = trunc(spells[spell].user_hp * 0.3);
        am = u_random(spells[spell].user_hp) + 1;
        if (am < mn) am = mn;
        player.chp += am;
        if (player.chp > player.mhp) player.chp = player.mhp;
        }
      if (spells[spell].user_health != 0) {
        player.health += u_random(spells[spell].user_health) + 1;
        if (player.health > 100) player.health = 100;
        } 
      switch (spells[spell].effect) {
        case 1:do_blink();
        case 2:player.effect[PE_PROT] = u_random(spells[spell].level * 8);
               player.effect[PE_APROT] = spells[spell].control; 
               break;
        case 3:touch(spells[spell].control); break;
        case 4:missile(spells[spell].control); break;
        case 6:do_sleep(); break;
        case 7:special(spells[spell].control); break;
        case 8:fear(); break;
        case 9:missile9(spells[spell].control); break;
        case 10:blind(); break;
        case 11:area25(spells[spell].control); break;
        case 12:drain(spells[spell].control); break;
        case 13:area49(spells[spell].control); break;
        case 14:super(spells[spell].control); break;
        }
      }
    else {
      clear_prompt();
      msg("Not enough Mana!!",14);
      }
    show_side();
    } /* void cast_spell(int number) */

  void join() {
    char key;
    char flag;
    int  mon;
    int  pos;
    int  xdir,ydir;
    int  i;
    clear_prompt();
    prompt("Ask who to join?");
    flag = ' ';
    while (flag == ' ') {
      key = inkey();
      if (key >= '1' && key < '5') flag = '*';
      if (key > '5' && key <= '9') flag = '*';
      }
    xdir = 0;
    ydir = 0;
    switch (key) {
      case '2':ydir = 1; break;
      case '8':ydir = -1; break;
      case '4':xdir = -1; break;
      case '6':xdir = 1; break;
      case '1':xdir = -1; ydir = 1; break;
      case '3':xdir = 1; ydir = 1; break;
      case '7':xdir = -1; ydir = -1; break;
      case '9':xdir = 1; ydir = -1; break;
      }
    mon = player.map[player.x + xdir][player.y + ydir];
    if (mon >= 0) {
      clear_prompt();
      msg("No one there ! ! !",14);
      }
    if (mon < 0) {
      mon = 0-mon;
      if (player.monster[1][mon].special<10) {
          clear_prompt();
          msg("No Way Scum!!!",14);
        }
      else
        if (player.monster[1][mon].special<20) {
            if (u_random(100)<(50+(player.level-player.monster[1][mon].level)*10)) {
                if (player.party[1].hp == 0) pos = 1;
                  else if (player.party[2].hp == 0) pos = 2;
                  else if (player.party[3].hp == 0) pos = 3;
                  else if (player.party[4].hp == 0) pos = 4;
                  else if (player.party[5].hp == 0) pos = 5;
                  else pos = 0;
                if (pos>0) {
                    clear_prompt();
                    msg("I would be Honored!!!",15);
                    player.party[pos] = player.monster[1][mon];
                    player.party[pos].exp = needed(player.party[pos].level);
                    player.party[pos].time = 255;
                    player.party[pos].special = player.party[pos].special-10;
                    player.map[player.x+xdir][player.y+ydir] = player.party[pos].prev;
                    show_spot(player.x+xdir,player.y+ydir);
                  }
                else {
                    clear_prompt();
                    msg("Your party seems full as it is!!",14);
                  }
              }
            else {
                clear_prompt();
                msg("No Thanks.",14);
              }
          }
        else {
            clear_prompt();
            msg("No Thanks.",14);
          }
    }
  player.mount = 0; player.peg = 0;
  for (i=1; i<=5; i++)
    if (player.party[i].hp>0) {
      if (player.party[i].sprite == 133) player.peg = 1;
      if (player.party[i].sprite == 148) player.mount = 1;
      if (player.party[i].sprite == 131) player.mount = 1;
      if (player.party[i].sprite == 132) player.mount = 1;
      if (player.party[i].sprite == 138) player.mount = 1;
      if (player.party[i].sprite == 155) player.peg = 1;
      if (player.party[i].sprite == 159) player.peg = 1;
      if (player.peg == 1) player.mount = 1;
      }
    } /* void join() */

  void buy_item() {
    int flag;
    for (i=0; i<5; i++) {
      if (player.region == player.houses[i].region &&
          player.land_x == player.houses[i].rx &&
          player.land_y == player.houses[i].ry &&
          player.x >= player.houses[i].cx-1 &&
          player.x <= player.houses[i].cx+1 &&
          player.y >= player.houses[i].cy-1 &&
          player.y <= player.houses[i].cy+1) {
        saveScreen();
        house_inventory(i);
        restoreScreen();
        return;
        }
      }
    flag = -1;
    i = 0;
    while (flag == -1) {
      if (player.region == forsale[i].region &&
          player.land_x == forsale[i].rx &&
          player.land_y == forsale[i].ry &&
          player.x >= forsale[i].cx-1 &&
          player.x <= forsale[i].cx+1 &&
          player.y >= forsale[i].cy-1 &&
          player.y <= forsale[i].cy+1) flag = i;
      if (forsale[i].region == 999) flag = -2;
      i++;
      }
    for (i=0; i<5; i++) {
      if (forsale[i].region == player.houses[i].region &&
          forsale[i].rx == player.houses[i].rx &&
          forsale[i].ry == player.houses[i].ry &&
          forsale[i].cx == player.houses[i].cx &&
          forsale[i].cy == player.houses[i].cy) flag = -1;
      }
    if (flag >= 0) {
      saveScreen();
      buy_house(flag);
      restoreScreen();
      return;
      }

    flag = -1;
    i = 0;
    while (flag == -1) {
      if (player.region == shops[i].region &&
          player.land_x == shops[i].rx &&
          player.land_y == shops[i].ry &&
          player.x >= shops[i].cx-1 &&
          player.x <= shops[i].cx+1 &&
          player.y >= shops[i].cy-1 &&
          player.y <= shops[i].cy+1) flag = i;
      if (shops[i].shoptype == 999) flag = -2;
      i++;
      }
    if (flag >= 0) {
      saveScreen();
      switch (shops[flag].shoptype) {
        case  0:shop(shops[flag].name,SHOP_WEAP); break;
        case  1:shop(shops[flag].name,SHOP_ARMR); break;
        case  2:shop(shops[flag].name,SHOP_ALCH); break;
        case  3:shop(shops[flag].name,SHOP_JEWL); break;
        case  4:shop(shops[flag].name,SHOP_BOOK); break;
        case  5:shop(shops[flag].name,SHOP_ROBE); break;
        case  6:shop(shops[flag].name,SHOP_MAGC); break;
        case  7:library(shops[flag].name); break;
        case  8:tavern(shops[flag].name); break;
        case  9:school(shops[flag].name); break;
        case 10:travel(shops[flag].name); break;
        case 11:shop(shops[flag].name,SHOP_FOOD); break;
        case 12:pawn(shops[flag].name,1); break;
        case 13:temple(shops[flag].name); break;
        case 14:cavalier(shops[flag].name); break;
        case 15:mounts(shops[flag].name); break;
        case 16:bank(shops[flag].name); break;
        }
/*      show_screen(); */
      restoreScreen();
      show_player();
      }
    } /* void buy_item() */

  dc = 1;
  if (player.in_city == 'Y') check_noble();
  player.mount = 0; player.peg = 0;
  for (i=1; i<=5; i++)
    if (player.party[i].hp>0) {
      if (player.party[i].sprite == 133) player.peg = 1;
      if (player.party[i].sprite == 148) player.mount = 1;
      if (player.party[i].sprite == 131) player.mount = 1;
      if (player.party[i].sprite == 132) player.mount = 1;
      if (player.party[i].sprite == 138) player.mount = 1;
      if (player.party[i].sprite == 155) player.peg = 1;
      if (player.party[i].sprite == 159) player.peg = 1;
      if (player.peg == 1) player.mount = 1;
      }
  h_count = 0;
  word_counter = 0;
  haste_flag = ' ';
  clair = ' ';
  napping = ' ';
  graphmode();
  if (mod_exit == 2 && player.d_level == 0) {
      player.x = 20; player.y = 20;
      player.map[player.x][player.y] = 24;
      player.d_level = 0;
      down_level();
      if (player.gateway != '*') player.map[player.x][player.y] = 25;
    }
  if (mod_exit == 5) {
      player.d_level = 1;
      copyMap(&player.map,player.city);
      m_file = open("temp01.$$$",O_RDONLY);
      if (m_file < 0) {
        printf("Fatal Error: Could not open temp01.$$$\n");
        exit(1);
        }
      lseek(m_file,sizeof(KNOW_TYPE) * player.city,SEEK_SET);
      read(m_file,&(player.known),sizeof(KNOW_TYPE));
      close(m_file);
      i = 0;
      player.x = 50; player.y = 2;
      while (i >= 0) {
        if (links[i].region >= 99) i = -1;
        else if (links[i].region == player.region &&
            links[i].x      == player.land_x &&
            links[i].y      == player.land_y) {
          player.x = links[i].sx;
          player.y = links[i].sy;
          i = -1;
          } else i++; 
        }
      stock_town(player.city);
      player.map_x = player.x-8;
      player.map_y = player.y-8;
      if (player.map_x<1) player.map_x = 1;
      if (player.map_y<1) player.map_y = 1;
      if (player.map_x>84) player.map_x = 84;
      if (player.map_y>84) player.map_y = 84;

      i = 0;
      while (i >= 0) {
        if (shops[i].shoptype != 999) {
          if (shops[i].region == player.region &&
              shops[i].rx == player.land_x &&
              shops[i].ry == player.land_y)
            player.map[shops[i].cx][shops[i].cy] = 520;
          i++;
          } else i = -1;
        }
      i = 0;
      while (i >= 0) {
        if (forsale[i].region != 999) {
          if (forsale[i].region == player.region &&
              forsale[i].rx == player.land_x &&
              forsale[i].ry == player.land_y)
            player.map[forsale[i].cx][forsale[i].cy] = S_SALE;
          i++;
          } else i = -1;
        }
      for (i=0; i<5; i++)
        if (player.houses[i].region == player.region &&
            player.houses[i].rx == player.land_x &&
            player.houses[i].ry == player.land_y)
          player.map[player.houses[i].cx][player.houses[i].cy] = S_SOLD;

    }
  show_map();
  show_sm_map();
  discover();
  show_side();
  show_player();
  auto_detect();
  exitf = 0;
  while (exitf == 0) {
      if (player.effect[PE_SLEEP] != 0) key = ' ';
        else key = inkey();
      if (player.effect[PE_CONFUSED] > 0) {
        if (key == '1' || key == '2' || key == '3' || key == '4' ||
            key == '6' || key == '7' || key == '8' || key == '9') {
          switch (u_random(8)) {
            case 0:key = '1'; break;
            case 1:key = '2'; break;
            case 2:key = '3'; break;
            case 3:key = '4'; break;
            case 4:key = '6'; break;
            case 5:key = '7'; break;
            case 6:key = '8'; break;
            case 7:key = '9'; break;
            }
          }
        }
      switch (key) {
        case 'a':attack(); break;
        case 'Q':exitf = 1; break;
        case 'X':exitf = 4; break;
        case '8':move_up(); break;
        case '2':move_down(); break;
        case '4':move_left(); break;
        case '6':move_right(); break;
        case '7':move_up_left(); break;
        case '9':move_up_right(); break;
        case '1':move_down_left(); break;
        case '3':move_down_right(); break;
        case '>':down_level(); break;
        case '<':up_level(); break;
        case 's':search(); break;
        case 'H':show_icons(); break;
        case 'o':open_door(); break;
        case 'c':close_door(); break;
        case 'C':saveScreen(); crafting(); restoreScreen(); break;
        case 'i':do_inventory(); break;
        case 'g':do_get(); break;
        case 'q':show_quest(); break;
/*        case 'z':zap_a_wand(); break;  */
        case 'u':use_item(); break;
        case 'E':go_ship(); break;
/*        case 'e':eat(); break;         */
/*        case 'r':do_read(); break;     */
        case 'f':fire_weapon(); break;
        case 'm':cast_spell(0); break;
        case 161:cast_spell(1); break;
        case 192:cast_spell(2); break;
        case 163:cast_spell(3); break;
        case 164:cast_spell(4); break;
        case 165:cast_spell(5); break;
        case 222:cast_spell(6); break;
        case 166:cast_spell(7); break;
        case 170:cast_spell(8); break;
        case 168:cast_spell(9); break;
        case 169:cast_spell(10); break;
        case 'n':nap(); break;
        case 't':talk(); break;
        case 'T':throw(); break;
        case 'j':join(); break;
        case 'J':lock_door(); break;
        case 'p':party(); break;
        case 'P':if (player.map[player.x][player.y]>999) pack_it(7);
                 break;
        case 'l':light_torch(); break;
        case 'L':show_log(); break;
        case 'w':if (player.gateway != '*') {
                  if (word_counter == 0) say_word();
                  }
                 else {
                 clear_prompt();
                 msg("Words do Not work Here!!",12);
                 }
              break;
        case 'b':buy_item(); break;
        case 'S':
              saveScreen();
              save();
              restoreScreen();
/*              show_screen(); */
              break;
        case 'v':view(7); break;
        case 'V':soundon = (soundon == 'Y') ? 'N' : 'Y';
              break;
        case 'R':
              saveScreen();
              disp_char();
              restoreScreen();
/*              show_screen(); */
              break;
        case 'h':if (h_count == 0) healing();
              break;
        case '?':dungeon_help(); break;
        case 'Z':show_number(); break;
        case ':':wizard(); break;
        }
    key = ' ';
    discover();
    if (player.align <= 0 && player.class != 7) make_assassin();
    while (player.exp >= player.exp_next) { advancement(); show_side(); }
    if (has_intrinsic(A_TRAP)) {
      for (x=player.x-1; x<=player.x+1; x++)
        for (y=player.y-1; y<=player.y+1; y++)
          if (player.map[x][y] >= 800 && player.map[x][y] < 900) {
            player.known[x][y] = 1;
            player.map[x][y] = 40;
            show_spot(x,y);
            }
      }
    if (has_intrinsic(A_IDNT)) {
      if (player.map[player.x][player.y] >= 1000 && player.map[player.x][player.y] < 2000) {
        if (player.map_objects[player.map[player.x][player.y]-1000].level >= 0) {
          player.map_objects[player.map[player.x][player.y]-1000].level = -1;
          msg(get_name(&(player.map_objects[player.map[player.x][player.y]-1000])),14);
          }
        }
      }
    if (player.map[player.x][player.y] == 801 && player.effect[PE_SLEEP] != 0) {
      if (has_intrinsic(A_LEV) == 0) sleep_trap();
      }
    if (player.map[player.x][player.y] == 802) {
      if (has_intrinsic(A_LEV) == 0) poison_trap();
      }
    if (player.map[player.x][player.y] == 803) {
      if (has_intrinsic(A_LEV) == 0) dart_trap();
      }
    if (player.map[player.x][player.y] == 804) {
      if (has_intrinsic(A_LEV) == 0) teleport_trap();
      }
    if (player.map[player.x][player.y] == 41) {
        clear_prompt();
        msg("ZZZZAAAAPPPP!!!!!",12);
        player.chp = player.chp / 2;
        show_side();
      }
    if (player.map[player.x][player.y] == 38) {
        clear_prompt();
        msg("SIZZLE!!!!!",12);
        player.chp = player.chp / 2;
        show_side();
      }
    if (player.map[player.x][player.y] == 39) {
        clear_prompt();
        msg("GLUB GLUB!!!",12);
        player.chp = player.chp / 2;
        show_side();
      }
    if (has_intrinsic(A_SRCH)) search();
    if (haste_flag == ' ') {
        for (x=player.x-15; x<=player.x+15; x++)
          for (y=player.y-15; y<=player.y+15; y++)
            if (x>0 && x<100 && y>0 && y<100)
            if (player.map[x][y]<0)
            if (player.monster[1][0-player.map[x][y]].special<100)
            if (player.monster[1][0-player.map[x][y]].sleep == 0) {
                if ((player.monster[1][0-player.map[x][y]].mana != 0) &&
                    (player.monster[1][0-player.map[x][y]].special<10))
                      if (u_random(100)<50) enemy_missile(x,y);
                      move_enemy(x,y);
              }
        for (x=1; x<=60; x++)
          if (player.monster[1][x].special>90)
            player.monster[1][x].special -= 100;
        for (x=player.x-1; x<=player.x+1; x++)
          for (y=player.y-1; y<=player.y+1; y++)
            if (x>0 && x<100 && y>0 && y<100)
              if (player.map[x][y]<0)
                if (player.monster[1][0-player.map[x][y]].special<10)
                  enemy_hit(x,y);
        for (x=1; x<=5; x++) {
            if (player.party[x].sleep>0) player.party[x].sleep--;
            if (player.party[x].fear>0) player.party[x].fear--;
          }
        for (x=1; x<=60; x++) {
            if (player.monster[1][x].sleep>0) player.monster[1][x].sleep--;
            if (player.monster[1][x].fear>0) player.monster[1][x].fear--;
            if (player.monster[1][x].blind>0) player.monster[1][x].blind--;
            if (player.monster[1][x].confused>0) player.monster[1][x].confused--;
            if (player.monster[1][x].poison>0) {
              player.monster[1][x].poison--;
              player.monster[1][x].hp -= 2;
              dead_monster(&(player.monster[1][x]),'Y');
              }
          }
      }
    if (haste_flag == '*')  haste_flag = ' ';
      else {
          if (has_intrinsic(A_SPD)) haste_flag = '*';
        }
    if (word_counter>0)  word_counter--;
    dc--;
    if (dc == 0) {
        if (player.effect[PE_PROT]>0) {
            player.effect[PE_PROT]--;
            if (player.effect[PE_PROT] == 0)  show_side();
          }
        if (player.effect[PE_FIRE]>0) {
            player.effect[PE_FIRE]--;
            if (player.effect[PE_FIRE] == 0)  show_side();
          }
        if (player.effect[PE_HASTE]>0) {
            player.effect[PE_HASTE]--;
            if (player.effect[PE_HASTE] == 0)  show_side();
          }
        if (player.effect[PE_GIANT]>0) {
            player.effect[PE_GIANT]--;
            if (player.effect[PE_GIANT] == 0)  show_side();
          }
        dc = 1+trunc(player.level/6.0);
      }

    if (player.class == 10) 
      {
        if (player.level>=23)  player.effect[PE_HASTE] = 10;
        if (player.level>=17 && napping != '*')  player.effect[PE_SLEEP] = 0;
        if (player.level>=29)  player.effect[PE_POISON] = 0;
        if (player.level>=11)  player.effect[PE_FEAR] = 0;
        check_monk_weapon();
      }
      if (player.effect[PE_ETHER]>0) {
          player.effect[PE_ETHER]--;
          if (player.effect[PE_ETHER] == 0) show_side();
          if (player.effect[PE_ETHER] == 10) show_side();
        }
      if (player.effect[PE_POISON]>0) {
          player.effect[PE_POISON]--;
          player.chp--; show_side();
        }
      if (h_count>0) h_count--;
      if (player.effect[PE_READLORE]>0) player.effect[PE_READLORE]--;
      if (player.effect[PE_READLANG]>0) player.effect[PE_READLANG]--;
      if (player.effect[PE_FEAR]>0) player.effect[PE_FEAR]--;
      if (player.effect[PE_CONFUSED]>0) player.effect[PE_CONFUSED]--;
      if (player.effect[PE_LEV]>0) player.effect[PE_LEV]--;
      if (player.effect[PE_BLIND]>0) {
        player.effect[PE_BLIND]--;
        if (player.effect[PE_BLIND] == 0) show_map();
        }
      if (player.effect[PE_SLEEP]>0) {
          player.effect[PE_SLEEP]--;
          if (player.effect[PE_SLEEP] == 0) {
              if (napping == '*') napping = ' ';
              show_spot(player.x,player.y);
              show_player();
            }
        }
      if (player.effect[PE_LIGHT]>0) {
          player.effect[PE_LIGHT]--;
          if (player.effect[PE_LIGHT] == 0) show_side();
        }
      if (player.phase>0) {
          player.phase--;
          if (player.phase == 0) {
              for (x=1; x<=100; x++)
                for (y=1; y<=100; y++)
                  if (player.map[x][y] == 42) player.map[x][y] = 21;
              show_map();
            }
        }
      for (i=1; i<=5; i++) if (player.party[i].hp != 0)
        if (player.party[i].time<255 && player.party[i].time>0) {
            player.party[i].time--;
            if (player.party[i].time == 0)
              player.party[i].hp = 0;
          }
      player.hp_count--;
      if (napping == '*') {
        player.hp_count -= 5;
        if (has_intrinsic(A_NPHL)) player.hp_count -= 15;
        }

      for (i=1; i<=19; i++) {
        if (player.invent[i].otype != O_NONE) {
          if ((i==I_NCK1 || i==I_NCK2) &&
              player.invent[i].otype == O_NECK &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if ((i==I_RNG1 || i==I_RNG2 || i==I_RNG3 || i==I_RNG4) &&
              player.invent[i].otype == O_RING &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (i==I_SHLD &&
              player.invent[i].otype == O_SHLD &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (i==I_ARMR &&
              player.invent[i].otype == O_ARMR &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (i==I_ROBE &&
              player.invent[i].otype == O_ROBE &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (i==I_BOOT &&
              player.invent[i].otype == O_BOOT &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (i==I_HELM &&
              player.invent[i].otype == O_HELM &&
              player.invent[i].effect == E_INTR &&
              player.invent[i].control == A_HEAL) 
            player.hp_count -= player.invent[i].damage;
          else if (player.invent[i].otype != O_NECK &&
                   player.invent[i].otype != O_RING &&
                   player.invent[i].otype != O_SHLD &&
                   player.invent[i].otype != O_ARMR &&
                   player.invent[i].otype != O_ROBE &&
                   player.invent[i].otype != O_BOOT &&
                   player.invent[i].otype != O_HELM &&
                   player.invent[i].effect == E_INTR &&
                   player.invent[i].control == A_HEAL) 
                 player.hp_count -= player.invent[i].damage;
          }
        }

      if (player.class == 2) player.hp_count -= 3;
      if (player.class == 3) player.hp_count -= 2;
      if (player.class == 5) player.hp_count -= 2;
      if (player.hp_count<1) {
          player.hp_count = 20;
          if (player.chp<player.mhp) player.chp = player.chp+1;
          show_side();
        }
      player.mana_count--;
      if (napping == '*') player.mana_count -= 5;
      if (player.mana_count<1) {
          player.mana_count = 20;
          if (player.cmana<player.mmana) player.cmana = player.cmana+1;
          show_side();
        }
      take_time();
      if (player.in_city == 'Y')
        if (player.x == 1 || player.x == 100 ||
            player.y == 1 || player.y == 100) {
            m_file = open("temp01.$$$",O_RDWR);
            if (m_file < 0) {
              printf("Fatal Error: Could not open temp01.$$$\n");
              exit(1);
              }
            lseek(m_file,sizeof(KNOW_TYPE)*player.city,SEEK_SET);
            write(m_file,&(player.known),sizeof(KNOW_TYPE));
            close(m_file);
            exitf = 2;
          }
      if (has_intrinsic(A_DTUP) || has_intrinsic(A_DTDN)) {
        sx = -1; sy = -1;
        d = 99999.0;
        for (x=1; x<=100; x++)
          for (y=1; y<=100; y++)
            if ((player.map[x][y] == S_UPSTAIR && has_intrinsic(A_DTUP)) ||
                (player.map[x][y] == S_DNSTAIR && has_intrinsic(A_DTDN)) ) {
              if ((x-player.x)*(x-player.x) + (y-player.y)*(y-player.y) < d) {
                sx = x;
                sy = y;
                d = (x-player.x)*(x-player.x) + (y-player.y)*(y-player.y);
                }
              }
        if (sx >= 0) {
          if (abs(player.x-sx)<4 && player.y<sy) x = 92;
          else if (abs(player.x-sx)<4 && player.y>sy) x = 91;
          else if (player.x<sx && abs(player.y-sy)<4) x = 93;
          else if (player.x>sx && abs(player.y-sy)<4) x = 94;
          else if (player.x<sx && player.y<sy) x = 97;
          else if (player.x>sx && player.y<sy) x = 98;
          else if (player.x<sx && player.y>sy) x = 95;
          else if (player.x>sx && player.y>sy) x = 96;
          else x = 10;
          putimage(300,453,select_sprite(10),0);
          putimage(300,453,select_sprite(x),0);
          } else putimage(300,453,select_sprite(10),0);
        } else putimage(300,453,select_sprite(10),0);
      if (player.d_level == 0) exitf = 2;
      if (player.chp<1) exitf = 6;
      if (player.health<=0) exitf = 6;
    if (has_intrinsic(A_FOOD) && player.health < 100) player.health++;
    }
  if (exitf == 1) mod_exit = 3;
  if (exitf == 2) mod_exit = 1;
  if (exitf == 4) mod_exit = 4;
  if (exitf == 6) mod_exit = 6;
  remove_bones();
  }

