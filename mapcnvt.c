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


void process(char* fname) {
  FILE*    in_file;
  char     buffer[200];
  int      x,y;

  in_file = fopen(fname,"r");
  if (in_file == NULL) {
    printf("Could not open %s\n",fname);
    exit(1);
    }

  printf("  {\n");
  for (y=0; y<=100; y++) {
    if (y != 0) fgets(buffer,200,in_file);
      else for (x=0; x<=100; x++) buffer[x] = ' ';
    printf("    { 1,");
    for (x=1; x<=100; x++) {
      switch (buffer[x-1]) {
        case ' ':printf("1"); break;
        case '.':printf("1"); break;
        case '#':printf("2"); break;
        case '^':printf("3"); break;
/*        case 'v':printf("19"); break; */
        case 'v':printf("177"); break;
        case '~':printf("4"); break;
        case '-':printf("8"); break;
        case '=':printf("6"); break;
        case '(':printf("9"); break;
        case '!':printf("17"); break;
        case '@':printf("21"); break;
        case '+':printf("7"); break;
        case '\\':printf("23"); break;
        case '/':printf("22"); break;
        case '|':printf("14"); break;
        case '%':printf("20"); break;
        case 's':printf("13"); break;
        case ',':printf("15"); break;
        case 'c':printf("26"); break;
        case 't':printf("27"); break;
        case 'b':printf("29"); break;
        case 'h':printf("28"); break;
        case '}':printf("32"); break;
        case 'm':printf("30"); break;
        case '1':printf("5"); break;
        case 'A':printf("11"); break;
        case 'B':printf("520"); break;
        case 'C':printf("521"); break;
        case 'D':printf("522"); break;
        case 'E':printf("523"); break;
        case 'F':printf("524"); break;
        case 'G':printf("525"); break;
        case 'H':printf("526"); break;
        case 'I':printf("527"); break;
        case 'J':printf("528"); break;
        case 'K':printf("529"); break;
        case 'L':printf("530"); break;
        case 'M':printf("531"); break;
        case 'N':printf("532"); break;
        case 'O':printf("533"); break;
        case 'P':printf("534"); break;
        case 'Q':printf("535"); break;
        default :printf("7"); break;
        }
      if (x<100) printf(",");
      }
    printf(" }");
    if (y != 100) printf(",");
    printf("\n");
    }
  fclose(in_file);
  printf("    },\n");
  }

int main(int argc,char** argv) {
  printf("#ifdef MAIN\n");
  printf("MAP_TYPE maps[] ={\n");
  process("map11.map");    /* place the null map */
  process("map11.map");
  process("map12.map");
  process("map13.map");
  process("map14.map");
  process("map21.map");
  process("map22.map");
  process("map23.map");
  process("map24.map");
  process("map31.map");
  process("map32.map");
  process("map33.map");
  process("map34.map");
  process("radon.map");
  process("generic.map");
  process("village.map");
  process("marduk.map");
  process("nichor.map");
  process("eshter.map");
  printf("  };\n");
  printf("#else\n");
  printf("extern MAP_TYPE maps[];\n");
  printf("#endif\n");
  return 0;
  }

