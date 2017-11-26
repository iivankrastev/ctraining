#ifndef _QUEUE_OBJECT_
#define _QUEUE_OBJECT_

void *queue_create(void);
void queue_destroy(void *);
int queue_put(void *, int);
int queue_get(void *, int *);

#endif
