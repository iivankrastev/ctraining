#ifndef _RINGBUFFER_
#define _RINGBUFFER_

struct ringbuffer{
    int n, idx;
    short int *buf;
};

typedef struct ringbuffer ringbuf;

int init (ringbuf *ring, int N);
void push (ringbuf *r, short int d);
void print (ringbuf *r);

#endif 
