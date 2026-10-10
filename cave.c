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

void cave() {
  char haste_flag;
  int  i;
  int  m_file = 0;
  int  x,y;
  int  sx,sy;
  double d;
  byte key;
  int dmg;
  char buffer[20];
  int  previous;

/*  int  activeDelay; */

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
          }
        }
      }
    } /* void take_time() */

  int barriers() {
    int i;
    i = 0;
    if (player.map[player.x][player.y-1] == dungeon_wall) i |= 1;
    if (player.map[player.x+1][player.y] == dungeon_wall) i |= 2;
    if (player.map[player.x][player.y+1] == dungeon_wall) i |= 4;
    if (player.map[player.x-1][player.y] == dungeon_wall) i |= 8;
    return i;
    }

  void hit_enemy() {
    NPC_REC* monster;
/*    activeDelay = 0; */
    monster = get_monster(player.x,player.y);
    if (monster == NULL) return;
    if (is_weapon(&(player.invent[I_RHND]))) meleehit(0,&(player.invent[I_RHND]),get_weapon(),monster,'R');
      else meleehit(0,NULL,get_weapon(),monster,'R');
    if (is_weapon(&(player.invent[I_LHND])) && monster->hp > 0) meleehit(0,&(player.invent[I_LHND]),offhand_weapon() / 2,monster,'L');
    } /* void hit_enemy() */

  void search_wall(int px,int py,int wall) {
    int x,y;
    for (x=px-1; x<= px+1; x++)
      for (y=py-1; y<= py+1; y++)
        if (x>1 && x<99 && y>1 && y<99)
          if (player.map[x][y] == wall) {
            if (player.map[x-1][y] != wall && player.map[x+1][y] != wall) {
              player.map[x][y] = 22;
              player.known[x][y] = 0;
              add_skill(SK_SCOUT,1);
              }
            if (player.map[x][y-1] != wall && player.map[x][y+1] != wall) {
              player.map[x][y] = 22;
              player.known[x][y] = 0;
              add_skill(SK_SCOUT,1);
              }
            }
     return;



      if (player.map[px][py-1] == wall && player.map[px][py-2] != wall &&
          player.map[px-1][py-1] == wall && player.map[px+1][py-1] == wall &&
          player.map[px][py] != wall) {
        player.map[px][py-1] = 22;
        player.known[px][py-1] = 0;
        add_skill(SK_SCOUT,1);
        }
      if (player.map[px][py+1] == wall && player.map[px][py+2] != wall &&
          player.map[px-1][py+1] == wall && player.map[px+1][py+1] == wall &&
          player.map[px][py] != wall) {
        player.map[px][py+1] = 22;
        player.known[px][py+1] = 0;
        add_skill(SK_SCOUT,1);
        }
      if (player.map[px-1][py] == wall && player.map[px-2][py] != wall &&
          player.map[px-1][py-1] == wall && player.map[px-1][py+1] == wall &&
          player.map[px][py] != wall) {
        player.map[px-1][py] = 22;
        player.known[px-1][py] = 0;
        add_skill(SK_SCOUT,1);
      }
      if (player.map[px+1][py] == wall && player.map[px+2][py] != wall &&
          player.map[px+1][py-1] == wall && player.map[px+1][py+1] == wall &&
          player.map[px][py] != wall) {
        player.map[px+1][py] = 22;
        player.known[px+1][py] = 0;
        add_skill(SK_SCOUT,1);
        }
    }

  void search() {
    int x,y;
    int px,py;
    if (player.in_city == 'Y') return;
    px = player.x;
    py = player.y;
    for (x=player.x-1; x<= player.x+1; x++)
      for (y=player.y-1; y<= player.y+1; y++)
        if (player.map[x][y]>=800 && player.map[x][y]<900) {
            if (u_random(100) < (10+get_skill(SK_SCOUT)) || has_intrinsic(A_SRCH)) {
            player.map[x][y] = 40;
            player.known[x][y] = 0;
            add_skill(SK_SCOUT,1);
            }
        }
    if (u_random(100) < (10 + get_skill(SK_SCOUT)) || has_intrinsic(A_SRCH)) {
      search_wall(px,py,21);
      search_wall(px,py,38);
      search_wall(px,py,39);
      search_wall(px,py,41);
      } 
    discover();
    if (u_random(10) == 1) add_skill(SK_SCOUT,1);
    } /* void search() */
 
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
        arena(0-player.map[player.x][player.y],7,barriers(),player.x,player.y);
      else hit_enemy();
      }
    player.x -= xdir;
    player.y -= ydir;
    } /* void attack() */

  void eat() {
    OBJECT_REC* item;
    int i;
    if (player.health > 100) {
      clear_prompt();
      prompt("Too full to eat any more");
      return;
      }
    item = NULL;
    for (i=1; i<11; i++)
      if (player.invent[i].otype == O_FOOD) {
         item = &(player.invent[i]);
         i = 99;
        }
    if (item == NULL) {
      for (i=1; i<=32; i++)
        if (player.pack[i].otype == O_FOOD) {
          item = &(player.pack[i]);
          i = 99;
          }
      }
    if (item == NULL) {
      clear_prompt();
      prompt("Nothing to Eat!!!");
      }
    else {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        }
      perform_effect(item);
      show_side();
      }
    }

