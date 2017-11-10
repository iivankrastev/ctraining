#include <stdio.h>

#include "vector_object.h"

int main(void) {
	void *v = vector_create(3);
		if (!v) return 1;
	void *v2 = vector_create(3);
		if (!v2) return 2;
	double component, component2;
	int j, i;
	
	for (j = 0; j < vector_dim(v); j++) /*Set VECTOR 1*/
		(void)vector_set_component(v, j, (double)j);

	printf("V1 Components\n");
	for (j = 0; j < vector_dim(v); j++) { /*Get VECTOR 1*/
		(void)vector_get_component(v, j, &component);
		printf("%lf\n", component);
	}

	for (j = 0, i = 3; j < vector_dim(v2); j++, i++) {/*Set VECTOR 2*/
		(void)vector_set_component(v2, j, (double)i);
	}
	
	printf("\nV2 Components\n");
	for (j = 0; j < vector_dim(v2); j++) { /*Get VECTOR 2*/
		(void)vector_get_component(v2, j, &component2);
		printf("%lf\n", component2);
	}
	
	printf("\nvector_sub2(V2, V1) \t V2 = V2 - V1\n");
	vector_sub2(v2, v); /*Vector sub*/
		for (j = 0; j < vector_dim(v); j++) {
			(void)vector_get_component(v2, j, &component2);
			printf("%lf\n", component2);
		}

	vector_destroy(v2);
	vector_destroy(v);

	return 0;
}
