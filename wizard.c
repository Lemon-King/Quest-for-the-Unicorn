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

typedef struct {
  char name[26];
  int  number;
  } WIZARD_SPECIALS;

WIZARD_SPECIALS special_names[] = {
  { "Clairaudience",1 },            /* 1 */
  { "Clairvoyance",2 },             /* 2 */
  { "Haste",3 },                    /* 3 */
  { "Giant Strength",4 },           /* 4 */
  { "Ethereal",5 },                 /* 5 */
  { "Light",6 },                    /* 6 */
  { "Locate All",7 },               /* 7 */
  { "Object Location",8 },          /* 8 */
  { "Monster Location",9 },         /* 9 */
  { "Lore Scroll",10 },              /* 10 */
  { "Information Scroll",11 },       /* 11 */
  { "Identification",12 },           /* 12 */
  { "Protection",13 },               /* 13 */
  { "Magic Mapping",14 },            /* 14 */
  { "Return to Surface",15 },        /* 15 */
  { "Increase Strength",16 },        /* 16 */
  { "Increase Dexterity",17 },       /* 17 */
  { "Increase Intelligence",18 },    /* 18 */
  { "Double Mana",19 },              /* 19 */
  { "General Message",20 },          /* 20 */
  { "Read Languages",21 },           /* 21 */
  { "Detect Magic",22 },             /* 22 */
  { "Identify Monster",23 },         /* 23 */
  { "Slow Poison",24 },              /* 24 */
  { "Cure Poison",25 },              /* 25 */
  { "Permanent Light",26 },          /* 26 */
  { "Monster Summoning",27 },        /* 27 */
  { "Read Lore",28 },                /* 28 */
  { "Dispel Force Field",29 },       /* 29 */
  { "Force Field",30 },              /* 30 */
  { "Increase Random Stat",31 },     /* 31 */
  { "Monster Summoning II",32 },     /* 32 */
  { "Monster Summoning III",33 },    /* 33 */
  { "Phase Door",34 },               /* 34 */
  { "Permanancy",35 },               /* 35 */
  { "Remove Fear",36 },              /* 36 */
  { "Find Traps",37 },               /* 37 */
  { "Fire Resistance",38 },          /* 38 */
  { "Summon Shadow",39 },            /* 39 */
  { "Create Food",40 },              /* 40 */
  { "Sticks to Snakes",41 },         /* 41 */
  { "Summon Monster",42 },           /* 42 */
  { "Enhance Trap Location",43 },    /* 43 */
  { "Summon Air Elemental",44 },     /* 44 */
  { "Summon Water Elemental",45 },   /* 45 */
  { "Talning Rod Functions",46 },    /* 46 */
  { "Tardis Functions",47 },         /* 47 */
  { "Show Bottom Map",48 },          /* 48 */
  { "Library",49 },                  /* 49 */
  { "Trio of Might",50 },            /* 50 */
  { "Lore Message",51 },             /* 51 */
  { "Enlightenment",52 },            /* 52 */
  { "Knowledge",53 },                /* 53 */
  { "Mana Back to Max",54 },         /* 54 */
  { "Double Mana",55 },              /* 55 */
  { "Experience 5%",56 },            /* 56 */
  { "Experience 7%",57 },            /* 57 */
  { "Experience 10%",58 },           /* 58 */
  { "Experience 15%",59 },           /* 59 */
  { "Cause Sleep",60 },              /* 60 */
  { "Cause Fear",61 },               /* 61 */
  { "Cause Blindness",62 },          /* 62 */
  { "Cause Confusion",63 },          /* 63 */
  { "Cure Confusion",64 },           /* 64 */
  { "Cure Fear",65 },                /* 65 */
  { "Cure Blindness",66 },           /* 66 */
  { "Cure All",67 },                 /* 67 */
  { "Enchant Weapon",68 },           /* 68 */
  { "Enchant Armor",69 },            /* 69 */
  { "Corrode Weapon",70 },           /* 70 */
  { "Corrode Armor",71 },            /* 71 */
  { "Bless",72 },                    /* 72 */
  { "Charging",73 },                 /* 73 */
  { "Enhanced Bless",74 },           /* 74 */
  { "Summon Torches",75 },           /* 75 */
  { "Levitation",76 },               /* 76 */
  { "Sex Change",77 },               /* 77 */
  { "Alcohol",78 },                  /* 78 */
  { "Random Recipe",79 },            /* 79 */
  { "Add Socket",80 },               /* 80 */
  { "Remove Enchants",81 },          /* 81 */
  { "Remove Socketed Items",82 },    /* 82 */
  { "Add Random Charm",83 },         /* 83 */
  { "Add Random Candy",84 },         /* 84 */
  { "Add Random Item",85 },          /* 85 */
  { "Charm Monster",86 },            /* 86 */
  { "Remove Root",87 },              /* 87 */
  { "Bandage",88 },                  /* 88 */
  { "Polymorph",89 },                /* 89 */
  { "Pacify",90 },                   /* 90 */
  { "Flare",91 },                    /* 91 */
  };

char game_edited;

