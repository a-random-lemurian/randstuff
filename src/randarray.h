

#include <stdio.h>
#include <stdlib.h>
inline extern void
RandomArray_char (int arraySize, int offset,
                  int samplesize, char chararray[])
{
    for(int i=0;i<samplesize;i++)
    {printf("%c",chararray[offset+rand()%arraySize]);}
}