#define S_GRASS                 1
#define S_DNSTAIR              24
#define S_UPSTAIR              25
#define S_SALE                247
#define S_SOLD                248
#define FINAL_BOSS            "Eshter"
#define FINAL_GOLD_REWARD     50000
#define SPELL_SCROLL           498
#define ITEM_SUNSTONE          522
#define ITEM_RECIPE            639

#ifdef MAIN

/* Dedicated Sprite Codes */

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
    {  17,  9, 72, 16, 54, 62, "Radon Crafters" },
    {  18,  9, 72, 16, 22, 56, "Radon Spells" },
    {  19,  9, 72, 16, 55, 56, "Radon Recipes" },
    /* Marduk */
    {   0,  7, 32, 19, 28, 11, "The Marduk Edge" },
    {   1,  7, 32, 19, 28, 27, "Marduk Armour" },
    {   2,  7, 32, 19, 19, 11, "Marduk Potions" },
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
    {  17,  7, 32, 19, 25, 21, "Marduk Crafting Supply" },
    {  18,  7, 32, 19, 39, 11, "Marduk Spellcasting" },
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
    {  15,  2, 63, 76, 12,  3, "Enchanted Creatures" },
    {  17,  2, 63, 76, 94, 78, "The Crafter's Aid" },
    {  18,  2, 63, 76, 71, 19, "Nina's Spells" },
    /* Generic Cities */
    /* Goldville */
    {   0,  5, 33, 28, 42, 48, "The Golden Defense" },
    {   1,  5, 33, 28, 59, 48, "Goldville Defense Co." },
    {   2,  5, 33, 28, 42, 37, "Potion Brewers of Goldville" },
    {   3,  5, 33, 28, 70, 26, "Goldville Gems" },
    {   4,  5, 33, 28, 59, 37, "The Scroll Shop" },
    {   5,  5, 33, 28, 69, 37, "Goldville Clothiers" },
    {   6,  5, 33, 28, 50, 37, "The Magician's Den" },
    {   7,  5, 33, 28, 90, 25, "The Goldville Library" },
    {   8,  5, 33, 28, 53, 17, "Goldville Tavern" },
    {   9,  5, 33, 28, 90, 47, "Goldville College" },
    {  10,  5, 33, 28, 65, 17, "Goldville Travel" },
    {  11,  5, 33, 28, 30, 17, "The Miner's Store" },
    {  12,  5, 33, 28, 30, 26, "The Gold Mine" },
    {  13,  5, 33, 28, 34, 61, "The Druidic Temple" },
    {  14,  5, 33, 28, 44,  3, "The Cavalier's Guild" },
    {  16,  5, 33, 28, 31, 51, "Goldville Savings Bank" },
    {  18,  5, 33, 28, 52, 67, "The Complete Spellcaster" },
    /* Capetown */
    {   0,  9, 61, 45, 42, 48, "Capetown Weaponry" },
    {   1,  9, 61, 45, 59, 48, "The Defensive Stance" },
    {   2,  9, 61, 45, 42, 37, "Potions Etc." },
    {   3,  9, 61, 45, 70, 26, "Capetown Jewels" },
    {   4,  9, 61, 45, 59, 37, "Dragon Books" },
    {   5,  9, 61, 45, 69, 37, "The Magic Cloak" },
    {   6,  9, 61, 45, 50, 37, "The Enchantress" },
    {   7,  9, 61, 45, 90, 25, "The Capetown Library" },
    {   8,  9, 61, 45, 53, 17, "The Traveller's Inn" },
    {   9,  9, 61, 45, 90, 47, "Capetown Institute" },
    {  10,  9, 61, 45, 65, 17, "Capetown Travel" },
    {  11,  9, 61, 45, 30, 17, "The Traveller's Supply" },
    {  12,  9, 61, 45, 30, 26, "Lake Imports" },
    {  13,  9, 61, 45, 34, 61, "The Druidic Temple" },
    {  14,  9, 61, 45, 44,  3, "The Cavalier's Guild" },
    {  16,  9, 61, 45, 31, 51, "Capetown Bank" },
    {  18,  9, 61, 45, 52, 67, "Lakeside Spells" },
    /* New South Radon */
    {   0,  9, 49, 64, 42, 48, "The REAL Defense" },
    {   1,  9, 49, 64, 59, 48, "Protection Co." },
    {   2,  9, 49, 64, 42, 37, "Radon Valley Potions" },
    {   3,  9, 49, 64, 70, 26, "The Sparkling Diamond" },
    {   4,  9, 49, 64, 59, 37, "The Sage's Delight" },
    {   5,  9, 49, 64, 69, 37, "Cloaks and Things" },
    {   6,  9, 49, 64, 50, 37, "The Magician's Fancy" },
    {   7,  9, 49, 64, 90, 25, "The Lore Archives" },
    {   8,  9, 49, 64, 53, 17, "The Happy Rest" },
    {   9,  9, 49, 64, 90, 47, "South Radon U." },
    {  10,  9, 49, 64, 65, 17, "Adventurer's Travel" },
    {  11,  9, 49, 64, 30, 17, "The Dungeneer's Needs" },
    {  12,  9, 49, 64, 30, 26, "Dragon Treasures" },
    {  13,  9, 49, 64, 34, 61, "The Druidic Temple" },
    {  14,  9, 49, 64, 44,  3, "The Cavalier's Guild" },
    {  16,  9, 49, 64, 31, 51, "South Radon Bank" },
    {  18,  9, 49, 64, 52, 67, "Southern Spellcasting" },
    /* Talgon */
    {   0, 10, 57, 53, 42, 48, "Talgon Weapons Supply" },
    {   1, 10, 57, 53, 59, 48, "Dragon Defense Co." },
    {   2, 10, 57, 53, 42, 37, "Talgon Potion Supply" },
    {   3, 10, 57, 53, 70, 26, "Talgon Jewel Works" },
    {   4, 10, 57, 53, 59, 37, "The Wizard's Scribe" },
    {   5, 10, 57, 53, 69, 37, "Talgon Fashions" },
    {   6, 10, 57, 53, 50, 37, "The Wizardess" },
    {   7, 10, 57, 53, 90, 25, "The Talgon General Library" },
    {   8, 10, 57, 53, 53, 17, "The Talgon Inn" },
    {   9, 10, 57, 53, 90, 47, "Talgon U." },
    {  10, 10, 57, 53, 65, 17, "Talgon Travel Agency" },
    {  11, 10, 57, 53, 30, 17, "Talgon Supply Co." },
    {  12, 10, 57, 53, 30, 26, "Halkanar Curios" },
    {  13, 10, 57, 53, 34, 61, "The Druidic Temple" },
    {  14, 10, 57, 53, 44,  3, "The Cavalier's Guild" },
    {  16, 10, 57, 53, 31, 51, "Talgon Savings" },
    {  18, 10, 57, 53, 52, 67, "The Wizard's Tools" },
    /* New Solat */
    {   0,  3, 44, 49, 42, 48, "Ye Olde Weapons Shoppe" },
    {   1,  3, 44, 49, 59, 48, "Armour Plus" },
    {   2,  3, 44, 49, 42, 37, "Sorcerer's Potions" },
    {   3,  3, 44, 49, 70, 26, "Solat Gems" },
    {   4,  3, 44, 49, 59, 37, "The Wizard's Scroll" },
    {   5,  3, 44, 49, 69, 37, "Solat Clothing" },
    {   6,  3, 44, 49, 50, 37, "The Olde Spell" },
    {   7,  3, 44, 49, 90, 25, "Solat Information Center" },
    {   8,  3, 44, 49, 53, 17, "New Solat Pub" },
    {   9,  3, 44, 49, 90, 47, "Solat Training Facility" },
    {  10,  3, 44, 49, 65, 17, "Ye Olde Travel Company" },
    {  11,  3, 44, 49, 30, 17, "The Dragon Supply Co." },
    {  12,  3, 44, 49, 30, 26, "Solat Relics" },
    {  13,  3, 44, 49, 34, 61, "The Druidic Temple" },
    {  14,  3, 44, 49, 44,  3, "The Cavalier's Guild" },
    {  18,  3, 44, 49, 52, 67, "The Modern Spellcaster" },
    /* Talfharin */
    {   0,  1, 46, 49, 42, 48, "The Sharp Edge" },
    {   1,  1, 46, 49, 59, 48, "River Defense Co." },
    {   2,  1, 46, 49, 42, 37, "Alaras Concoctions" },
    {   3,  1, 46, 49, 70, 26, "The Adamantite Works" },
    {   4,  1, 46, 49, 59, 37, "Halkanar Books" },
    {   5,  1, 46, 49, 69, 37, "The Cloak Merchant" },
    {   6,  1, 46, 49, 50, 37, "Unicorn Magic" },
    {   7,  1, 46, 49, 90, 25, "The Records Archive" },
    {   8,  1, 46, 49, 53, 17, "The Mermaid Inn" },
    {   9,  1, 46, 49, 90, 47, "Northwest U." },
    {  10,  1, 46, 49, 65, 17, "Talfharin Travel" },
    {  11,  1, 46, 49, 30, 17, "The Adventurer's Supply Co." },
    {  12,  1, 46, 49, 30, 26, "River Imports" },
    {  13,  1, 46, 49, 34, 61, "The Druidic Temple" },
    {  14,  1, 46, 49, 44,  3, "The Cavalier's Guild" },
    {  18,  1, 46, 49, 52, 67, "Halkanar Spells" },


    {   0,  0,  0, 0,  42, 48, "Village Weapons" },
    {   1,  0,  0, 0,  58, 48, "Village Armour" },
    {   8,  0,  0, 0,  49, 56, "Village Inn" },
    {  11,  0,  0, 0,  50, 41, "Village Supply" },

    { 999,  0,  0,  0,  0,  0, "EOL" }
  };

