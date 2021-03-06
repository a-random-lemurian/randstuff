/* randhex.c
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

#include "checkoverflow.h"
#include "randarray.h"
#include "argcheck.h"

#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int help_flag;
static int upper_flag;
static int mixed_flag;
static int ignore_int_limit;
static int high_mem_use;
static int hexlen_specified;

void PrintHelp(char **argv) {
	printf(
	"Usage: %c [OPTIONS]\n\n"

	"options:\n"
	"-h, --help                Print help and exit\n"
	"-l, --length              Length of hexadecimal\n"
	"    --upper               Use uppercase hex letters\n"
	"    --mixed               Use mixedcase hex letters\n"
	"    --highmemuse          Allocate more memory (~1MB) for print\n"
	"                          buffer (allows for faster printing)\n",
	*argv[0]);
}

int main(int argc, char **argv) {

	CheckArguments(argc, argv);

	int c;
	const char *hexlen = 0;

	while (1)
	{
		static struct option longopts[] = {
			{"length", required_argument, 0, 'l'},
			{"help", no_argument, &help_flag, 1},
			{"upper", no_argument, &upper_flag, 1},
			{"mixed", no_argument, &mixed_flag, 1},
			{"ignoreintlimit", no_argument, &ignore_int_limit, 1},
			{"highmemuse", no_argument, &high_mem_use, 1},
		};

		int optindex = 0;
		c = getopt_long(argc, argv, "hl:", longopts, &optindex);

		if (c == -1) {
			break;
		}

		switch (c) {
		case 'h':
			help_flag = 1;
			break;
		case 'l':
			hexlen_specified = 1;
			hexlen = optarg;
			break;
		}
	}

	if (help_flag) {
		PrintHelp(argv);
		return 0;
	};


	int posarg = 0;

	if (optind < argc) {
		while (optind < argc) {
			if (posarg == 0 && !hexlen_specified)
				hexlen = argv[optind++];
			posarg++;
		}
	}

	if (hexlen == 0) {
		printf("fatal: length of hex not specified\n"
					 "try: %s -l 40",
					 argv[0]);
		exit(1);
	}


	if (mixed_flag && upper_flag) {
		printf("fatal: --mixed and --upper are mutually exclusive\n");
		exit(1);
	}

	int offset = 0;
	int len = 16;

	char hex[22] = "abcdef0123456789ABCDEF";

	if (mixed_flag) {
		len = 22;
	};
 
	if (upper_flag) {
		offset = 6;
	};

	int num_i = CheckOverflow_cchar(ignore_int_limit, hexlen, 10, 1);

	RandomArray_char(len, offset, num_i, hex, high_mem_use);
}
