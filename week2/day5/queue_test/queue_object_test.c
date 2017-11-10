#include <stdio.h>
#include <stdlib.h>

#include "queue_object.h"

int main(void) {
	void *queue;
	int j;
	queue_datum d;
	
	queue = queue_create();
	if (!queue) {
		fprintf(stderr, "Cannot create queue\n");
		exit(1);
	}
	
	for (j = 0; j < 100; j++) {
		if (j & 1) {
			d.type = INTEGER;
			d.d.i = j;
		} else {
			d.type = POINTER;
			d.d.v = queue;
		}
		
		if (!queue_put(queue, d))
			goto destructor;
	}
	
	while (queue_get(queue, &d)) {
		switch (d.type) {
		case INTEGER:
			printf("INTEGER %d\n", d.d.i);
			break;
		case POINTER:
			printf("POINTER %p\n", d.d.v);
			break;
		default:
			fprintf(stderr, "Uknown type!");
			goto destructor;
		}
	}
	
destructor:
	queue_destroy(queue);
	
	return 0;
}
