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

void arena(int monster,int floor) {
  KNOW_TYPE tmp_known;
  MAP_TYPE  tmp_map;
  byte key;
  int  hold_x;
  int  hold_y;
  int  hold_mapx;
  int  hold_mapy;
  int  i,j;
  char flag;
  char haste_flag;
  byte sfloor;
  byte ofloor;
  int  x,y;

  void enemy_hit(int x,int y) {
    int i,j;
    int hit;
    int mon;
    mon = player.map[x][y] - 400;
    i = 25 + (player.monster[mon][a_mon].level * 2) +
             (player.monster[mon][a_mon].attack / 2);
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
    if (player.effect[PE_SLEEP] > 0) i += 25;
    if (player.effect[PE_BLIND] > 0) i += 25;
    if (player.monster[mon][a_mon].blind > 0) i -= 25;
    if (player.monster[mon][a_mon].fear > 0) i -= 10;
    if (i < 10) i = 10;
    if (i > 90) i = 90;
    clear_prompt();
    if (u_random(100) < i) {
      prompt("OUCH!!!");
      noise(750,100);
      i = player.monster[mon][a_mon].attack;
      i = u_random(i) + 1;
      switch (player.monster[mon][a_mon].special) {
        case 2:if (player.class != 8 && player.effect[PE_SLEEP] == 0) {
                 hit = 50 + ((player.monster[mon][a_mon].level - player.level) * 5) - player.ability[5] * 2;
                 if (has_intrinsic(A_NOSL)) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   prompt("Slept!!!");
                   if (player.effect[PE_SLEEP] == 0)
                     player.effect[PE_SLEEP] = u_random((player.monster[mon][a_mon].level - player.level) * 5);
                   }
                 }
               break;
        case 3:if (player.class != 8) {
                 hit = 50 + ((player.monster[mon][a_mon].level - player.level) * 5) - player.ability[5] * 2;
                 if (has_intrinsic(A_NOPS)) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   prompt("Poisoned!!!");
                   player.effect[PE_POISON] = u_random(player.monster[mon][a_mon].attack);
                   }
                 }
               break;
        case 5:if (player.class != 8) {
                 hit = 50 + ((player.monster[mon][a_mon].level - player.level) * 5) - player.ability[5] * 2;
                 if (has_intrinsic(A_RSFR)) hit /= 2;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   prompt("Scared!!!");
                   player.effect[PE_FEAR] += u_random((player.monster[mon][a_mon].level - player.level) * 5);
                   }
                 }
               break;
        }
      player.chp -= i;
      if (player.chp < 0) player.chp = 0;
      show_side();
      }
    else {
      prompt("Missed . . .");
      noise(100,100);
      }
    }

  void enemy_attack(int x,int y) {
    char flag;
    int  ex = 0,ey = 0;
    int  i,j;
    int  mon;
    int  target;
    int  hit;
    flag = ' ';
    for (i=x-1; i<=x+1; i++)
      for (j=y-1; j<=y+1; j++)
        if (flag == ' ') {
          if (player.map[i][j]>300 && player.map[i][j]<400) {
            flag = '*';
            ex = i;
            ey = j;
            }
          if (player.x == i && player.y == j) {
            flag = '#';
            ex = i;
            ey = j;
            }
          }
    if (flag == '#') enemy_hit(x,y);
    if (flag == '*') {
      mon = player.map[x][y] - 400;
      target = player.map[ex][ey] - 300;
      i = 50 + player.monster[mon][a_mon].level * 2 +
               player.monster[mon][a_mon].defense * 2;
      if (player.party[target].sleep > 0) i += 50;
      if (player.party[target].fear > 0) i += 25;
      i -= player.party[target].level * 2;
      i -= player.party[target].defense * 2;
      if (i < 20) i = 20;
      if (i > 80) i = 80;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("HIT !!!");
        noise(1000,100);
        if (in_sight(ex,ey) == '*') {
          show_sprite(ex-player.map_x,ey-player.map_y,100);
          delay(250);
          show_spot(ex,ey);
          }
        i = u_random(player.monster[mon][a_mon].attack);
        player.party[target].hp -= i;
        switch (player.monster[mon][a_mon].special) {
          case 2:hit = 50 + ((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                 if (u_random(100) < hit) {
                   clear_prompt();
                   prompt("Slept!!!");
                   player.party[target].sleep = u_random((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                   show_spot(ex,ey);
                   }
          case 5:hit = 50 + ((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                 if (u_random(100) < hit) {
                   clear_prompt();
                   prompt("Scared!!!");
                   player.party[target].fear = u_random((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                   }
          }
        if (player.party[target].hp <= 0) {
          player.map[ex][ey] = floor;
          player.party[target].hp = 0;
          show_spot(ex,ey);
          }
        }
      }
    }

  void party_attack(int x,int y) {
    char flag;
    int  ex = 0,ey = 0;
    int  i,j;
    int  mon;
    int  target;
    flag = ' ';
    for (i=x-1; i<=x+1; i++)
      for (j=y-1; j<=y+1; j++)
        if (flag == ' ')
          if (player.map[i][j]>400 && player.map[i][j]<500) {
            flag = '*';
            ex = i;
            ey = j;
            }
    if (flag != ' ') {
      mon = player.map[x][y] - 300;
      target = player.map[ex][ey] - 400;
      i = 50 + player.party[mon].level * 2 + player.party[mon].defense * 2;
      if (player.monster[target][a_mon].sleep > 0) i += 50;
      if (player.monster[target][a_mon].fear > 0) i += 25;
      i -= player.monster[target][a_mon].level * 2;
      i -= player.monster[target][a_mon].defense * 2;
      if (i < 20) i = 20;
      if (i > 80) i = 80;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("HIT !!!");
        noise(1000,100);
        if (in_sight(ex,ey) == '*') {
          show_sprite(ex-player.map_x,ey-player.map_y,100);
          delay(250);
          show_spot(ex,ey);
          }
        i = u_random(player.party[mon].attack);
        player.monster[target][a_mon].hp -= i;
        if (player.monster[target][a_mon].hp <= 0) {
          player.map[ex][ey] = floor;
          player.monster[target][a_mon].hp = 0;
          show_spot(ex,ey);
          player.party[mon].exp += player.monster[target][a_mon].exp;
          while (player.party[mon].exp > needed(player.party[mon].level + 1)) {
            player.party[mon].level ++;
            player.party[mon].attack += 2;
            player.party[mon].defense += 2;
            if (player.party[mon].mana != 0)
              player.party[mon].mana += 25;
            }
          }
        }
      }
    }

  void arena_party_missile(int ex,int ey) {
    char flag;
    int  x,y;
    int  xdir,ydir;
    int  mon;
    int  dist;
    int  targetx;
    int  targety;
    int  target;
    int  i;

    void find_target() {
      int x1,y1;
      dist = 32000;
      targetx = player.x;
      targety = player.y;
      for (x1 = 10; x1<=26; x1++)
        for (y1= 10; y1<=26; y1++)
          if (player.map[x1][y1]>400 && player.map[x1][y1]<500)
            if (sqr(x1-ex) + sqr(y1-ey) < dist) {
              targetx = x1;
              targety = y1;
              dist = (sqr(x1-ex) + sqr(y1-ey));
              }
      }

    mon = player.map[ex][ey] - 300;
    xdir = 0;
    ydir = 0;
    find_target();
    if (ex < targetx) xdir = 1; else if (ex > targetx) xdir = -1;
    if (ey < targety) ydir = 1; else if (ey > targety) ydir = -1;
    x = ex;
    y = ey;
    flag = ' ';
    if (dist > 30000) flag = '&';
    while (flag == ' ') {
      x += xdir;
      y += ydir;
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(50);
        show_spot(x,y);
        if (x == player.x && y == player.y) show_player();
        }
      if (player.map[x][y] < 255) {
        if (player.map[x][y] == 21 ||
            player.map[x][y] == 22 ||
            player.map[x][y] == 16 ||
            player.map[x][y] == 18 ||
            player.map[x][y] == 20 ||
            player.map[x][y] == 176 ||
            player.map[x][y] == 3 ||
            player.map[x][y] == 178) flag = '*';
        }
      if (player.map[x][y] > 400 && player.map[x][y] < 500) flag = '#';
      }
    if (player.map[x][y]>400 && player.map[x][y]<500 && dist<30000) {
      target = player.map[x][y] - 400;
      i = 90;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("HIT !!!");
        noise(1000,100);
        if (in_sight(x,y) == '*') {
          show_sprite(x-player.map_x,y-player.map_y,100);
          delay(250);
          show_spot(x,y);
          }
        i = u_random(player.party[mon].mana / 4 + 1);
        player.monster[target][a_mon].hp -= i;
        if (player.monster[target][a_mon].hp <= 0) {
          player.map[x][y] = floor;
          player.monster[target][a_mon].hp = 0;
          show_spot(x,y);
          player.party[mon].exp += player.monster[target][a_mon].exp;
          while (player.party[mon].exp > needed(player.party[mon].level + 1)) {
            player.party[mon].level ++;
            player.party[mon].attack += 2;
            player.party[mon].defense += 2;
            if (player.party[mon].mana != 0)
              player.party[mon].mana += 25;
            }
          }

        }
      else {
        clear_prompt();
        prompt("Fizzle. . .");
        }
      }
    }

  void arena_enemy_missile(int ex,int ey) {
    char flag = ' ';
    int  x,y;
    int  xdir,ydir;
    int  mon;
    int  dist;
    int  targetx;
    int  targety;
    int  target;
    int  i,j;
    int  ring;

    void find_target() {
      int x1,y1;
      dist = (sqr(player.x-ex) + sqr(player.y-ey));
      targetx = player.x; targety = player.y;
      for (x1=10; x1<=26; x1++)
        for (y1=10; y1<=26; y1++)
          if (player.map[x1][y1]>300 && player.map[x1][y1]<400)
            if ((sqr(x1-ex) + sqr(y1-ey)) < dist) {
              targetx = x1;
              targety = y1;
              dist = sqr(x1-ex) + sqr(y1-ey);
              }
      }

    mon = player.map[ex][ey] - 400;
    xdir = 0;
    ydir = 0;
    find_target();
    if (ex < targetx) xdir = 1; else if (ex > targetx) xdir = -1;
    if (ey < targety) ydir = 1; else if (ey > targety) ydir = -1;
    x = ex;
    y = ey;
    while (flag == ' ') {
      x += xdir;
      y += ydir;
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(50);
        show_spot(x,y);
        if (x == player.x && y == player.y) show_player();
        }
      if (player.map[x][y] < 255) {
        if (player.map[x][y] == 21 ||
            player.map[x][y] == 22 ||
            player.map[x][y] == 16 ||
            player.map[x][y] == 18 ||
            player.map[x][y] == 20 ||
            player.map[x][y] == 176 ||
            player.map[x][y] == 3 ||
            player.map[x][y] == 178) flag = '*';
        }
      if (player.map[x][y] > 300 && player.map[x][y] < 400) flag = '#';
      if (x == player.x && y == player.y) flag = '*'; 
      }
    if (x == player.x && y == player.y) {
      i = 90;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("HIT !!");
        noise(1000,100);
        if (in_sight(x,y) == '*') {
          show_sprite(x-player.map_x,y-player.map_y,100);
          delay(250);
          show_spot(x,y);
          }
        ring = 0;
        for (j=1; j<=19; j++) {
          if (player.invent[j].otype != O_NONE &&
              player.invent[j].effect == E_INTR &&
              player.invent[j].control == A_REFL) { ring = j; j=99; }
          }
        if (ring == 0) {
          i = u_random(player.monster[mon][a_mon].mana / 4 + 1);
          j = intrinsic_count(A_RFIR);
          while (j > 0) { i /= 2; j--; }
          j = intrinsic_count(A_RELE);
          while (j > 0) { i /= 2; j--; }
          player.chp -= i;
          if (player.chp < 0) player.chp = 0;
          show_player();
          }
        if (ring != 0) {
          r_missile(player.monster[mon][a_mon].mana / 4 + 1);
          i = player.skill[8] + (player.level - player.monster[mon][a_mon].level);
          i += player.ability[10] * 5;
          if (i>0) i += 75;
          if (i > 98) i = 98;
          if (i < 0) {
            player.invent[ring].otype = O_NONE;
            clear_prompt();
            prompt("Ring Melted!!");
            delay(1000);
            }
          if (u_random(101) > i) {
            player.invent[ring].otype = O_NONE;
            clear_prompt();
            prompt("Ring Melted!!");
            delay(1000);
            }
          }
        show_side();
        show_player();
        }
      else {
        clear_prompt();
        prompt("Fizzle. . .");
        show_player();
        }
      }
    if (player.map[x][y] > 300 && player.map[x][y] < 400) {
      target = player.map[x][y] - 300;
      i = 90;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("HIT !!!");
        noise(1000,100);
        if (in_sight(x,y) == '*') {
          show_sprite(x-player.map_x,y-player.map_y,100);
          delay(250);
          show_spot(x,y);
          }
        i = u_random(player.monster[mon][a_mon].mana / 4 + 1);
        player.party[target].hp -= i;
        if (player.party[target].hp <= 0) {
          player.map[x][y] = floor;
          player.party[target].hp = 0;
          show_spot(x,y);
          }
        }
      else {
        clear_prompt();
        prompt("Fizzle. . .");
        }
      }
    }

  void hit_enemy() {
    int i;
    int j;
    int mon;
    i = 25 + (player.weapon/2) + (player.skill[16]*2) + (player.ability[1]*4);
    i += player.level;
    if (player.invent[2].otype == O_EDGE) i += (player.skill[2] * 2);
    if (player.invent[2].otype == O_POLE) i += (player.skill[3] * 2);
    for (j=1; j<=10; j++) {
      if (player.invent[j].otype != O_NONE && player.invent[j].effect == E_INHT)
        i+= player.invent[j].control;
      }
    mon = player.map[player.x][player.y] - 400;
    i -= (player.monster[mon][a_mon].defense * 3);
    if (player.monster[mon][a_mon].fear > 0) i += 10;
    if (player.monster[mon][a_mon].sleep > 0) i += 25;
    if (i < 10) i = 10;
    if (i > 90) i = 90;
    clear_prompt();
    if (u_random(100) < i) {
      prompt("HIT!!!");
      noise(1000,100);
      if ((player.invent[2].otype == O_DAGR ||
           player.invent[2].otype == O_EDGE ||
           player.invent[2].otype == O_POLE) &&
          player.invent[2].effect == E_POSN) {
        player.monster[mon][a_mon].poison += player.invent[2].damage;
        prompt("Poisoned !!!");
        }

      if (player.class == 10) {
        if (u_random(100) < (player.level * 2)) {
          prompt("Paralyzed!");
          noise(1000,100);
          delay(500);
          player.monster[mon][a_mon].sleep = u_random(2 * (player.level - player.monster[mon][a_mon].level));
          show_spot(player.x,player.y);
          if (u_random(500) < player.level) {
            prompt("Killed!");
            noise(1000,100);
            delay(500);
            player.monster[mon][a_mon].hp = 0;
            }
          }
        }
      if (player.monster[mon][a_mon].special > 9) {
        player.align -= 5;
        if (player.align < 0) player.align = 0;
        }
      i = 3 +(player.weapon / 2) + (player.ability[3] * 3);
      if (player.effect[PE_GIANT] > 0) i += (player.weapon / 2);
      i = u_random(i) + 1;
      player.monster[mon][a_mon].hp -= i;
      dead_monster(&(player.monster[mon][a_mon]),'Y');
/*
      if (player.monster[mon][a_mon].hp <= 0) {
        if (strcmp(player.monster[mon][a_mon].name,"Eshter") == 0) eshter();
        player.exp += player.monster[mon][a_mon].exp;
        if (player.monster[mon][a_mon].prev == floor) {
          i = u_random(100);
          if (i <= 60) {
            lvl = player.monster[mon][a_mon].level;
            player.monster[mon][a_mon].prev = place_object(lvl) + 1000;
            }
          if (i>=61 && i<=80) player.monster[mon][a_mon].prev = 79;
          if (i>=81 && i<=99) player.monster[mon][a_mon].prev = 84;
          }
        player.map[player.x][player.y] = player.monster[mon][a_mon].prev;
        show_spot(player.x,player.y);
        clear_prompt();
        sprintf(buffer,"Exp=%.0f",player.monster[mon][a_mon].exp);
        prompt(buffer);
        if (player.monster[mon][a_mon].special > 9) {
          player.align -= 20;
          if (player.align < 0) player.align = 0;
          }
        show_side();
        }
*/

      }
    else {
      prompt("Miss . . .");
      noise(200,100);
      }
    }

  char valid(int x,int y) {
    flag = '*';
    if (player.map[x][y] < 255) {
      if (player.map[x][y] == 143) flag = ' ';
      if (player.map[x][y] == 22) flag = ' ';
      if (player.map[x][y] == 16) flag = ' ';
      if (player.map[x][y] == 18) flag = ' ';
      if (player.map[x][y] == 20) flag = ' ';
      if (player.map[x][y] == 176) flag = ' ';
      if (player.map[x][y] == 4) flag = ' ';
      if (player.map[x][y] == 3) flag = ' ';
      if (player.map[x][y] == 178) flag = ' ';
      }
    return flag;
    }

  void move_up() {
    remove_player();
    player.y--;
    if (valid(player.x,player.y) != '*') player.y++;
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.y++;
      }
    show_player();
    }

  void move_down() {
    remove_player();
    player.y++;
    if (valid(player.x,player.y) != '*') player.y--;
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.y--;
      }
    show_player();
    }

  void move_left() {
    remove_player();
    player.x--;
    if (valid(player.x,player.y) != '*') player.x++;
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x++;
      }
    show_player();
    }

  void move_right() {
    remove_player();
    player.x++;
    if (valid(player.x,player.y) != '*') player.x--;
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x--;
      }
    show_player();
    }

  void move_up_left() {
    remove_player();
    player.x--;
    player.y--;
    if (valid(player.x,player.y) != '*') {
      player.x++;
      player.y++;
      }
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x++;
      player.y++;
      }
    show_player();
    }

  void move_up_right() {
    remove_player();
    player.x++;
    player.y--;
    if (valid(player.x,player.y) != '*') {
      player.x--;
      player.y++;
      }
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x--;
      player.y++;
      }
    show_player();
    }

  void move_down_left() {
    remove_player();
    player.x--;
    player.y++;
    if (valid(player.x,player.y) != '*') {
      player.x++;
      player.y--;
      }
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x++;
      player.y--;
      }
    show_player();
    }

  void move_down_right() {
    remove_player();
    player.x++;
    player.y++;
    if (valid(player.x,player.y) != '*') {
      player.x--;
      player.y--;
      }
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      hit_enemy();
      player.x--;
      player.y--;
      }
    show_player();
    }

  void do_inventory() {
    OBJECT_REC* item;
    saveScreen();
    item = inventory(0);
    restoreScreen();
/*
    if (i != 0) player.map[player.x][player.y] = i + 1000;
    show_screen();
*/
    }

