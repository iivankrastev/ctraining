#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *_t0, const void *_t1) {
	const char **t0 = (const char **)_t0;
	const char **t1 = (const char **)_t1;

	return strcmp(*t0, *t1);
}

int main(void) {
	char *s[10] = {"spanak", "pakspanak", "malkodomashno", "bira", "stolche",
		        "golqmkef", "talkischeap", "stigaveche", "abv", "end"} ;
	int i, j;
    
	qsort((void *)s, 10, sizeof(char), &compare);
	
	for (i = 0; i < 10; i++) {
	    for (j = 0; j < strlen(s[i]); j++)
		printf("%s\n", s[i][j]);
	}	
	
	return 0;
}

