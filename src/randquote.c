/* randquote.c
 *
 * Copyright (C) 2021-2022 Lemuria
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */


#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static int help_flag;

void PrintHelp(char** argv)
{
	printf(
	"Usage: %s [OPTIONS] -f [FILE]\n\n"

	"Options:\n"
	"-h, --help       Print this message and exit\n"
	"-f, --file       File to select random quote from\n"
	,argv[0]);
}


int main (int argc, char** argv)
{
	int c;
	char* filename = "-";

	for (;;) {
		static struct option longopts[] = {
			//{"length", required_argument, 0, 'l'},
			{"help", no_argument, &help_flag, 1},
			{"file", required_argument, 0, 'f'}
		};

		int optindex = 0;
		c = getopt_long(argc, argv, "hf:", longopts, &optindex);

		if (c == -1) {
			break;
		}

		switch (c) {
		case 'h':
			help_flag = 1;
			break;
		case 'f':
			filename = optarg;
			break;
		}
	}

	FILE *fptr;

	if ((fptr = fopen(filename, "r")) == NULL)
	{
		printf("fatal: file could not be opened");
		exit(1);
	}

	srand(clock());

	int lineno = 1;
	char first[100], next[100];

	if (fgets(first, 100, fptr))
	{
		while (fgets(next, 100, fptr))
		{
			if (rand() % ++lineno == 0)
				strcpy(first, next);
		}
	}

	fclose(fptr);
	fputs(first, stdout);
}
