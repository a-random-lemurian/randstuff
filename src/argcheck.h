/* argcheck.h
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

#ifndef ARGCHECK_H_
#define ARGCHECK_H_

#include <stdio.h>
#include <stdlib.h>

inline extern void CheckArguments (int argc, char** argv)
{
	if (argc == 1)
	{
		printf("fatal: no arguments were supplied, try again with the -h flag");
		exit(1);
	}
}

#endif
