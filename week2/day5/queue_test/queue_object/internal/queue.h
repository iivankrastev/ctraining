#ifndef _QUEUE_
#define _QUEUE_

#include "queue_object.h"

struct list {
	queue_datum d;
	struct list *n;
};
typedef struct list list;

struct queue {
	list *B, *E;
};
typedef struct queue queue;

#endif
