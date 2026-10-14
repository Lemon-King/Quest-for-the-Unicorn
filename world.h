#define S_GRASS                 1
#define S_DNSTAIR              24
#define S_UPSTAIR              25
#define S_SALE                247
#define S_SOLD                248

#ifdef MAIN

/* Dedicated Sprice Codes */

/*    Typ Rgn  rX  rY  cX  cY name   */
SHOP_REC shops[] = {
    /* Radon */
    {   0,  9, 72, 16, 62, 74, "The Fighting Edge" },
    {   1,  9, 72, 16, 67, 74, "The Best Defense" },
    {   2,  9, 72, 16,  5, 56, "Radon Concoctions" },
    {   3,  9, 72, 16, 66, 56, "Radon Jewelry" },
    {   4,  9, 72, 16, 67, 68, "Radon Scrolls" },
    {   5,  9, 72, 16, 67, 62, "Radon Fashions" },
    {   6,  9, 72, 16,  5, 61, "The Enchanter" },
    {   7,  9, 72, 16, 59, 40, "The General Library of Radon" },
    {   8,  9, 72, 16, 59, 13, "The Traveller's Stop" },
    {   8,  9, 72, 16,  5, 67, "The Wizard's Rod" },
    {   8,  9, 72, 16, 35, 83, "The Seamen's Inn" },
    {   8,  9, 72, 16, 66, 83, "Radon Inn" },
    {   9,  9, 72, 16, 59, 44, "Radon U." },
    {  10,  9, 72, 16, 36, 91, "Radon Travel Agency" },
    {  11,  9, 72, 16,  5, 75, "Radon Supply Company" },
    {  12,  9, 72, 16, 21, 73, "Radon Import" },
    {  13,  9, 72, 16, 57, 74, "The Druidic Temple" },
    {  14,  9, 72, 16, 20, 83, "The Cavalier's Guild" },
    {  16,  9, 72, 16, 54, 68, "Halkanar National Bank" },
    /* Marduk */
    {   0,  7, 32, 19, 28, 11, "The Marduk Edge" },
    {   1,  7, 32, 19, 28, 27, "Marduk Armour" },
    {   2,  7, 32, 19, 19, 11, "Maduk Potions" },
    {   3,  7, 32, 19, 10, 19, "Marduk Gems" },
    {   4,  7, 32, 19, 19, 19, "Marduk Sage Supply" },
    {   5,  7, 32, 19, 10, 35, "Marduk Clothiers" },
    {   6,  7, 32, 19, 19, 27, "The Wizard's Right Hand" },
    {   7,  7, 32, 19, 82, 14, "The Halkanar Library" },
    {   8,  7, 32, 19, 28, 54, "The Unicorn Inn" },
    {   8,  7, 32, 19, 20, 84, "The Crew's Nest" },
    {   9,  7, 32, 19, 57, 15, "The Marduk Institute" },
    {  10,  7, 32, 19, 44, 73, "Marduk Travel" },
    {  11,  7, 32, 19, 28, 43, "Marduk Supply Company" },
    {  12,  7, 32, 19, 37, 27, "Importers of Marduk" },
    {  13,  7, 32, 19, 40, 19, "The Druidic Temple" },
    {  14,  7, 32, 19, 26, 35, "The Cavalier's Guild" },
    /* Nichorville */
    {   0,  2, 63, 76, 86, 19, "Nichorville Weapons" },
    {   1,  2, 63, 76, 21, 31, "Nichorville Armour" },
    {   2,  2, 63, 76, 39, 53, "Nichorville Potions" },
    {   3,  2, 63, 76,  7, 22, "Nichorville Jewelry" },
    {   4,  2, 63, 76, 48, 53, "Nichorville Books" },
    {   5,  2, 63, 76, 73, 53, "Zoltar's Cloak Shop" },
    {   6,  2, 63, 76, 57, 53, "Nichor's Magic Supply" },
    {   7,  2, 63, 76, 94, 53, "The Nichorville Archives" },
    {   8,  2, 63, 76, 43, 22, "Nichorville Inn" },
    {   9,  2, 63, 76, 81, 58, "University of Nichorville" },
    {  10,  2, 63, 76, 97, 12, "Nichorville Travel" },
    {  11,  2, 63, 76, 61, 22, "Nichorville Provisions" },
    {  12,  2, 63, 76, 59, 10, "The Importer" },
    {  13,  2, 63, 76, 87, 72, "The Druidic Temple" },
    {  14,  2, 63, 76, 85, 89, "The Cavalier's Guild" },
    /* Generic Cities */
    {   0,  9, 61, 45, 42, 48, "Capetown Weaponry" },
    {   0,  9, 49, 64, 42, 48, "The REAL Defense" },
    {   0,  5, 33, 28, 42, 48, "The Golden Defense" },
    {   0,  1, 46, 49, 42, 48, "The Sharp Edge" },
    {   0,  3, 44, 49, 42, 48, "Ye Olde Weapons Shoppe" },
    {   0, 10, 57, 53, 42, 48, "Talgon Weapons Supply" },
    {   1,  9, 61, 45, 59, 48, "The Defensive Stance" },
    {   1,  9, 49, 64, 59, 48, "Protection Co." },
    {   1,  5, 33, 28, 59, 48, "Goldville Defense Co." },
    {   1,  1, 46, 49, 59, 48, "River Defense Co." },
    {   1,  3, 44, 49, 59, 48, "Armour Plus" },
    {   1, 10, 57, 53, 59, 48, "Dragon Defense Co." },
    {   2,  9, 61, 45, 42, 37, "Potions Etc." },
    {   2,  9, 49, 64, 42, 37, "Radon Valley Potions" },
    {   2,  5, 33, 28, 42, 37, "Potion Brewers of Goldville" },
    {   2,  1, 46, 49, 42, 37, "Alaras Concoctions" },
    {   2,  3, 44, 49, 42, 37, "Sorcerer's Potions" },
    {   2, 10, 57, 53, 42, 37, "Talgon Potion Supply" },
    {   3,  9, 61, 45, 70, 26, "Capetown Jewels" },
    {   3,  9, 49, 64, 70, 26, "The Sparkling Diamond" },
    {   3,  5, 33, 28, 70, 26, "Goldville Gems" },
    {   3,  1, 46, 49, 70, 26, "The Adamantite Works" },
    {   3,  3, 44, 49, 70, 26, "Solat Gems" },
    {   3, 10, 57, 53, 70, 26, "Talgon Jewel Works" },
    {   4,  9, 61, 45, 59, 37, "Dragon Books" },
    {   4,  9, 49, 64, 59, 37, "The Sage's Delight" },
    {   4,  5, 33, 28, 59, 37, "The Scroll Shop" },
    {   4,  1, 46, 49, 59, 37, "Halkanar Books" },
    {   4,  3, 44, 49, 59, 37, "The Wizard's Scroll" },
    {   4, 10, 57, 53, 59, 37, "The Wizard's Scribe" },
    {   5,  9, 61, 45, 69, 37, "The Magic Cloak" },
    {   5,  9, 49, 64, 69, 37, "Cloaks and Thinks" },
    {   5,  5, 33, 28, 69, 37, "Goldville Clothiers" },
    {   5,  1, 46, 49, 69, 37, "The Cloak Merchant" },
    {   5,  3, 44, 49, 69, 37, "Solat Clothing" },
    {   5, 10, 57, 53, 69, 37, "Talgon Fashions" },
    {   6,  9, 61, 45, 50, 37, "The Enchantress" },
    {   6,  9, 49, 64, 50, 37, "The Magician's Fancy" },
    {   6,  5, 33, 28, 50, 37, "The Magician's Den" },
    {   6,  1, 46, 49, 50, 37, "Unicorn Magic" },
    {   6,  3, 44, 49, 50, 37, "The Olde Spell" },
    {   6, 10, 57, 53, 50, 37, "The Wizardess" },
    {   7,  9, 61, 45, 90, 25, "The Capetown Library" },
    {   7,  9, 49, 64, 90, 25, "The Lore Archives" },
    {   7,  5, 33, 28, 90, 25, "The Goldville Library" },
    {   7,  1, 46, 49, 90, 25, "The Records Archive" },
    {   7,  3, 44, 49, 90, 25, "Solat Information Center" },
    {   7, 10, 57, 53, 90, 25, "The Talgon General Library" },
    {   8,  9, 61, 45, 53, 17, "The Traveller's Inn" },
    {   8,  9, 49, 64, 53, 17, "The Happy Rest" },
    {   8,  5, 33, 28, 53, 17, "Goldville Tavern" },
    {   8,  1, 46, 49, 53, 17, "The Mermaid Inn" },
    {   8,  3, 44, 49, 53, 17, "New Solat Pub" },
    {   8, 10, 57, 53, 53, 17, "The Talgon Inn" },
    {   9,  9, 61, 45, 90, 47, "Capetown Institute" },
    {   9,  9, 49, 64, 90, 47, "South Radon U." },
    {   9,  5, 33, 28, 90, 47, "Goldville College" },
    {   9,  1, 46, 49, 90, 47, "Northwest U." },
    {   9,  3, 44, 49, 90, 47, "Solat Training Facility" },
    {   9, 10, 57, 53, 90, 47, "Talgon U." },
    {  10,  9, 61, 45, 65, 17, "Capetown Travel" },
    {  10,  9, 49, 64, 65, 17, "Adventurer's Travel" },
    {  10,  5, 33, 28, 65, 17, "Goldville Travel" },
    {  10,  1, 46, 49, 65, 17, "Talfharin Travel" },
    {  10,  3, 44, 49, 65, 17, "Ye Olde Travel Company" },
    {  10, 10, 57, 53, 65, 17, "Talgon Travel Agency" },
    {  11,  9, 61, 45, 30, 17, "The Traveller's Supply" },
    {  11,  9, 49, 64, 30, 17, "The Dungeneer's Needs" },
    {  11,  5, 33, 28, 30, 17, "The Miner's Store" },
    {  11,  1, 46, 49, 30, 17, "The Adventurer's Supply Co." },
    {  11,  3, 44, 49, 30, 17, "The Dragon Supply Co." },
    {  11, 10, 57, 53, 30, 17, "Talgon Supply Co." },
    {  12,  9, 61, 45, 30, 26, "Lake Imports" },
    {  12,  9, 49, 64, 30, 26, "Dragon Treasures" },
    {  12,  5, 33, 28, 30, 26, "The Gold Mine" },
    {  12,  1, 46, 49, 30, 26, "River Imports" },
    {  12,  3, 44, 49, 30, 26, "Solat Relics" },
    {  12, 10, 57, 53, 30, 26, "Halkanar Curios" },
    {  13,  9, 61, 45, 34, 61, "The Druidic Temple" },
    {  13,  9, 49, 64, 34, 61, "The Druidic Temple" },
    {  13,  5, 33, 28, 34, 61, "The Druidic Temple" },
    {  13,  1, 46, 49, 34, 61, "The Druidic Temple" },
    {  13,  3, 44, 49, 34, 61, "The Druidic Temple" },
    {  13, 10, 57, 53, 34, 61, "The Druidic Temple" },
    {  14,  9, 61, 45, 44,  3, "The Cavalier's Guild" },
    {  14,  9, 49, 64, 44,  3, "The Cavalier's Guild" },
    {  14,  5, 33, 28, 44,  3, "The Cavalier's Guild" },
    {  14,  1, 46, 49, 44,  3, "The Cavalier's Guild" },
    {  14,  3, 44, 49, 44,  3, "The Cavalier's Guild" },
    {  14, 10, 57, 53, 44,  3, "The Cavalier's Guild" },

    {  16,  9, 61, 45, 31, 51, "Capetown Bank" },
    {  16,  9, 49, 64, 31, 51, "South Radon Bank" },
    {  16,  5, 33, 28, 31, 51, "Goldville Savings Bank" },
    {  16, 10, 57, 53, 31, 51, "Talgon Savings" },

    {   0,  0,  0, 0,  42, 48, "Village Weapons" },
    {   1,  0,  0, 0,  58, 48, "Village Armour" },
    {   8,  0,  0, 0,  49, 56, "Village Inn" },
    {  11,  0,  0, 0,  50, 41, "Village Supply" },

    { 999,  0,  0,  0,  0,  0, "EOL" }
  };

