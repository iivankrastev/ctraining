#include <stdio.h>

char any(char* ,char*);

int main (void){

    char a[] = "abcd";
    char b[] = "dead";

    printf("Match found: %c\n",any(a,b));
}

char any (char *a, char *b){
    
    char c;
    int i, j;

    for (i = 0; a[i] != '\0'; i++){
	for (j = 0; b[j] != '\0'; j++){
	    if (a[i] == b[j]){
		c = a[i];
		break;
	    }
	}
    }

    return c;
}
