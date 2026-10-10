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

void arena(int monster,int floor,int barriers,int srcx,int srcy) {
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
  int dmg;
  char buffer[20];
  int all_dead;
  int arena_x;
  int arena_y;


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
          delay(delay_hit);
          show_spot(ex,ey);
          }
        i = u_random(player.monster[mon][a_mon].attack);
        if (party_combat_mode != 'F') i /= NPC_DIV;
        if (i < 1) i = 1;
        player.party[target].hp -= i;
        if ((player.monster[mon][a_mon].special & MS_SLEEP) == MS_SLEEP) {
          hit = 50 + ((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                 if (u_random(100) < hit && player.party[target].sleep == 0) {
                   clear_prompt();
                   prompt("Party slept!!!");
                   player.party[target].sleep = u_random(player.monster[mon][a_mon].level);
                   show_spot(ex,ey);
                   }
            }
        if ((player.monster[mon][a_mon].special & MS_FEAR) == MS_FEAR) {
          hit = 50 + ((player.monster[mon][a_mon].level - player.party[target].level) * 5);
                 if (u_random(100) < hit && player.party[target].fear == 0) {
                   clear_prompt();
                   prompt("Party scared!!!");
                   player.party[target].fear = 5 + u_random(player.monster[mon][a_mon].level);
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
          delay(delay_hit);
          show_spot(ex,ey);
          }
        i = u_random(player.party[mon].attack);
        if (party_combat_mode != 'F') i /= NPC_DIV;
        if (i < 1) i = 1;
        player.monster[target][a_mon].hp -= i;
        dead_monster(&(player.monster[target][a_mon]),'Y',ex,ey);
/*
        if (player.monster[target][a_mon].hp <= 0) {
          player.map[ex][ey] = floor;
          player.monster[target][a_mon].hp = 0;
          show_spot(ex,ey);
          gain_exp(player.monster[target][a_mon].exp,mon);
          }
*/
        }
      }
    }

  void arena_party_missile(int ex,int ey) {
    char flag;
    int  x,y;
    int  mon;
    int  dist;
    int  targetx;
    int  targety;
    int  target;
    int  i;
    double fx,fy;
    double xdir,ydir;

    void find_target() {
      int x1,y1;
      dist = 32000;
      targetx = player.x;
      targety = player.y;
      for (x1 = offset_x; x1<=offset_x+16; x1++)
        for (y1= offset_y; y1<=offset_y+16; y1++)
          if (player.map[x1][y1]>400 && player.map[x1][y1]<500)
            if (sqr(x1-ex) + sqr(y1-ey) < dist) {
              targetx = x1;
              targety = y1;
              dist = (sqr(x1-ex) + sqr(y1-ey));
              }
      }

    mon = player.map[ex][ey] - 300;
    find_target();
    xdir = targetx - ex;
    ydir = targety - ey;
    if (abs(targetx - ex) >= abs(targety - ey)) {
      ydir = ydir / abs(xdir);
      if (xdir > 0) xdir = 1;
      if (xdir < 0) xdir = -1;
      } else {
      xdir = xdir / abs(ydir);
      if (ydir > 0) ydir = 1;
      if (ydir < 0) ydir = -1;
      }
    fx = ex + 0.5;
    fy = ey + 0.5;
    x = ex;
    y = ey;
    flag = ' ';
    if (dist > 30000) flag = '&';
    while (flag == ' ') {
      fx += xdir;
      fy += ydir;
      x = fx;
      y = fy;
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(delay_ranged);
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
      if (player.map[x][y] >= 600 && player.map[x][y] < 700) flag = '*';
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
          delay(delay_hit);
          show_spot(x,y);
          }
        i = u_random(player.party[mon].mana / 8 + 1);
        if (party_combat_mode != 'F') i /= NPC_DIV;
        if (i < 1) i = 1;
        player.monster[target][a_mon].hp -= i;
        dead_monster(&(player.monster[target][a_mon]),'Y',x,y);
/*
        if (player.monster[target][a_mon].hp <= 0) {
          player.map[x][y] = floor;
          player.monster[target][a_mon].hp = 0;
          show_spot(x,y);
          gain_exp(player.monster[target][a_mon].exp,mon);
          }
*/
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
    int  mon;
    int  dist;
    int  targetx;
    int  targety;
    int  target;
    int  i,j;
    int  ring;
    double  fx,fy;
    double  xdir,ydir;
    char elem[20];
    char buffer[60];

    void find_target() {
      int x1,y1;
      dist = (sqr(player.x-ex) + sqr(player.y-ey));
      targetx = player.x; targety = player.y;
      for (x1=offset_x; x1<=offset_x+16; x1++)
        for (y1=offset_y; y1<=offset_y+16; y1++)
          if (player.map[x1][y1]>300 && player.map[x1][y1]<400)
            if ((sqr(x1-ex) + sqr(y1-ey)) < dist) {
              targetx = x1;
              targety = y1;
              dist = sqr(x1-ex) + sqr(y1-ey);
              }
      }

    mon = player.map[ex][ey] - 400;
    find_target();
    xdir = targetx - ex;
    ydir = targety - ey;
    if (abs(targetx - ex) >= abs(targety - ey)) {
      ydir = ydir / abs(xdir);
      if (xdir > 0) xdir = 1;
      if (xdir < 0) xdir = -1;
      } else {
      xdir = xdir / abs(ydir);
      if (ydir > 0) ydir = 1;
      if (ydir < 0) ydir = -1;
      }
    x = ex;
    y = ey;
    fx = ex + 0.5;
    fy = ey + 0.5;
    while (flag == ' ') {
      fx += xdir;
      fy += ydir;
      x = fx;
      y = fy;
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(delay_ranged);
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
      if (player.map[x][y] >= 600 && player.map[x][y] < 700) flag = '*';
      if (player.map[x][y] > 300 && player.map[x][y] < 400) flag = '#';
      if (x == player.x && y == player.y) flag = '*'; 
      }
    if (x == player.x && y == player.y) {
      i = 50;
      i += 2 * (player.monster[mon][a_mon].level - (player.level / 2));
      if (i > 90) i = 90;
      if (i < 10) i = 10;
      i -= get_bonus(S_DDG) * 2;
      if (i > 90) i = 90;
      if (i < 10) i = 10;
      if (u_random(100) < get_dodge()) {
        i = 0;
        msg("Dodged",7);
        }
      if (u_random(100) < i) {
        strcpy(elem,"");
        clear_prompt();
        noise(1000,100);
        if (in_sight(x,y) == '*') {
          show_sprite(x-player.map_x,y-player.map_y,100);
          delay(delay_hit);
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
          if ((player.monster[mon][a_mon].special & MS_FIRE_ATK) == MS_FIRE_ATK) {
            if (has_intrinsic(A_RFIR) || has_intrinsic(A_RELE) || player.effect[PE_FIRE] > 0) i /= 2;
            i = reduce_damage(i,S_FIR);
            strcpy(elem," fire ");
            }
          if ((player.monster[mon][a_mon].special & MS_COLD_ATK) == MS_COLD_ATK) {
            if (has_intrinsic(A_RCLD) || has_intrinsic(A_RELE) || player.effect[PE_COLD] > 0) i /= 2;
            i = reduce_damage(i,S_CLD);
            strcpy(elem," cold ");
            }
          if ((player.monster[mon][a_mon].special & MS_ELEC_ATK) == MS_ELEC_ATK) {
            if (has_intrinsic(A_RELC) || has_intrinsic(A_RELE) || player.effect[PE_ELEC] > 0) i /= 2;
            i = reduce_damage(i,S_ELC);
            strcpy(elem," electric ");
            }
          if ((player.monster[mon][a_mon].special & MS_ARCN_ATK) == MS_ARCN_ATK) {
            if (has_intrinsic(A_RDRK) || player.effect[PE_ARCN] > 0) i /= 2;
            i = reduce_damage(i,S_ARC);
            strcpy(elem," arcane ");
            }
          if ((player.monster[mon][a_mon].special & MS_PSIONIC) == MS_PSIONIC) {
            if (has_intrinsic(A_RPSI) || player.effect[PE_MIND]) i /= 4;
            strcpy(elem," psionic ");
            }
          i = magic_adjust(i);
          if (u_random(100) < (20+player.ability[5] * 20)) i /= 2;
          sprintf(buffer,"ZAP for %d%s",i,elem);
          msg(buffer,12);
          stats_take_damage(i);
          player.chp -= i;
          if (player.chp < 0) player.chp = 0;
          show_player();
          }
        if (ring != 0) {
          r_missile(player.monster[mon][a_mon].mana / 4 + 1);
          i = get_skill(8) + (player.level - player.monster[mon][a_mon].level);
          i += player.ability[10] * 5;
          if (i>0) i += 75;
          if (i > 98) i = 98;
          if (i < 0) {
            player.invent[ring].otype = O_NONE;
            clear_prompt();
            prompt("Ring Melted!!");
            }
          if (u_random(101) > i) {
            player.invent[ring].otype = O_NONE;
            clear_prompt();
            prompt("Ring Melted!!");
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
          delay(delay_hit);
          show_spot(x,y);
          }
        i = u_random(player.monster[mon][a_mon].mana / 8 + 1);
        if (party_combat_mode != 'F') i /= NPC_DIV;
        if (i < 1) i = 1;
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
    NPC_REC* monster;
    monster = get_monster(player.x,player.y);
    if (monster == NULL) return;
    if (is_weapon(&(player.invent[I_RHND]))) meleehit(0,&(player.invent[I_RHND]),get_weapon(),monster,'R');
      else meleehit(0,NULL,get_weapon(),monster,'R');
    if (is_weapon(&(player.invent[I_LHND])) && monster->hp > 0)
      meleehit(0,&(player.invent[I_LHND]),offhand_weapon() / 2,monster,'L');
    }

  void move(int xdir,int ydir) {
    int x,y;
    last_target_x = 0;
    last_target_y = 0;
    remove_player();
    x = player.x;
    y = player.y;
    player.x += xdir;
    player.y += ydir;

    if (player.effect[PE_FEAR] > 0 && 
        (player.x <= offset_x || player.y <= offset_y ||
         player.x >= offset_x + ARENA_SIZE_X || player.y >= offset_y + ARENA_SIZE_Y) 
        ) {
      player.x -= xdir;
      player.y -= ydir;
      }
    if (valid_move(player.x,player.y) != '*') {
      player.x -= xdir;
      player.y -= ydir;
      }
    if (player.map[player.x][player.y]>400 &&
        player.map[player.x][player.y]<500) {
      player.x -= xdir;
      player.y -= ydir;
      show_player();
      player.x += xdir;
      player.y += ydir;
      hit_enemy();
      player.x -= xdir;
      player.y -= ydir;
      }
    if (player.map[player.x][player.y]>300 &&
        player.map[player.x][player.y]<400) {
      player.x -= xdir;
      player.y -= ydir;
      }
    if (player.effect[PE_ROOT] > 0) { player.x = x; player.y = y; }
    if (get_weight() > get_max_weight()) { player.x = x; player.y = y; msg("Overburdoned",15); }
    show_player();
    stats.counts[STAT_STEPS_TAKEN]++;
    check_autos();
    }

  void do_inventory() {
    saveScreen();
    inventory(0);
    restoreScreen();
    }

  void pick_spot(int* x,int* y,int what) {
    *x = u_random(ARENA_SIZE_X) + offset_x;
    *y = u_random(ARENA_SIZE_Y) + offset_y;
    if (player.map[*x][*y] != what) {
      *x = u_random(ARENA_SIZE_X) + offset_x;
      *y = u_random(ARENA_SIZE_Y) + offset_y;
      }
    }

  void find_closest_mob() {
    int dist;
    int closestX;
    int closestY;
    dist = 50000;
    closestX = 0;
    closestY = 0;
    for (x=1; x<100; x++)
      for (y=1; y<100; y++) {
        if (player.map[x][y] > 400 && player.map[x][y] < 500) {
          if (sqr(x-player.x) + sqr(y-player.y) < dist) {
            dist = sqr(x-player.x) + sqr(y-player.y);
            closestX = x;
            closestY = y;
            }
          }
        }
    target_x = closestX;
    target_y = closestY;
    }

  /* ************************************** */
  /* ***** Actual start of Arena code ***** */
  /* ************************************** */
  arena_x = srcx;
  arena_y = srcy;
  all_dead = 0;
  while (keypressed()) key=inkey();
  lastFloor = currentFloor;
  snakes = 0;
  haste_flag = ' ';
  in_arena = 'Y';
  a_mon = monster;
  ofloor = floor;
  sfloor = floor;
  if (sfloor == 2) sfloor = 1;
  currentFloor = sfloor;
  offset_x = 50 - ARENA_SIZE_X / 2;
  offset_y = 50 - ARENA_SIZE_Y / 2;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      tmp_known[x][y] = player.known[x][y];
      tmp_map[x][y] = player.map[x][y];
      player.map[x][y] = sfloor;
      player.known[x][y] = 0;
      if (x >= offset_x && x <= offset_x+ARENA_SIZE_X &&
          y >= offset_y && y <= offset_y+ARENA_SIZE_Y) player.known[x][y] = 1;
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
  player.x = offset_x + 8;
  player.y = offset_x + 11;
  player.map_x = offset_x - (TILES_X / 2 - ARENA_SIZE_X / 2);
  player.map_y = offset_y - (TILES_Y / 2 - ARENA_SIZE_Y / 2);
  if (player.party[1].hp != 0) player.map[offset_x+6][offset_y+12] = 301;
  if (player.party[2].hp != 0) player.map[offset_x+10][offset_y+12] = 302;
  if (player.party[3].hp != 0) player.map[offset_x+3][offset_y+13] = 303;
  if (player.party[4].hp != 0) player.map[offset_x+13][offset_y+13] = 304;
  if (player.party[5].hp != 0) player.map[offset_x+8][offset_y+13] = 305;
  if (player.monster[1][monster].hp != 0) player.map[offset_x+8][offset_y+4] = 401;
  if (player.monster[2][monster].hp != 0) player.map[offset_x+6][offset_y+3] = 402;
  if (player.monster[3][monster].hp != 0) player.map[offset_x+10][offset_y+3] = 403;
  if (player.monster[4][monster].hp != 0) player.map[offset_x+3][offset_y+2] = 404;
  if (player.monster[5][monster].hp != 0) player.map[offset_x+13][offset_y+2] = 405;
  if ((barriers & 1) == 1) {
    for (i=offset_x; i<=offset_x+16; i++) {
      player.map[i][offset_y] = dungeon_wall;
      player.map[i][offset_y+1] = dungeon_wall;
      }
    }
  if ((barriers & 2) == 2) {
    for (i=offset_y; i<=offset_y+16; i++) {
      player.map[offset_x+14][i] = dungeon_wall;
      player.map[offset_x+15][i] = dungeon_wall;
      }
    }
  if ((barriers & 4) == 4) {
    for (i=offset_x; i<=offset_x+16; i++) {
      player.map[i][offset_y+14] = dungeon_wall;
      player.map[i][offset_y+15] = dungeon_wall;
      }
    }
  if ((barriers & 8) == 8) {
    for (i=offset_y; i<=offset_y+16; i++) {
      player.map[offset_x][i] = dungeon_wall;
      player.map[offset_x+1][i] = dungeon_wall;
      }
    }
  for (i=1; i<=5; i++)
    player.monster[i][monster].speed = abs(player.monster[i][monster].speed);
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
    show_time();
    if (player.effect[PE_SLEEP] != 0) key = ' ';
      else key = inkey();
      if (player.effect[PE_FEAR] > 0 &&
          ((key >= '1' && key <= '9') || key == 'f')) {
        find_closest_mob();
        key = fear_dir(player.x,player.y,target_x,target_y);
        }
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
      case '8': move(0,-1); break;
      case '2': move(0,1); break;
      case '4': move(-1,0); break;
      case '6': move(1,0); break;
      case '7': move(-1,-1); break;
      case '9': move(1,-1); break;
      case '1': move(-1,1); break;
      case '3': move(1,1); break;
      case '}':save_gear('N',-1); break;
      case ']':load_gear('N',-1); break;
      case '{':save_gear('Y',-1); break;
      case '[':load_gear('Y',-1); break;
      case 'i': do_inventory(); break;
      case 'g': do_get(); break;
      case 'G':if (player.map[player.x][player.y] > 999) pack_it(floor);
               break;
      case 'u': use_item(); break;
      case 'f': fire_weapon(); break;
      case 'm': cast_spell(0); break;
      case 161:fkey_pressed(1); break;
      case 162:fkey_pressed(2); break;
      case 163:fkey_pressed(3); break;
      case 164:fkey_pressed(4); break;
      case 165:fkey_pressed(5); break;
      case 166:fkey_pressed(6); break;
      case 167:fkey_pressed(7); break;
      case 168:fkey_pressed(8); break;
      case 169:fkey_pressed(9); break;
      case 160:fkey_pressed(10); break;
      case 201:shift_fkey_pressed(1); break;
      case 202:shift_fkey_pressed(2); break;
      case 203:shift_fkey_pressed(3); break;
      case 204:shift_fkey_pressed(4); break;
      case 205:shift_fkey_pressed(5); break;
      case 206:shift_fkey_pressed(6); break;
      case 207:shift_fkey_pressed(7); break;
      case 208:shift_fkey_pressed(8); break;
      case 209:shift_fkey_pressed(9); break;
      case 210:shift_fkey_pressed(10); break;
      case 211:alt_fkey_pressed(1); break;
      case 212:alt_fkey_pressed(2); break;
      case 213:alt_fkey_pressed(3); break;
      case 214:alt_fkey_pressed(4); break;
      case 215:alt_fkey_pressed(5); break;
      case 216:alt_fkey_pressed(6); break;
      case 217:alt_fkey_pressed(7); break;
      case 218:alt_fkey_pressed(8); break;
      case 219:alt_fkey_pressed(9); break;
      case 220:alt_fkey_pressed(10); break;
      case 221:ctrl_fkey_pressed(1); break;
      case 222:ctrl_fkey_pressed(2); break;
      case 223:ctrl_fkey_pressed(3); break;
      case 224:ctrl_fkey_pressed(4); break;
      case 225:ctrl_fkey_pressed(5); break;
      case 226:ctrl_fkey_pressed(6); break;
      case 227:ctrl_fkey_pressed(7); break;
      case 228:ctrl_fkey_pressed(8); break;
      case 229:ctrl_fkey_pressed(9); break;
      case 230:ctrl_fkey_pressed(10); break;
      case 'h': healing(); break;
      case 'T': throw(' '); break;
      case '-':throw('L'); break;
      case '=':throw('R'); break;
      case '+':throw('R'); break;
      case 'p': party(); break;
      case 'P':if (player.map[player.x][player.y] > 999) pack_it(floor);
               break;
      case 'v': view(floor); break;
      case 'V': soundon = (soundon == 'Y') ? 'N' : 'Y';
                break;
      case '?': combat_help(); break;
      case 'H': show_icons(); break;
      case ':': special(54,NULL); break;
      case 'R': disp_char();
                show_screen();
                break;
      case 13 : if (all_dead) exitf = 1; break;
      case 27 : if (all_dead) exitf = 1; break;
      }
    if (has_intrinsic(A_IDNT)) {
      if (player.map[player.x][player.y] >= 1000 && player.map[player.x][player.y] < 2000) {
        if (player.map_objects[player.map[player.x][player.y]-1000].level >= 0) {
          player.map_objects[player.map[player.x][player.y]-1000].level = -1;
          msg(get_name(&(player.map_objects[player.map[player.x][player.y]-1000])),14);
          stats.counts[STAT_ITEMS_IDENTED]++;
          }
        }
      }
    if (player.align <= 0 && player.class != 7) make_assassin();
    if (player.align <= 0 && !(classes[player.class-1].flags & CF_ROGUE)) make_assassin();
    while (player.exp >= player.exp_next) {
      advancement();
      show_side();
      }
    if (haste_flag == ' ') {
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>400 && player.map[x][y]<500 &&
              (player.monster[player.map[x][y]-400][a_mon].special & MS_MOVED) == 0 &&
              player.monster[player.map[x][y]-400][a_mon].sleep == 0) {
            if (player.monster[player.map[x][y]-400][a_mon].mana != 0 &&
                (player.monster[player.map[x][y]-400][a_mon].special & MS_FRIENDLY) == 0 &&
                u_random(100) < 40) arena_enemy_missile(x,y);
                arena_move_enemy(x,y);
            }
      for (x=player.x-15; x<=player.x+15; x++)
        for (y=player.y-15; y<=player.y+15; y++)
          if (x>0 && x<100 && y>0 && y<100 &&
              player.map[x][y]>300 && player.map[x][y]<400 &&
              (player.party[player.map[x][y]-300].special & MS_MOVED) == 0 &&
              player.party[player.map[x][y]-300].sleep == 0) {
            if (player.party[player.map[x][y]-300].mana != 0 &&
                (player.party[player.map[x][y]-300].special & MS_EVADE) == 0  &&
                u_random(100) < 40) arena_party_missile(x,y);
            if (player.party[player.map[x][y]-300].mana != 0 &&
                (player.party[player.map[x][y]-300].special & MS_HEALER) == MS_HEALER  &&
                u_random(100) < 25) arena_party_heal(player.map[x][y]-300);
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
        if ((player.monster[x][a_mon].special & MS_MOVED) == MS_MOVED)
          player.monster[x][a_mon].special -= MS_MOVED;
        }
      for (x=1; x<=5; x++) {
        if ((player.party[x].special & MS_MOVED) == MS_MOVED)
          player.party[x].special -= MS_MOVED;
        }
      if (snakes != 0) {
        for (x=offset_x; x<=offset_x+16; x++)
          for (y=offset_y; y<=offset_y+16; y++)
            if (player.map[x][y] == 143) move_snake(x,y,floor);
        }
      for (x=offset_x; x<=offset_x+16; x++)
        for (y=offset_y; y<=offset_y+16; y++)
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
          dead_monster(&(player.monster[x][a_mon]),'Y',player.x,player.y);
          }
        }
      } /* if (haste_flag == ' ') */
    if (classes[player.class-1].flags & CF_MONK) {
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
      dc = 1 + rcs_trunc(player.level / 6.0);
      } /* if (dc == 0) */
    if (player.effect[PE_ETHER] > 0) {
      player.effect[PE_ETHER]--;
      if (player.effect[PE_ETHER] == 0) show_side();
      if (player.effect[PE_ETHER] == 10) show_side();
      }
    if (player.effect[PE_POISON] > 0) {
      dmg = player.effect[PE_POISON] / 10;
      if (dmg < 1) dmg = 1;
      player.effect[PE_POISON] -= dmg;
      sprintf(buffer,"%d poison damage",dmg);
      msg(buffer,13);
      stats_take_damage(dmg);
      player.chp -= dmg;
      show_side();
      }
    if (player.effect[PE_DOT]>0) {
        dmg = player.effect[PE_DOT] / 10;
        if (dmg < 1) dmg = 1;
        player.effect[PE_DOT] -= dmg;
        sprintf(buffer,"%d DOT damage",dmg);
        msg(buffer,12);
        stats_take_damage(dmg);
        player.chp -= dmg; show_side();
      }
    if (player.effect[PE_CONFUSED] > 0) player.effect[PE_CONFUSED]--;
    if (player.effect[PE_HCOUNT] > 0) player.effect[PE_HCOUNT]--;
    if (player.effect[PE_READLORE] > 0) player.effect[PE_READLORE]--;
    if (player.effect[PE_READLANG] > 0) player.effect[PE_READLANG]--;
    if (player.effect[PE_FEAR] > 0) {
       player.effect[PE_FEAR]--;
       if (player.effect[PE_FEAR] == 0) msg("No longer afraid",14);
       }
    if (player.effect[PE_SLEEP] > 0) player.effect[PE_SLEEP]--;
    if (player.effect[PE_LEV] > 0) player.effect[PE_LEV]--;
    if (player.effect[PE_ROOT] > 0) player.effect[PE_ROOT]--;
    player.hp_count -= get_hpr();
    if (player.hp_count < 1) {
      player.hp_count = 20;
      if (player.chp < get_mhp()) player.chp++;
      show_side();
      }
    player.mana_count -= get_manar();
    if (player.mana_count < 1) {
      player.mana_count = 100;
      if (player.cmana < get_mmana()) player.cmana++;
      show_side();
      }
    if (player.chp < 1) exitf = 6;
    if (player.x <= offset_x || player.y <= offset_y ||
        player.x >= offset_x + ARENA_SIZE_X || player.y >= offset_y + ARENA_SIZE_Y) exitf = 1;
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
  all_dead = -1;
  for (i=1; i<=5; i++) {
    if (player.monster[i][a_mon].hp < 0)
      player.monster[i][a_mon].hp = 0;
    if (player.monster[i][a_mon].hp > 0) all_dead = 0;
    }
  flag = ' ';
  while (flag != '*') {
    flag = '*';
    for (i=1; i<5; i++) {
      if (player.monster[i][a_mon].hp == 0 &&
          player.monster[i+1][a_mon].hp > 0) {
        flag = ' ';
        player.monster[i][a_mon] = player.monster[i+1][a_mon];
        player.monster[i+1][a_mon].hp = 0;
        }
      }
    }
  if (player.monster[1][a_mon].hp == 0) player.map[arena_x][arena_y] = ofloor;
  j = (player.effect[PE_HEROIC] > 0) ? player.effect[PE_HEROIC] : 1;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) {
      while (player.party[i].exp > needed(player.party[i].level + 1)) {
        player.party[i].level++;
        player.party[i].attack += 2 * j;
        player.party[i].defense += 2 * j;
        if (player.party[i].mana != 0) player.party[i].mana += 25;
        }
      }
  for (i=1; i<=5; i++) {
    if (player.party[i].hp < 0) player.party[i].hp = 0;
    if (player.party[i].hp > 0) player.party[i].hp = player.party[i].level * (9 * j);
    }
  check_mount();
  currentFloor = lastFloor;
  in_arena = 'N';
  show_map();
  show_sm_map();
  show_side();
  while (keypressed()) key=inkey();
  }