/* Travel Agency Sold Ships */
/*   map,   x,   y */
TR_SHIP_REC tr_ships[] = {
    { 13,  47,  98 },
    { 16,  60,  83 },
    { 99,  99,  99 }
  };

/* For Sale Houses */
/*    reg,  rx, ry, cx, cy, price */
FORSALE forsale[] = {
    {   5,  33, 28, 18, 65, 300000 },                   /* Goldville */
    {   9,  72, 16, 84, 60, 150000 },                   /* Radon */
    { 999, 999,999,999,999,      0 },                   /* EOL */
  };

/* Region Names */
REGION_REC regions[] = {
     { "The Northern Realm" },                         /* 1 */
     { "The Realm of Nichor" },                        /* 2 */
     { "The Olde Realm" },                             /* 3 */
     { "The Northeast Wastes" },                       /* 4 */
     { "The Great Desert" },                           /* 5 */
     { "The Kobold Mountains" },                       /* 6 */
     { "The Realm of Marduk" },                        /* 7 */
     { "The Realm of Larkon" },                        /* 8 */
     { "Radon Valley" },                               /* 9 */
     { "The Realm of Talgon" },                        /* 10 */
     { "The Enchanted Lands" },                        /* 11 */
     { "The Valley of the Unicorns" }                  /* 12 */
  };