void wizard() {
  char buffer[80];
  char buffer2[80];
  char key;
  char pword[41];
  int  sorted[2500];
  int  num_sorted;

  void sort_special_names() {
    int i;
    char flag;
    WIZARD_SPECIALS tmp;
    flag = '*';
    while (flag == '*') {
      flag = ' ';
      for (i=0; i<90; i++)
        if (strcmp(special_names[i].name,special_names[i+1].name) > 0) {
          flag = '*';
          tmp = special_names[i];
          special_names[i] = special_names[i+1];
          special_names[i+1] = tmp;
          }
      }
    }

  int input(char* prompt) {
    int ret;
    strcpy(buffer,"");
    strcpy(pword,prompt);
    msg(pword,11);
    key = 0;
    while (key != 13) { 
      sprintf(buffer2,"%s_",pword);
      key = inkey();
      if (key >= ' ') {
        buffer[strlen(buffer) + 1] = 0;
        buffer[strlen(buffer)] = key;
        pword[strlen(pword) + 1] = 0;
        pword[strlen(pword)] = key;
        msg(pword,-11);
        }
      if (key == 8 && strlen(buffer) > 0) {
        buffer[strlen(buffer) - 1] = 0;
        pword[strlen(pword) - 1] = 0;
        msg(pword,-11);
        }
      }
    ret = atoi(buffer);
    return ret;
    }

  void character() {
    int  i;
    int  x,y;
    char key;
    int  pos;
    int  dir;
    int  original_class;
    int  original_level;
    char buffer[32];
    original_class = player.class;
    original_level = player.level;
    clrscr();
    textcolor(15); gotoxy(35,1); txt_write("Character:");
    textcolor(2);
    gotoxy(4,3); txt_write("Age    :");
    gotoxy(4,4); txt_write("Sex    :");
    gotoxy(4,5); txt_write("Race   :");
    gotoxy(4,6); txt_write("Class  :");
    gotoxy(4,7); txt_write("Level  :");
    gotoxy(4,8); txt_write("Str    :");
    gotoxy(4,9); txt_write("Dex    :");
    gotoxy(4,10); txt_write("Con    :");
    gotoxy(4,11); txt_write("Int    :");
    gotoxy(4,12); txt_write("Wis    :");
    gotoxy(4,13); txt_write("Chr    :");
    gotoxy(4,14); txt_write("C Hp   :");
    gotoxy(4,15); txt_write("M Hp   :");
    gotoxy(4,16); txt_write("C Mana :");
    gotoxy(4,17); txt_write("M Mana :");
    gotoxy(4,18); txt_write("Gold   :");
    gotoxy(28, 3); txt_write("Bows       :");
    gotoxy(28, 4); txt_write("1H Swords  :");
    gotoxy(28, 5); txt_write("Spears     :");
    gotoxy(28, 6); txt_write("Maces      :");
    gotoxy(28, 7); txt_write("Scouting   :");
    gotoxy(28, 8); txt_write("Language   :");
    gotoxy(28, 9); txt_write("Lore       :");
    gotoxy(28,10); txt_write("Magic      :");
    gotoxy(28,11); txt_write("Healing    :");
    gotoxy(28,12); txt_write("Medicine   :");
    gotoxy(28,13); txt_write("Riding     :");
    gotoxy(28,14); txt_write("Boating    :");

    gotoxy(57, 3); txt_write("Oracle     :");
    gotoxy(57, 4); txt_write("Charm      :");
    gotoxy(57, 5); txt_write("Survival   :");
    gotoxy(57, 6); txt_write("Combat     :");
    gotoxy(57, 7); txt_write("Daggers    :");
    gotoxy(57, 8); txt_write("2H Swords  :");
    gotoxy(57, 9); txt_write("Axes       :");
    gotoxy(57,10); txt_write("Flails     :");
    gotoxy(57,11); txt_write("Crossbows  :");
    gotoxy(57,12); txt_write("Tridents   :");
    gotoxy(57,13); txt_write("Poleaxes   :");
    gotoxy(57,14); txt_write("Thrown     :");
    textcolor(14);
    sprintf(buffer,"%d",player.age); gotoxy(13,3); txt_write(buffer);
    sprintf(buffer,"%s",(player.sex == 'F') ? "Female" : "Male"); gotoxy(13,4); txt_write(buffer);
    sprintf(buffer,"%s",races[player.race-1].name); gotoxy(13,5); txt_write(buffer);
    sprintf(buffer,"%s",classes[player.class-1].name); gotoxy(13,6); txt_write(buffer);
    sprintf(buffer,"%d",player.level); gotoxy(13,7); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[1]); gotoxy(13,8); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[2]); gotoxy(13,9); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[3]); gotoxy(13,10); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[4]); gotoxy(13,11); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[5]); gotoxy(13,12); txt_write(buffer);
    sprintf(buffer,"%d",player.stat[6]); gotoxy(13,13); txt_write(buffer);
    sprintf(buffer,"%d",player.chp); gotoxy(13,14); txt_write(buffer);
    sprintf(buffer,"%d",player.mhp); gotoxy(13,15); txt_write(buffer);
    sprintf(buffer,"%d",player.cmana); gotoxy(13,16); txt_write(buffer);
    sprintf(buffer,"%d",player.mmana); gotoxy(13,17); txt_write(buffer);
    sprintf(buffer,"%d",get_gold()); gotoxy(13,18); txt_write(buffer);
    for (i=1; i<=12; i++) {
      sprintf(buffer,"%2d %05d",player.skill[i] / 100000,player.skill[i] % 100000);
      gotoxy(41,i+2); txt_write(buffer);
      sprintf(buffer,"%2d %05d",player.skill[i+12] / 100000,player.skill[i+12] % 100000);
      gotoxy(70,i+2); txt_write(buffer);
      }
    key = ' ';
    pos = 1;
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    x = 1;
    y = 3;
    while (key != 13 && key != 27) {
/*
      x = (pos < 17) ? 11 : 41;
      y = (pos < 17) ? pos + 2 : pos - 14;
*/
      textcolor(15); gotoxy(x,y); txt_write("-->");
      key = inkey();
      textcolor(15); gotoxy(x,y); txt_write("   ");
      textcolor(14);
      dir = 0;
      if (key == '2') {
        y++;
        if (x == 1 && y > 18) y = 3;
        if (x != 1 && y > 14) y = 3;
        }
      if (key == '8') {
        y--;
        if (x == 1 && y < 3) y = 18;
        if (x != 1 && y < 3) y = 14;
        }
      if (key == '4') {
        if (x == 1) x = 54;
        else if (x == 54) x = 25;
        else x = 1;
        if (x != 1 && y > 14) y = 14;
        }
      if (key == '6') {
        if (x == 1) x = 25;
        else if (x == 25) x = 54;
        else x = 1;
        if (x != 1 && y > 14) y = 14;
        }
      if (key == '-') dir = -1;
      if (key == '+') dir = 1;
      if (key == '=') dir = 1;
      if (dir != 0) {
        game_edited = 'Y';
        if (x == 1 && y == 3) {
          player.age += dir;
          if (player.age < 18) player.age = 18;
          if (player.age > 99) player.age = 99;
          sprintf(buffer,"%d   ",player.age); gotoxy(13,3); txt_write(buffer);
          }
        if (x == 1 && y == 4) {
          player.sex = (player.sex == 'F') ? 'M' : 'F';
          sprintf(buffer,"%s     ",(player.sex == 'F') ? "Female" : "Male"); gotoxy(13,4); txt_write(buffer);
          }
        if (x == 1 && y == 5) {
          player.race += dir;
          if (player.race < 1) player.race = NUM_RACES;
          if (player.race > NUM_RACES) player.race = 1;
          sprintf(buffer,"%s         ",races[player.race-1].name); gotoxy(13,5); txt_write(buffer);
          }
        if (x == 1 && y == 6) {
          player.class += dir;
          if (player.class < 1) player.class = NUM_CLASSES;
          if (player.class > NUM_CLASSES) player.class = 1;
          sprintf(buffer,"%s      ",classes[player.class-1].name); gotoxy(13,6); txt_write(buffer);
          }
        if (x == 1 && y == 7) {
          player.level += dir;
          if (player.level < 1) player.level = 1;
          if (player.level > 99) player.level = 99;
          sprintf(buffer,"%d     ",player.level); gotoxy(13,7); txt_write(buffer);
          }
        if (x == 1 && (y >= 8 && y <= 13)) {
          player.stat[y-7] += dir;
          if (player.stat[y-7] < 3) player.stat[y-7] = 3;
          if (player.stat[y-7] > 99) player.stat[y-7] = 99;
          sprintf(buffer,"%d     ",player.stat[y-7]); gotoxy(13,y); txt_write(buffer);
          }
        if (x == 1 && y == 14) {
          player.chp += dir;
          if (player.chp < 0) player.chp = 0;
          if (player.chp > player.mhp) player.chp = player.mhp;
          sprintf(buffer,"%d     ",player.chp); gotoxy(13,14); txt_write(buffer);
          }
        if (x == 1 && y == 15) {
          player.mhp += dir;
          if (player.mhp < 0) player.mhp = 0;
          sprintf(buffer,"%d     ",player.mhp); gotoxy(13,15); txt_write(buffer);
          }
        if (x == 1 && y == 16) {
          player.cmana += dir;
          if (player.cmana < 0) player.cmana = 0;
          if (player.cmana > player.mmana) player.cmana = player.mmana;
          sprintf(buffer,"%d     ",player.cmana); gotoxy(13,16); txt_write(buffer);
          }
        if (x == 1 && y == 17) {
          player.mmana += dir;
          if (player.mmana < 0) player.mmana = 0;
          sprintf(buffer,"%d     ",player.mmana); gotoxy(13,17); txt_write(buffer);
          }
        if (x == 1 && y == 18) {
          if (dir > 0) add_gold(100); else sub_gold(100);
          if (get_gold() < 0) player.gold_coins = 0;
          sprintf(buffer,"%d",get_gold()); gotoxy(13,18); txt_write(buffer);
          }
        if (x != 1) {
          pos = (x == 25) ? y - 2 : y + 10;
          player.skill[pos] += 100000 * dir;
          if (player.skill[pos] > 9900000) player.skill[pos] = 9900000;
          if (player.skill[pos] < 0) player.skill[pos] = 0;
          sprintf(buffer,"%2d %05d     ",player.skill[pos] / 100000,player.skill[pos] % 100000);
          gotoxy(x+16,y); txt_write(buffer);
          }
        }
      }
    if (player.level != original_level || player.class != original_class) {
      }
    }

  int show_trophies(int top) {
    int i;
    int count;
    char buffer[256];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && trophies[i+top].criteria_type < 999) {
      sprintf(buffer,"   %s",trophies[i+top].name);
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void view_trophy(int num) {
    int i;
    unsigned int u;
    int count,count2;
    int ox,oy;
    OBJECT_REC* item;
    char buffer[32];
    int line;
    ox = 21;
    oy = 4;
    textcolor(7);
    gotoxy(ox,oy); txt_write("+-------------------------------------+");
    for (i=0; i<16; i++) {
      gotoxy(ox,oy+i+1); txt_write("|                                     |");
      }
    gotoxy(ox,oy+17); txt_write("+-------------------------------------+");
    line = oy+1;
    gotoxy(ox+2,line++); txt_write(trophies[num].name);
    gotoxy(ox+2,line++); txt_write(trophies[num].desc);
    if (has_trophy(num)) {
      textcolor(10); gotoxy(ox+2,1+line++); txt_write("Acquired");
      } else {
      line++;
      switch (trophies[num].criteria_type) {
        case TC_LEVEL:
          sprintf(buffer,"Progress: %d/%d",player.level,trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_TORCH:
          sprintf(buffer,"Progress: %d/%d",player.torch,trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_STEPS:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_STEPS_TAKEN],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_SLEEP:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_HOURS_NAPPED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_LGOLD:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_GOLD_LOOTED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_GOLD:
          sprintf(buffer,"Progress: %d/%d",get_gold()+player.bank,trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_TYPE:
          switch(trophies[num].control[0]) {
            case O_EDGE: sprintf(buffer,"Using: Edge weapons"); break;
            case O_ARMR: sprintf(buffer,"Using: Armor"); break;
            case O_POTN: sprintf(buffer,"Using: Potions"); break;
            case O_RING: sprintf(buffer,"Using: Rings"); break;
            case O_STFF: sprintf(buffer,"Using: Staves"); break;
            case O_FOOD: sprintf(buffer,"Using: Food"); break;
            case O_MISC: sprintf(buffer,"Using: Miscellaneous items"); break;
            case O_SCRL: sprintf(buffer,"Using: Scrolls"); break;
            case O_NECK: sprintf(buffer,"Using: Necklaces"); break;
            case O_ROBE: sprintf(buffer,"Using: Cloaks"); break;
            case O_BOOT: sprintf(buffer,"Using: Boots"); break;
            case O_HELM: sprintf(buffer,"Using: Helms"); break;
            case O_SHLD: sprintf(buffer,"Using: Shields"); break;
            case O_BOOK: sprintf(buffer,"Using: Books"); break;
            case O_POLE: sprintf(buffer,"Using: Pole weapons"); break;
            case O_BOW: sprintf(buffer,"Using: Bows/Crossbows"); break;
            case O_ONCE: sprintf(buffer,"Using: One-time items"); break;
            case O_SMWP: sprintf(buffer,"Using: Small weapons"); break;
            case O_JEWL: sprintf(buffer,"Using: Gems/Jewels"); break;
            case O_PROJ: sprintf(buffer,"Using: Projectile weapons"); break;
            case O_CRFT: sprintf(buffer,"Using: Crafting items"); break;
            case O_ALCH: sprintf(buffer,"Using: Alcoholic drinks"); break;
            case O_BLNT: sprintf(buffer,"Using: Blunt weapons"); break;
            case O_WAND: sprintf(buffer,"Using: Wands"); break;
            case O_CONS: sprintf(buffer,"Using: Consumables"); break;
            case O_GACH: sprintf(buffer,"Using: Gachas"); break;
            }
          gotoxy(ox+2,line++); txt_write(buffer);
          sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[2]],trophies[num].control[1]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_ITEM:
          gotoxy(ox+2,line++); txt_write("Use specific items:");
          if (trophies[num].control[0] > 0) {
            item = find_linked_item(trophies[num].control[0]);
            gotoxy(ox+4,line++); txt_write(item->name);
            sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[2]],trophies[num].control[1]);
            gotoxy(ox+6,line++); txt_write(buffer);
            }
          if (trophies[num].control[3] > 0) {
            item = find_linked_item(trophies[num].control[3]);
            gotoxy(ox+4,line++); txt_write(item->name);
            sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[5]],trophies[num].control[4]);
            gotoxy(ox+6,line++); txt_write(buffer);
            }
          break;
        case TC_COMN:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_COMMONS],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_RARE:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_RARES],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_VRARE:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_VERY_RARES],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_URARE:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ULTRA_RARES],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_LCLEAR:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_LEVELS_CLEARED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_DCLEAR:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_DUNGEON_CLEARED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_MESG:
          count = 0;
          for (i=0; i<NO_OF_GENS; i++)
            if (player.gen[i] != 0) count++;
          sprintf(buffer,"Progress: %d/%d",count,NO_OF_GENS);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_LORE:
          count = 0;
          for (i=0; i<NO_OF_LORE; i++)
            if (player.lore[i] != 0) count++;
          sprintf(buffer,"Progress: %d/%d",count,NO_OF_LORE);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_DMGDN:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_DAMAGE],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_DMGTK:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_DAMAGE_TAKEN],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_SOCK:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_SOCKETS_ADDED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_ENCH:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ENCHANTMENTS],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_CRAFT:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ITEMS_CRAFTED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_HOUSE:
          count = 0;
          for (i=0; i<5; i++)
            if (player.houses[i].region != 0 && player.houses[i].mortgage == 0) count++;
          sprintf(buffer,"Progress: %d/%d",count,trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_DRAGON:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_DRAGONS],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_PICKT:
          switch(trophies[num].control[0]) {
            case O_EDGE: sprintf(buffer,"Picking up: Edge weapons"); break;
            case O_ARMR: sprintf(buffer,"Picking up: Armor"); break;
            case O_POTN: sprintf(buffer,"Picking up: Potions"); break;
            case O_RING: sprintf(buffer,"Picking up: Rings"); break;
            case O_STFF: sprintf(buffer,"Picking up: Staves"); break;
            case O_FOOD: sprintf(buffer,"Picking up: Food"); break;
            case O_MISC: sprintf(buffer,"Picking up: Miscellaneous items"); break;
            case O_SCRL: sprintf(buffer,"Picking up: Scrolls"); break;
            case O_NECK: sprintf(buffer,"Picking up: Necklaces"); break;
            case O_ROBE: sprintf(buffer,"Picking up: Cloaks"); break;
            case O_BOOT: sprintf(buffer,"Picking up: Boots"); break;
            case O_HELM: sprintf(buffer,"Picking up: Helms"); break;
            case O_SHLD: sprintf(buffer,"Picking up: Shields"); break;
            case O_BOOK: sprintf(buffer,"Picking up: Books"); break;
            case O_POLE: sprintf(buffer,"Picking up: Pole weapons"); break;
            case O_BOW: sprintf(buffer,"Picking up: Bows/Crossbows"); break;
            case O_ONCE: sprintf(buffer,"Picking up: One-time items"); break;
            case O_SMWP: sprintf(buffer,"Picking up: Small weapons"); break;
            case O_JEWL: sprintf(buffer,"Picking up: Gems/Jewels"); break;
            case O_PROJ: sprintf(buffer,"Picking up: Projectile weapons"); break;
            case O_CRFT: sprintf(buffer,"Picking up: Crafting items"); break;
            case O_ALCH: sprintf(buffer,"Picking up: Alcoholic drinks"); break;
            case O_BLNT: sprintf(buffer,"Picking up: Blunt weapons"); break;
            case O_WAND: sprintf(buffer,"Picking up: Wands"); break;
            case O_CONS: sprintf(buffer,"Picking up: Consumables"); break;
            }
          gotoxy(ox+2,line++); txt_write(buffer);
          sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[2]],trophies[num].control[1]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_PICKI:
          gotoxy(ox+2,line++); txt_write("Pick up specific items:");
          if (trophies[num].control[0] > 0) {
            item = find_linked_item(trophies[num].control[0]);
            gotoxy(ox+4,line++); txt_write(item->name);
            sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[2]],trophies[num].control[1]);
            gotoxy(ox+6,line++); txt_write(buffer);
            }
          if (trophies[num].control[3] > 0) {
            item = find_linked_item(trophies[num].control[3]);
            gotoxy(ox+4,line++); txt_write(item->name);
            sprintf(buffer,"Progress: %d/%d",stats.counts[trophies[num].control[5]],trophies[num].control[4]);
            gotoxy(ox+6,line++); txt_write(buffer);
            }
          break;
        case TC_MSTAT:
          count = 0;
          for (i=1; i<7; i++)
            if (player.stat[i] == 99) count++;
          sprintf(buffer,"Progress: %d/%d",count,trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_FIRE:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ARROWS_FIRED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_TOXIC:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_POISONED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_DEF:
          sprintf(buffer,"Progress: %d/%d",get_armour(),trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_SKILL:
          sprintf(buffer,"Progress: %d/%d",get_skill(trophies[num].control[0]),trophies[num].control[1]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_SOLD:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ITEMS_SOLD],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_TALK:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_CONVERSATIONS],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_CLASS:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_CLASSES_TAKEN],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_IDENT:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_ITEMS_IDENTED],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_EQUIP:
          gotoxy(ox+2,line++); txt_write("Equip item set:");
          for (i=0; i<7; i++) {
            if (trophies[num].control[i] > 0) {
              item = find_linked_item(trophies[num].control[i]);
              gotoxy(ox+4,line++); txt_write(item->name);
              }
            }
          break;
        case TC_QUESTS:
          count = 0;
          count2 = 0;
          i = 0;
          while (links[i].region < 90) {
            if (player.quests[i] == 'Y') count++;
            count2++;
            i++;
            }
          sprintf(buffer,"Progress: %d/%d",count,count2);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_HKILL:
          sprintf(buffer,"Progress: %d/%d",stats.counts[STAT_HARD_MOB],trophies[num].control[0]);
          gotoxy(ox+2,line++); txt_write(buffer);
          break;
        case TC_PICKR:
          gotoxy(ox+2,line++); txt_write("Need:");
          for (i=trophies[num].control[0]; i<=trophies[num].control[1]; i++) {
            count = 1 << (i-trophies[num].control[0]);
            if ((stats.counts[trophies[num].control[2]] & count) == 0) {
              if (line < oy+16) {
                item = find_linked_item(i);
                gotoxy(ox+4,line++); txt_write(item->name);
                }
              else if (line == oy+16) {
                gotoxy(ox+4,line++); txt_write("...");
                }
              }
            }
          break;
        case TC_ITEMR:
          gotoxy(ox+2,line++); txt_write("Need to use:");
          for (i=trophies[num].control[0]; i<=trophies[num].control[1]; i++) {
            count = 1 << (i-trophies[num].control[0]);
            if ((stats.counts[trophies[num].control[2]] & count) == 0) {
              if (line < oy+16) {
                item = find_linked_item(i);
                gotoxy(ox+4,line++); txt_write(item->name);
                }
              else if (line == oy+16) {
                gotoxy(ox+4,line++); txt_write("...");
                }
              }
            }
          break;
        case TC_TRICK:
          gotoxy(ox+2,line++); txt_write("Need to use:");
          for (i=trophies[num].control[0]; i<=trophies[num].control[1]; i++) {
            count = 1 << (i-trophies[num].control[0]);
            if ((stats.counts[trophies[num].control[3]] & count) == 0) {
              if (line < oy+16) {
                item = find_linked_item(i);
                gotoxy(ox+4,line++); txt_write(item->name);
                }
              else if (line == oy+16) {
                gotoxy(ox+4,line++); txt_write("...");
                }
              }
            }
          break;
        case TC_CARDS:
          u = stats.counts[trophies[num].control[0]];
          count = 0;
          while (u != 0) {
            if ((u & 1) == 1) count++;
            u >>= 1;
            }
          u = trophies[num].control[1];
          count2 = 0;
          while (u != 0) {
            if ((u & 1) == 1) count2++;
            u >>= 1;
            }
          sprintf(buffer,"Progress: %d/%d",count,count2);
          gotoxy(ox+6,line++); txt_write(buffer);
          break;
        }
      }
