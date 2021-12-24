#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

static int help_flag;


void
PrintHelp (char **argv)
{
  printf(
    "Usage: %c [OPTIONS]\n\n"

    "options:\n"
    "-h, --help     Print help and exit\n"
    "-l, --length   Length of hexadecimal\n"
    "               numbers to print\n"
  ,*argv[0]);
}

int
main (int argc, char** argv)
{ int c;
  int hexlen = 0;
  for (;;) {
    static struct option longopts[] = {
    {"length", required_argument, 0, 'l'},
    {"help",   no_argument, &help_flag, 1}};

    int optindex = 0;
    c = getopt_long (argc, argv, "hl:",
                     longopts, &optindex);

    if(c==-1){break;}

    switch(c){
      case 'h':
        help_flag = 1;
        break;
      case 'l':
        hexlen = atoi(optarg);
        break;
    }}

  if(help_flag){PrintHelp(argv);return 0;};

  if(hexlen==0){
    printf("fatal: length of hex not specified\n"
           "try: %s -l 40",argv[0]);
    exit (1);}

  srand(clock());

  const char hex[16] = 
    {'a', 'b', 'c', 'd',
     'e', 'f' ,'0', '1',
     '2', '3', '4', '5',
     '6', '7', '8', '9'};

  for(int i = 0; i < hexlen; i++)
  {printf("%c",hex[rand()%16]);}}