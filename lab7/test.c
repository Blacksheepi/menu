#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
int Quit(int argc, char **argv)
{
    exit(0);
}
int argtest(int argc, char **argv)
{
  const char *optString = "abc";
  opterr = 0;
  int opt;
//printf("argc: %d\n",argc);
//printf("argv[1]: %s\n", argv[1]);
  while((opt = getopt(argc, argv, optString)) != -1)
  {
//printf("opt = %d\n",opt);
    switch(opt)
    {
    case 'a':
        printf("this -a option\n");
    printf("you are so cool!\n");
    break;
    case 'b':
    printf("this -b option\n");
    printf("Hello World!\n");
    break;
    case 'c':
    printf("this -c option\n");
    printf("today is Monday!\n");
    break;
    default:
    printf("this cmd has three option:\n");
    printf("-a\n-b\n-c\n");
    break;
    }
  }
  optind = 0;
  return 0;
}
int main(int argc, char **argv)
{
MenuConfig("version", "menu v1.0(Menu program v3.0.0 inside)", NULL);
MenuConfig("argtest", "test arg option", argtest);
MenuConfig("quit", "quit from menu", Quit);
ExcuteMenu();
return 0;
}
