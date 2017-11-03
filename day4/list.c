#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main (void){

    list *p, *root = NULL;
    int i = 0;
    
    for (i; i < 5; i++){ 
	if(add(&root,i) == 0)
	    printf("FAILED TO ADD!\n");
	else
	    printf("Added : %d\n", i); 
	/*
	if (get(&root,&i) != 0)
	    printf("Got : %d\n", i);
	else
	    printf("No more entries\n");
	*/
    }
    
    for (p = root; p; p = p->n){
	p->d *= 2;
	printf("%d\n",p->d);
    }
    /*
    i++;

    if (get(&root,&i) != 0)
	printf("Got : %d\n", i);
    else
	printf("No more entries\n");
    */

}

int add(list **root, int d){

    list *l = (list*)malloc(sizeof(list));
    if(!l)
	return 0;
    l->n = *root;
    l->d = d;
    *root = l;

    return 1;
}

int get (list **root, int *d){
    list *tmp = *root;	/*To not lose root*/
    if (!tmp)		/*If list is empty ->exit*/
	return 0;
    *root = (*root)->n;
    *d = tmp->d;
    free(tmp);

    return 1;
}



