#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int
main (int argc, char** argv)
{
  if(argc==1)
  {
    printf("Usage: %c", *argv[0]);
    return 1;
  }

  srand(clock());

  const char hex[16] = 
    {'a', 'b', 'c', 'd',
     'e', 'f' ,'0', '1',
     '2', '3', '4', '5',
     '6', '7', '8', '9'};

  for(int i = 0; i < atoi(argv[1]); i++)
  {
    printf("%c",hex[rand()%16]);
  }
}
