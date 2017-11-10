#include <stdio.h>

#include "vector_object.h"

int main(void) {
	void *v = vector_create(3);
		if (!v) return 1;
	void *v2 = vector_create(3);
		if (!v2) return 2;
	void *v3 = vector_create(3);
		if (!v3) return 3;
	double component, component2, component3;
	int j, i;
	
	for (j = 0; j < vector_dim(v); j++) /*Set VECTOR 1*/
		(void)vector_set_component(v, j, 0);

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

	for (j = 0, i = 6; j < vector_dim(v3); j++, i++) /*Set VECTOR 3*/
		(void)vector_set_component(v3, j, (double)i);

	printf("\nV3 Components\n");
	for (j = 0; j < vector_dim(v3); j++) { /*Get VECTOR 3*/
		(void)vector_get_component(v3, j, &component3);
		printf("%lf\n", component3);
	}

	printf("\nvector_add3(V1, V2, V3) \t V1 = V2 + V3\n");
	vector_add3(v, v2, v3); /*Vector sub3*/
		for (j = 0; j < vector_dim(v); j++) {
			(void)vector_get_component(v, j, &component);
			printf("%lf\n", component);
		}

	vector_destroy(v3);
	vector_destroy(v2);
	vector_destroy(v);
	return 0;
}
