/*
Homework:
In accordance with void qsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
write a function void *bin_search(void *base, void *val, size_t nel, size_t width, int (*compar)(const void *, const void *));
which does the https://en.wikipedia.org/wiki/Binary_search_algorithm

In order to move or dereference the pointers properly use this cast:
((void *)((unsigned char *)base + i * width)) where (i) is between 0 and nel - 1,
which would be on par with base[i] (alas, incorrect) if the type of base was known.

You'll be calling the callback compare with the second argument set to val of type void *,
and the first argument should be whatever element you're referencing.

The compar callback should be the same as the compar callback of qsort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#include "bin_search.h"

int compare_int (const void * a, const void * b) {
	return ( *(uint32_t*)a - *(uint32_t*)b );
}

int main ()
{
	int * ptr_item;
	int searchkey;
	int i;

	uint32_t m[20];

	for (i = 0; i < 20; i++) {
		m[i] = (uint32_t)rand() % 100;
		printf("Value: %d\n ", m[i] );
	}

	qsort((void *)m, 20, sizeof(uint32_t), &compare_int);
	printf("**********SORTED***********\n");
	for (i = 0; i < 20; i++)
		printf("Value: %d\n ", m[i] );

	printf ("Enter a searchkey: ");
	scanf ("%d", &searchkey);

	ptr_item = (int*) bsearch (&searchkey, m, 20, sizeof (int), compare_int);

	if (ptr_item != NULL)
		printf ("%d is found in the array.\n",*ptr_item);
	else
		printf ("%d is not found in the array.\n",searchkey);
	return 0;
}



