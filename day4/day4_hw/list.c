/*
List with two pointers - front and back. 
Can add entries in front and back of the list.
(STUPID WAY)
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main (void){

    FILE *f;
    list *head = NULL;
    list *foot = NULL;
    int r;
    
    f = fopen("file","r");

    if(!f)
	return 1;
    
    for (r = fgetc(f); r >= 0; r = fgetc(f)){
	if (addend2(&head, &foot, r) != 0)
	    continue;
    }
	
    fclose(f);

    while (get(&head,&r) != 0)
	printf("%c\n",(char)r);
    
    return 1;

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

int addend (list **root, int d){
    
    list *p, *t;

    if(!(*root))
	return add(root,d);

    for(p = *root; p; p = p->n){
	if(!p->n){
	    t = (list*)malloc(sizeof(list));
	    t->n = NULL;
	    t->d = d;
	    p->n = t;
	    break;
	}
    }
    return 1;    
}

int addend2 (list **head, list **foot, int d){
  
    list *l = (list*)malloc(sizeof(list));  /*Allocates memory for the newnode and store the address in pointer newnode*/

    if(!l)				    /*If there's no memory*/
	return 0;			    /*Terminate*/

    l->d = d;				    /* Assign value to the data variable of the newnode*/
    l->n = NULL;			    /* Assign NULL to the next pointer of the newnode*/

    if(*head == NULL){			    /*Checks if the list is empty.*/    
	*head = l;			    /* Places the address of the new node in HEAD pointer.*/
	*foot = l;			    /* Places the address of the new node in LAST pointer.*/
	return 0;			    /*Terminate*/
    }

    (*foot)->n = l;			    /* If the list is not empty, then make the next pointer of the present last node point to the new node*/
    *foot=(*foot)->n;			    /* Increment LAST to point to the new last node.*/

    return 1;
}






