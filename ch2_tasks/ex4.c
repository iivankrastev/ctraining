/*
Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
each character in s1 that matches any character in the string s2 .
*/

#include <stdio.h>

void squeeze (char *s1, char *s2);

int main (void){
	
	char s1 [] = "combolombo";
	char s2 [] = "cow";

	printf("First string: %s\n", s1);
	printf("Second string: %s\n", s2);

	squeeze(s1, s2);
	
	return 0;
}

void squeeze(char *s1, char *s2) {

    int i, j, m;
    
    for (m = 0; s2[m] != '\0'; m++) {
	for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[m])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
    
    printf ("Now the first string looks like this : %s\n", s1);
        
    return;
}

