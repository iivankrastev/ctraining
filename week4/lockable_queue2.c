#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#include "queue_object.h"

struct lockable_queue {
	pthread_mutexattr_t mattr;
	pthread_mutex_t mtx;
	pthread_mutexattr_t mattr_term;
	pthread_mutex_t mtx_term;
	void *queue;
};
typedef struct lockable_queue lockable_queue;

void *consumer_thread(void *arg) {
	lockable_queue *queue = (lockable_queue *)arg;
	queue_datum d;
	
	while (1) {
		pthread_mutex_lock(&queue->mtx);
		if (queue_get(queue->queue, &d)) {
			if (d.type == INTEGER) printf("CONSUMER INTEGER %d\n", d.d.i);
			else if (d.type == POINTER) printf("CONSUMER POINTER %p\n", d.d.v);
		} else if (pthread_mutex_trylock(&queue->mtx_term) != EBUSY) {
			pthread_mutex_unlock(&queue->mtx);
			break;
		}
		pthread_mutex_unlock(&queue->mtx);
	}
	return NULL;
}

void *producer0_thread(void *arg) {
	lockable_queue *queue = (lockable_queue *)arg;
	queue_datum d;
	
	d.type = INTEGER;
	for (d.d.i = 0; d.d.i < 1000; d.d.i++) {
		pthread_mutex_lock(&queue->mtx);
		printf("PRODUCER %d\n", d.d.i);
		queue_put(queue->queue, d);
		pthread_mutex_unlock(&queue->mtx);
	}
	
	pthread_mutex_unlock(&queue->mtx_term);
	
	return NULL;
}

void *producer1_thread(void *arg) {
	lockable_queue *queue = (lockable_queue *)arg;
	queue_datum d;
	int j;
	
	d.type = POINTER;
	d.d.p = arg;
	for (j = 0; j < 1000; j++) {
		pthread_mutex_lock(&queue->mtx);
		printf("PRODUCER %p\n", d.d.p);
		queue_put(queue->queue, d);
		pthread_mutex_unlock(&queue->mtx);
	}
	
	pthread_mutex_unlock(&queue->mtx_term);
	
	return NULL;
}

int main(void) {
	pthread_attr_t qattr;
	pthread_t producer0, producer1, consumer;
	lockable_queue queue;
	
	pthread_mutexattr_init(&queue.mattr);
	pthread_mutexattr_settype(&queue.mattr, PTHREAD_MUTEX_NORMAL);
	pthread_mutex_init(&queue.mtx, &queue.mattr);
	
	pthread_mutexattr_init(&queue.mattr_term);
	pthread_mutexattr_settype(&queue.mattr_term, PTHREAD_MUTEX_NORMAL);
	pthread_mutex_init(&queue.mtx_term, &queue.mattr_term);
	pthread_mutex_lock(&queue.mtx_term);
	
	queue.queue = queue_create();
	
	pthread_attr_init(&qattr);
	pthread_create(&consumer, &qattr, &consumer_thread, &queue);
	pthread_create(&producer0, &qattr, &producer0_thread, &queue);
	pthread_create(&producer1, &qattr, &producer1_thread, &queue);
		
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
	
	queue_destroy(queue.queue);
	
	pthread_attr_destroy(&qattr);
	pthread_mutex_destroy(&queue.mtx_term);
	pthread_mutexattr_destroy(&queue.mattr_term);
	pthread_mutex_destroy(&queue.mtx);
	pthread_mutexattr_destroy(&queue.mattr);
	
	return 0;
}

