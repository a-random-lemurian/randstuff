/* randfromargs.c
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
#include <stdlib.h>
#include <string.h>

#include "argcheck.h"
#include "checkoverflow.h"
#include "randarray.h"

static int help_flag, ignore_int_limit, high_mem_use;

void PrintHelp(char **argv) {
	printf(
	"Usage: %s [OPTIONS] -a [ARRAY] -l [LENGTH]\n\n"

	"specify your own strings to choose from randomly\n"
	"options:\n"
	"-h, --help                Print this message and exit\n"
	"-a, --array               Array (can be a string, does not support {})\n"
	"-l, --length              Length of characters to print\n"
	"    --highmemuse          Allocate more memory (~1MB) for\n"
	"                          print buffer (allows for faster printing)",
	argv[0]);
}


int main(int argc, char **argv) {

	CheckArguments(argc, argv);

	int c;
	char *samplesize = "0";
	char *array = "  ";

	while (1)
	{
		static struct option longopts[] = {
			{"length", required_argument, 0, 'l'},
			{"help", no_argument, &help_flag, 1},
			{"ignoreintlimit", no_argument, &ignore_int_limit, 1},
			{"array", required_argument, NULL, 'a'},
			{"highmemuse", no_argument, &high_mem_use, 1}
		};

		int optindex = 0;
		c = getopt_long(argc, argv, "hl:a:", longopts, &optindex);

		if (c == -1) {
			break;
		};

		switch (c) {
		case 'h':
			PrintHelp(argv);
			exit(1);
		case 'a':
			array = optarg;
			break;
		case 'l':
			samplesize = optarg;
			break;
		}
	}

  int samplesize_i = CheckOverflow_cchar(ignore_int_limit, samplesize, 10, 1);
  RandomArray_char(strlen(array), 0, samplesize_i, array, high_mem_use);

}