/* Treasure Link Codes */
#define T_001         1
#define T_002         2
#define T_003         3
#define T_004         4
#define T_005         5
#define T_006         6
#define T_007         7
#define T_008         8
#define T_009         9
#define T_010        10
#define T_011        11
#define T_012        12
#define T_013        13
#define T_014        14
#define T_015        15
#define T_016        16
#define T_017        17
#define T_018        18
#define T_019        19
#define T_020        20
#define T_021        21
#define T_022        22
#define T_023        23
#define T_024        24
#define T_025        25
#define T_026        26
#define T_027        27
#define T_028        28
#define T_029        29
#define T_030        30
#define T_031        31
#define T_032        32
#define T_033        33
#define T_034        34
#define T_035        35
#define T_036        36
#define T_037        37
#define T_038        38
#define T_039        39
#define T_040        40
#define T_041        41
#define T_042        42
#define T_043        43
#define T_044        44
#define T_045        45
#define T_046        46
#define T_047        47
#define T_048        48
#define T_049        49
#define T_050        50
#define T_051        51
#define T_052        52
#define T_053        53
#define T_054        54
#define T_055        55
#define T_056        56
#define T_057        57
#define T_058        58
#define T_059        59
#define T_060        60
#define T_061        61
#define T_062        62
#define T_063        63
#define T_064        64
#define T_065        65
#define T_066        66
#define T_067        67
#define T_068        68
#define T_069        69
#define T_070        70
#define T_071        71
#define T_072        72
#define T_073        73
#define T_074        74
#define T_075        75
#define T_076        76
#define T_077        77
#define T_078        78
#define T_079        79
#define T_080        80
#define T_081        81
#define T_082        82
#define T_083        83
#define T_084        84
#define T_085        85
#define T_086        86
#define T_087        87
#define T_088        88
#define T_089        89
#define T_090        90
#define T_091        91
#define T_092        92
#define T_093        93
#define T_094        94
#define T_095        95
#define T_096        96
#define T_097        97
#define T_098        98
#define T_099        99
#define T_100       100
#define T_101       101
#define T_102       102
#define T_103       103
#define T_104       104
#define T_105       105
#define T_106       106
#define T_107       107
#define T_108       108
#define T_109       109
#define T_110       110
#define T_111       111
#define T_112       112
#define T_113       113
#define T_114       114
#define T_115       115
#define T_116       116
#define T_117       117
#define T_118       118
#define T_119       119
#define T_120       120
#define T_121       121
#define T_122       122
#define T_123       123
#define T_124       124
#define T_125       125
#define T_126       126
#define T_127       127
#define T_128       128
#define T_129       129
#define T_130       130
#define T_131       131
#define T_132       132
#define T_133       133
#define T_134       134
#define T_135       135
#define T_136       136
#define T_137       137
#define T_138       138
#define T_139       139
#define T_140       140
#define T_141       141
#define T_142       142
#define T_143       143
#define T_144       144
#define T_145       145
#define T_146       146
#define T_147       147
#define T_148       148
#define T_149       149
#define T_150       150
#define T_151       151
#define T_152       152
#define T_153       153
#define T_154       154
#define T_155       155
#define T_156       156
#define T_157       157
#define T_158       158
#define T_159       159
#define T_160       160
#define T_161       161


