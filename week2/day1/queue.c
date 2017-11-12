#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main (void){
    FILE *f;
    queue q;
    int r;
    
    init(&q);
    f = fopen("file","r");

    if(!f)
	return 1;
    
    for (r = fgetc(f); r >= 0; r = fgetc(f)){
	if (push(&q, r) != 0)
	    continue;
    }
	
    fclose(f);

    while (pop(&q,&r) != 0)
	printf("%c\n",(char)r);
    
    return 1;
}

void init(queue *q){	
    q->head = q->tail = NULL;
    return;
}

int push(queue *q, int d){
    
    list *entry = (list*)malloc(sizeof(list));
    if (!entry) 
	return 0;
    entry->d = d;
    entry->n = NULL;
    if (q->tail) {
	q->tail->n = entry; // ??????????????????  
	q->tail = entry;
    } else {	/*Case in which this is the first pushed element in the queue*/	
	q->head = q->tail = entry;	/*Both pointers point to it*/
    }
    
    return 1;
}

int pop (queue *q, int *d){
   
    list *temp;	    

    if (!q->head)   /* Case in which the queue is empty */	
	return 0;

    *d = q->head->d;	    //saving the data 
    temp = q->head;	    //saving the b pointer
    q->head = q->head->n;   //pointing to next element
    if (!q->head)
	q->tail = NULL;	    //if this was the last element 	
    free(temp);	    

    return 1;
}


