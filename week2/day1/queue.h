#ifndef _QUEUE_
#define _QUEUE_

struct list {
    int d;
    struct list *n;
};
typedef struct list list;

struct queue {
    list *head;
    list *tail;
};
typedef struct queue queue;

void init(queue *q);
int push(queue *q, int d);
int pop (queue *q, int *d);

#endif