/*
  void eat() {
    OBJECT_REC* item;
    inv_item = 0;
    item = NULL;
    if (player.health > 100) {
      clear_prompt();
      prompt("Too full to eat any more");
      return;
      }
    if (item == NULL) {
      saveScreen();
      item = inventory(NULL);
      restoreScreen();
      }
    if (item != NULL && item->otype == O_FOOD) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        if (use_from_ground == 'Y') player.map[player.x][player.y] = currentFloor;
        }
      perform_effect(item);
      }
    show_spot(player.x,player.y);
    show_player();
    show_side();
    }
*/

  void move(int xdir,int ydir) {
    int x,y;
    int previous;
    int ex,ey;
    last_target_x = 0;
    last_target_y = 0;
    remove_player();
    x = player.x;
    y = player.y;
    if (player.map[player.x+xdir][player.y+ydir] == 22 &&
        auto_open_doors == 'Y') {
        player.map[player.x+xdir][player.y+ydir] = 23;
        show_spot(player.x+xdir,player.y+ydir);
        show_player();
        return;
      }
    if (player.map[player.x+xdir][player.y+ydir] == 21 &&
        auto_bump_walls == 'Y') {
        search();
        show_player();
        return;
      }
    player.x += xdir;
    player.y += ydir;
    if (valid_move(player.x,player.y) == ' ') {
      player.x -= xdir;
      player.y -= ydir;
      }
    if (player.map[player.x][player.y] < 0 &&
        (player.monster[1][0-player.map[player.x][player.y]].special & MS_FRIENDLY) == 0) {
      if (combat_mode == 'F' || (player.monster[2][0-player.map[player.x][player.y]].hp != 0)) {
        ex = player.x;
        ey = player.y;
        previous = player.monster[1][0-player.map[ex][ey]].prev;
        arena(0-player.map[player.x][player.y],7,barriers(),player.x,player.y);
        if (player.map[ex][ey] == 7) player.map[ex][ey] = previous;
        show_spot(ex,ey);
        }
      else {
        player.x = x;
        player.y = y;
        show_player();
        player.x += xdir;
        player.y += ydir;
        hit_enemy();
        }
      player.x = x;
      player.y = y;
      }
    if (player.effect[PE_ROOT] > 0) { player.x = x; player.y = y; }
    if (get_weight() > get_max_weight()) { player.x = x; player.y = y; msg("Overburdoned",15); }
    if (adjust_map() == 'Y') show_map();
    show_player();
    stats.counts[STAT_STEPS_TAKEN]++;
    check_autos();
    }

  void remove_bones() {
    }

  int check_level_cleared() {
    int x,y;
    if (player.in_city == 'Y' || player.d_level < 1 || levelCleared) return 0;
    y = 0;
    for (x=1; x<=60; x++)
      if (player.monster[1][x].hp > 0 && (player.monster[1][x].special & MS_FRIENDLY) == 0) y++;
    return (y > 0) ? 0 : -1;
    }

  void down_level(int check_clear) {
    int i,j;
    if (player.map[player.x][player.y] == 24 ||
        player.map[player.x][player.y] == 5) {
      if (player.d_level > 0) {
        save_level();
        if (current_dungeon.level[player.d_level-1].cleared == 0) {
          if (check_level_cleared(player.d_level-1)) {
            current_dungeon.level[player.d_level-1].cleared = -1;
            stats.counts[STAT_LEVELS_CLEARED]++;
            j = -1;
            for (i=0; i<10; i++) if (current_dungeon.level[i].cleared == 0) j = 0;
            if (j) stats.counts[STAT_DUNGEON_CLEARED]++;
            }
          }
        }
      player.d_level++;
      make_map('D');
      levelCleared = check_level_cleared();
      player.map_x = player.x - TILES_X/2;
      player.map_y = player.y - TILES_Y/2;
      if (player.map_x < 1) player.map_x = 1;
      if (player.map_y < 1) player.map_y = 1;
      if (player.map_x > 100-TILES_X) player.map_x = 100-TILES_X;
      if (player.map_y > 100-TILES_Y) player.map_y = 100-TILES_Y;
      show_screen();
/*      activeDelay = 2; */
      if (in_room(player.x,player.y) && can_see()) light_room();
      }
    } /* void down_level() */

  void up_level() {
    int i,j;
    if (player.map[player.x][player.y] == 25) {
      save_level();
      if (current_dungeon.level[player.d_level-1].cleared == 0) {
        if (check_level_cleared(player.d_level-1)) {
          current_dungeon.level[player.d_level-1].cleared = -1;
          stats.counts[STAT_LEVELS_CLEARED]++;
          j = -1;
          for (i=0; i<10; i++) if (current_dungeon.level[i].cleared == 0) j = 0;
          if (j) stats.counts[STAT_DUNGEON_CLEARED]++;
          }
        }
      player.d_level--;
      if (player.d_level != 0) {
        make_map('U');
        levelCleared = check_level_cleared();
        }
      player.map_x = player.x - TILES_X/2;
      player.map_y = player.y - TILES_Y/2;
      if (player.map_x < 1) player.map_x = 1;
      if (player.map_y < 1) player.map_y = 1;
      if (player.map_x > 100-TILES_X) player.map_x = 100-TILES_X;
      if (player.map_y > 100-TILES_Y) player.map_y = 100-TILES_Y;
      if (player.d_level != 0) show_screen();
/*      activeDelay = 2; */
      if (in_room(player.x,player.y) && can_see()) light_room();
      }
    } /* void up_level() */

  void do_inventory() {
    saveScreen();
    inventory(NULL);
    restoreScreen();
    show_map();
    show_player();
    auto_detect();
    } /* void do_inventory() */

  void talk() {
    char key;
    char flag;
    int  i;
    NPC_REC* monster;
    int  xdir,ydir;
    key = item_dir(-1);
    if (key == ' ') {
      clear_prompt();
      prompt("Talk to who?");
      flag = ' ';
      while (flag == ' ') {
        key = inkey();
        if (key >= '1' && key < '5') flag = '*';
        if (key > '5' && key <= '9') flag = '*';
        }
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
    monster = get_monster(player.x + xdir,player.y + ydir);
    if (monster == NULL) {
      clear_prompt();
      msg("No one there ! ! !",14);
      }
    if (monster != NULL) {
      if ((monster->special & MS_FRIENDLY) == 0) {
        clear_prompt();
        prompt("Die Scum!!!");
        }
      else {
        if ((monster->special & MS_TALKED) == 0) {
          monster->special |= MS_TALKED;
          flag = ' ';
          i = 0;
          while (trophies[i].criteria_type < 999) {
            if (trophies[i].criteria_type == TC_TRICK) {
              if (player.invent[I_ARMR].link >= trophies[i].control[0] &&
                  player.invent[I_ARMR].link <= trophies[i].control[1] &&
                  (player.invent[I_RHND].link == trophies[i].control[2] ||
                   player.invent[I_LHND].link == trophies[i].control[2])
                 ) {
                stats.counts[trophies[i].control[3]] |= 
                     ( 1 << (player.invent[I_ARMR].link - trophies[i].control[0]));
                msg("Trick or Treat",15);
                special(84,NULL);
                flag = '*';
                }
              }
            i++;
            }
          if (flag == ' ' && player.in_city == 'Y' && player.city == 17) special(51,NULL);
            else special(20,NULL);
          stats.counts[STAT_CONVERSATIONS]++;
          }
        else {
          clear_prompt();
          msg("Hello!!",9);
          }
        }
      }
    } /* void talk() */

  void light_torch() {
    if (player.torch > 0) {
      player.torch--;
      player.effect[PE_LIGHT] = 2000;
      show_side();
      show_map();
      show_player();
      }
    } /* void light_torch() */

  void add_to_party(NPC_REC* monster,int x,int y) {
    int pos;
    if (player.party[1].hp == 0) pos = 1;
      else if (player.party[2].hp == 0) pos = 2;
      else if (player.party[3].hp == 0) pos = 3;
      else if (player.party[4].hp == 0) pos = 4;
      else if (player.party[5].hp == 0) pos = 5;
      else pos = 0;
    if (pos>0) {
      clear_prompt();
      msg("I would be Honored!!!",15);
      monster->special |= MS_FRIENDLY;
      player.party[pos] = *monster;
      player.party[pos].exp = needed(player.party[pos].level);
      player.party[pos].time = -1;
      player.party[pos].hp = player.party[pos].level * 9;
      player.map[x][y] = player.party[pos].prev;
      if (player.effect[PE_HEROIC] > 0) {
        player.party[pos].hp *= player.effect[PE_HEROIC];
        }
      show_spot(x,y);
      }
    else {
     clear_prompt();
     msg("Your party seems full as it is!!",14);
     }
  }

  void join() {
    char key;
    char flag;
    NPC_REC*  monster;
    int  xdir,ydir;
    key = item_dir(-1);
    if (key == ' ') {
      clear_prompt();
      prompt("Ask who to join?");
      flag = ' ';
      while (flag == ' ') {
        key = inkey();
        if (key >= '1' && key < '5') flag = '*';
        if (key > '5' && key <= '9') flag = '*';
        }
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
    monster = get_monster(player.x + xdir,player.y + ydir);
    if (monster == NULL) {
      clear_prompt();
      msg("No one there ! ! !",14);
      }
    if (monster != NULL) {
      if ((monster->special2 & M2_PACIFIED) != 0) {
        if (u_random(100)<(50+(player.level-monster->level)*10)) {
          add_to_party(monster,player.x+xdir,player.y+ydir);
          }
        else {
            clear_prompt();
            msg("No Thanks.",14);
          }
        }
      else if ((monster->special & MS_FRIENDLY) == 0) {
          clear_prompt();
          msg("No Way Scum!!!",14);
        }
      else
        if ((monster->special & MS_JOIN) == 0) {
          monster->special |= MS_JOIN;
            if (u_random(100)<(50+(player.level-monster->level)*10)) {
              add_to_party(monster,player.x+xdir,player.y+ydir);
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
    check_mount();
    } /* void join() */

  int is_merchant() {
    int flag;
    int i;
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
    if (flag >= 0) return -1;
    return 0;
    }

  void buy_item() {
    int flag;
    int x,y;
    int price;
    OBJECT_REC item;
    OBJECT_REC* pitem;
    flag = 0;
    for (y=player.y-1; y<=player.y+1; y++)
      for (x=player.x-1; x<=player.x+1; x++)
        if (player.map[x][y] == 536) flag = -1;
    if (flag == -1) {
      pitem = NULL;
      if (u_random(1000) < 10) pitem = find_linked_item(532);
      else if (u_random(1000) < 100) pitem = find_linked_item(533);
      else if (u_random(1000) < 500) pitem = find_linked_item(535);
      else pitem = find_linked_item(534);
      price = 1000;
      if (player.in_city == 'N') {
        price = 300 - (player.d_level * 10);
        }
      if (price < 200) price = 200;
      if (get_gold() < price) {
        msg("Not enough gold",14);
        pitem = NULL;
        }
      if (pitem != NULL) {
        sub_gold(price);
        item = *pitem;
        if (item.level > 0) item.level = -item.level;
        inventory(&item);
        show_screen();
        }
      }
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
        case 12:pawn(shops[flag].name,get_city()); break;
        case 13:temple(shops[flag].name); break;
        case 14:cavalier(shops[flag].name); break;
        case 15:mounts(shops[flag].name); break;
        case 16:bank(shops[flag].name); break;
        case 17:shop(shops[flag].name,SHOP_CRFT); break;
        case 18:shop(shops[flag].name,SHOP_SPEL); break;
        case 19:shop(shops[flag].name,SHOP_RECP); break;
        }
/*      show_screen(); */
      restoreScreen();
      show_player();
      }
    } /* void buy_item() */

  void find_closest_mob() {
    int dist;
    int closestX;
    int closestY;
    dist = 50000;
    closestX = 0;
    closestY = 0;
    for (x=1; x<100; x++)
      for (y=1; y<100; y++) {
        if (player.map[x][y] < 0) {
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

  void gps() {
    char buffer[20];
    sprintf(buffer,"Region    : %d",player.region);
    msg(buffer,15);
    sprintf(buffer,"Region X,Y: %d,%d",player.land_x,player.land_y);
    msg(buffer,15);
    sprintf(buffer,"X,Y       : %d,%d",player.x,player.y);
    msg(buffer,15);
    }

  int check_quit() {
    int key;
    saveScreen();
    clrscr();
    textcolor(12); gotoxy(35,8); txt_write("WARNING!!!");
    textcolor(15); gotoxy(6,10); txt_write("Using the <Q>uit command will permenently end your current character.");
    textcolor(15); gotoxy(6,11); txt_write("Are you sure you want to permenently end this character (Y/N)?");
    key = ' ';
    while (key != 'Y' && key != 'N') {
      key = inkey();
      if (key == 'y') key = 'Y';
      if (key == 'n') key = 'N';
      }
    restoreScreen();
    return (key == 'Y') ? -1 : 0;
    }

   void run() {
     msg("Run dir?",14);
     get_dir(&run_x,&run_y);
     }

   void check_stop_running() {
     int x;
     int y;
     if (valid_move(player.x+run_x,player.y+run_y) == ' ') {
       run_x = 0;
       run_y = 0;
       return;
       }
     if (player.map[player.x+run_x][player.y+run_y] == 24 ||
         player.map[player.x+run_x][player.y+run_y] == 25) {
       run_x = 0;
       run_y = 0;
       return;
       }
     for (y=player.y-1; y<= player.y+1; y++)
       for (x=player.x-1; x<= player.x+1; x++)
         if (player.map[x][y] < 0) {
           run_x = 0;
           run_y = 0;
           return;
           }
     }

  /* **************************************** */
  /* ***** Actual start of dungeon code ***** */
  /* **************************************** */
  currentFloor = 7;
  dungeon_floor = currentFloor;
  dungeon_wall = 21;
  levelCleared = 0;
  dc = 1;
  if (player.in_city == 'Y') {
    check_noble();
    }
  check_mount();
  word_counter = 0;
  haste_flag = ' ';
  clair = ' ';
  napping = ' ';
  graphmode();
  if (used_sunstone == 'Y') {
    player.x = 20; player.y = 20;
    player.map[player.x][player.y] = 24;
    player.d_level--;
    down_level(0);
    used_sunstone = 'N';
    }
  else if (mod_exit == 2 && player.d_level == 0) {
      player.x = 20; player.y = 20;
    player.map[player.x][player.y] = 24;
      player.d_level = 0;
      down_level(0);
    }
  if (mod_exit == 5) {
      player.d_level = 1;
      copyMap(&player.map,player.city);
#ifdef MINGW
      m_file = open("temp01.$$$",O_RDONLY | O_BINARY);
#else
      m_file = open("temp01.$$$",O_RDONLY);
#endif
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
      player.map_x = player.x-TILES_X/2;
      player.map_y = player.y-TILES_Y/2;
      if (player.map_x<1) player.map_x = 1;
      if (player.map_y<1) player.map_y = 1;
      if (player.map_x>100-TILES_X) player.map_x = 100-TILES_X;
      if (player.map_y>100-TILES_Y) player.map_y = 100-TILES_Y;

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
  player.map_x = player.x - TILES_X/2;
  player.map_y = player.y - TILES_Y/2;
  if (player.map_x < 1) player.map_x = 1;
  if (player.map_y < 1) player.map_y = 1;
  if (player.map_x > 100-TILES_X) player.map_x = 100-TILES_X;
  if (player.map_y > 100-TILES_Y) player.map_y = 100-TILES_Y;
  if (player.in_city == 'Y') {
    for (x=1; x<=100; x++)
      for (y=1; y<=100; y++)
        if (player.known[x][y] == 0) player.known[x][y] = 1;
    }
  show_map();
  show_sm_map();
  discover();
  show_side();
  show_player();
  auto_detect();
  exitf = 0;
  run_x = 0;
  run_y = 0;
  while (exitf == 0) {
     show_time();
     show_player();
     if (run_x != 0 || run_y != 0) check_stop_running();
      if (player.effect[PE_SLEEP] != 0) key = ' ';
        else {
          if (run_x == -1 && run_y == 0) key = '4';
          if (run_x == 1 && run_y == 0) key = '6';
          if (run_x == 0 && run_y == -1) key = '8';
          if (run_x == 0 && run_y == 1) key = '2';
          if (run_x == -1 && run_y == -1) key = '7';
          if (run_x == 1 && run_y == -1) key = '9';
          if (run_x == -1 && run_y == 1) key = '1';
          if (run_x == 1 && run_y == 1) key = '3';
          if (run_x == 0 && run_y == 0) key = inkey();
          }
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
        case 'a':attack(); break;
        case 'Q':if (check_quit()) exitf = 1; break;
        case 'X':exitf = 4; break;
        case '8':move(0,-1); break;
        case '2':move(0,1); break;
        case '4':move(-1,0); break;
        case '6':move(1,0); break;
        case '7':move(-1,-1); break;
        case '9':move(1,-1); break;
        case '1':move(-1,1); break;
        case '3':move(1,1); break;
        case '5':run(); break;
        case '>':down_level(-1); break;
        case '<':up_level(); break;
        case '}':save_gear('N',-1); break;
        case ']':load_gear('N',-1); break;
        case '{':save_gear('Y',-1); break;
        case '[':load_gear('Y',-1); break;
        case 'e':eat(); break;
        case 's':search(); break;
        case 'H':show_icons(); break;
        case 'o':open_door(); break;
        case 'c':close_door(); break;
        case 'C':saveScreen(); crafting(); restoreScreen(); break;
        case 'i':do_inventory(); break;
        case 'g':do_get(); break;
        case 'G':if (player.map[player.x][player.y]>999) pack_it(7);
                 break;
        case 'q':show_quest(); break;
        case 'u':use_item(); break;
        case 'E':go_ship(); break;
        case 'f':fire_weapon(); break;
        case 'm':cast_spell(0); break;
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
        case 'x':transcribe(); break;
        case 'n':nap(); break;
        case 't': if (is_merchant()) buy_item(); else talk();
                   break;
        case 'T':throw(' '); break;
        case '-':throw('L'); break;
        case '=':throw('R'); break;
        case '+':throw('R'); break;
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
              if (player.effect[PE_HEROIC] >= 0) exitf = 4;
              else {
                saveScreen();
                save();
                restoreScreen();
                }
              break;
        case 'v':view(7); break;
        case 'V':soundon = (soundon == 'Y') ? 'N' : 'Y';
              break;
        case 'R':
              saveScreen();
              disp_char();
              restoreScreen();
              break;
        case 'h':healing(); break;
        case 'A':activate(player.x,player.y); break;
        case '?':dungeon_help(); break;
        case '~':gps(); break;
        case 'Z':show_number(); break;
        case ':':wizard(); break;
#ifdef ASCII
        case 'M':
                  saveScreen();
                  miniMap();
                  restoreScreen();
                  break;
#endif
/*        case '^':pit_trap(); break; */
        }
    key = ' ';
    discover();
    if (player.in_city != 'Y')
      if (in_room(player.x,player.y) && can_see()) light_room();
    if (player.align <= 0 && !(classes[player.class-1].flags & CF_ROGUE)) make_assassin();
    while (player.exp >= player.exp_next) { advancement(); show_side(); }
    if (has_intrinsic(A_TRAP) || u_random(100) < (get_skill(SK_SCOUT) / 5)) {
      for (x=player.x-1; x<=player.x+1; x++)
        for (y=player.y-1; y<=player.y+1; y++)
          if (x >= 1 && x<= 99 && y >= 1 && y <= 99)
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
          stats.counts[STAT_ITEMS_IDENTED]++;
          }
        }
      }
    if (player.map[player.x][player.y] == 801 && player.effect[PE_SLEEP] != 0) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) sleep_trap();
      }
    if (player.map[player.x][player.y] == 802) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) poison_trap();
      }
    if (player.map[player.x][player.y] == 803) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) dart_trap();
      }
    if (player.map[player.x][player.y] == 804) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) teleport_trap();
      }
    if (player.map[player.x][player.y] == 805) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) fire_trap();
      }
    if (player.map[player.x][player.y] == 806) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) blind_trap();
      }
    if (player.map[player.x][player.y] == 807) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) root_trap();
      }
    if (player.map[player.x][player.y] == 808) {
      player.map[player.x][player.y] = 40;
      if (has_intrinsic(A_LEV) == 0) pit_trap();
      }
    if (player.map[player.x][player.y] == 41) {
      if (player.gateway == '*' || has_intrinsic(A_FCNG) == 0) {
        clear_prompt();
        msg("ZZZZAAAAPPPP!!!!!",12);
        stats_take_damage(player.chp / 2);
        player.chp = player.chp / 2;
        show_side();
        }
      }
    if (player.map[player.x][player.y] == 38) {
        clear_prompt();
        msg("SIZZLE!!!!!",12);
        stats_take_damage(player.chp / 2);
        player.chp = player.chp / 2;
        show_side();
      }
    if (player.map[player.x][player.y] == 39) {
        clear_prompt();
        msg("GLUB GLUB!!!",12);
        stats_take_damage(player.chp / 2);
        player.chp = player.chp / 2;
        show_side();
      }
    if (has_intrinsic(A_SRCH)) search();
    if (haste_flag == ' ') {
/*      if (activeDelay > 0) activeDelay--; */
/*      else { */
          for (x=1; x<100; x++)
            for (y=1; y<100; y++)
              if (x>0 && x<100 && y>0 && y<100)
              if (player.map[x][y]<0) {
                if ((player.monster[1][0-player.map[x][y]].special & MS_MOVED) == 0)
                if (player.monster[1][0-player.map[x][y]].sleep <= 0) {
                  if (player.monster[1][0-player.map[x][y]].speed < 0) {
                    if (can_be_seen() && los(player.x,player.y,x,y,'Y') != 0 &&
                        abs(player.x-x) < 20 && abs(player.y-y) < 20)
                      player.monster[1][0-player.map[x][y]].speed = 0-player.monster[1][0-player.map[x][y]].speed;
                    }
                  if ((player.monster[1][0-player.map[x][y]].mana != 0) &&
                      ((player.monster[1][0-player.map[x][y]].special & MS_FRIENDLY) == 0) &&
                      (player.monster[1][0-player.map[x][y]].speed >= 0))
                    if (u_random(100)<50) enemy_missile(x,y);
                  if (player.monster[1][0-player.map[x][y]].speed >= 0 &&
                      player.monster[1][0-player.map[x][y]].sleep == 0 &&
                      (player.monster[1][0-player.map[x][y]].special2 & M2_PACIFIED) == 0)
                    move_enemy(x,y);
                  }
                }
          for (x=1; x<=60; x++)
            if ((player.monster[1][x].special & MS_MOVED) == MS_MOVED)
              player.monster[1][x].special -= MS_MOVED;
          for (x=player.x-1; x<=player.x+1; x++)
            for (y=player.y-1; y<=player.y+1; y++)
              if (x>1 && x<100 && y>1 && y<100)
                if (player.map[x][y]<0)
                  if ((player.monster[1][0-player.map[x][y]].special & MS_FRIENDLY) == 0 &&
                       player.monster[1][0-player.map[x][y]].sleep <= 0) {

                    if (player.monster[2][0-player.map[x][y]].hp != 0) {
                      previous = player.monster[1][0-player.map[x][y]].prev;
                      arena(0-player.map[x][y],7,barriers(),x,y);
                      if (player.map[x][y] == 7) player.map[x][y] = previous;
                      }
                      else enemy_hit(x,y);
                    }
/*          }   */

        for (x=1; x<=5; x++) {
            if (player.party[x].sleep>0) player.party[x].sleep--;
            if (player.party[x].fear>0) player.party[x].fear--;
          }
        for (x=1; x<=60; x++) {
            if (player.monster[1][x].sleep>0) player.monster[1][x].sleep--;
            if (player.monster[1][x].sleep<0) player.monster[1][x].sleep++;
            if (player.monster[1][x].fear>0) {
              player.monster[1][x].fear--;
              if (player.monster[1][x].fear == 0) msg("Mob no longer scared",7);
              }
            if (player.monster[1][x].blind>0) player.monster[1][x].blind--;
            if (player.monster[1][x].confused>0) player.monster[1][x].confused--;
            if (player.monster[1][x].poison>0) {
msg("here",15);
sprintf(buffer,"poison=%d",player.monster[1][x].poison);
msg(buffer,15);
              player.monster[1][x].poison--;
              player.monster[1][x].hp -= 2;
              dead_monster(&(player.monster[1][x]),'Y',player.x,player.y);
msg("done",15);
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
            if (player.effect[PE_PROT] == 0) {
              show_side();
              msg("Protection fades",7);
              }
          }
        if (player.effect[PE_FIRE]>0) {
            player.effect[PE_FIRE]--;
            if (player.effect[PE_FIRE] == 0)  show_side();
          }
        if (player.effect[PE_COLD]>0) {
            player.effect[PE_COLD]--;
            if (player.effect[PE_COLD] == 0)  show_side();
          }
        if (player.effect[PE_ELEC]>0) {
            player.effect[PE_ELEC]--;
            if (player.effect[PE_ELEC] == 0)  show_side();
          }
        if (player.effect[PE_ARCN]>0) {
            player.effect[PE_ARCN]--;
            if (player.effect[PE_ARCN] == 0)  show_side();
          }
        if (player.effect[PE_HASTE]>0) {
            player.effect[PE_HASTE]--;
            if (player.effect[PE_HASTE] == 0)  show_side();
          }
        if (player.effect[PE_GIANT]>0) {
            player.effect[PE_GIANT]--;
            if (player.effect[PE_GIANT] == 0)  show_side();
          }
        dc = 1+rcs_trunc(player.level/6.0);
      }

    if (classes[player.class-1].flags & CF_MONK)
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
      if (player.effect[PE_HCOUNT] > HEAL_TIME) player.effect[PE_HCOUNT] = HEAL_TIME;
      if (player.effect[PE_HCOUNT] > 0) player.effect[PE_HCOUNT]--;
      if (player.effect[PE_READLORE]>0) player.effect[PE_READLORE]--;
      if (player.effect[PE_READLANG]>0) player.effect[PE_READLANG]--;
      if (player.effect[PE_FEAR]>0) {
        player.effect[PE_FEAR]--;
        if (player.effect[PE_FEAR] == 0) msg("No longer afraid",14);
        }
      if (player.effect[PE_CONFUSED]>0) {
        player.effect[PE_CONFUSED]--;
        if (player.effect[PE_CONFUSED] == 0) msg("Your head clears",14);
        }
      if (player.effect[PE_LEV]>0) {
        player.effect[PE_LEV]--;
        if (player.effect[PE_LEV] == 0) show_side();
        }
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
      if (player.effect[PE_ROOT]>0) {
          player.effect[PE_ROOT]--;
          if (player.effect[PE_ROOT] == 0) {
              show_spot(player.x,player.y);
              show_player();
            }
        }
      if (player.effect[PE_LIGHT]>0) {
          player.effect[PE_LIGHT]--;
          if (player.effect[PE_LIGHT] == 0) {
            run_x = 0;
            run_y = 0;
            show_side();
            show_map();
            }
        }
      if (player.effect[PE_POLYTIME]>0) {
          player.effect[PE_POLYTIME]--;
          if (player.effect[PE_POLYTIME] == 10) msg("Poly ends 10 turns",15);
          if (player.effect[PE_POLYTIME] > 0 && player.effect[PE_POLYTIME] < 6) {
            sprintf(buffer,"Poly ends %d turns",player.effect[PE_POLYTIME]);
            msg(buffer,15);
            }
          if (player.effect[PE_POLYTIME] == 0) {
            msg("Polymorph ended",15);
            player.chp -= monsters[player.effect[PE_POLYMORPH]].hp;
            player.mhp -= monsters[player.effect[PE_POLYMORPH]].hp;
            if (player.chp < 0) player.chp = 0;
            show_side();
            }
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
        if (player.party[i].time>0) {
            player.party[i].time--;
            if (player.party[i].time == 0)
              player.party[i].hp = 0;
          }
      player.hp_count -= get_hpr();
      if (player.hp_count<1) {
          player.hp_count = 50;
          if (player.chp<get_mhp()) player.chp = player.chp+1;
          show_side();
        }
      player.mana_count -= get_manar();
      if (player.mana_count<1) {
          player.mana_count = 100;
          if (player.cmana<get_mmana()) player.cmana = player.cmana+1;
          show_side();
        }
      take_time();
      if (player.in_city == 'Y')
        if (player.x == 1 || player.x == 100 ||
            player.y == 1 || player.y == 100) {
#ifdef MINGW
            m_file = open("temp01.$$$",O_RDWR | O_BINARY);
#else
            m_file = open("temp01.$$$",O_RDWR);
#endif
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
#ifdef ASCII
          putimage(400,675,select_sprite(10),0);
          putimage(400,675,select_sprite(x),0);
#else
          putimage(300,screen_height-27,select_sprite(10),0);
          putimage(300,screen_height-27,select_sprite(x),0);
#endif
          } else
#ifdef ASCII		
		  putimage(400,675,select_sprite(10),0);
#else
		  putimage(300,screen_height-27,select_sprite(10),0);
#endif
        } else
#ifdef ASCII
	       	putimage(400,675,select_sprite(10),0);
#else
	       	putimage(300,screen_height-27,select_sprite(10),0);
#endif
      check_trophies();
      if (player.d_level == 0) exitf = 2;
      if (player.chp<1) exitf = 6;
      if (player.health<=0) exitf = 6;
    if (has_intrinsic(A_FOOD) && player.health < 100) player.health++;
    if (get_str() <= 0 || get_dex() <= 0 || get_int() <= 0 ||
        get_con() <= 0 || get_wis() <= 0 || get_chr() <= 0) exitf = 9;
    }
  /* ************************************ */
  /* ***** End of main dungeon loop ***** */
  /* ************************************ */
  if (exitf == 1) mod_exit = 3;
  if (exitf == 2) mod_exit = 1;
  if (exitf == 4) mod_exit = 4;
  if (exitf == 6) mod_exit = 6;
  if (exitf == 7) mod_exit = 7;
  if (exitf == 9) mod_exit = 9;
  if (exitf == 10) mod_exit = 2;
  remove_bones();
  }

