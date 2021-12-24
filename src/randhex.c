#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include <limits.h>
#include <errno.h>

static int help_flag;
static int upper_flag;
static int mixed_flag;
static int ignore_int_limit;

void
PrintHelp (char **argv)
{
  printf(
    "Usage: %c [OPTIONS]\n\n"

    "options:\n"
    "-h, --help     Print help and exit\n"
    "-l, --length   Length of hexadecimal\n"
    "               numbers to print\n"
    "    --upper    Use uppercase hex letters\n"
    "    --mixed    Use mixedcase hex letters\n"
  ,*argv[0]);
}

int
main (int argc, char** argv)
{ int c;
  const char* hexlen = 0;

  for (;;) {
    static struct option longopts[] = {
    {"length", required_argument, 0, 'l'},
    {"help",   no_argument, &help_flag, 1},
    {"upper",  no_argument, &upper_flag,1},
    {"mixed",  no_argument, &mixed_flag,1},
    {"ignoreintlimit", no_argument, &ignore_int_limit,1}};

    int optindex = 0;
    c = getopt_long (argc, argv, "hl:",
                     longopts, &optindex);

    if(c==-1){break;}

    switch(c){
      case 'h':
        help_flag = 1;
        break;
      case 'l':
        hexlen = optarg;
        break;
    }}

  if(help_flag){PrintHelp(argv);return 0;};


  if(hexlen==0){
    printf("fatal: length of hex not specified\n"
           "try: %s -l 40",argv[0]);
    exit (1);}

  srand(clock());

  if (mixed_flag && upper_flag) {
    printf ("fatal: --mixed and --upper are mutually exclusive\n");
    exit (1);
  }

  int offset = 0;
  int len = 16;

  char hex[22] = "abcdef0123456789ABCDEF";

  if(mixed_flag){len=22;};
  if(upper_flag){offset=6;};

  long num = strtol(hexlen, NULL, 10);
  if(errno == ERANGE){
    printf("fatal: -l argument exceeds signed long integer limit\n");
    exit(1);
  }
  if (num > INT_MAX && !ignore_int_limit){
    printf("fatal: -l argument exceeds signed 32-bit integer limit\n"
           "ignore this with --ignoreintlimit");
    exit(1);
  }
  int num_i = (int)num;

  for(int i = 0; i < num_i; i++)
  {printf("%c",hex[offset+rand()%len]);}}