#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void *bin_search(void *val, void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {

	size_t l, u, i;
	const void *p;
	int comparison;

	l = 0;
	u = nel;

	while (l < u) {
      i = (l + u) / 2;
      p = (void *)(((unsigned char *) base) + (i * width));
      comparison = (*compar) (val, p);

      if (comparison < 0)
    	  u = i;
      else if (comparison > 0)
    	  l = i + 1;
      else
    	  return (void *) p;
    }

	return NULL;
}
