/* checkoverflow.h
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

#ifndef CHECKOVERFLOW_H
#define CHECKOVERFLOW_H

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

#endif