/*
  void do_quaff() {
    int i;
    inv_item = 0;
    if (player.map[player.x][player.y]>1087 &&
        player.map[player.x][player.y]<1096) {
      i = 0-(player.map[player.x][player.y] - 1000);
      player.map[player.x][player.y] = 7;
      }
    else i = inventory(0);
    if (i<0 && objects[0-i].otype == O_POTN) {
      if (inv_item != 0) player.invent[inv_item] = 0;
      i = 0 - i;
      if (i>87 && i<96) {
        if (objects[i].effect == 7) special(objects[i].control);
        if (objects[i].effect == 1) {
          player.chp += u_random(objects[i].user_hp*(player.skill[9]+1));
          player.health += u_random(objects[i].user_health);
          if (player.chp > player.mhp) player.chp = player.mhp;
          if (player.health > 100) player.health = 100;
          }
        if (objects[i].effect == 8)
          player.effect[PE_POISON] += u_random(player.diff*5+player.d_level /3);
        }
      i = 0;
      }
    if (i>0) player.map[player.x][player.y] = i + 1000;
    show_screen();
    }
*/

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
      item = inventory(0);
      show_screen();
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
    } /* void do_quaff() */

/*
  void zap_a_wand() {
    int i;
    i = inventory(0);
    if (i>0) player.map[player.x][player.y] = i + 1000;
    show_screen();
    if (i < 0) {
      i = 0 - i;
      if (objects[i].otype == O_WAND) {
        if (u_random(30) > player.level)
          if (inv_item != 0) player.invent[inv_item] = 0;
        if (objects[i].effect == 7) special(objects[i].control);
        if (objects[i].effect == 1) {
          player.chp += u_random(objects[i].user_hp);
          player.health += u_random(objects[i].user_health);
          if (player.chp > player.mhp) player.chp = player.mhp;
          if (player.health > 100) player.health = 100;
          }
        if (objects[i].effect == 3) missile(objects[i].damage);
        if (objects[i].effect == 4) fear();
        if (objects[i].effect == 5) do_sleep();
        }
      }
    show_side();
    }
*/

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
    } /* void zap_a_wand() */

