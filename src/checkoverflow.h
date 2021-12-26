#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
inline extern int CheckOverflow_cchar(int ignore_int_limit, const char *samplesize, int numbase, int errcode)
{
	long num = strtol(samplesize, NULL, numbase);

	if (errno == ERANGE) {
		printf("fatal: -l argument exceeds signed long integer limit\n");
		exit(errcode);
	}

	if (num > INT_MAX && !ignore_int_limit) {
		printf("fatal: -l argument exceeds signed 32-bit integer limit\n"
		       "ignore this with --ignoreintlimit");
		exit(errcode);
	}
	return (int)num;
}
