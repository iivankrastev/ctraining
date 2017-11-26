#ifndef BIN_SEARCH_H_
#define BIN_SEARCH_H_

void *bin_search(void *val, void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

#endif /* BIN_SEARCH_H_ */