/*
  void use_item() {
    int i;
    i = inventory(0);
    if (i>0) player.map[player.x][player.y] = i + 1000;
    show_screen();
    if (i < 0) {
      i = 0 - i;
      if (i >= 135) {
        if (i>136 && i<145 && inv_item != 0) player.invent[inv_item] = 0;
        if (u_random(30) > player.level) player.invent[inv_item] = 0;
        if (objects[i].effect == 7) {
          special(objects[i].control);
          show_map();
          show_sm_map();
          }
        if (objects[i].user_hp > 0) {
          player.chp += u_random(objects[i].user_hp);
          if (player.chp > player.mhp) player.chp = player.mhp;
          }
        if (objects[i].user_health > 0) {
          player.health += u_random(objects[i].user_health);
          if (player.health > 100) player.health = 100;
          }
        if (objects[i].effect == 4) fear();
        if (objects[i].effect == 5) do_sleep();
        if (objects[i].effect == 6) teleport();
        if (objects[i].effect == 3)
          switch (objects[i].control) {
            case 2:missile(objects[i].damage); break;
            case 3:area9(objects[i].damage); break;
            case 4:area25(objects[i].damage); break;
            case 5:missile9(objects[i].damage); break;
            }
        }
      }
    show_side();
    show_sm_map();
    show_map();
    show_player();
    }
*/

  void use_item() {
    OBJECT_REC* item;
    saveScreen();
    item = inventory(0);
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
    clair = ' ';
    } /* void use_item() */

