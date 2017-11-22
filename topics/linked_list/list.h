#ifndef _LIST_
#define _LIST_

struct list{
    int d;  //data
    struct list *n; //pointer to next element
};

typedef struct list list;

int add(list **root, int d);
int get(list **root, int *d);

#endif
