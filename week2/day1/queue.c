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
    q->B = q->E = NULL;
    return;
}

int push(queue *q, int d){
    
    list *newnode = (list*)malloc(sizeof(list));
    if (!newnode) 
	return 0;
    newnode->d = d;
    newnode->n = NULL;
    if (q->E) {
	q->E->n = newnode;  
	q->E = newnode;
    } else {	
	//if q->E is pointing to NULL
	//Begin and End pointers is pointing at the same place
	q->B = q->E = newnode;	
    }
    
    return 1;
}

int pop (queue *q, int *d){
   
    list *t;	    //temporary var

    if (!q->B)	    //if there's no list behind the queue
	return 0;
    *d = q->B->d;   //saving the data 
    t = q->B;	    //saving the b pointer
    q->B = q->B->n; //pointing to next element
    if (!q->B)
	q->E = NULL;//if this was the last element 	
    free(t);	    

    return 1;
}