/*
  void do_read() {
    int i;
    inv_item = 0;
    if (player.map[player.x][player.y]>1115 &&
        player.map[player.x][player.y]<1125) {
      i = 0 - (player.map[player.x][player.y] - 1000);
      player.map[player.x][player.y] = 7;
      }
    else i = inventory(0);
    if (i < 0 && (objects[0-i].otype == O_SCRL ||
                  objects[0-i].otype == O_BOOK)) {
      if (inv_item != 0) player.invent[inv_item] = 0;
      i = 0 - i;
      if (i > 115 && i < 125 && objects[i].effect == 7)
        special(objects[i].control);
      if (i > 136 && i < 145) {
        if (objects[i].effect == 7) {
          special(objects[i].control);
          show_map();
          show_sm_map();
          }
        if (objects[i].user_hp > 0) {
          player.chp += u_random(objects[i].user_hp);
          if (player.chp > player.mhp) player.chp = player.mhp;
          }
        if (objects[i].user_health > 0) {
          player.health += u_random(objects[i].user_health);
          if (player.health > 100) player.health = 100;
          }
        }
      i = 0;
      }
    if (i > 0) player.map[player.x][player.y] = i + 1000;
    show_screen();
    }
*/

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
      player.map[player.x][player.y] = 7;
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
    if (clair != ' ') show_screen();
    clair = ' ';
    } /* void do_read() */

