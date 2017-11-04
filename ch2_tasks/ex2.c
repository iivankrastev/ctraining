/*
for (i=0 ; i < lim-1 && (c=getchar()) != '\n' && c != EOF;   ++i)
s[i] = c;

Exercise 2-2. Write a loop equivalent to the for loop above without using && or || .
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

int main (void) {

	int i, lim, c;
	char s[MAX_STRING_LENGTH];
	
	i = 0;
	lim = MAX_STRING_LENGTH;

	while (i < (lim - 1)){
		c = getchar();

		if (c == EOF)
			break;
		else if (c == '\n')
			break;
		s[i++] = c;
	}
	s[i] = '\0';   
	return 0;
}