/*    citynum region rx ry */
CITY_NUMBER cities[] = {
    /* Radon */
    {   1,  9, 72, 16 },
    /* Marduk */
    {   2,  7, 32, 19 },
    /* Nichorville */
    {   3,  2, 63, 76 },
    /* Goldville */
    {   4,  5, 33, 28 },
    /* Capetown */
    {   5,  9, 61, 45 },
    /* Talgon */
    {   6, 10, 57, 53 },
    /* New Solat */
    {   7,  3, 44, 49 },
    /* Talfharin */
    {   8,  1, 46, 49 },
    /* New South Radon */
    {   9,  9, 49, 64 },
    /* End of list */
    { 999,  3, 44, 49 },
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
    {   2,  63, 76, 60, 72, 450000 },                   /* Nichorville */
    {   1,  46, 49, 18, 65, 200000 },                   /* Talfharin */
    {   3,  44, 49, 18, 65, 175000 },                   /* New Solat */
    {  10,  57, 53, 18, 65, 160000 },                   /* Talgon */
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
#define T_162       162
#define T_163       163
#define T_164       164
#define T_165       165
#define T_166       166
#define T_167       167
#define T_168       168
#define T_169       169
#define T_170       170
#define T_171       171
#define T_172       172
#define T_173       173
#define T_174       174
#define T_175       175
#define T_176       176
#define T_177       177
#define T_178       178
#define T_179       179
#define T_180       180
#define T_181       181
#define T_182       182
#define T_183       183
#define T_184       184
#define T_185       185
#define T_186       186
#define T_187       187
#define T_188       188
#define T_189       189
#define T_190       190
#define T_191       191
#define T_192       192
#define T_193       193
#define T_194       194
#define T_195       195
#define T_196       196
#define T_197       197
#define T_198       198
#define T_199       199
#define T_200       200
#define T_201       201
#define T_202       202
#define T_203       203
#define T_204       204
#define T_205       205
#define T_206       206
#define T_207       207
#define T_208       208
#define T_209       209
#define T_210       210
#define T_211       211
#define T_212       212
#define T_213       213
#define T_214       214
#define T_215       215
#define T_216       216
#define T_217       217
#define T_218       218
#define T_219       219
#define T_220       220
#define T_221       221
#define T_222       222
#define T_223       223
#define T_224       224
#define T_225       225
#define T_226       226
#define T_227       227
#define T_228       228
#define T_229       229
#define T_230       230
#define T_231       231
#define T_232       232
#define T_233       233
#define T_234       234
#define T_235       235
#define T_236       236
#define T_237       237
#define T_238       238
#define T_239       239
#define T_240       240
#define T_241       241
#define T_242       242
#define T_243       243
#define T_244       244
#define T_245       245
#define T_246       246
#define T_247       247
#define T_248       248
#define T_249       249
#define T_250       250
#define T_251       251
#define T_252       252
#define T_253       253
#define T_254       254
#define T_255       255
#define T_256       256
#define T_257       257
#define T_258       258
#define T_259       259
#define T_260       260
#define T_261       261
#define T_262       262
#define T_263       263
#define T_264       264
#define T_265       265
#define T_266       266
#define T_267       267
#define T_268       268
#define T_269       269
#define T_270       270
#define T_271       271
#define T_272       272
#define T_273       273
#define T_274       274
#define T_275       275
#define T_276       276
#define T_277       277
#define T_278       278
#define T_279       279
#define T_280       280
#define T_281       281
#define T_282       282
#define T_283       283
#define T_284       284
#define T_285       285
#define T_286       286
#define T_287       287
#define T_288       288
#define T_289       289
#define T_290       290
#define T_291       291
#define T_292       292
#define T_293       293
#define T_294       294
#define T_295       295
#define T_296       296
#define T_297       297
#define T_298       298
#define T_299       299
#define T_300       300
#define T_301       301
#define T_302       302
#define T_303       303
#define T_304       304
#define T_305       305
#define T_306       306
#define T_307       307
#define T_308       308
#define T_309       309
#define T_310       310
#define T_311       311
#define T_312       312
#define T_313       313
#define T_314       314
#define T_315       315
#define T_316       316
#define T_317       317
#define T_318       318
#define T_319       319
#define T_320       320
#define T_321       321
#define T_322       322
#define T_323       323
#define T_324       324
#define T_325       325
#define T_326       326
#define T_327       327
#define T_328       328
#define T_329       329
#define T_330       330
#define T_331       331
#define T_332       332
#define T_333       333
#define T_334       334
#define T_335       335
#define T_336       336
#define T_337       337
#define T_338       338
#define T_339       339
#define T_340       340
#define T_341       341
#define T_342       342
#define T_343       343
#define T_344       344
#define T_345       345
#define T_346       346
#define T_347       347
#define T_348       348
#define T_349       349
#define T_350       350
#define T_351       351
#define T_352       352
#define T_353       353
#define T_354       354
#define T_355       355
#define T_356       356
#define T_357       357
#define T_358       358
#define T_359       359
#define T_360       360
#define T_361       361
#define T_362       362
#define T_363       363
#define T_364       364
#define T_365       365
#define T_366       366
#define T_367       367
#define T_368       368
#define T_369       369
#define T_370       370
#define T_371       371
#define T_372       372
#define T_373       373
#define T_374       374
#define T_375       375
#define T_376       376
#define T_377       377
#define T_378       378
#define T_379       379
#define T_380       380
#define T_381       381
#define T_382       382
#define T_383       383
#define T_384       384
#define T_385       385
#define T_386       386
#define T_387       387
#define T_388       388
#define T_389       389
#define T_390       390
#define T_391       391
#define T_392       392
#define T_393       393
#define T_394       394
#define T_395       395
#define T_396       396
#define T_397       397
#define T_398       398
#define T_399       399
#define T_400       400
#define T_401       401
#define T_402       402
#define T_403       403
#define T_404       404
#define T_405       405
#define T_406       406
#define T_407       407
#define T_408       408
#define T_409       409
#define T_410       410
#define T_411       411
#define T_412       412
#define T_413       413
#define T_414       414
#define T_415       415
#define T_416       416
#define T_417       417
#define T_418       418
#define T_419       419
#define T_420       420
#define T_421       421
#define T_422       422
#define T_423       423
#define T_424       424
#define T_425       425
#define T_426       426
#define T_427       427
#define T_428       428
#define T_429       429
#define T_430       430
#define T_431       431
#define T_432       432
#define T_433       433
#define T_434       434
#define T_435       435
#define T_436       436
#define T_437       437
#define T_438       438
#define T_439       439
#define T_440       440
#define T_441       441
#define T_442       442
#define T_443       443
#define T_444       444
#define T_445       445
#define T_446       446
#define T_447       447
#define T_448       448
#define T_449       449
#define T_450       450
#define T_451       451
#define T_452       452
#define T_453       453
#define T_454       454
#define T_455       455
#define T_456       456
#define T_457       457
#define T_458       458
#define T_459       459
#define T_460       460
#define T_461       461
#define T_462       462
#define T_463       463
#define T_464       464
#define T_465       465
#define T_466       466
#define T_467       467
#define T_468       468
#define T_469       469
#define T_470       470
#define T_471       471
#define T_472       472
#define T_473       473
#define T_474       474
#define T_475       475
#define T_476       476
#define T_477       477
#define T_478       478
#define T_479       479
#define T_480       480
#define T_481       481
#define T_482       482
#define T_483       483
#define T_484       484
#define T_485       485
#define T_486       486
#define T_487       487
#define T_488       488
#define T_489       489
#define T_490       490
#define T_491       491
#define T_492       492
#define T_493       493
#define T_494       494
#define T_495       495
#define T_496       496
#define T_497       497
#define T_498       498
#define T_499       499
#define T_500       500
#define T_501       501
#define T_502       502
#define T_503       503
#define T_504       504
#define T_505       505
#define T_506       506
#define T_507       507
#define T_508       508
#define T_509       509
#define T_510       510
#define T_511       511
#define T_512       512
#define T_513       513
#define T_514       514
#define T_515       515
#define T_516       516
#define T_517       517
#define T_518       518
#define T_519       519
#define T_520       520
#define T_521       521
#define T_522       522
#define T_523       523
#define T_524       524
#define T_525       525
#define T_526       526
#define T_527       527
#define T_528       528
#define T_529       529
#define T_530       530
#define T_531       531
#define T_532       532
#define T_533       533
#define T_534       534
#define T_535       535
#define T_536       536
#define T_537       537
#define T_538       538
#define T_539       539
#define T_540       540
#define T_541       541
#define T_542       542
#define T_543       543
#define T_544       544
#define T_545       545
#define T_546       546
#define T_547       547
#define T_548       548
#define T_549       549
#define T_550       550
#define T_551       551
#define T_552       552
#define T_553       553
#define T_554       554
#define T_555       555
#define T_556       556
#define T_557       557
#define T_558       558
#define T_559       559
#define T_560       560
#define T_561       561
#define T_562       562
#define T_563       563
#define T_564       564
#define T_565       565
#define T_566       566
#define T_567       567
#define T_568       568
#define T_569       569
#define T_570       570
#define T_571       571
#define T_572       572
#define T_573       573
#define T_574       574
#define T_575       575
#define T_576       576
#define T_577       577
#define T_578       578
#define T_579       579
#define T_580       580
#define T_581       581
#define T_582       582
#define T_583       583
#define T_584       584
#define T_585       585
#define T_586       586
#define T_587       587
#define T_588       588
#define T_589       589
#define T_590       590
#define T_591       591
#define T_592       592
#define T_593       593
#define T_594       594
#define T_595       595
#define T_596       596
#define T_597       597
#define T_598       598
#define T_599       599
#define T_600       600
#define T_601       601
#define T_602       602
#define T_603       603
#define T_604       604
#define T_605       605
#define T_606       606
#define T_607       607
#define T_608       608
#define T_609       609
#define T_610       610
#define T_611       611
#define T_612       612
#define T_613       613
#define T_614       614
#define T_615       615
#define T_616       616
#define T_617       617
#define T_618       618
#define T_619       619
#define T_620       620
#define T_621       621
#define T_622       622
#define T_623       623
#define T_624       624
#define T_625       625
#define T_626       626
#define T_627       627
#define T_628       628
#define T_629       629
#define T_630       630
#define T_631       631
#define T_632       632
#define T_633       633
#define T_634       634
#define T_635       635
#define T_636       636
#define T_637       637
#define T_638       638
#define T_639       639
#define T_640       640
#define T_641       641
#define T_642       642
#define T_643       643
#define T_644       644
#define T_645       645
#define T_646       646
#define T_647       647
#define T_648       648
#define T_649       649
#define T_650       650
#define T_651       651
#define T_652       652
#define T_653       653
#define T_654       654
#define T_655       655
#define T_656       656
#define T_657       657
#define T_658       658
#define T_659       659
#define T_660       660
#define T_661       661
#define T_662       662
#define T_663       663
#define T_664       664
#define T_665       665

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
/*  quest  region   x   y typ dif  name                       treasure  prem   sx   sy boss adds    # */
LINK_REC links[] = {
  {    14,      1, 27, 75, 11,  8,"Temple of the Forest",        L_001,    0,   0,   0,  31,  32,   2 },
  {    31,      1, 25, 29, 11, 15,"Horror Point",                T_521,    0,   0,   0,  33,  33,   1 },
  {    44,      1, 73, 24, 11, 19,"Ruins of Castle Caldnar",     T_001,    0,   0,   0,  34,  35,   2 },
  {    24,      1, 81, 43, 11, 13,"Ruins of Alukrahn",           T_002,    0,   0,   0,   9,  36,   3 },
  {     0,      1, 46, 49,  5, 14,"Talfharin",                       0,    0,  50,   3,   0,   0,   0 },

  {    15,      2, 32, 55, 11,  8,"Temple of the North",         L_003,    0,   0,   0,  37,  14,   2 },
  {    16,      2, 45, 76, 11,  9,"Stronghold of the Orcs",      L_004,    0,   0,   0,  41,  42,   2 },
  {    12,      2, 17, 86, 11,  7,"Ruins of Aljan",              L_014,    0,   0,   0,  38,  39,   2 },
  {    27,      2, 32, 28, 11, 14,"Castle Alakahri",             T_003,    0,   0,   0,  33,  40,   2 },
  {     0,      2, 63, 76,  5, 17,"Nichorville",                     0, 2500,  50,   3,   0,   0,   0 },

  {    37,      3, 27, 22, 11, 17,"Solat",                       T_004,    0,   0,   0,  35,  40,   2 },
  {    58,      3, 50, 28, 11, 25,"Ruins of Castle Tralin",      T_005,    0,   0,   0,  48,  35,   4 },
  {    50,      3, 80, 24, 11, 20,"The Den of the Dragon",       L_015,    0,   0,   0,  47,   8,   4 },
  {    17,      3, 67, 91, 11, 10,"Isle of the Dead",            L_005,    0,   0,   0,  43,  44,   2 },
  {    21,      3, 14, 61, 11, 12,"The Haunted isle",            L_006,    0,   0,   0,  45,  46,   2 },
  {    25,      3, 85, 61, 11, 13,"Temple of the Water",         L_007,    0,   0,   0,  19,  19,   2 },
  {     0,      3, 44, 49,  5, 14,"New Solat",                       0,    0,  50,   3,   0,   0,   0 },

  {    26,      4, 68, 55, 11, 13,"The Great Swamp",             L_008,    0,   0,   0,  49,  36,   2 },
  {    32,      4, 56, 71, 11, 15,"The Trolls Den",              L_009,    0,   0,   0,  53,  54,   2 },
  {    38,      4, 85, 79, 11, 17,"Lamia Point",                 L_010,    0,   0,   0,  51,  52,   4 },
  {    35,      4, 60, 16, 11, 16,"The Olde Forest",             L_011,    0,   0,   0,  50,  21,   2 },

  {     4,      5, 30, 30, 11,  3,"The Mines of the Desert",     L_036,    0,   0,   0,  29,  30,   2 },
  {     7,      5, 48, 39, 11,  5,"Temple of the Crescent",      L_012,    0,   0,   0,  12,  11,   2 },
  {    29,      5, 25, 80, 11, 15,"Areth Knoll",                 T_006,    0,   0,   0,  21,  19,   2 },
  {     5,      5, 48, 88, 11,  4,"Temple of the Sun",           L_013,    0,   0,   0,  27,  28,   1 },
  {     0,      5, 33, 28,  5, 14,"Goldville",                       0,    0,  50,   3,   0,   0,   0 },

  {     9,      6, 93, 98, 11,  6,"Den of the Beast",            L_014,    0,   0,   0,  13,  62,   2 },
  {    30,      6, 75, 83, 11, 15,"Arath Ma Kon",                T_007,    0,   0,   0,  65,  66,   2 },
  {    22,      6, 33, 81, 11, 12,"Algamar Ruins",               L_015,    0,   0,   0,  45,  46,   3 },
  {    19,      6, 78, 68, 11, 11,"Hall of the Kobold Lords",    L_016,    0,   0,   0,  67,  68,   3 },
  {     8,      6, 26, 62, 11,  5,"Temple of the Dark",          L_017,    0,   0,   0,  63,  25,   2 },
  {    34,      6, 71, 46, 11, 16,"Ruins of Caldnar",            T_008,    0,   0,   0,  69,  65,   2 },
  {    23,      6, 23, 41, 11, 12,"Lost Mine of the Dwarves",    T_009,    0,   0,   0,  70,  71,   2 },
  {    11,      6, 75, 32, 11,  7,"Temple of the Moon",          L_018,    0,   0,   0,  64,  39,   2 },
  {    41,      6, 16, 28, 11, 18,"The Den of Horror",           T_010,    0,   0,   0,   0,   0,   0 },

  {    33,      7, 31, 79, 11, 15,"Isle of Will-o-Wisps",        L_019,    0,   0,   0,  65,  66,   2 },
  {    39,      7, 10, 50, 11, 17,"Hall of the Giants",          L_020,    0,   0,   0,  78,  57,   3 },
  {    51,      7, 59, 65, 11, 20,"The Black Hole",              T_011,    0,   0,   0,  75,  46,   4 },
  {    36,      7, 89, 69, 11, 16,"The Lost Tomb",               L_021,    0,   0,   0,  69,  21,   2 },
  {    54,      7, 44, 79, 11, 21,"The Tomb of Caldnar",         T_012,    0,   0,   0,  77,  65,   2 },
  {    45,      7, 84, 80, 11, 19,"Cave of Enchantment",         L_022,    0,   0,   0,  73,  74,   3 },
  {    42,      7, 80, 90, 11, 18,"The Valley of Fear",          L_023,    0,   0,   0,  34,  72,   3 },
  {     0,      7, 32, 19,  5, 16,"Marduk",                          0,    0,   2,  50,   0,   0,   0 },

  {    53,      8, 55, 40, 11, 20,"The Ruins of Larkon",         T_013,    0,   0,   0,  73,  74,   3 },
  {    52,      8, 51, 66, 11, 20,"Valley of the Gods",          T_014,    0,   0,   0,  73,  73,   4 },
  {    46,      8, 20, 71, 11, 19,"Valley of the Giants",        T_015,    0,   0,   0,  73,  74,   2 },
  {    47,      8, 12, 84, 11, 19,"Valley of the Titans",        T_016,    0,   0,   0,  73,  73,   2 },

  {     1,      9, 72,  8, 11,  1,"Radon Mine",                  T_061,    0,   0,   0,  22,  23,   2 },
  {     3,      9, 62, 55, 11,  3,"Radon Isle",                  T_021,    0,   0,   0,  25,  26,   2 },
  {     2,      9, 25, 64, 11,  2,"Platinum Mine",               T_020,    0,   0,   0,  24,  22,   1 },
  {     0,      9, 72, 16,  5, 13,"Radon",                           0,    0,  50,   3,   0,   0,   0 },
  {     0,      9, 61, 45,  5, 14,"Capetown",                        0,    0,  50,   3,   0,   0,   0 },
  {     0,      9, 49, 64,  5, 14,"New South Radon",                 0,    0,  50,   3,   0,   0,   0 },

  {     6,     10, 76, 18, 11,  4,"The Goblin Caves",            T_453,    0,   0,   0,  55,  56,   2 },
  {    13,     10, 80,  6, 11,  8,"Calton Peak",                 L_025,    0,   0,   0,  15,  13,   2 },
  {    20,     10,  9, 54, 11, 12,"The Lost Valley",             L_026,    0,   0,   0,  57,  58,   3 },
  {    18,     10, 10,  5, 11, 10,"Gargoyle Peak",               L_027,    0,   0,   0,  59,  60,   2 },
  {    10,     10, 90, 75, 11,  7,"Temple of the South",         L_028,    0,   0,   0,  32,  61,   2 },
  {    28,     10, 49, 81, 11, 15,"The Valley of Blood",         L_029,    0,   0,   0,  53,  33,   2 },
  {     0,     10, 57, 53,  5, 14,"Talgon",                          0,    0,  50,   3,   0,   0,   0 },

  {    55,     11, 68, 61, 11, 21,"Elanthers Forge",             T_018,    0,   0,   0,  80,  65,   4 },
  {    43,     11, 95,  8, 11, 18,"The Earth Wound",             L_030,    0,   0,   0,  34,  72,   3 },
  {    56,     11, 96, 92, 11, 22,"The Gates of Hell",           L_025,    0,   0,   0,  75,  45,   4 },
  {    57,     11, 13, 88, 11, 23,"Throne of the Gods",          L_031,    0,   0,   0,  84,  83,   4 },
  {    48,     11, 45, 61, 11, 19,"The caves of Lone Peak",      T_019,    0,   0,   0,  82,  81,   3 },
  {    40,     11, 34, 40, 11, 17,"The Cave of Souls",           L_032,    0,   0,   0,  35,  65,   3 },
  {    49,     11, 29,  9, 11, 19,"The cave of Wisps",           L_033,    0,   0,   0,  85,  86,   2 },
  {    59,     11, 64, 29, 11, 25,"The Cave of Dragons",         L_034,    0,   0,   0,  87,  88,   2 },

  {    60,     12, 23, 56, 11, 25,"Lost Valley of the Unicorns", L_035,    0,   0,   0,   0,   0,   0 },

  {     0,     99,99,99,99,99,"END",99, 0,   0,   0,   0,   0,   0 }
  };

/* Special maps:
   13 - Radon
   14 - Generic City
   15 - Village
   16 - Marduk
   17 - Nichorville
   18 - Eshter
*/

COMPASS compass_points[] = {
  { 44, 1 },         /* Ruins of Castle Caldnar */
  { 31, 2 },         /* Horror Point */
  { 14, 3 },         /* Temple of the Forest */
  { 24, 4 },         /* Ruins of Alukrahn */
  { 27, 5 },         /* Castle Alakahri */
  { 15, 6 },         /* Temple of the North */
  { 12, 7 },         /* Ruins of Aljan */
  { 16, 8 },         /* Stronghold of the Orcs */
  { 37, 9 },         /* Ruins of Solat */
  { 58, 10 },        /* Ruins of Castle Tralin */
  { 50, 11 },        /* Den of the Dragon */
  { 17, 12 },        /* Isle of the Dead */
  { 21, 13 },        /* The Haunted Isle */
  { 25, 14 },        /* Temple of the Water */
  { 26, 15 },        /* The Great Swamp */
  { 35, 16 },        /* The Olde Forest */
  { 38, 17 },        /* Lamia Point */
  { 32, 18 },        /* The Trolls Den */
  {  7, 19 },        /* Temple of the Crescent */
  {  5, 20 },        /* Temple of the Sun */
  {  4, 21 },        /* Mines of the Desert */
  { 29, 22 },        /* Areth Knoll */
  { 41, 23 },        /* Den of Horror */
  {  8, 24 },        /* Temple of the Dark */
  { 22, 25 },        /* Algamar Ruins */
  { 23, 26 },        /* The Lost Mine of the Dwarves */
  {  9, 27 },        /* Den of the Beast */
  { 30, 28 },        /* Arath Ma Kon */
  { 19, 29 },        /* Hall of the Kobold Lords */
  { 34, 30 },        /* Ruins of Caldnar */
  { 11, 31 },        /* Temple of the Moon */
  { 33, 32 },        /* Isle of the Will-o-Wisps */
  { 55, 33 },        /* The Tomb of Caldnar */
  { 51, 34 },        /* The Black Hole */
  { 39, 35 },        /* Hall of the Giants */
  { 36, 36 },        /* The Lost Tomb */
  { 45, 37 },        /* The Cave of Enchantment */
  { 42, 38 },        /* The Valley of Fear */
  { 52, 39 },        /* Valley of the Gods */
  { 46, 40 },        /* Valley of the Giants */
  { 47, 41 },        /* Valley of the Titans */
  { 53, 42 },        /* Ruins of Larkon */
  {  1, 43 },        /* Radon Mines */
  {  2, 44 },        /* Platinum Mines */
  {  3, 45 },        /* Radon Isle */
  { 18, 46 },        /* Gargoyle Peak */
  { 13, 47 },        /* Calton Peak */
  {  6, 48 },        /* Goblin Caves */
  { 20, 49 },        /* The Lost Valley */
  { 10, 50 },        /* Temple of the South */
  { 28, 51 },        /* The Valley of Blood */
  { 59, 52 },        /* The Cave of Dragons */
  { 40, 53 },        /* The Cave of Souls */
  { 49, 54 },        /* The Cave of Wisps */
  { 56, 55 },        /* The Gates of Hell */
  { 57, 56 },        /* Throne of the Gods */
  { 43, 57 },        /* The Earth Wound */
  { 48, 58 },        /* The Caves of Lone Peak */
  { 54, 59 },        /* Elanther's Forge */
  { 99, 99 },
  };

PREDEF_MAP predef_maps[] = {
  {  12, 80, 78, 4, 18 },
  };

char* end_text[] = {
  "  Congratulations!!!! You have defeated Eshter and freed the Unicorns!!",
  "  After Eshter's defeat the power of the unicorns was capable of driving",
  "  the rest of the evil out of this realm.  consequently the unicorns decided",
  "  to remain in this realm where they would be safe from further malice",
  "  against htem.  For their gratitude for rescuing them, the unicorns have",
  "  given you 50,000 gold pieces plus free travel back through the Gateway",
  "  to your home world.",
  " ",
  " ",
  "_END_",
  };

HUNTING_ITEMS hunting_items[] = {
  { ITEM_SRATIONS, 100000 },      /* Standard Rations    */
  {           640,  10000 },      /* Aloe Vera           */
  {           641,  10000 },      /* Chamomile           */
  {           642,  10000 },      /* Clove               */
  {           643,  10000 },      /* Ginger              */
  {           644,  10000 },      /* Ginseng             */
  {           645,  10000 },      /* Juniper             */
  {           646,   2000 },      /* Lavender            */
  {           647,    500 },      /* Milk Thistle        */
  {           648,  10000 },      /* Primrose            */
  {           649,  10000 },      /* Saffron             */
  {           650,  10000 },      /* Sage                */
  {           651,  10000 },      /* Valerian            */
  {           652,  10000 },      /* Witch Hazel         */
  {           653,   1000 },      /* Rosemary            */
  {           654,    250 },      /* Fennel              */
  {            66,   2000 },      /* Copper Ore          */
  {           528,   1000 },      /* Iron Ore            */
  {            64,    500 },      /* Silver Ore          */
  {            62,    250 },      /* Gold Ore            */
  {            67,    125 },      /* Mithril Ore         */
  {            31,   5000 },      /* Wood                */
  {            73,   5000 },      /* Water               */
  {          9999, 999000 },
  };

#else

extern REGION_REC regions[];
extern LINK_REC links[];
extern SHOP_REC shops[];
extern TR_SHIP_REC tr_ships[];
extern FORSALE forsale[];
extern char* end_text[];
extern PREDEF_MAP predef_maps[];
extern COMPASS compass_points[];
extern CITY_NUMBER cities[];
extern HUNTING_ITEMS hunting_items[];

#endif