/*
    item = find_linked_item(recipes[num].object);
    gotoxy(ox+2,line++); txt_write(item->name);
*/
    key = inkey();
    }

  void trphies() {
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    count = 0;
    while (trophies[count].criteria_type < 900) count++;
    textcolor(15); gotoxy(36,1); txt_write("Trophies:");
    sprintf(buffer,"Count: %d",count);
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_trophies(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_trophies(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_trophies(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 13) {
        view_trophy(top+pos);
        count = show_trophies(top);
        }
      }
    }

  int show_recipes(int top) {
    int i;
    int count;
    OBJECT_REC* item;
    char buffer[256];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && recipes[i+top].object < 999) {
      item = find_linked_item(recipes[i+top].object);
      sprintf(buffer,"   %s",item->name);
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void view_recipe(int num) {
    int i;
    int ox,oy;
    OBJECT_REC* item;
    int line;
    ox = 23;
    oy = 4;
    textcolor(7);
    gotoxy(ox,oy); txt_write("+-----------------------------+");
    for (i=0; i<16; i++) {
      gotoxy(ox,oy+i+1); txt_write("|                             |");
      }
    gotoxy(ox,oy+17); txt_write("+-----------------------------+");
    line = oy+1;
    item = find_linked_item(recipes[num].object);
    gotoxy(ox+2,line++); txt_write(item->name);
    if (recipes[num].craft_item > 0) {
      item = find_linked_item(recipes[num].craft_item);
      gotoxy(ox+2,line++); txt_write("Craft Item: ");
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    gotoxy(ox+2,line++); txt_write("Ingredients:");
    if (recipes[num].object1 > 0) {
      item = find_linked_item(recipes[num].object1);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object2 > 0) {
      item = find_linked_item(recipes[num].object2);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object3 > 0) {
      item = find_linked_item(recipes[num].object3);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object4 > 0) {
      item = find_linked_item(recipes[num].object4);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object5 > 0) {
      item = find_linked_item(recipes[num].object5);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object6 > 0) {
      item = find_linked_item(recipes[num].object6);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object7 > 0) {
      item = find_linked_item(recipes[num].object7);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object8 > 0) {
      item = find_linked_item(recipes[num].object8);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object9 > 0) {
      item = find_linked_item(recipes[num].object9);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    if (recipes[num].object10 > 0) {
      item = find_linked_item(recipes[num].object10);
      gotoxy(ox+4,line++); txt_write(item->name);
      }
    key = inkey();
    }

  void rcipes() {
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    textcolor(15); gotoxy(36,1); txt_write("Recipes:");
    sprintf(buffer,"Count: %d",recipe_count);
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("L");
    textcolor(3); txt_write(")earn, (");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_recipes(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_recipes(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_recipes(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 13) {
        view_recipe(top+pos);
        count = show_recipes(top);
        }
      if (key == 'l' || key == 'L') {
        game_edited = 'Y';
        player.lore[RECIPE_BASE+top+pos] = 1;
        }
      }
    }

  int show_specials(int top) {
    int i;
    int count;
    char buffer[256];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && i+top < 91) {
      sprintf(buffer,"   %s",special_names[i+top].name);
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void spcials() {
    char key;
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    textcolor(15); gotoxy(35,1); txt_write("Specials:");
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("I");
    textcolor(3); txt_write(")nvoke, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_specials(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_specials(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_specials(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 'i' || key == 'I') {
        game_edited = 'Y';
        restoreScreen();
        special(special_names[pos+top].number,NULL);
        show_map();
        show_sm_map();
        show_side();
        show_player();
        show_messages();
        saveScreen();
        clrscr();
        textcolor(15); gotoxy(35,1); txt_write("Specials:");
        gotoxy(1,24); textcolor(3); txt_write("(");
        textcolor(14); txt_write("I");
        textcolor(3); txt_write(")nvoke, (");
        textcolor(14); txt_write("ESC");
        textcolor(3); txt_write(") exit");
        count = show_specials(top);
        }
      }
    }

  int show_objects(int top) {
    int i;
    int count;
    char buffer[256];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && i+top < num_sorted) {
      sprintf(buffer,"   %s",objects[sorted[i+top]].name);
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void itemColor(OBJECT_REC* item) {
    if (item == NULL) return;
    if (abs(item->rarity) > 2500) {               /* Common */
      textcolor(7);
      return;
      }
    if (abs(item->rarity) > 500) {                /* Uncommon */
      textcolor(15);
      return;
      }
    if (abs(item->rarity) > 100) {                /* Rare */
      textcolor(10);
      return;
      }
    if (abs(item->rarity) > 10) {                 /* Very Rare */
      textcolor(9);
      return;
      }
    if (abs(item->rarity) > 3)  {                 /* Ultra Rare */
      textcolor(13);
      return;
      }
    textcolor(14);
    }

  void view_object(int num) {
    int i;
    int ox,oy;
    int line;
    double d;
    char buffer[64];
    ox = 23;
    oy = 4;
    textcolor(7);
    gotoxy(ox,oy); txt_write("+-----------------------------+");
    for (i=0; i<16; i++) {
      gotoxy(ox,oy+i+1); txt_write("|                             |");
      }
    gotoxy(ox,oy+17); txt_write("+-----------------------------+");
    itemColor(&(objects[num]));
    gotoxy(ox+2,oy+1); txt_write(objects[num].name);
    textcolor(7);
    gotoxy(ox+2,oy+2);
    switch (objects[num].otype) {
      case O_EDGE: txt_write("Edge Weapon"); break;
      case O_BLNT: txt_write("Blunt Weapon"); break;
      case O_ARMR: txt_write("Armor"); break;
      case O_POTN: txt_write("Potion"); break;
      case O_RING: txt_write("Ring"); break;
      case O_STFF: txt_write("Staff"); break;
      case O_WAND: txt_write("Wand"); break;
      case O_FOOD: txt_write("Food"); break;
      case O_MISC: txt_write("Miscellaneous"); break;
      case O_SCRL: txt_write("Scroll"); break;
      case O_NECK: txt_write("Necklace"); break;
      case O_ROBE: txt_write("Robe"); break;
      case O_BOOT: txt_write("Boots"); break;
      case O_HELM: txt_write("Helm"); break;
      case O_SHLD: txt_write("Shield"); break;
      case O_BOOK: txt_write("Book"); break;
      case O_POLE: txt_write("Polearm"); break;
      case O_BOW : txt_write("Missile"); break;
      case O_JEWL: txt_write("Jewel"); break;
      case O_PROJ: txt_write("Energy"); break;
      case O_DAGR: txt_write("Dagger"); break;
      case O_CRFT: txt_write("Craft Item"); break;
      case O_ALCH: txt_write("Alcohol"); break;
      case O_CONS: txt_write("Consumable"); break;
      case O_TRAP: txt_write("Trap"); break;
      }
    if (objects[num].effect == E_LGCY) {
      gotoxy(44,oy+2); txt_write("Legacy");
      }
    else if (objects[num].effect == E_MUTA) {
      gotoxy(44,oy+2); txt_write("Mutable");
      }
    else {
      if (abs(objects[num].rarity) > 2500) { gotoxy(46,oy+2);                             txt_write("Common"); }
      if (abs(objects[num].rarity) > 500 && abs(objects[num].rarity) <= 2500) { gotoxy(44,oy+2); txt_write("Uncommon"); }
      if (abs(objects[num].rarity) > 100 && abs(objects[num].rarity) <= 500) { gotoxy(48,oy+2);  txt_write("Rare"); }
      if (abs(objects[num].rarity) > 10 && abs(objects[num].rarity) <= 100) { gotoxy(43,oy+2);   txt_write("Very Rare"); }
      if (abs(objects[num].rarity) > 0 && abs(objects[num].rarity) <= 10) { gotoxy(42,oy+2);     txt_write("Ultra Rare"); }
      }
    strcpy(buffer,"");
    effect(objects[num].effect,objects[num].control,buffer);
    gotoxy(ox+2,oy+3); txt_write(buffer);
    line = oy + 4;
    if (objects[num].otype == O_DAGR ||
        objects[num].otype == O_EDGE ||
        objects[num].otype == O_POLE ||
        objects[num].otype == O_BLNT ||
        objects[num].otype == O_WAND ||
        objects[num].otype == O_BOW ||
        objects[num].effect == E_ATCK) {
      sprintf(buffer,"Damage: %d",objects[num].damage);
      gotoxy(ox+2,line++); txt_write(buffer);
      }
    if (objects[num].otype == O_ARMR ||
        objects[num].otype == O_ROBE ||
        objects[num].otype == O_HELM ||
        objects[num].otype == O_BOOT ||
        objects[num].otype == O_SHLD) {
      sprintf(buffer,"Defense: %d",objects[num].damage);
      gotoxy(ox+2,line++); txt_write(buffer);
      }
    if (objects[num].effect == E_PROT) {
      sprintf(buffer,"Protection: %d",objects[num].control);
      gotoxy(ox+2,line++); txt_write(buffer);
      }
    line++;
    if (objects[num].num_enchantments > 0) {
      if (objects[num].enchantments[0] != 0) {
        get_attribute_name(buffer,objects[num].enchantments[0]);
        gotoxy(ox+2,line++);
        txt_write(buffer);
        }
      }
    if (objects[num].num_enchantments > 1) {
      if (objects[num].enchantments[1] != 0) {
        get_attribute_name(buffer,objects[num].enchantments[1]);
        gotoxy(ox+2,line++);
        txt_write(buffer);
        }
      }
    if (objects[num].num_enchantments > 2) {
      if (objects[num].enchantments[2] != 0) {
        get_attribute_name(buffer,objects[num].enchantments[2]);
        gotoxy(ox+2,line++);
        txt_write(buffer);
        }
      }
    d = objects[num].cost;
    if (objects[num].charges > 0) d += objects[num].charges * objects[num].costp;
    sprintf(buffer,"Base Cast: %.0f",d);
    gotoxy(ox+2,oy+16); textcolor(14); txt_write(buffer);
    key = inkey();
    }

  void sort_objects() {
    int i;
    int t;
    int flag;
    flag = -1;
    while (flag) {
      flag = 0;
      for (i=0; i<num_sorted-1; i++)
        if (strcmp(objects[sorted[i]].name,objects[sorted[i+1]].name) > 0) {
          t = sorted[i];
          sorted[i] = sorted[i+1];
          sorted[i+1] = t;
          flag = -1;
          }
      }
    }

  void objcts() {
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    OBJECT_REC item;
    pos = 0;
    top = 0;
    clrscr();
    count = 0;
    num_sorted = 0;
    while (objects[count].otype < 999) {
      count++;
      sorted[num_sorted++] = count;
      }
    sort_objects();
    textcolor(15); gotoxy(35,1); txt_write("Objects:");
    sprintf(buffer,"Count: %d",count);
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("A");
    textcolor(3); txt_write(")quire, (");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_objects(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_objects(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_objects(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 13) {
        view_object(sorted[top+pos]);
        count = show_objects(top);
        }
      if (key == 'a' || key == 'A') {
        game_edited = 'Y';
        item = objects[sorted[top+pos]];
        if (item.level > 0) item.level = -item.level;
        if (item.level == 0) item.level = -1;
        inventory(&item);
        clrscr();
        count = 0;
        while (objects[count].otype < 999) count++;
        textcolor(15); gotoxy(35,1); txt_write("Objects:");
        sprintf(buffer,"Count: %d",count);
        textcolor(14); gotoxy(65,1); txt_write(buffer);
        gotoxy(1,24); textcolor(3); txt_write("(");
        textcolor(14); txt_write("A");
        textcolor(3); txt_write(")quire, (");
        textcolor(14); txt_write("ENTER");
        textcolor(3); txt_write(") View, (");
        textcolor(14); txt_write("ESC");
        textcolor(3); txt_write(") exit");
        count = show_objects(top);
        }
      }
    }

  int show_messages(int top,char mode) {
    int i;
    int count;
    char buffer[256];
    i = 0;
    count = 0;
    if (mode == 'G') {
      textcolor(10);
      while (i < 20 && gen[i+top].link < 900) {
        sprintf(buffer,"   %s",gen[i+top].message);
        while (strlen(buffer) < 80) strcat(buffer," ");
        if (strlen(buffer) > 79) buffer[79] = 0;
        gotoxy(1,i+3); txt_write(buffer);
        i++;
        count++;
        }
      }
    if (mode == 'L') {
      textcolor(11);
      while (i < 20 && lore[i+top].link < 900) {
        sprintf(buffer,"   %s",lore[i+top].message);
        while (strlen(buffer) < 80) strcat(buffer," ");
        if (strlen(buffer) > 79) buffer[79] = 0;
        gotoxy(1,i+3); txt_write(buffer);
        i++;
        count++;
        }
      }
    i = count;
    while (i < 20) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 80) strcat(buffer," ");
      if (strlen(buffer) > 79) buffer[79] = 0;
      gotoxy(1,i+3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void messages(char mode) {
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    if (mode == 'G') {
      textcolor(15); gotoxy(31,1); txt_write("General Messages:");
      sprintf(buffer,"Count: %d",NO_OF_GENS);
      } else {
      textcolor(15); gotoxy(33,1); txt_write("Lore Messages:");
      sprintf(buffer,"Count: %d",NO_OF_LORE);
      }
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("L");
    textcolor(3); txt_write(")earn, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_messages(top,mode);
    key = '1';
    while (key != 27) {
      if (count != 0) { textcolor(14); gotoxy(1,pos+3); txt_write("-->"); }
      key = inkey();
      textcolor(14); gotoxy(1,pos+3); txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 20) {
        top += 20;
        count = show_messages(top,mode);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 20;
        count = show_messages(top,mode);
        pos = 0;
        }
      if (key == 'l' || key == 'L') {
        game_edited = 'Y';
        if (mode == 'G') player.gen[top+pos] = 1;
        if (mode == 'L') player.lore[top+pos] = 1;
        }
      }
    }


  int show_spells(int top) {
    int i;
    int count;
    char buffer[256];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && spells[i+top].effect < 900) {
      sprintf(buffer,"   %s",spells[i+top].name);
      while (strlen(buffer) < 20) strcat(buffer," ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void view_spell(int num) {
    int i;
    int ox,oy;
    char buffer[32];
    int line;
    ox = 23;
    oy = 4;
    textcolor(7);
    gotoxy(ox,oy); txt_write("+-----------------------------+");
    for (i=0; i<16; i++) {
      gotoxy(ox,oy+i+1); txt_write("|                             |");
      }
    gotoxy(ox,oy+17); txt_write("+-----------------------------+");
    line = oy+1;
    gotoxy(ox+2,line++); txt_write(spells[num].name);
    sprintf(buffer,"Class: %s",classes[spells[num].allign-1].name);
    gotoxy(ox+2,line++); txt_write(buffer);
    sprintf(buffer,"Level: %d",spells[num].level);
    gotoxy(ox+2,line++); txt_write(buffer);
    sprintf(buffer,"Mana : %d",spells[num].mana);
    gotoxy(ox+2,line++); txt_write(buffer);
    line++;
    show_spell(num,23,7,line);
    key = inkey();
    }

  void splls() {
    int  i;
    char known;
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    count = 0;
    while (spells[count].effect < 900) count++;
    textcolor(15); gotoxy(37,1); txt_write("Spells:");
    sprintf(buffer,"Count: %d",count);
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("L");
    textcolor(3); txt_write(")earn, (");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_spells(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_spells(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_spells(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 13) {
        view_spell(top+pos);
        count = show_spells(top);
        }
      if (key == 'l' || key == 'L') {
        known = 'N';
        for (i=0; i<1000; i++) if (spellbook[i] == top+pos) known = 'Y';
        if (known == 'N') {
          game_edited = 'Y';
          i = 1;
          while (spellbook[i] != 0) i++;
          spellbook[i] = top+pos;
          }
        }
      }
    }

  int show_monsters(int top) {
    int i;
    int count;
    char buffer[256];
    char tmp[32];
    i = 0;
    count = 0;
    textcolor(10);
    while (i < 40 && monsters[i+top].speed < 900) {
      sprintf(buffer,"   %s",monsters[i+top].name);
      while (strlen(buffer) < 20) strcat(buffer," ");
      sprintf(tmp,"%d  ",monsters[i+top].level);
      strcat(buffer,tmp);
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      count++;
      }
    i = count;
    while (i < 40) {
      sprintf(buffer,"   ");
      while (strlen(buffer) < 40) strcat(buffer," ");
      if (strlen(buffer) > 39) buffer[39] = 0;
      gotoxy(((i < 20) ? 9 : 48),((i < 20) ? i : i-20) + 3); txt_write(buffer);
      i++;
      }
    return count;
    }

  void view_monster(int num) {
    int i;
    int ox,oy;
    char buffer[32];
    ox = 23;
    oy = 4;
    textcolor(7);
    gotoxy(ox,oy); txt_write("+-----------------------------+");
    for (i=0; i<16; i++) {
      gotoxy(ox,oy+i+1); txt_write("|                             |");
      }
    gotoxy(ox,oy+17); txt_write("+-----------------------------+");
    gotoxy(ox+2,oy+1); txt_write(monsters[num].name);
    sprintf(buffer,"Lvl:%d",monsters[num].level);
    gotoxy(ox+23,oy+1); txt_write(buffer);
    sprintf(buffer,"Hp :%d",monsters[num].hp);
    gotoxy(ox+2,oy+3); txt_write(buffer);
    sprintf(buffer,"Mana:%d",monsters[num].mana);
    gotoxy(ox+16,oy+3); txt_write(buffer);
    sprintf(buffer,"Atk:%d",monsters[num].attack);
    gotoxy(ox+2,oy+4); txt_write(buffer);
    sprintf(buffer,"Def :%d",monsters[num].defense);
    gotoxy(ox+16,oy+4); txt_write(buffer);
    sprintf(buffer,"Exp:%.0f",monsters[num].exp);
    gotoxy(ox+2,oy+5); txt_write(buffer);
    sprintf(buffer,"/Hp :%.0f",monsters[num].exp_hp);
    gotoxy(ox+16,oy+5); txt_write(buffer);
    i = 7;
    if (monsters[num].special & MS_FRIENDLY) { 
      gotoxy(ox+2,oy+i); txt_write("Friendly");
      i++;
      }
    if (monsters[num].special & MS_HEALER) { 
      gotoxy(ox+2,oy+i); txt_write("Healer");
      i++;
      }
    if (monsters[num].special & MS_MOUNT) { 
      gotoxy(ox+2,oy+i); txt_write("Rideable");
      i++;
      }
    if (monsters[num].special & MS_FLY) { 
      gotoxy(ox+2,oy+i); txt_write("Can Fly");
      i++;
      }
    if (monsters[num].special & MS_AMAGIC) { 
      gotoxy(ox+2,oy+i); txt_write("Anti-Magic");
      i++;
      }
    if (monsters[num].special & MS_APHYSICAL) { 
      gotoxy(ox+2,oy+i); txt_write("Anti-Physical");
      i++;
      }
    if (monsters[num].special & MS_IARCN) { 
      gotoxy(ox+2,oy+i); txt_write("Immune Arcane");
      i++;
      }
    if (monsters[num].special & MS_IFIRE) { 
      gotoxy(ox+2,oy+i); txt_write("Immune Fire");
      i++;
      }
    if (monsters[num].special & MS_ICOLD) { 
      gotoxy(ox+2,oy+i); txt_write("Immune Cold");
      i++;
      }
    if (monsters[num].special & MS_IELEC) { 
      gotoxy(ox+2,oy+i); txt_write("Immune Electric");
      i++;
      }
    if (monsters[num].special & MS_RARCN) { 
      gotoxy(ox+2,oy+i); txt_write("Resist Arcane");
      i++;
      }
    if (monsters[num].special & MS_RFIRE) { 
      gotoxy(ox+2,oy+i); txt_write("Resist Fire");
      i++;
      }
    if (monsters[num].special & MS_RCOLD) { 
      gotoxy(ox+2,oy+i); txt_write("Resist Cold");
      i++;
      }
    if (monsters[num].special & MS_RELEC) { 
      gotoxy(ox+2,oy+i); txt_write("Resist Electric");
      i++;
      }
    if (monsters[num].special & MS_DOT) { 
      gotoxy(ox+2,oy+i); txt_write("Damage over Time");
      i++;
      }
    if (monsters[num].special & MS_POISON) { 
      gotoxy(ox+2,oy+i); txt_write("Poison");
      i++;
      }
    if (monsters[num].special & MS_FEAR) { 
      gotoxy(ox+2,oy+i); txt_write("Fear");
      i++;
      }
    if (monsters[num].special & MS_ROOT) { 
      gotoxy(ox+2,oy+i); txt_write("Root");
      i++;
      }
    if (monsters[num].special & MS_SLEEP) { 
      gotoxy(ox+2,oy+i); txt_write("Sleep");
      i++;
      }
    if (monsters[num].special & MS_CONFUSION) { 
      gotoxy(ox+2,oy+i); txt_write("Confusion");
      i++;
      }
    if (monsters[num].special & MS_PSIONIC) { 
      gotoxy(ox+2,oy+i); txt_write("Psionic Attack");
      i++;
      }
    if (monsters[num].special & MS_ARCN_ATK) { 
      gotoxy(ox+2,oy+i); txt_write("Arcane Attack");
      i++;
      }
    if (monsters[num].special & MS_FIRE_ATK) { 
      gotoxy(ox+2,oy+i); txt_write("Fire Attack");
      i++;
      }
    if (monsters[num].special & MS_COLD_ATK) { 
      gotoxy(ox+2,oy+i); txt_write("Cold Attack");
      i++;
      }
    if (monsters[num].special & MS_ELEC_ATK) { 
      gotoxy(ox+2,oy+i); txt_write("Electric Attack");
      i++;
      }
    key = inkey();
    }

  void mnsters() {
    char key;
    char buffer[40];
    int  pos;
    int  top;
    int  count;
    pos = 0;
    top = 0;
    clrscr();
    count = 0;
    while (monsters[count].speed < 900) count++;
    textcolor(15); gotoxy(35,1); txt_write("Monsters:");
    sprintf(buffer,"Count: %d",count);
    textcolor(14); gotoxy(65,1); txt_write(buffer);
    gotoxy(1,24); textcolor(3); txt_write("(");
    textcolor(14); txt_write("ENTER");
    textcolor(3); txt_write(") View, (");
    textcolor(14); txt_write("ESC");
    textcolor(3); txt_write(") exit");
    count = show_monsters(top);
    key = '1';
    while (key != 27) {
      if (count != 0) {
        textcolor(14);
        gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
        txt_write("-->");
        }
      key = inkey();
      textcolor(14);
      gotoxy(((pos < 20) ? 9 : 48),((pos < 20) ? pos : pos-20) + 3);
      txt_write("   ");
      if (key == '2' && count != 0) {
        if (++pos >= count) pos = 0;
        }
      if (key == '8' && count != 0) {
        if (--pos < 0) pos = count-1;
        }
      if (key == '3' && count == 40) {
        top += 40;
        count = show_monsters(top);
        pos = 0;
        }
      if (key == '9' && top != 0) {
        top -= 40;
        count = show_monsters(top);
        pos = 0;
        }
      if (key == '4' || key == '6') {
        pos = (pos < 20) ? pos + 20 : pos - 20;
        if (pos >= count) pos = count-1;
        }
      if (key == 13) {
        view_monster(top+pos);
        count = show_monsters(top);
        }
      }
    }

  void password() {
    strcpy(buffer,"");
    strcpy(pword,"Password ?");
    msg(pword,11);
    key = 0;
    while (key != 13) { 
      sprintf(buffer2,"%s_",pword);
      key = inkey();
      if (key >= ' ') {
        buffer[strlen(buffer) + 1] = 0;
        buffer[strlen(buffer)] = key;
        pword[strlen(pword) + 1] = 0;
        pword[strlen(pword)] = '*';
        msg(pword,-11);
        }
      if (key == 8 && strlen(buffer) > 0) {
        buffer[strlen(buffer) - 1] = 0;
        pword[strlen(pword) - 1] = 0;
        msg(pword,-11);
        }
      }
    }

  void wizard_warning() {
    char key;
    clrscr();
    textcolor(12);
    gotoxy(35,7);
    txt_write("WARNING!!!");
    textcolor(7);
    gotoxy(15,9); txt_write("Using Wizard mode to alter the game will force the");
    gotoxy(15,10); txt_write("current character into casual mode.");
    textcolor(15);
    gotoxy(28,12); txt_write("Press <ENTER> to continue");
    key = ' ';
    while (key != 13) {
      key = inkey();
      }
    clrscr();
    }

  void main_menu() {
    char key;
    int  line;
    key = '*';
    while (key != '0') {
      clrscr();
      line = 6;
      textcolor(11); gotoxy(32,line++); txt_write("A. Monsters");
      textcolor(11); gotoxy(32,line++); txt_write("B. Objects");
      textcolor(11); gotoxy(32,line++); txt_write("C. Messages");
      textcolor(11); gotoxy(32,line++); txt_write("D. Lore");
      textcolor(11); gotoxy(32,line++); txt_write("E. Spells");
      textcolor(11); gotoxy(32,line++); txt_write("F. Special");
      textcolor(11); gotoxy(32,line++); txt_write("G. Character");
      textcolor(11); gotoxy(32,line++); txt_write("H. Recipes");
      textcolor(11); gotoxy(32,line++); txt_write("I. Trophies");
      textcolor(11); gotoxy(32,line++); txt_write("0. Exit");
      line++;
      textcolor(10); gotoxy(32,line); txt_write("   ?");
      key = inkey();
      if (key == 27) key = '0';
      if (key == 'a' || key == 'A') mnsters();
      if (key == 'b' || key == 'B') objcts();
      if (key == 'c' || key == 'C') messages('G');
      if (key == 'd' || key == 'D') messages('L');
      if (key == 'e' || key == 'E') splls();
      if (key == 'f' || key == 'F') spcials();
      if (key == 'g' || key == 'G') character();
      if (key == 'h' || key == 'H') rcipes();
      if (key == 'i' || key == 'I') trphies();
      }
    }

  if (wizardmode == 'N') {
    password();
    }
  saveScreen();
  if (wizardmode != 'Y' && strcmp(buffer,"rcs123") != 0) return;
  if (wizardmode == 'N') wizard_warning();
  wizardmode = 'Y';
  sort_special_names();
  game_edited = 'N';
  main_menu();
  restoreScreen();
  if (game_edited == 'Y') player.effect[PE_HEROIC] = -1;
  }
