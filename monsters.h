#ifdef MAIN
/*
typedef struct {
  int    speed;
  int    number;
  int    hp;
  int    max_hp;
  int    mana;
  int    level;
  int    attack;
  int    defense;
  double exp;
  double exp_hp;
  unsigned int    special;
  unsigned int    special2;
  int    sprite;
  int    mtype;
  char   name[16];
  int    time;
  int    sleep;  
  int    fear;
  int    blind;
  int    confused;
  int    poison;
  int    prev;
  int    treasure;
  } NPC_REC;


Current monster number = 105
*/

/* SP   #  HP MHP  MN LV  AT  DF    XP +H SP                                          SPR NAME */
NPC_REC monsters[] = {
  { 1,  0,  9,  9,  0, 1,  3, 10,   20, 2, 0,                                           0,121,MT_BEAST    ,"Hobgoblin",      255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  3,  8,    5, 1, 0,                                           0,339,MT_HUMANOID ,"Kobold",         255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  2,  6,   10, 1, MS_DOT,                                      0,110,MT_BEAST    ,"Larva",          255,0,0,0,0,0,7,0 },
  { 1, 10,  8,  8,  0, 1,  3,  6,   45, 3, 0,                                           0,134,MT_BEAST    ,"Giant Frog",     255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  2,  8,   10, 1, 0,                                           0,123,MT_HUMANOID ,"Orc",            255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  2,  6,   14, 1, 0,                                           0,125,MT_UNDEAD   ,"Skeleton",       255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  2,  8,   10, 1, 0,                                           0,123,MT_HUMANOID ,"Goblin",         255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  2,  6,   32, 1, MS_FRIENDLY,                                 0,139,MT_HUMANOID ,"Nixie",          255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8, 50, 1,  2, 10,  105, 1, MS_FRIENDLY,                                 0,140,MT_HUMANOID ,"Pixie",          255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 1,  3,  4,   20, 2, MS_FEAR,                                     0,136,MT_UNDEAD   ,"Zombie",         255,0,0,0,0,0,7,0 },

  { 1,  0, 16, 16,  0, 2, 12, 14,   20, 2, 0,                                           0,102,MT_BEAST    ,"Giant Ant",      255,0,0,0,0,0,7,0 },
  { 1,  0,  4,  4,  0, 2,  2,  2,   30, 1, MS_POISON,                                   0,110,MT_BEAST    ,"Giant Centipede",255,0,0,0,0,0,7,0 },
  { 1,  0,  4,  4,  0, 2,  2,  2,   30, 1, MS_POISON,                                   0,105,MT_BEAST    ,"Floating Eye",   255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 2, 16,  2,  610, 2, MS_AMAGIC | MS_DOT,                          0,107,MT_BEAST    ,"Green Slime",    255,0,0,0,0,0,7,0 },
  { 1,  0, 18, 18, 25, 2,  4, 16,  275, 3, MS_POISON,                                   0,121,MT_DEMON    ,"Imp",            255,0,0,0,0,0,7,0 },
  { 2,  1, 18, 18,  0, 2,  4,  8,  120, 3, 0,                                           0,120,MT_BEAST    ,"Giant Lynx",     255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 2, 12,  8,   65, 2, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,118,MT_UNDEAD   ,"Ghoul",          255,0,0,0,0,0,7,0 },
  { 1,  0, 11, 11,  0, 2,  7, 16,   20, 2, 0,                                           0,123,MT_HUMANOID ,"Orc Guard",      255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8,  0, 2,  2,  6,   65, 2, MS_POISON | MS_ROOT,                         0,145,MT_BEAST    ,"Large Spider",   255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 2,  5, 10,   36, 2, 0,                                           0,123,MT_HUMANOID ,"Troglodyte",     255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16, 50, 2,  5,  2,  105, 3, MS_FRIENDLY,                                 0,139,MT_HUMANOID ,"Dryad",          255,0,0,0,0,0,7,0 },

  { 1,  0, 24, 24,  0, 3,  6,  8,   35, 3, 0,                                           0,103,MT_BEAST    ,"Giant Badger",   255,0,0,0,0,0,7,0 },
  { 1,  0, 25, 25,  0, 3,  8, 14,  500, 4, MS_SLEEP | MS_DOT,                           0,110,MT_BEAST    ,"Carrion Crawler",255,0,0,0,0,0,7,0 },
  { 1,  0, 27, 27,  0, 3, 16,  4,  200, 5, MS_AMAGIC,                                   0,106,MT_BEAST    ,"Gray Ooze",      255,0,0,0,0,0,7,0 },
  { 2,  0, 24, 24,  0, 3,  6,  6,  145, 3, MS_SLEEP,                                    0,119,MT_BEAST    ,"Harpy",          255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24,  0, 3,  8,  6,   35, 3, 0,                                           0,120,MT_BEAST    ,"Hyena",          255,0,0,0,0,0,7,0 },
  { 2,  2, 26, 26,  0, 3,  6,  8,  150, 4, 0,                                           0,120,MT_BEAST    ,"Leopard",        255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 3,  8, 16,   20, 4, 0,                                           0,123,MT_HUMANOID ,"Orc Chief",      255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24,  0, 3, 10,  6,  255, 4, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,  7,MT_UNDEAD   ,"Shadow",         255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 3,  6,  8,  145, 3, MS_POISON | MS_ROOT,                         0,145,MT_BEAST    ,"Huge Spider",    255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8, 25, 3,  8,  6,   18, 1, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,152,MT_DEMON    ,"Manes demon",    255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24, 75, 3,  8,  2,  350, 3, MS_FRIENDLY | MS_HEALER,                     0,139,MT_HUMANOID ,"Nymph",          255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24, 75, 3, 10,  8,   80, 1, MS_FRIENDLY,                                 0,140,MT_HUMANOID ,"Sprite",         255,0,0,0,0,0,7,0 },

  { 1,  0, 36, 36,  0, 4,  6, 10,  165, 5, 0,                                           0,115,MT_HUMANOID ,"Gargoyle",       255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,  0, 4,  8,  4,  150, 4, MS_SLEEP | MS_DOT,                           0,116,MT_BEAST    ,"Gelatinous Cube",255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,  0, 4, 20, 12,  250, 8, MS_FIRE_ATK | MS_RFIRE,                      0,120,MT_DEMON    ,"Hell Hound",     255,0,0,0,0,0,7,0 },
  { 1, 23, 32, 32,  0, 4, 10, 10,   90, 5, 0,                                           0,123,MT_HUMANOID ,"Ogre",           255,0,0,0,0,0,7,0 },
  { 1,  0, 36, 36,  0, 4,  8, 12,  315, 5, MS_POISON | MS_ROOT,                         0,145,MT_BEAST    ,"Giant Spider",   255,0,0,0,0,0,7,0 },
  { 1, 26, 32, 32,  0, 4,  8, 10,  540, 5, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,118,MT_UNDEAD   ,"Wight",          255,0,0,0,0,0,7,0 },
  { 1,102, 32, 32,  0, 4,  6, 12,   85, 4, MS_FRIENDLY | MS_MOUNT,                      0,148,MT_BEAST    ,"Centaur",        255,0,0,0,0,0,7,0 },
  { 1,101, 20, 20,  0, 4,  8,  6,   85, 4, MS_FRIENDLY | MS_MOUNT,                      0,131,MT_BEAST    ,"Horse",          255,0,0,0,0,0,7,0 },
  { 1,  3, 36, 36,  0, 4,  8,  8,   90, 5, MS_MOUNT,                                    0,120,MT_BEAST    ,"Worg",           255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,  0, 4,  8, 14,  350,10, MS_SLEEP,                                    0,331,MT_HUMANOID ,"Sirine",         255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,  0, 4,  8, 10,  100, 4, 0,                                           0,339,MT_HUMANOID ,"Kobold Miner",   255,0,0,0,0,0,7,0 },

  { 1,  0, 40, 40,  0, 5,  6, 10,  165, 5, 0,                                           0,122,MT_BEAST    ,"5 head Hydra",   255,0,0,0,0,0,7,0 },
  { 2,  4, 40, 40,  0, 5, 12, 10,  300, 6, 0,                                           0,120,MT_BEAST    ,"Lion",           255,0,0,0,0,0,7,0 },
  { 1, 22, 33, 33,  0, 5, 12, 12,  225, 8, 0,                                           0,123,MT_HUMANOID ,"Ogre Leader",    255,0,0,0,0,0,7,0 },
  { 2, 30, 45, 45,  0, 5, 10, 14,  650, 6, MS_POISON,                                   0,142,MT_BEAST    ,"Giant Scorpian", 255,0,0,0,0,0,7,0 },
  { 1,  0, 41, 41,  0, 5,  7, 10,  350, 6, MS_POISON,                                   0,143,MT_BEAST    ,"Boalisk",        255,0,0,0,0,0,7,0 },
  { 1, 56, 33, 33,  0, 5, 12, 12,  225, 8, 0,                                           0,123,MT_HUMANOID ,"Goblin Guard",   255,0,0,0,0,0,7,0 },

  { 1,  5, 54, 54,  0, 6, 16,  8,  475, 8, 0,                                           0,104,MT_BEAST    ,"Cave Bear",      255,0,0,0,0,0,7,0 },
  { 1, 28, 48, 48,  0, 6,  6, 10,  250, 6, 0,                                           0,122,MT_BEAST    ,"6 head Hydra",   255,0,0,0,0,0,7,0 },
  { 2,  0, 51, 51,  0, 6,  8, 12,  525, 8, 0,                                           0,127,MT_HUMANOID ,"Manticore",      255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,  0, 6,  4, 10,  725, 6, MS_SLEEP,                                    0,128,MT_HUMANOID ,"Medusa",         255,0,0,0,0,0,7,0 },
  { 1,  0, 51, 51,  0, 6,  8,  8,  400, 8, 0,                                           0,130,MT_HUMANOID ,"Minotaur",       255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,  0, 6, 12, 14, 1150, 8, MS_FEAR,                                     0,136,MT_UNDEAD   ,"Mummy",          255,0,0,0,0,0,7,0 },
  { 2,103, 54, 54,  0, 6, 20, 28,  600, 8, MS_ARCN_ATK | MS_RARCN | MS_MOUNT,           0,138,MT_DEMON    ,"Nightmare",      255,0,0,0,0,0,7,0 },
  { 1, 24, 37, 37,  0, 6, 14, 16,  225,10, 0,                                           0,123,MT_HUMANOID ,"Ogre Chieftain", 255,0,0,0,0,0,7,0 },
  { 1, 29, 49, 49,  0, 6,  8, 10,  225, 8, MS_POISON,                                   0,143,MT_BEAST    ,"Giant Snake",    255,0,0,0,0,0,7,0 },
  { 2,  0, 54, 54,  0, 6, 12, 12,  525, 8, 0,                                           0,123,MT_HUMANOID ,"Troll",          255,0,0,0,0,0,7,0 },
  { 1,  0, 51, 51,  0, 6, 18,  6,  575, 8, 0,                                           0,  7,MT_ELEMENTAL,"Wind Walker",    255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,150, 6, 30, 20, 2100, 6, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,151,MT_DEMON    ,"Succubus",       255,0,0,0,0,0,7,0 },

  { 2, 11, 56, 56,  0, 7, 16, 14,  375,10, MS_FLY | MS_MOUNT,                           0,117,MT_BEAST    ,"Griffon",        255,0,0,0,0,0,7,0 },
  { 1, 25, 56, 56,  0, 7, 16, 20, 2450,10, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,118,MT_UNDEAD   ,"Groaning Spirit",255,0,0,0,0,0,7,0 },
  { 1, 27, 56, 56,  0, 7,  8, 10,  400, 8, 0,                                           0,122,MT_BEAST    ,"7 head Hydra",   255,0,0,0,0,0,7,0 },
  { 1,  0, 42, 42,175, 7, 12, 12,  900, 6, MS_DOT,                                      0,123,MT_HUMANOID ,"Ogre Magi",      255,0,0,0,0,0,7,0 },
  { 1,  0, 59, 59,  0, 7, 16, 16, 1650,10, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,118,MT_UNDEAD   ,"Spectre",        255,0,0,0,0,0,7,0 },
  { 2, 62, 56, 56,300, 7, 18, 18, 8500,24, MS_FIRE_ATK | MS_RFIRE | MS_FLY | MS_MOUNT,  0,155,MT_DRAGON   ,"Green Dragon",   255,0,0,0,0,0,7,0 },
  { 1, 55, 56, 56,  0, 7,  8, 10,  400, 8, 0,                                           0,123,MT_HUMANOID ,"Goblin Chief",   255,0,0,0,0,0,7,0 },

  { 2,  0, 64, 64,  0, 8,  8, 10,  650,10, 0,                                           0,122,MT_BEAST    ,"8 head Hydra",   255,0,0,0,0,0,7,0 },
  { 1,  0, 56, 56,  0, 8, 16, 14, 1090,10, 0,                                           0,  7,MT_ELEMENTAL,"Inv. Stalker",   255,0,0,0,0,0,7,0 },
  { 2,  0, 44, 44,200, 8,125, 10, 1800,12, MS_PSIONIC,                                  0,129,MT_HUMANOID ,"Mind Flayer",    255,0,0,0,0,0,7,0 },
  { 1, 12, 64, 64,  0, 8, 16, 12, 1400,12, 0,                                           0,135,MT_GIANT    ,"Hill Giant",     255,0,0,0,0,0,7,0 },
  { 1,  6, 64, 64,200, 8,  8, 22, 1550,10, MS_FEAR,                                     0,144,MT_BEAST    ,"Gyno-Sphinx",    255,0,0,0,0,0,7,0 },
  { 3,  0, 64, 64,200, 8, 16, 20, 1275,10, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type I Demon",   255,0,0,0,0,0,7,0 },
  { 4, 63, 63, 63,200, 8, 16, 34, 3000,12, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type V Demon",   255,0,0,0,0,0,7,0 },
  { 1, 61, 64, 64,  0, 8, 36, 20, 1000,10, MS_ARCN_ATK | MS_IARCN,                      0,125,MT_UNDEAD   ,"Apparition",     255,0,0,0,0,0,7,0 },

  { 2,  0, 75, 75,200, 9,  8, 20,12900,20, MS_AMAGIC,                                   0,105,MT_HUMANOID ,"Beholder",       255,0,0,0,0,0,7,0 },
  { 1,  0, 72, 72,  0, 9, 48, 24, 2300,12, 0,                                           0,109,MT_BEAST    ,"Bulette",        255,0,0,0,0,0,7,0 },
  { 2,  0, 72, 72,  0, 9,  8, 10, 1000,12, 0,                                           0,122,MT_BEAST    ,"9 head Hydra",   255,0,0,0,0,0,7,0 },
  { 1,  0, 72, 72,225, 9,  4, 14, 1700,12, 0,                                           0,124,MT_BEAST    ,"Lamia",          255,0,0,0,0,0,7,0 },
  { 1,  0, 72, 72,  0, 9, 18, 20, 1800,14, 0,                                           0,135,MT_GIANT    ,"Stone Giant",    255,0,0,0,0,0,7,0 },
  { 2,  0, 72, 72,225, 9, 10, 18,  600,12, MS_FEAR,                                     0,144,MT_BEAST    ,"Hieraco-Sphinx", 255,0,0,0,0,0,7,0 },
  { 2,  0, 72, 72,  0, 9, 12, 16, 1300,12, MS_SLEEP,                                    0,146,MT_HUMANOID ,"Umber Hulk",     255,0,0,0,0,0,7,0 },
  { 1, 39, 72, 72,  0, 9, 16, 36, 1200,12, MS_AMAGIC,                                   0,147,MT_BEAST    ,"Will-o-wisp",    255,0,0,0,0,0,7,0 },
  { 2,  0, 72, 72,225, 9, 32, 24, 2000,12, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type II Demon",  255,0,0,0,0,0,7,0 },
  { 1,  0, 72, 72,250, 9, 26, 24, 3600,12, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type VI Demon",  255,0,0,0,0,0,7,0 },
  { 2, 13, 40, 40,225, 9, 32, 22, 4000,10, MS_ELEC_ATK | MS_RELEC | MS_FLY | MS_MOUNT,  0,156,MT_DRAGON   ,"White Dragon",   255,0,0,0,0,0,7,0 },

  { 1,  0, 80, 80,  0,10, 24,  8, 1350,14, MS_DOT,                                      0,106,MT_BEAST    ,"Black Pudding",  255,0,0,0,0,0,7,0 },
  { 1, 38, 80, 80,250,10, 48, 16, 1950,14, MS_FIRE_ATK | MS_IFIRE,                      0,114,MT_ELEMENTAL,"Efreeti",        255,0,0,0,0,0,7,0 },
  { 2,  0, 80, 80,  0,10,  8, 10, 1500,14, 0,                                           0,122,MT_BEAST    ,"10 head Hydra",  255,0,0,0,0,0,7,0 },
  { 1, 14, 80, 80,  0,10, 32, 14, 1350,14, MS_FIRE_ATK | MS_RFIRE | MS_DOT,             0,126,MT_BEAST    ,"Fire Lizard",    255,0,0,0,0,0,7,0 },
  { 2, 32, 80, 80,  0,10, 40, 20, 4050,14, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,118,MT_UNDEAD   ,"Ghost",          255,0,0,0,0,0,7,0 },
  { 1,  0, 80, 80,  0,10, 48, 12, 2250,14, MS_COLD_ATK | MS_ICOLD | MS_DOT,             0,135,MT_GIANT    ,"Frost Giant",    255,0,0,0,0,0,7,0 },
  { 1, 64, 80, 80,250,10,  3, 12, 2700,14, MS_POISON,                                   0,137,MT_BEAST    ,"Spirit Naga",    255,0,0,0,0,0,7,0 },
  { 1,  0, 80, 80,  0,10, 20, 20, 2750,16, MS_POISON | MS_ROOT,                         0,108,MT_BEAST    ,"Roper",          255,0,0,0,0,0,7,0 },
  { 3,  0, 80, 80,250,10, 24, 28, 2400,14, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type III Demon", 255,0,0,0,0,0,7,0 },
  { 1,  0, 80, 80,  0,10, 20, 15, 2250,14, 0,                                           0,339,MT_HUMANOID ,"Kobold Warrior", 255,0,0,0,0,0,7,0 },

  { 2,  0, 88, 88,  0,11, 10, 10, 2150,16, 0,                                           0,122,MT_BEAST    ,"11 head Hydra",  255,0,0,0,0,0,7,0 },
  { 1, 31, 88, 88,275,11, 20, 20,10500,16, MS_SLEEP | MS_ARCN_ATK | MS_IARCN,           0,125,MT_UNDEAD   ,"Lich",           255,0,0,0,0,0,7,0 },
  { 1, 37, 88, 88,  0,11, 60, 14, 2700,16, MS_FIRE_ATK | MS_IFIRE,                      0,135,MT_GIANT    ,"Fire Giant",     255,0,0,0,0,0,7,0 },
  { 1,  0, 88, 88,275,11, 80, 34,47280, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN | MS_DOT,   0,152,MT_DEMON    ,"Juiblex",        255,0,0,0,0,0,7,0 },
  { 2, 46, 88, 88,275,11, 16, 22, 3000,16, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,152,MT_DEMON    ,"Type IV Demon",  255,0,0,0,0,0,7,0 },
  { 2, 15, 48, 48,250,11, 36, 14, 4200,12, MS_FIRE_ATK | MS_RFIRE | MS_FLY | MS_MOUNT,  0,153,MT_DRAGON   ,"Black Dragon",   255,0,0,0,0,0,7,0 },

  { 1, 16,128,128,  0,12, 40, 16, 2850,15, MS_ELEC_ATK | MS_RELEC,                      0,101,MT_ELEMENTAL,"Air Elemental",  255,0,0,0,0,0,7,0 },
  { 3, 44, 96, 96,  0,12, 10, 10, 2850,16, 0,                                           0,122,MT_BEAST    ,"12 head Hydra",  255,0,0,0,0,0,7,0 },
  { 1, 58, 96, 96,  0,12, 72, 16, 4250,16, MS_ELEC_ATK | MS_IELEC,                      0,135,MT_GIANT    ,"Cloud Giant",    255,0,0,0,0,0,7,0 },
  { 1,  0, 96, 96,300,12,  8, 14, 3550,16, MS_POISON,                                   0,137,MT_BEAST    ,"Guardian Naga",  255,0,0,0,0,0,7,0 },
  { 1,  7, 96, 96,300,12, 12, 24, 2850,16, MS_FEAR,                                     0,144,MT_BEAST    ,"Andro-Sphinx",   255,0,0,0,0,0,7,0 },
  { 2, 60, 96, 96,  0,12, 10, 10, 2850,16, 0,                                           0,115,MT_HUMANOID ,"Large Gargoyle", 255,0,0,0,0,0,7,0 },
  { 1, 68, 96, 96,  0,12, 10, 10, 2850,16, 0,                                           0,339,MT_HUMANOID ,"Kobold Guard",   255,0,0,0,0,0,7,0 },

  { 3, 43,104,104,  0,13, 10, 10, 3000,18, 0,                                           0,122,MT_BEAST    ,"13 head Hydra",  255,0,0,0,0,0,7,0 },
  { 2, 17, 80, 80,375,13, 48, 18,10000,26, MS_COLD_ATK | MS_RCOLD | MS_FLY | MS_MOUNT,  0,157,MT_DRAGON   ,"Blue Dragon",    255,0,0,0,0,0,7,0 },
  { 3, 59,104,104,  0,13, 10, 10, 3000,18, 0,                                           0,115,MT_HUMANOID ,"Huge Gargoyle",  255,0,0,0,0,0,7,0 },

  { 1, 18,128,128,  0,14, 48, 16, 2850,15, MS_FIRE_ATK | MS_RFIRE,                      0,111,MT_ELEMENTAL,"Fire Elemental", 255,0,0,0,0,0,7,0 },
  { 3, 36,112,112,  0,14, 12, 10, 3950,18, 0,                                           0,122,MT_BEAST    ,"14 head Hydra",  255,0,0,0,0,0,7,0 },
  { 2,  8, 88, 88,400,14, 60, 22,20000,25, MS_FIRE_ATK | MS_RFIRE | MS_DOT | MS_FLY | MS_MOUNT, 0,154,MT_DRAGON   ,"Red Dragon",255,0,0,0,0,0,7,0 },
  { 1,  0,112,112,  0,14, 12, 10, 3950,18, 0,                                           0,123,MT_HUMANOID ,"Troll Guard",    255,0,0,0,0,0,7,0 },
  { 1, 71,112,112,  0,14, 48, 16, 2850,20, 0,                                           0,121,MT_HUMANOID ,"Dwarven Guard",  255,0,0,0,0,0,7,0 },

  { 3,  0,120,120,  0,15, 12, 10, 4000,20, 0,                                           0,122,MT_BEAST    ,"15 head Hydra",  255,0,0,0,0,0,7,0 },
  { 1, 57,120,120,  0,15, 84, 18, 5850,20, MS_ELEC_ATK | MS_IELEC,                      0,135,MT_GIANT    ,"Storm Giant",    255,0,0,0,0,0,7,0 },
  { 1, 49,120,120,  0,15, 24,  8, 4900,20, MS_POISON,                                   0,141,MT_BEAST    ,"Purple Worm",    255,0,0,0,0,0,7,0 },
  { 2, 45,120,120,375,15, 60, 32,63900, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN,            0,150,MT_DEMON    ,"Orcus",          255,0,0,0,0,0,7,0 },
  { 2, 70,120,120,  0,15, 50, 18, 4000,20, 0,                                           0,121,MT_HUMANOID ,"Dwarven Chief",  255,0,0,0,0,0,7,0 },

  { 1,  0,128,128,  0,16, 64, 14, 5250,20, MS_ELEC_ATK | MS_IELEC,                      0,101,MT_ELEMENTAL,"Aerial Servant", 255,0,0,0,0,0,7,0 },
  { 1, 40,128,128,  0,16, 64, 14, 5250,20, MS_ELEC_ATK | MS_IELEC,                      0,101,MT_ELEMENTAL,"Aerial Servant", 255,0,0,0,0,0,7,0 },
  { 1, 19,128,128,  0,16, 60, 16, 2850,15, MS_COLD_ATK | MS_RCOLD | MS_DOT,             0,112,MT_ELEMENTAL,"Water Elemental",255,0,0,0,0,0,7,0 },
  { 4,  9,128,128,  0,16, 12, 10, 5250,20, 0,                                           0,122,MT_BEAST    ,"16 head Hydra",  255,0,0,0,0,0,7,0 },
  { 2, 72,128,128,500,16, 60, 20,63580, 1, MS_FIRE_ATK | MS_IFIRE | MS_FLY | MS_MOUNT,  0,158,MT_DRAGON   ,"Chromatic Dragon",255,0,0,0,0,0,7,0 },
  { 1, 54,128,128,300,16, 60, 20,63580, 1, MS_ARCN_ATK | MS_RARCN,                      0,123,MT_HUMANOID ,"Troll Shaman",   255,0,0,0,0,0,7,0 },

  { 2, 20,132,132,  0,17, 38, 28, 7000,25, MS_FRIENDLY | MS_MOUNT | MS_FLY,             0,133,MT_BEAST    ,"Pegasus",        255,0,0,0,0,0,7,0 },
  { 1, 33,136,136,425,17, 74, 18, 7000,25, MS_ELEC_ATK | MS_IELEC | MS_DOT,             0,135,MT_GIANT    ,"Lesser Titan",   255,0,0,0,0,0,7,0 },
  { 2, 66,132,132,  0,18, 32, 16, 2850,15, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,118,MT_UNDEAD   ,"Unbound Spirit", 255,0,0,0,0,0,7,0 },

  { 1, 21,128,128,  0,18, 32, 16, 2850,15, 0,                                           0,113,MT_ELEMENTAL,"Earth Elemental",255,0,0,0,0,0,7,0 },
  { 2, 53,128,128,  0,18, 32, 16, 2850,15, 0,                                           0,123,MT_HUMANOID ,"Troll Chieften", 255,0,0,0,0,0,7,0 },
  { 2, 65,128,128,  0,18, 32, 16, 2850,15, MS_FEAR | MS_ARCN_ATK | MS_RARCN,            0,118,MT_UNDEAD   ,"Greater Spirit", 255,0,0,0,0,0,7,0 },

/* SP   #  HP MHP  MN LV  AT  DF    XP +H SP                                          SPR NAME */
  { 1, 52,136,136,200,19, 40, 20, 3850,20, MS_AMAGIC,                                   0,124,MT_BEAST,    "Lamia Guard",    255,0,0,0,0,0,7,0 },
  { 1, 69,100,100,600,19, 40, 20, 5000,25, MS_AMAGIC | MS_ARCN_ATK,                     0,166,MT_HUMANOID ,"Necromancer",    255,0,0,0,0,0,7,0 },
  { 1,104,100,100,150,19, 30, 35, 4000,23, MS_APHYSICAL|MS_COLD_ATK|MS_RCOLD,    M2_DRAIN,347,MT_HUMANOID ,"Vampire",        255,0,0,0,0,0,7,0 },

  { 1, 35,100,100,900,20, 50, 50,10000,35, MS_AMAGIC,                                   0,166,MT_HUMANOID ,"Dark-Magi",      255,0,0,0,0,0,7,0 },
  { 1, 74,160,160,500,20, 84, 22, 9000,30, MS_ELEC_ATK | MS_IELEC | MS_DOT,             0,135,MT_GIANT    ,"Major Titan",    255,0,0,0,0,0,7,0 },
  { 1, 81,160,160,500,20, 84, 22, 9000,30, MS_ARCN_ATK | MS_IARCN | MS_DOT,             0,135,MT_DEMON    ,"Lesser God",     255,0,0,0,0,0,7,0 },

  { 2, 34,168,168,675,21, 96, 26,75000, 1, MS_FIRE_ATK | MS_IFIRE | MS_DOT,             0,159,MT_DRAGON   ,"Platinum Dragon",255,0,0,0,0,0,7,0 },
  { 1, 82,168,168,675,21, 96, 22, 9000,30, MS_ARCN_ATK | MS_IARCN | MS_DOT,             0,135,MT_DEMON    ,"Fallen God",     255,0,0,0,0,0,7,0 },
  { 2, 86,168,168,425,21, 85, 20,10000,30, MS_ARCN_ATK | MS_IARCN | MS_DOT,             0,147,MT_BEAST    ,"Arcane Wisp",    255,0,0,0,0,0,7,0 },

  { 1, 73,176,176,550,22, 94, 26,11000,35, MS_ELEC_ATK | MS_IELEC | MS_DOT,             0,135,MT_GIANT    ,"Elder Titan",    255,0,0,0,0,0,7,0 },

  { 1, 83,184,184,700,23, 96, 28,12000,30, MS_ARCN_ATK | MS_IARCN | MS_DOT,             0,135,MT_DEMON    ,"Old God",        255,0,0,0,0,0,7,0 },

  { 2, 88,192,192,600,24, 96, 26,70000, 1, MS_FIRE_ATK | MS_IFIRE | MS_DOT,             0,159,MT_DRAGON   ,"Elder Dragon",   255,0,0,0,0,0,7,0 },

  { 2, 75,200,200,625,25, 80, 36,74000, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN | MS_DOT,   0,149,MT_DEMON    ,"Demogorgon",     255,0,0,0,0,0,7,0 },


  { 1,  0,250,250,100,30, 12, 16,  400, 5, MS_FRIENDLY | MS_MOUNT,               M2_NORND,132,MT_BEAST    ,"Unicorn",        255,0,0,0,0,0,7,0 },

/* SP   #  HP MHP  MN LV  AT  DF    XP +H SP SPR NAME */
  { 1,  0,  8,  8,  0, 1,  2,  5,   10, 1, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Veteran",        255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,  0, 2,  7,  7,   15, 2, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Warrior",        255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24,  0, 3,  9,  9,   20, 2, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Swordsman",      255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,  0, 4, 11, 11,   25, 3, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Hero",           255,0,0,0,0,0,7,0 },
  { 1,  0, 40, 40,  0, 5, 13, 13,   30, 4, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Swashbuckler",   255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,  0, 6, 15, 15,   40, 4, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Myrmidon",       255,0,0,0,0,0,7,0 },
  { 1,  0, 56, 56,  0, 7, 17, 17,   75, 5, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Champion",       255,0,0,0,0,0,7,0 },
  { 1,  0, 64, 64,  0, 8, 19, 19,  125, 6, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Superhero",      255,0,0,0,0,0,7,0 },
  { 1,  0, 72, 72,  0, 9, 21, 21,  175, 7, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Lord",           255,0,0,0,0,0,7,0 },
  { 1,  0, 80, 80,  0,10, 23, 23,  225, 7, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Lord",           255,0,0,0,0,0,7,0 },
  { 1,  0, 88, 88,  0,11, 25, 25,  275, 8, MS_FRIENDLY,                           M2_CITY,163,MT_HUMANOID ,"Lord",           255,0,0,0,0,0,7,0 },
  { 1,  0,  4,  4, 50, 1,  4,  4,   10, 1, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Prestidigitator",255,0,0,0,0,0,7,0 },
  { 1,  0,  8,  8, 75, 2,  6,  6,   15, 1, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Evoker",         255,0,0,0,0,0,7,0 },
  { 1,  0, 12, 12,100, 3,  8,  8,   20, 1, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Conjurer",       255,0,0,0,0,0,7,0 },
  { 1,  0, 16, 16,125, 4, 10, 10,   40, 2, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Theurgist",      255,0,0,0,0,0,7,0 },
  { 1,  0, 20, 20,150, 5, 12, 12,   60, 3, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Thaumaturgist",  255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24,175, 6, 14, 14,   80, 4, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Magician",       255,0,0,0,0,0,7,0 },
  { 1,  0, 28, 28,200, 7, 16, 16,  100, 4, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Enchanter",      255,0,0,0,0,0,7,0 },
  { 1,  0, 32, 32,225, 8, 18, 18,  120, 5, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Warlock",        255,0,0,0,0,0,7,0 },
  { 1,  0, 36, 36,250, 9, 20, 20,  140, 6, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Sorcerer",       255,0,0,0,0,0,7,0 },
  { 1,  0, 40, 40,275,10, 22, 22,  160, 7, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Necromancer",    255,0,0,0,0,0,7,0 },
  { 1,  0, 44, 44,300,11, 24, 24,  180, 8, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Wizard",         255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,325,12, 26, 26,  200, 8, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Wizard",         255,0,0,0,0,0,7,0 },
  { 1,  0, 52, 52,350,13, 28, 28,  250,10, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Wizard",         255,0,0,0,0,0,7,0 },
  { 1,  0, 56, 56,375,14, 30, 30,  300,12, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Wizard",         255,0,0,0,0,0,7,0 },
  { 1,  0,100,100,900,20, 50, 50, 1000,15, MS_FRIENDLY,                           M2_CITY,165,MT_HUMANOID ,"Arch-Magi",      255,0,0,0,0,0,7,0 },
  { 1,  0,  6,  6, 50, 1,  4,  4,   10, 1, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Acolyte",        255,0,0,0,0,0,7,0 },
  { 1,  0, 12, 12, 75, 2,  6,  6,   15, 1, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Adept",          255,0,0,0,0,0,7,0 },
  { 1,  0, 18, 18,100, 3,  8,  8,   20, 1, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Priest",         255,0,0,0,0,0,7,0 },
  { 1,  0, 24, 24,125, 4, 10, 10,   30, 2, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Curate",         255,0,0,0,0,0,7,0 },
  { 1,  0, 30, 30,150, 5, 12, 12,   40, 2, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Prefect",        255,0,0,0,0,0,7,0 },
  { 1,  0, 36, 36,175, 6, 14, 14,   50, 3, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Canon",          255,0,0,0,0,0,7,0 },
  { 1,  0, 42, 42,200, 7, 16, 16,   60, 3, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Lama",           255,0,0,0,0,0,7,0 },
  { 1,  0, 48, 48,225, 8, 18, 18,   80, 4, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"Patriarch",      255,0,0,0,0,0,7,0 },
  { 1,  0, 54, 54,250, 9, 20, 20,  100, 4, MS_FRIENDLY | MS_HEALER,               M2_CITY,164,MT_HUMANOID ,"High Priest",    255,0,0,0,0,0,7,0 },
  { 1,  0,  5,  5,  0, 1,  3,  3,    5, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 10, 10,  0, 2,  4,  4,    7, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 15, 15,  0, 3,  5,  5,    9, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 20, 20,  0, 4,  6,  6,   11, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 25, 25,  0, 5,  7,  7,   13, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 30, 30,  0, 6,  8,  8,   15, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 35, 35,  0, 7,  9,  9,   17, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 40, 40,  0, 8, 10, 10,   19, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 45, 45,  0, 9, 11, 11,   21, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 50, 50,  0,10, 12, 12,   25, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,162,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0,  5,  5,  0, 1,  3,  3,    5, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 10, 10,  0, 2,  4,  4,    7, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 15, 15,  0, 3,  5,  5,    9, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 20, 20,  0, 4,  6,  6,   11, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 25, 25,  0, 5,  7,  7,   13, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 30, 30,  0, 6,  8,  8,   15, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 35, 35,  0, 7,  9,  9,   17, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 40, 40,  0, 8, 10, 10,   19, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 45, 45,  0, 9, 11, 11,   21, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },
  { 1,  0, 50, 50,  0,10, 12, 12,   25, 1, MS_FRIENDLY,                M2_NORND | M2_CITY,161,MT_HUMANOID ,"Human",          255,0,0,0,0,0,7,0 },


/* SP   #  HP MHP  MN LV  AT  DF    XP +H SP                                              SPR NAME */
/* Special bosses and adds */
  { 2, 41, 88, 88,  0,11, 10, 10, 2150,16, 0,                                        M2_NORND | M2_BOSS,333,MT_HUMANOID ,"Orc Warchief",255,0,0,0,0,0,7,0 },
  { 2, 42, 80, 80,  0,10,  8, 10, 1500,14, 0,                                        M2_NORND | M2_BOSS,123,MT_BEAST    ,"Orc Captain",255,0,0,0,0,0,7,0 },
  { 2, 47,184,184,675,23, 96, 26,75000, 1, MS_FIRE_ATK | MS_IFIRE | MS_DOT,          M2_NORND | M2_BOSS,334,MT_DRAGON   ,"Dragon Queen",255,0,0,0,0,0,7,0 },
  { 2, 48,224,224,625,28, 80, 36,74000, 1, MS_FEAR | MS_DOT,                         M2_NORND | M2_BOSS,335,MT_DEMON    ,"Count Tralin",255,0,0,0,0,0,7,0 },
  { 1, 50,136,136,  0,19, 32, 16, 2850,15, 0,                                        M2_NORND | M2_BOSS,336,MT_ELEMENTAL,"Forest Spirit",255,0,0,0,0,0,7,0 },
  { 1, 51,100,100,400,20, 50, 50,10000,35, MS_AMAGIC,                                M2_NORND | M2_BOSS,337,MT_HUMANOID ,"Lamia Queen",255,0,0,0,0,0,7,0 },
  { 1, 67,112,112,  0,14, 24, 10, 3950,18, MS_DOT | MS_FIRE_ATK,                     M2_NORND | M2_BOSS,338,MT_HUMANOID ,"Kobold Lord",255,0,0,0,0,0,7,0 },
  { 2, 77,200,200,625,25, 80, 36,74000, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN | MS_DOT,M2_NORND | M2_BOSS,340,MT_UNDEAD   ,"Caldnar",255,0,0,0,0,0,7,0 },
  { 1, 78,160,160,  0,20, 84, 22, 9000,30, MS_AMAGIC,                                M2_NORND | M2_BOSS,135,MT_GIANT    ,"Giant King",255,0,0,0,0,0,7,0 },
  { 2, 80,200,200,625,25, 80, 36,74000, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN | MS_DOT,M2_NORND | M2_BOSS,341,MT_UNDEAD   ,"Elanther",255,0,0,0,0,0,7,0 },
  { 2, 84,216,216,800,27, 90, 40,90000, 1, MS_FEAR | MS_ARCN_ATK | MS_IARCN | MS_DOT,M2_NORND | M2_BOSS,149,MT_DEMON    ,"Corrupted God",255,0,0,0,0,0,7,0 },
  { 2, 85,176,176,550,22, 94, 26,11000,35, MS_ELEC_ATK | MS_IELEC | MS_DOT,          M2_NORND | M2_BOSS,147,MT_BEAST    ,"Greater Wisp",255,0,0,0,0,0,7,0 },
  { 2, 87,216,216,700,27, 96, 26,90000, 1, MS_FIRE_ATK | MS_IFIRE | MS_DOT,          M2_NORND | M2_BOSS,159,MT_DRAGON   ,"Ancient Dragon",255,0,0,0,0,0,7,0 },
  { 1, 91,100,100,300,30, 50, 50,10000,35, 0,                                        M2_NORND,          160,MT_BEAST    ,"Dalek",255,0,0,0,0,0,7,0 },
  { 1, 90,-999,100,900,40,100, 50,90000,35, MS_AMAGIC | MS_ARCN_ATK,                  M2_NORND,          179,MT_HUMANOID ,"Eshter",255,0,0,0,0,0,7,0 },

  { 999,999,999,999,0,0, 0, 0,0,0,0, 0,0,0,"EOL",255,0,0,0,0,0,7,0 },
  };

NPC_STATS npc_stats[] = {
  { 1,  10, 18, 10,  8,  8, 10 }
  };

#else

extern NPC_REC monsters[];
extern NPC_STATS npc_stats[];

#endif

