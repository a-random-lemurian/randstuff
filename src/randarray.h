/* randarray.h
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

#ifndef RANDARRAY_H
#define RANDARRAY_H

#include <stdio.h>
#include <stdlib.h>

inline extern void RandomArray_char(int arraySize, int offset, int samplesize,
                                    char chararray[])
{
	/* Based on the samplesize, instead define strings of a set size
	 * based on samplesize. Then flush these strings out of the buffer,
	 * for faster printing.
	 */

	int blksiz = 10; // Block size, default is 10
	int runoff = 0; // Runoff that doesn't fit in the blocks


	if (samplesize > 10000)       blksiz = 1000;
	if (samplesize > 100000)      blksiz = 5000;
	if (samplesize > 1000000)    blksiz = 10000;
	if (samplesize > 10000000)   blksiz = 100000;


	while (samplesize % blksiz != 0)
	{
		samplesize--;
		runoff++;
	}

	int i;

	for (i = 0; i < runoff; i++) {
		printf("%c", chararray[offset + rand() % arraySize]);
	}

	i = 0;

	char blk[blksiz+1];

	blk[blksiz] = '\0';

	int idx;

	for (int loops = 0; loops < samplesize; loops += blksiz)
	{


		for (idx = 0; idx < blksiz; idx++)
		{
			blk[idx] = chararray[offset+ rand() % arraySize];
		}

		idx = 0;
		printf("%s", blk);

	}


	puts ("\n");
}

#endif
