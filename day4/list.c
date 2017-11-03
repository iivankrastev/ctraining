/*
Open a file, read every char and put it in a linked list.
Then get all elements of the list and print them.
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main (void){

    FILE *f;
    list *root = NULL;
    int r;
    
    f = fopen("file","r");

    if(!f)
	return 1;
    
    for (r = fgetc(f); r >= 0; r = fgetc(f)){
	if (add(&root, r) != 0)
	    continue;
    }
	
    fclose(f);

    while (get(&root,&r) != 0)
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