/*
  void do_get() {
    int i;
    char buffer[80];
    if (player.map[player.x][player.y] > 1000) {
      i = inventory(player.map[player.x][player.y] - 1000);
      player.map[player.x][player.y] = floor;
      show_screen();
      }
    else if (player.map[player.x][player.y] == 84) {
      player.torch++;
      player.map[player.x][player.y] = floor;
      i = 0;
      show_spot(player.x,player.y);
      show_player();
      }
    else if (player.map[player.x][player.y] == 79) {
      i = u_random(player.diff * 10 + player.d_level);
      clear_prompt();
      sprintf(buffer,"Found %d Gold Pieces",i);
      prompt(buffer);
      player.map[player.x][player.y] = floor;
      player.gold += i;
      i = 0;
      show_spot(player.x,player.y);
      show_player();
      }
    else {
      i = inventory(0);
      show_screen();
      }
    if (i > 0) player.map[player.x][player.y] = i + 1000;
    }
*/

  void do_get() {
    int i;
    OBJECT_REC item;
    char buffer[80];
    if (player.map[player.x][player.y] > 1000) {
      saveScreen();
      item=player.map_objects[player.map[player.x][player.y] - 1000];
      player.map_objects[player.map[player.x][player.y] - 1000].otype = O_NONE;
      player.map[player.x][player.y] = 7;
      inventory(&item);
      restoreScreen();
      }
    else if (player.map[player.x][player.y] == 84) {
      player.torch++;
      player.map[player.x][player.y] = 7;
      i = 0;
      show_spot(player.x,player.y);
      show_player();
      }
    else if (player.map[player.x][player.y] == 79) {
      i = u_random(player.diff * 50 + player.d_level);
      clear_prompt();
      sprintf(buffer,"Found %d Gold Pieces",i);
      prompt(buffer);
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
    } /* void do_get() */

/*
  void fire_weapon() {
    if (player.invent[2] > 31 && player.invent[2] < 44)
      fire(objects[player.invent[2]].damage,0);
    if (player.invent[2] > 43 && player.invent[2] < 49) {
      fire(objects[player.invent[2]].damage,player.invent[2]);
      player.weapon = 0;
      player.invent[2] = 0;
      }
    }
*/

  void fire_weapon() {
    if (player.invent[2].otype == O_BOW)
      fire(player.invent[2].damage,NULL);
    if (player.invent[2].otype == O_PROJ)
      missile(player.invent[2].damage);
    } /* void fire_weapon() */

/*
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
      if (player.invent[hand] == 1) damage = objects[1].damage * 4;
      else if (player.invent[hand] == 15) damage = objects[15].damage * 4;
      else if (player.invent[hand] == 16) damage = objects[16].damage * 4;
      else if (player.invent[hand]>59 && player.invent[hand]<88) damage = 20;
      else damage = 8;
      fire(damage,player.invent[hand]);
      if (hand == 2) player.weapon = 0;
      player.invent[hand] = 0;
      }
    }
*/

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
      prompt("Not enough Mana!!");
      }
    show_side();
    }

  void make_assassin() {
    player.class = 7;
    strcpy(player.title,"Rogue");
    player.exp = 0;
    player.exp_next = 100000;
    player.align = 0;
    }

  void pick_spot(int* x,int* y,int what) {
    *x = u_random(16) + 10;
    *y = u_random(16) + 10;
    if (player.map[*x][*y] != what) {
      *x = u_random(16) + 10;
      *y = u_random(16) + 10;
      }
    }

  snakes = 0;
  haste_flag = ' ';
  in_arena = 'Y';
  a_mon = monster;
  ofloor = floor;
  sfloor = floor;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      tmp_known[x][y] = player.known[x][y];
      tmp_map[x][y] = player.map[x][y];
      player.map[x][y] = sfloor;
      player.known[x][y] = 1;
      }
  for (x=1; x<=100; x++) {
    player.map[x][1] = 21;
    player.map[x][100] = 21;
    player.map[1][x] = 21;
    player.map[100][x] = 21;
    }
  hold_x = player.x;
  hold_y = player.y;
  hold_mapx = player.map_x;
  hold_mapy = player.map_y;
  player.x = 18;
  player.y = 22;
  player.map_x = 10;
  player.map_y = 10;
  if (player.party[1].hp != 0) player.map[15][23] = 301;
  if (player.party[2].hp != 0) player.map[21][23] = 302;
  if (player.party[3].hp != 0) player.map[12][24] = 303;
  if (player.party[4].hp != 0) player.map[24][24] = 304;
  if (player.party[5].hp != 0) player.map[18][24] = 305;
  if (player.monster[1][monster].hp != 0) player.map[18][13] = 401;
  if (player.monster[2][monster].hp != 0) player.map[15][12] = 402;
  if (player.monster[3][monster].hp != 0) player.map[21][12] = 403;
  if (player.monster[4][monster].hp != 0) player.map[12][11] = 404;
  if (player.monster[5][monster].hp != 0) player.map[24][11] = 405;
  player.map[player.x][player.y] = 99;
  for (i=1; i<=5; i++) player.monster[i][monster].prev = sfloor;
  switch (floor) {
    case 1:for (i=1; i<=4; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 20;
             }
           for (i=1; i<=4; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 18;
             }
           break;
    case 2:floor = 1;
           for (i=1; i<=35; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 20;
             }
           for (i=1; i<=6; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 18;
             }
           break;
    case 177:floor = 177;
           for (i=1; i<=35; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 3;
             }
           for (i=1; i<=6; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 178;
             }
           break;
    case 8:for (i=1; i<=6; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 16;
             }
           for (i=1; i<=6; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 176;
             }
           break;
    case 6:for (i=1; i<=12; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 1;
             }
           for (i=1; i<=10; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 20;
             }
           for (i=1; i<=20; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 4;
             }
           break;
    case 9:for (i=1; i<=35; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 18;
             }
           for (i=1; i<=6; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 20;
             }
           for (i=1; i<=10; i++) {
             pick_spot(&x,&y,floor);
             player.map[x][y] = 2;
             }
           break;
    }
  player.map[player.x][player.y] = floor;
  for (i=1; i<=5; i++) player.party[i].prev = floor;
  graphmode();
  show_map();
  show_side();
  show_player();
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
      case '8': move_up(); break;
      case '2': move_down(); break;
      case '4': move_left(); break;
      case '6': move_right(); break;
      case '7': move_up_left(); break;
      case '9': move_up_right(); break;
      case '1': move_down_left(); break;
      case '3': move_down_right(); break;
      case 'i': do_inventory(); break;
      case 'g': do_get(); break;
      case 'q': do_quaff(); break;
      case 'z': zap_a_wand(); break;
      case 'u': use_item(); break;
      case 'r': do_read(); break;
      case 'f': fire_weapon(); break;
      case 'm': cast_spell(0); break;
      case 161: cast_spell(1); break;
      case 162: cast_spell(2); break;
      case 163: cast_spell(3); break;
      case 164: cast_spell(4); break;
      case 165: cast_spell(5); break;
      case 222: cast_spell(6); break;
      case 166: cast_spell(7); break;
      case 170: cast_spell(8); break;
      case 168: cast_spell(9); break;
      case 169: cast_spell(10); break;
      case 'T': throw(); break;
      case 'p': party(); break;
      case 'P':if (player.map[player.x][player.y] > 999) pack_it(floor);
               break;
      case 'v': view(floor); break;
      case 'V': soundon = (soundon == 'Y') ? 'N' : 'Y';
                break;
      case '?': combat_help(); break;
      case 'H': show_icons(); break;
      case ':': special(54); break;
      case 'R': disp_char();
                show_screen();
                break;
      }
    if (player.align <= 0 && player.class != 7) make_assassin();
    while (player.exp >= player.exp_next) {
      advancement();
      show_side();
      }
    if (haste_flag == ' ') {
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>400 && player.map[x][y]<500 &&
              player.monster[player.map[x][y]-400][a_mon].special < 100 &&
              player.monster[player.map[x][y]-400][a_mon].sleep == 0) {
            if (player.monster[player.map[x][y]-400][a_mon].mana != 0 &&
                player.monster[player.map[x][y]-400][a_mon].special < 10 &&
                u_random(100) < 40) arena_enemy_missile(x,y);
                arena_move_enemy(x,y);
            }
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>300 && player.map[x][y]<400 &&
              player.party[player.map[x][y]-300].special < 100 &&
              player.party[player.map[x][y]-300].sleep == 0) {
            if (player.party[player.map[x][y]-300].mana != 0 &&
                player.party[player.map[x][y]-300].special < 20 &&
                u_random(100) < 40) arena_party_missile(x,y);
                arena_move_party(x,y);
            }
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>300 && player.map[x][y]<400 &&
              player.party[player.map[x][y]-300].sleep == 0) party_attack(x,y);
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>400 && player.map[x][y]<500 &&
              player.monster[player.map[x][y]-400][a_mon].sleep == 0)
            enemy_attack(x,y);
      for (x=1; x<=5; x++) {
        if (player.monster[x][a_mon].special > 90)
          player.monster[x][a_mon].special -= 100;
        }
      for (x=1; x<=5; x++) {
        if (player.party[x].special > 90)
          player.party[x].special -= 100;
        }
      if (snakes != 0)
        for (x=player.map_x; x<=player.map_x+16; x++)
          for (y=player.map_y; y<=player.map_y+16; y++)
            if (player.map[x][y] == 143) move_snake(x,y,floor);
      for (x=player.map_x; x<=player.map_x+16; x++)
        for (y=player.map_y; y<=player.map_y+16; y++)
          if (player.map[x][y] == 144) player.map[x][y] = 143;
      for (x=1; x<=5; x++) {
        if (player.party[x].sleep > 0) player.party[x].sleep--;
        if (player.party[x].fear > 0) player.party[x].fear--;
        }
      for (x=1; x<=5; x++) {
        if (player.monster[x][a_mon].sleep > 0) player.monster[x][a_mon].sleep--;
        if (player.monster[x][a_mon].fear > 0) player.monster[x][a_mon].fear--;
        if (player.monster[x][a_mon].blind > 0) player.monster[x][a_mon].blind--;
        if (player.monster[x][a_mon].confused > 0) player.monster[x][a_mon].confused--;
        if (player.monster[x][a_mon].poison > 0) {
          player.monster[x][a_mon].poison--;
          player.monster[x][a_mon].hp -= 2;
          dead_monster(&(player.monster[x][a_mon]),'Y');
          }
        }
      } /* if (haste_flag == ' ') */
    if (player.class == 10) {
      if (player.level >= 23) player.effect[PE_HASTE] = 10;
      if (player.level >= 17) player.effect[PE_SLEEP] = 0;
      if (player.level >= 29) player.effect[PE_POISON] = 0;
      if (player.level >= 14) player.effect[PE_FEAR] = 0;
      check_monk_weapon();
      }
    if (haste_flag == '*') haste_flag = ' ';
    else {
      if (has_intrinsic(A_SPD)) haste_flag = '*';
      }
    dc--;
    if (dc == 0) {
      if (player.effect[PE_PROT] > 0) {
        player.effect[PE_PROT]--;
        if (player.effect[PE_PROT] == 0) show_side();
        }
      if (player.effect[PE_FIRE] > 0) {
        player.effect[PE_FIRE]--;
        if (player.effect[PE_FIRE] == 0) show_side();
        }
      if (player.effect[PE_HASTE] > 0) {
        player.effect[PE_HASTE]--;
        if (player.effect[PE_HASTE] == 0) show_side();
        }
      if (player.effect[PE_GIANT] > 0) {
        player.effect[PE_GIANT]--;
        if (player.effect[PE_GIANT] == 0) show_side();
        }
      dc = 1 + trunc(player.level / 6.0);
      } /* if (dc == 0) */
    if (player.effect[PE_ETHER] > 0) {
      player.effect[PE_ETHER]--;
      if (player.effect[PE_ETHER] == 0) show_side();
      if (player.effect[PE_ETHER] == 10) show_side();
      }
    if (player.effect[PE_POISON] > 0) {
      player.effect[PE_POISON]--;
      player.chp--;
      show_side();
      }
    if (player.effect[PE_CONFUSED] > 0) player.effect[PE_CONFUSED]--;
    if (h_count > 0) h_count--;
    if (player.effect[PE_READLORE] > 0) player.effect[PE_READLORE]--;
    if (player.effect[PE_READLANG] > 0) player.effect[PE_READLANG]--;
    if (player.effect[PE_FEAR] > 0) player.effect[PE_FEAR]--;
    if (player.effect[PE_SLEEP] > 0) player.effect[PE_SLEEP]--;
    if (player.effect[PE_LEV] > 0) player.effect[PE_LEV]--;
    player.hp_count--;
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
    if (player.hp_count < 1) {
      player.hp_count = 20;
      if (player.chp < player.mhp) player.chp++;
      show_side();
      }
    player.mana_count--;
    if (player.mana_count < 1) {
      player.mana_count = 20;
      if (player.cmana < player.mmana) player.cmana++;
      show_side();
      }
    if (player.chp < 1) exitf = 6;
    if (player.x == 10 || player.y == 10 ||
        player.x == 25 || player.y == 25) exitf = 1;
    } /* while (exitf == 0) */
  exitf = 0;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      player.known[x][y] = tmp_known[x][y];
      player.map[x][y] = tmp_map[x][y];
      }
  player.x = hold_x;
  player.y = hold_y;
  player.map_x = hold_mapx;
  player.map_y = hold_mapy;
  flag = ' ';
  for (i=1; i<=5; i++)
    if (player.monster[i][a_mon].hp < 0)
      player.monster[i][a_mon].hp = 0;
  j = 1;
  for (i=1; i<=5; i++)
    if (player.monster[i][a_mon].hp > 0) {
      flag = '*';
      if (i != 6) {
        player.monster[j][a_mon] = player.monster[i][a_mon];
        player.monster[i][a_mon].hp = 0;
        j++;
        }
      else j++;
      }
  if (flag != '*') player.map[player.x][player.y] = ofloor;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) {
      while (player.party[i].exp > needed(player.party[i].level + 1)) {
        player.party[i].level++;
        player.party[i].attack += 2;
        player.party[i].defense += 2;
        if (player.party[i].mana != 0) player.party[i].mana += 25;
        }
      }
  for (i=1; i<=5; i++) {
    if (player.party[i].hp < 0) player.party[i].hp = 0;
    if (player.party[i].hp > 0) player.party[i].hp = player.party[i].level * 9;
    }
  player.mount = 0;
  player.peg = 0;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) {
      if (player.party[i].sprite == 133) player.peg = 1;
      if (player.party[i].sprite == 148) player.mount = 1;
      if (player.party[i].sprite == 131) player.mount = 1;
      if (player.party[i].sprite == 132) player.mount = 1;
      if (player.party[i].sprite == 138) player.mount = 1;
      if (player.party[i].sprite == 155) player.mount = 1;
      if (player.party[i].sprite == 159) player.mount = 1;
      if (player.peg == 1) player.mount = 1;
      }
  in_arena = 'N';
  show_map();
  show_sm_map();
  show_side();
  }

