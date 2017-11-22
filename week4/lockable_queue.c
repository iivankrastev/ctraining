#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "queue_object.h"

struct lockable_queue {
	pthread_mutexattr_t mattr;
	pthread_mutex_t mtx;
	int term;
	void *queue;
};
typedef struct lockable_queue lockable_queue;

void *print_thread(void *arg) {
	lockable_queue *queue = (lockable_queue *)arg;
	queue_datum d;
	
	while (1) {
		pthread_mutex_lock(&queue->mtx);
		if (queue_get(queue->queue, &d)) {
			if (d.type == INTEGER) printf("%d\n", d.d.i);
			else if (d.type == POINTER) printf("%p\n", d.d.v);
		} else if (queue->term) {
			pthread_mutex_unlock(&queue->mtx);
			break;
		}
		pthread_mutex_unlock(&queue->mtx);
	}
	return NULL;
}

int main(void) {
	pthread_attr_t qattr;
	pthread_t qthr;
	lockable_queue queue;
	queue_datum d;
	
	pthread_mutexattr_init(&queue.mattr);
	pthread_mutexattr_settype(&queue.mattr, PTHREAD_MUTEX_NORMAL);
	pthread_mutex_init(&queue.mtx, &queue.mattr);
	queue.term = 0;
	queue.queue = queue_create();
	
	pthread_attr_init(&qattr);
	pthread_attr_setname_np(&qattr, "queue thread");
	
	pthread_create(&qthr, &qattr, &print_thread, &queue);
	
	d.type = INTEGER;
	for (d.d.i = 0; d.d.i < 1000; d.d.i++) {
		pthread_mutex_lock(&queue.mtx);
		printf("MUTEX main %d\n", d.d.i);
		queue_put(queue.queue, d);
		pthread_mutex_unlock(&queue.mtx);
	}
	
	queue.term = 1;
	pthread_join(qthr, NULL);
	
	queue_destroy(queue.queue);
	
	return 0;
}

