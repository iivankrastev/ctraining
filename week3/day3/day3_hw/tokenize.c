#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tokenize.h"

void tokenize(char *string, char *sep, char **tokens){

    char *dest, *p, *pnext;
    int i, j;
    size_t n;
    char *temp;

    dest = strdup(string);
    if (!dest) return;

    pnext = dest;
    for (p = strstr(pnext, sep), i = 0; p; p = strstr(pnext, sep), i++) {
    	printf("p: %s\n pnext: %s\n", p, pnext);
    	for (j = 0; j < strlen(sep); j++)
    		p[j] = '0';
    	pnext = p + strlen(sep);
    }

    printf ("%s\n", dest);
    printf ("Number of tokens needed: %d\n", i);

    tokens = (char **)calloc(i, sizeof(char *));

    for (j = 0; j < i; j++){
    	tokens[j] = (char *)malloc(sizeof(char));
    	//memset(tokens[i], '\0', sizeof(char));
    	//strcpy(tokens[i], "");
    	printf("%s\n", tokens[j]);
    }

    //memset(tokens[i], '\0', sizeof(tokens[i]));
    //strncpy(tokens[0], dest,2);
    //printf("%s\n", tokens[0]);
    //printf ("%s\n", strncat("rag", "abonito", 4));
    //printf("%s\n", tokens[0]);

    temp = strdup(dest);
    pnext = temp;

    for (p = strchr(pnext, '0'), i = 0; p; p = strchr(pnext, '0'), i++) {
        	//printf("p: %s\n pnext: %s\n", p, pnext);
    		n = strlen(pnext) - strlen(p);
    		//printf("%d\n", (int)n);
    		strncpy(tokens[i], pnext, n);
    		printf("%s\n", tokens[i]);
    		pnext = p + strlen(sep);
    		//printf("debug\n");
    }

    free(dest);

    return;

}


