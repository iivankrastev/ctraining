#include <stdio.h>
#include <stdlib.h>

#include "queue_object.h"

int main(void) {
	void *queue;
	int j;
	char c;
	queue_datum d;
	
	queue = queue_create();
	if (!queue) {
		fprintf(stderr, "Cannot create queue\n");
		exit(1);
	}

	for (c = 'a'; c < 'f'; c++) {
			d.type = CHAR;
			d.d.c = c;
		if (!queue_put(queue, d))
			goto destructor;
	}

	for (j = 0; j < 5; j++) {
		if (j & 1) {
			d.type = SHORTI;
			d.d.hd = j;
		} else {
			d.type = LONGI;
			d.d.ld = j;
		}
		if (!queue_put(queue, d))
			goto destructor;
	}

	for (j = 0; j < 5; j++) {
		if (j & 1) {
			d.type = DOUBLE;
			d.d.d = j;
		} else {
			d.type = FLOAT;
			d.d.f = j;
		}
		if (!queue_put(queue, d))
			goto destructor;
	}

	for (j = 0; j < 5; j++) {
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
		case DOUBLE:
			printf("DOUBLE %lf\n", d.d.d);
			break;
		case FLOAT:
			printf("FLOAT %f\n", d.d.f);
			break;
		case SHORTI:
			printf("SHORT INT %hd\n", d.d.hd);
			break;
		case LONGI:
			printf("LONG INT %ld\n", d.d.ld);
			break;
		case CHAR:
			printf("CHAR %c\n", d.d.c);
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