/* Lore Message Link Codes */
#define L_001      1001
#define L_002      1002
#define L_003      1003
#define L_004      1004
#define L_005      1005
#define L_006      1006
#define L_007      1007
#define L_008      1008
#define L_009      1009
#define L_010      1010
#define L_011      1011
#define L_012      1012
#define L_013      1013
#define L_014      1014
#define L_015      1015
#define L_016      1016
#define L_017      1017
#define L_018      1018
#define L_019      1019
#define L_020      1020
#define L_021      1021
#define L_022      1022
#define L_023      1023
#define L_024      1024
#define L_025      1025
#define L_026      1026
#define L_027      1027
#define L_028      1028
#define L_029      1029
#define L_030      1030
#define L_031      1031
#define L_032      1032
#define L_033      1033
#define L_034      1034
#define L_035      1035
#define L_036      1036

/* Dungeons and Towns */
/*  quest  region   x   y typ dif  name                       treasure  prem   sx   sy */
LINK_REC links[] = {
  {    14,      1, 27, 75, 11,  8,"Temple of the Forest",        L_001,    0,   0,   0 },
  {    31,      1, 25, 29, 11, 15,"Horror Point",                L_002,    0,   0,   0 },
  {    44,      1, 73, 24, 11, 19,"Ruins of Castle Caldnar",     T_001,    0,   0,   0 },
  {    24,      1, 81, 43, 11, 13,"Ruins of Alukrahn",           T_002,    0,   0,   0 },
  {     0,      1, 46, 49,  5, 14,"Talfharin",                       0,    0,  50,   3 },

  {    15,      2, 32, 55, 11,  8,"Temple of the North",         L_003,    0,   0,   0 },
  {    16,      2, 45, 76, 11,  9,"Stronghold of the Orcs",      L_004,    0,   0,   0 },
  {    12,      2, 17, 86, 11,  7,"Ruins of Aljan",               1014,    0,   0,   0 },
  {    27,      2, 32, 28, 11, 14,"Castle Alakahri",             T_003,    0,   0,   0 },
  {     0,      2, 63, 76,  5, 17,"Nichorville",                     0, 2500,  50,   3 },

  {    37,      3, 27, 22, 11, 17,"Solat",                       T_004,    0,   0,   0 },
  {    58,      3, 50, 28, 11, 25,"Ruins of Castle Tralin",      T_005,    0,   0,   0 },
  {    50,      3, 80, 24, 11, 20,"The Den of the Dragon",        1015,    0,   0,   0 },
  {    17,      3, 67, 91, 11, 10,"Isle of the Dead",            L_005,    0,   0,   0 },
  {    21,      3, 14, 61, 11, 12,"The Haunted isle",            L_006,    0,   0,   0 },
  {    25,      3, 85, 61, 11, 13,"Temple of the Water",         L_007,    0,   0,   0 },
  {     0,      3, 44, 49,  5, 14,"New Solat",                       0,    0,  50,   3 },

  {    26,      4, 68, 55, 11, 13,"The Great Swamp",             L_008,    0,   0,   0 },
  {    32,      4, 56, 71, 11, 15,"The Trolls Den",              L_009,    0,   0,   0 },
  {    38,      4, 85, 79, 11, 17,"Lamia Point",                 L_010,    0,   0,   0 },
  {    35,      4, 60, 16, 11, 16,"The Olde Forest",             L_011,    0,   0,   0 },

  {     4,      5, 30, 30, 11,  3,"The Mines of the Desert",     L_036,    0,   0,   0 },
  {     7,      5, 48, 39, 11,  5,"Temple of the Crescent",      L_012,    0,   0,   0 },
  {    29,      5, 25, 80, 11, 15,"Areth Knoll",                 T_006,    0,   0,   0 },
  {     5,      5, 48, 88, 11,  4,"Temple of the Sun",           L_013,    0,   0,   0 },
  {     0,      5, 33, 28,  5, 14,"Goldville",                       0,    0,  50,   3 },

  {     9,      6, 93, 98, 11,  6,"Den of the Beast",            L_014,    0,   0,   0 },
  {    30,      6, 75, 83, 11, 15,"Arath Ma Kon",                T_007,    0,   0,   0 },
  {    22,      6, 33, 81, 11, 12,"Algamar Ruins",               L_015,    0,   0,   0 },
  {    19,      6, 78, 68, 11, 11,"Hall of the Kobold Lords",    L_016,    0,   0,   0 },
  {     8,      6, 26, 62, 11,  5,"Temple of the Dark",          L_017,    0,   0,   0 },
  {    34,      6, 71, 46, 11, 16,"Ruins of Caldnar",            T_008,    0,   0,   0 },
  {    23,      6, 23, 41, 11, 12,"The Lost Mine of the Dwarves",T_009,    0,   0,   0 },
  {    11,      6, 75, 32, 11,  7,"Temple of the Moon",          L_018,    0,   0,   0 },
  {    41,      6, 16, 28, 11, 18,"The Den of Horror",           T_010,    0,   0,   0 },

  {    33,      7, 31, 79, 11, 15,"Isle of Will-o-Wisps",        L_019,    0,   0,   0 },
  {    39,      7, 10, 50, 11, 17,"Hall of the Giants",          L_020,    0,   0,   0 },
  {    51,      7, 59, 65, 11, 20,"The Black Hole",              T_011,    0,   0,   0 },
  {    36,      7, 89, 69, 11, 16,"The Lost Tomb",               L_021,    0,   0,   0 },
  {    55,      7, 44, 79, 11, 21,"The Tomb of Caldnar",         T_012,    0,   0,   0 },
  {    45,      7, 84, 80, 11, 19,"Cave of Enchantment",         L_022,    0,   0,   0 },
  {    42,      7, 80, 90, 11, 18,"The Valley of Fear",          L_023,    0,   0,   0 },
  {     0,      7, 32, 19,  5, 16,"Marduk",                          0,    0,   2,  50 },

  {    53,      8, 55, 40, 11, 20,"The Ruins of Larkon",         T_013,    0,   0,   0 },
  {    52,      8, 51, 66, 11, 20,"Valley of the Gods",          T_014,    0,   0,   0 },
  {    46,      8, 20, 71, 11, 19,"Valley of the Giants",        T_015,    0,   0,   0 },
  {    47,      8, 12, 84, 11, 19,"Valley of the Titans",        T_016,    0,   0,   0 },

  {     1,      9, 72,  8, 11,  1,"Radon Mine",                  T_061,    0,   0,   0 },
  {     3,      9, 62, 55, 11,  3,"Radon Isle",                  T_021,    0,   0,   0 },
  {     2,      9, 25, 64, 11,  2,"Platinum Mine",               T_020,    0,   0,   0 },
  {     0,      9, 72, 16,  5, 13,"Radon",                           0,    0,  50,   3 },
  {     0,      9, 61, 45,  5, 14,"Capetown",                        0,    0,  50,   3 },
  {     0,      9, 49, 64,  5, 14,"New South Radon",                 0,    0,  50,   3 },

  {     6,     10, 76, 18, 11,  4,"The Goblin Caves",            L_024,    0,   0,   0 },
  {    13,     10, 80,  6, 11,  8,"Calton Peak",                 L_025,    0,   0,   0 },
  {    20,     10,  9, 54, 11, 12,"The Lost Valley",             L_026,    0,   0,   0 },
  {    18,     10, 10,  5, 11, 10,"Gargoyle Peak",               L_027,    0,   0,   0 },
  {    10,     10, 90, 75, 11,  7,"Temple of the South",         L_028,    0,   0,   0 },
  {    28,     10, 49, 81, 11, 15,"The Valley of Blood",         L_029,    0,   0,   0 },
  {     0,     10, 57, 53,  5, 14,"Talgon",                          0,    0,  50,   3 },

  {    54,     11, 68, 61, 11, 20,"Elanthers Forge",             T_018,    0,   0,   0 },
  {    43,     11, 95,  8, 11, 18,"The Earth Wound",             L_030,    0,   0,   0 },
  {    56,     11, 96, 92, 11, 22,"The Gates of Hell",            1025,    0,   0,   0 },
  {    57,     11, 13, 88, 11, 23,"Throne of the Gods",          L_031,    0,   0,   0 },
  {    48,     11, 45, 61, 11, 19,"The caves of Lone Peak",      T_019,    0,   0,   0 },
  {    40,     11, 34, 40, 11, 17,"The Cave of Souls",           L_032,    0,   0,   0 },
  {    49,     11, 29,  9, 11, 19,"The cave of Wisps",           L_033,    0,   0,   0 },
  {    59,     11, 64, 29, 11, 25,"The Cave of Dragons",         L_034,    0,   0,   0 },

  {    60,     12, 23, 56, 11, 25,"Lost Valley of the Unicorns", L_035,    0,   0,   0 },

  {     0,     99,99,99,99,99,"END",99, 0,   0,   0 }
  };

#else

extern REGION_REC regions[];
extern LINK_REC links[];
extern SHOP_REC shops[];
extern TR_SHIP_REC tr_ships[];
extern FORSALE forsale[];

#endif

