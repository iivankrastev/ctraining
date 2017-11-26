#ifndef _QUEUE_
#define _QUEUE_

struct list {
	int d;
	struct list *n;
};
typedef struct list list;

struct queue {
	list *B, *E;
};
typedef struct queue queue;

#endif
