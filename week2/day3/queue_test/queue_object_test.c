#include <stdio.h>
#include <stdlib.h>

#include "queue_object.h"

int main(void) {
	void *queue;
	int j;

	queue = queue_create();
	if (!queue) {
		fprintf(stderr, "Cannot create queue\n");
		exit(1);
	}
	
	for (j = 0; j < 100; j++)
		if (!queue_put(queue, j))
			goto destructor;
	
	while (queue_get(queue, &j))
		printf("%d\n", j);

destructor:
	queue_destroy(queue);
	
	return 0;
}
