/* randascii.c
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

#include "argcheck.h"
#include "checkoverflow.h"
#include "randarray.h"
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int help_flag;
static int alphanumeric_flag;
static int ignore_int_limit;
static int high_mem_use;

void PrintHelp(char **argv) {
	printf(
	"Usage: %c [OPTIONS] -l [length]\n\n"

	"options:\n"
	"-h, --help                Print help and exit\n"
	"-l, --length              Length of ASCII string to print\n"
	"--alphanumeric            Use alphanumeric characters, no punctuation\n"
	"--highmemuse              Allocate more memory (~1MB) for print buffer\n"
	"                          (allows for faster printing)",
	*argv[0]);
}

int main(int argc, char **argv)
{
	CheckArguments(argc, argv);

	const char *samplesize = 0;

	int c;
	int len = 94;
	int offset = 0;

	char alphanumericAscii[66] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char printableAscii[94] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~!@#$%%^&*()_+`{}:\"|<>?,./;\'\\[]\'";

	while (1)
	{
		static struct option longopts[] = {
			{"length", required_argument, 0, 'l'},
			{"help", no_argument, &help_flag, 1},
			{"ignoreintlimit", no_argument, &ignore_int_limit, 1},
			{"alphanumeric", no_argument, &alphanumeric_flag, 1},
			{"highmemuse", no_argument, &high_mem_use, 1},
		};

		int optindex = 0;
		c = getopt_long(argc, argv, "hl:", longopts, &optindex);

		if (c == -1)
			break;

		switch (c) {
		case 'h':
			help_flag = 1;
			break;
		case 'l':
			samplesize = optarg;
			break;
		}
	}

	if (help_flag) {
		PrintHelp(argv);
		return 0;
	};

	if (samplesize == 0) {
		printf("fatal: length of sample not specified");
		exit(1);
	}

	int num_i = CheckOverflow_cchar(ignore_int_limit, samplesize, 10, 1);

	if (alphanumeric_flag) {
		RandomArray_char(len, offset, num_i, alphanumericAscii, high_mem_use);
		return 0;
	}

	RandomArray_char(len, offset, num_i, printableAscii, high_mem_use);
}
