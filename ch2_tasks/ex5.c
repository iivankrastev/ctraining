/*
Exercise 2-5. Write the function any(s1,s2) , which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2 . (The standard library function strpbrk does
the same job but returns a pointer to the location.)
*/

#include <stdio.h>

char any(char* ,char*);

int main (void){

    char a[] = "abcd";
    char b[] = "dead";

    printf("Match found: %c\n",any(a,b));

    return 0;
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
