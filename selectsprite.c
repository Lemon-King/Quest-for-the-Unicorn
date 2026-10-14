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
#include "unicorn.xpm"

char** select_sprite(int n) {
#ifdef DEBUG
  printf("%*sEntering: select_sprite(%d)\n",debug_tab,"",n);
  debug_tab += 2;
#endif
#ifdef DEBUG
  printf("%*sExiting: select_sprite()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  switch (n) {
    case 1:return sprite_1;                     /* Plains                */
    case 2:return sprite_2;                     /* Forest                */
    case 3:return sprite_3;                     /* Mountains             */
    case 4:return sprite_4;                     /* Water                 */
    case 5:return sprite_5;                     /* City                  */
    case 6:return sprite_6;                     /* Swamp                 */
    case 7:return sprite_7;                     /* Stone Floor           */
    case 8:return sprite_8;                     /* Desert                */
    case 9:return sprite_9;                     /* Hills                 */
    case 10:return sprite_10;                   /* Darkness              */
    case 11:return sprite_11;                   /* Dungeon Entrance      */
    case 12:return sprite_12;                   /* Ship                  */
    case 13:return sprite_13;                   /* Ship                  */
    case 14:return sprite_14;                   /* Dock                  */
    case 15:return sprite_15;                   /* Wood Floor            */
    case 16:return sprite_16;                   /* Cactus                */
    case 17:return sprite_17;                   /* Village               */
    case 18:return sprite_18;                   /* Plains Rock           */
    case 19:return sprite_19;                   /* Mountain Pass         */
    case 20:return sprite_20;                   /* Tree                  */
    case 21:return sprite_21;                   /* Brick Wall            */
    case 22:return sprite_22;                   /* Closed Door           */
    case 23:return sprite_23;                   /* Open Door             */
    case 24:return sprite_24;                   /* Down Stairs           */
    case 25:return sprite_25;                   /* Up Stairs             */
    case 26:return sprite_26;                   /* Chair                 */
    case 27:return sprite_27;                   /* Table                 */
    case 28:return sprite_28;                   /* Merchant              */
    case 29:return sprite_29;                   /* Bed                   */
    case 30:return sprite_30;                   /* Shelves               */
    case 31:return sprite_31;                   /* Activated Gateway     */
    case 32:return sprite_32;                   /* Gateway               */
    case 33:return sprite_33;                   /* Locked Door           */
    case 34:return sprite_34;                   /* Player Mask           */
    case 35:return sprite_35;                   /* Player                */
    case 36:return sprite_36;                   /* Asleep                */
    case 37:return sprite_37;                   /* Sound                 */
    case 38:return sprite_38;                   /* Fire                  */
    case 39:return sprite_39;                   /* Water                 */
    case 40:return sprite_40;                   /* Trap                  */
    case 41:return sprite_41;                   /* Force Field           */
    case 42:return sprite_42;                   /* Phase Door            */
    case 43:return sprite_43;                   /* Torch (light)         */
    case 44:return sprite_44;                   /* Fire Protection?      */
    case 45:return sprite_45;                   /* Giant Strength        */
    case 46:return sprite_46;                   /* Poisoned              */
    case 47:return sprite_47;                   /* Shield (protection)   */
    case 48:return sprite_48;                   /* Ethereal              */
    case 49:return sprite_49;                   /* Less Ethereal         */
    case 50:return sprite_50;                   /* Hasted                */
    case 51:return sprite_51;                   /* Sword                 */
    case 52:return sprite_52;                   /* Pole Weapon           */
    case 53:return sprite_53;                   /* Bow                   */
    case 54:return sprite_54;                   /* Crossbow              */
    case 55:return sprite_55;                   /* Armour                */
    case 56:return sprite_56;                   /* Helm                  */
    case 57:return sprite_57;                   /* Shield                */
    case 58:return sprite_58;                   /* Scroll                */
    case 59:return sprite_59;                   /* Talisman              */
    case 60:return sprite_60;                   /* Aurafax               */
    case 61:return sprite_61;                   /* Red Potion            */
    case 62:return sprite_62;                   /* Blue Potion           */
    case 63:return sprite_63;                   /* Green Potion          */
    case 64:return sprite_64;                   /* Gray Potion           */
    case 65:return sprite_65;                   /* Yellow Potion         */
    case 66:return sprite_66;                   /* Brown Potion          */
    case 67:return sprite_67;                   /* White Potion          */
    case 68:return sprite_68;                   /* Light Gray Potion     */
    case 69:return sprite_69;                   /* Boots                 */
    case 70:return sprite_70;                   /* Necklace              */
    case 71:return sprite_71;                   /* Jewel                 */
    case 72:return sprite_72;                   /* Staff                 */
    case 73:return sprite_73;                   /* Robe                  */
    case 74:return sprite_74;                   /* Ring                  */
    case 75:return sprite_75;                   /* Crystal Ball          */
    case 76:return sprite_76;                   /* Horn                  */
    case 77:return sprite_77;                   /* Cube                  */
    case 78:return sprite_78;                   /* Book                  */
    case 79:return sprite_79;                   /* Chest                 */
    case 80:return sprite_80;                   /* Red Magic             */
    case 81:return sprite_81;                   /* Tardis                */
    case 82:return sprite_82;                   /* Excalibur             */
    case 83:return sprite_83;                   /* Light Saber           */
    case 84:return sprite_84;                   /* Torch                 */
    case 85:return sprite_85;                   /* Talning Rod           */
    case 86:return sprite_86;                   /* Phaser                */
    case 87:return sprite_87;                   /* Amulet of Yathun      */
    case 88:return sprite_88;                   /* Lore book             */
    case 89:return sprite_89;                   /* Television            */
    case 90:return sprite_90;                   /* Computer              */
    case 91:return sprite_91;                   /* Up Arrow              */
    case 92:return sprite_92;                   /* Down Arrow            */
    case 93:return sprite_93;                   /* Right Arrow           */
    case 94:return sprite_94;                   /* Left Arrow            */
    case 95:return sprite_95;                   /* Up-Right Arrow        */
    case 96:return sprite_96;                   /* Up-Left Arrow         */
    case 97:return sprite_97;                   /* Down-Right Arrow      */
    case 98:return sprite_98;                   /* Down-Left Arrow       */
    case 99:return sprite_99;                   /* Food                  */
    case 100:return sprite_100;                 /* Green Magic           */
    case 101:return sprite_101;                 /* Air Elemental         */
    case 102:return sprite_102;                 /* Ant                   */
    case 103:return sprite_103;                 /* Rat                   */
    case 104:return sprite_104;                 /* Bear                  */
    case 105:return sprite_105;                 /* Beholder              */
    case 106:return sprite_106;                 /* Black Blob            */
    case 107:return sprite_107;                 /* Green Blob            */
    case 108:return sprite_108;                 /* Roper                 */
    case 109:return sprite_109;                 /* Bulette               */
    case 110:return sprite_110;                 /* Centipede             */
    case 111:return sprite_111;                 /* Fire Elemental        */
    case 112:return sprite_112;                 /* Water Elemental       */
    case 113:return sprite_113;                 /* Earth Elemental       */
    case 114:return sprite_114;                 /* Efreet                */
    case 115:return sprite_115;                 /* Gargoyle              */
    case 116:return sprite_116;                 /* Gelatinous Cube       */
    case 117:return sprite_117;                 /* Griffen               */
    case 118:return sprite_118;                 /* Ghost                 */
    case 119:return sprite_119;                 /* Harpy                 */
    case 120:return sprite_120;                 /* Dog                   */
    case 121:return sprite_121;                 /* Dwarflike             */
    case 122:return sprite_122;                 /* Hydra                 */
    case 123:return sprite_123;                 /* Orc                   */
    case 124:return sprite_124;                 /* Lamia                 */
    case 125:return sprite_125;                 /* Skeleton              */
    case 126:return sprite_126;                 /* Lizard                */
    case 127:return sprite_127;                 /* Manticore             */
    case 128:return sprite_128;                 /* Medusa                */
    case 129:return sprite_129;                 /* Mind Flayer           */
    case 130:return sprite_130;                 /* Minataur              */
    case 131:return sprite_131;                 /* Horse                 */
    case 132:return sprite_132;                 /* Unicorn               */
    case 133:return sprite_133;                 /* Pegasus               */
    case 134:return sprite_134;                 /* Frog                  */
    case 135:return sprite_135;                 /* Giant                 */
    case 136:return sprite_136;                 /* Mummy                 */
    case 137:return sprite_137;                 /* Naga                  */
    case 138:return sprite_138;                 /* Nightmare             */
    case 139:return sprite_139;                 /* Nixie                 */
    case 140:return sprite_140;                 /* Sprite                */
    case 141:return sprite_141;                 /* Purple Worm           */
    case 142:return sprite_142;                 /* Scorpion              */
    case 143:return sprite_143;                 /* Snake                 */
    case 144:return sprite_144;                 /* Sphinx                */
    case 145:return sprite_145;                 /* Spider                */
    case 146:return sprite_146;                 /* Umber Hulk            */
    case 147:return sprite_147;                 /* Will-o-wisp           */
    case 148:return sprite_148;                 /* Centaur               */
    case 149:return sprite_149;                 /* Demogorgon            */
    case 150:return sprite_150;                 /* Balrog                */
    case 151:return sprite_151;                 /* Sucubus               */
    case 152:return sprite_152;                 /* Demon                 */
    case 153:return sprite_153;                 /* Black Dragon          */
    case 154:return sprite_154;                 /* Red Dragon            */
    case 155:return sprite_155;                 /* Green Dragon          */
    case 156:return sprite_156;                 /* White Dragon          */
    case 157:return sprite_157;                 /* Blue Dragon           */
    case 158:return sprite_158;                 /* Chromatic Dragon      */
    case 159:return sprite_159;                 /* Platinum Dragon       */
    case 160:return sprite_160;                 /* Dalek                 */
    case 161:return sprite_161;                 /* Female                */
    case 162:return sprite_162;                 /* Male                  */
    case 163:return sprite_163;                 /* Fighter               */
    case 164:return sprite_164;                 /* Cleric                */
    case 165:return sprite_165;                 /* Mage                  */
    case 166:return sprite_166;                 /* Dark Mage             */
    case 167:return sprite_167;                 /* Crown of Might        */
    case 168:return sprite_168;                 /* Scepter of Might      */
    case 169:return sprite_169;                 /* Orb of Might          */
    case 170:return sprite_170;                 /* Axe of the Dwarves    */
    case 171:return sprite_171;                 /* mask - not used       */
    case 172:return sprite_172;                 /* mask - not used       */
    case 173:return sprite_173;                 /* mask - not used       */
    case 174:return sprite_174;                 /* mask - not used       */
    case 175:return sprite_175;                 /* mask - not used       */
    case 176:return sprite_176;                 /* Desert Rock           */
    case 177:return sprite_177;                 /* Moutain Floor         */
    case 178:return sprite_178;                 /* Mountain Rock         */
    case 179:return sprite_179;                 /* Eshter                */
    case 180:return sprite_180;                 /* Unused???             */
    case 181:return sprite_181;                 /* Unused???             */
    case 182:return sprite_182;                 /* Unused???             */
    case 183:return sprite_183;                 /* Unused???             */
    case 184:return sprite_184;                 /* Unused???             */
    case 185:return sprite_185;                 /* Unused???             */
    case 186:return sprite_186;                 /* Unused???             */
    case 187:return sprite_187;                 /* Unused???             */
    case 188:return sprite_188;                 /* Unused???             */
    case 189:return sprite_189;                 /* Unused???             */
    case 190:return sprite_190;                 /* Unused???             */
    case 191:return sprite_191;                 /* Unused???             */
    case 192:return sprite_192;                 /* Unused???             */
    case 193:return sprite_193;                 /* Unused???             */
    case 194:return sprite_194;                 /* Unused???             */
    case 195:return sprite_195;                 /* Unused???             */
    case 196:return sprite_196;                 /* Unused???             */
    case 197:return sprite_197;                 /* Unused???             */
    case 198:return sprite_198;                 /* Unused???             */
    case 199:return sprite_199;                 /* Unused???             */
    case 200:return sprite_200;                 /* Unused???             */
    case 201:return sprite_201;                 /* Dagger                */
    case 202:return sprite_202;                 /* Trident               */
    case 203:return sprite_203;                 /* Ale                   */
    case 204:return sprite_204;                 /* Beer                  */
    case 205:return sprite_205;                 /* Pole Axe              */
    case 206:return sprite_206;                 /* Mead                  */
    case 207:return sprite_207;                 /* Spear                 */
    case 208:return sprite_208;                 /* Pike                  */
    case 209:return sprite_209;                 /* Javelin               */
    case 210:return sprite_210;                 /* Lance                 */
    case 211:return sprite_211;                 /* Hammer                */
    case 212:return sprite_212;                 /* Jar                   */
    case 213:return sprite_213;                 /* Apple                 */
    case 214:return sprite_214;                 /* Lemon                 */
    case 215:return sprite_215;                 /* ruby                 */
    case 216:return sprite_216;                 /* emerald              */
    case 217:return sprite_217;                 /* amethyst             */
    case 218:return sprite_218;                 /* diamond              */
    case 219:return sprite_219;                 /* pearl                */
    case 220:return sprite_220;                 /* black pearl          */
    case 221:return sprite_221;                 /* holy water           */
    case 222:return sprite_222;                 /* anvil                */
    case 223:return sprite_223;                 /* flail                */
    case 224:return sprite_224;                 /* mace                 */
    case 225:return sprite_225;                 /* bardiche             */
    case 226:return sprite_226;                 /* morning star         */
    case 227:return sprite_227;                 /* unadorned ring       */
    case 228:return sprite_228;                 /* unadorned necklace   */
    case 229:return sprite_229;                 /* Blank scroll         */
    case 230:return sprite_230;                 /* Quill                */
    case 231:return sprite_231;                 /* Ink                  */
    case 232:return sprite_232;                 /* Hot plate            */
    case 233:return sprite_233;                 /* Pliers               */
    case 234:return sprite_234;                 /* Meat                 */
    case 235:return sprite_235;                 /* Saphire              */
    case 236:return sprite_236;                 /* Amber                */
    case 237:return sprite_237;                 /* Gold bar             */
    case 238:return sprite_238;                 /* Silver bar           */
    case 239:return sprite_239;                 /* Copper bar           */
    case 240:return sprite_240;                 /* Mithril bar          */
    case 241:return sprite_241;                 /* Copper Ore           */
    case 242:return sprite_242;                 /* Silver Ore           */
    case 243:return sprite_243;                 /* Gold Ore             */
    case 244:return sprite_244;                 /* Mithril Ore          */
    case 245:return sprite_245;                 /* Wood                 */
    case 246:return sprite_246;                 /* Tent                 */
    case 247:return sprite_247;                 /* For Sale             */
    case 248:return sprite_248;                 /* Sold House           */
    case 249:return sprite_249;                 /* Obsidion             */
    case 250:return sprite_250;                 /* Golden Helm          */
    case 251:return sprite_251;                 /* Mithril Helm         */
    case 252:return sprite_252;                 /* Golden Shield        */
    case 253:return sprite_253;                 /* Mithril Shield       */
    case 254:return sprite_254;                 /* Mithril Crossbow     */
    case 255:return sprite_255;                 /* Flame Sword          */
    case 256:return sprite_256;                 /* Sun Sword            */
    case 257:return sprite_257;                 /* Compass              */
    case 258:return sprite_258;                 /* Egg                  */
    case 259:return sprite_259;                 /* Potato               */
    case 260:return sprite_260;                 /* Cherry               */
    case 261:return sprite_261;                 /* Asparagus            */
    case 262:return sprite_262;                 /* Butter               */
    case 263:return sprite_263;                 /* Tomato               */
    case 264:return sprite_264;                 /* Lime                 */
    case 265:return sprite_265;                 /* White Obsidion       */
    case 266:return sprite_266;                 /* White Gold Bar       */
    case 267:return sprite_267;                 /* Powder               */
    case 268:return sprite_268;                 /* Onion                */
    case 269:return sprite_269;                 /* White Powder         */
    case 270:return sprite_270;                 /* Corn                 */
    case 271:return sprite_271;                 /* Green Bell Pepper    */
    case 272:return sprite_272;                 /* Red Bell Pepper      */
    case 273:return sprite_273;                 /* Bread                */
    case 274:return sprite_274;                 /* Yellow Bell Pepper   */
    case 275:return sprite_275;                 /* Mushroom             */
    case 276:return sprite_276;                 /* Cheese               */
    case 277:return sprite_277;                 /* Needle               */
    case 278:return sprite_278;                 /* Honey                */
    case 279:return sprite_279;                 /* Grapes               */
    case 280:return sprite_280;                 /* Meal                 */
    case 281:return sprite_281;                 /* Saphire Ring         */
    case 282:return sprite_282;                 /* Folding Boat         */
    case 283:return sprite_283;                 /* Broom                */
    }
  return sprite_200;
  }

