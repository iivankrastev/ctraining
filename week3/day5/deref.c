#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <string.h>

void *get_dereference(void *mem, size_t size, size_t el) {
	uint8_t *m = (uint8_t *)mem;
	
	return (void *)(m + size * el);
}

void set_dereference(void *mem, size_t size, size_t el, void *val) {
	uint8_t *m = ((uint8_t *)mem) + size * el;
	
	(void)memcpy((void *)m, val, size);
	return;
}

int main(void) {
	char a[10];
	char i;
	
	for (i = 0; i < 10; i++)
		set_dereference(&a, sizeof (char), i, &i);
	
	for (i = 0; i < 10; i++)
		printf("%d\n", *((char *)(get_dereference(&a, sizeof (char), i))));
	return 0;
}
