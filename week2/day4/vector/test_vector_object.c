#include <stdio.h>

#include "vector_object.h"

int main(void) {
	void *v = vector_create(3);
	double component;
	int j;
	
	if (!v) return 1;
	
	for (j = 0; j < vector_dim(v); j++)
		(void)vector_set_component(v, j, (double)j);
	
	for (j = 0; j < vector_dim(v); j++) {
		(void)vector_get_component(v, j, &component);
		printf("%lf\n", component);
	}
	
	vector_destroy(v);
	return 0;
}
