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
