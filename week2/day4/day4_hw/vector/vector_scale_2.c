#include <stdio.h>

#include "vector_object.h"

int main(void) {
	void *v = vector_create(3);
		if (!v) return 1;
	double component;
	int j;
	
	for (j = 0; j < vector_dim(v); j++) /*Set VECTOR 1*/
		(void)vector_set_component(v, j, (double)j);

	printf("V1 Components\n");
	for (j = 0; j < vector_dim(v); j++) { /*Get VECTOR 1*/
		(void)vector_get_component(v, j, &component);
		printf("%lf\n", component);
	}
	
	printf("\nvector_scale2(V1, 2.0) \t V1 = V1 * 2.0\n");
	vector_scale2(v, 2.0); /*Scale 2*/
		for (j = 0; j < vector_dim(v); j++) { 
			(void)vector_get_component(v, j, &component);
			printf("%lf\n", component);
	}

	vector_destroy(v);

	return 0;
}
