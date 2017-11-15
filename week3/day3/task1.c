#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
s1 = abcdefg
s2 = cde
out = abCDEfg

s1 = abcdefg
s2 = cfg
out = abcdefg
*/

int main (void){
	
    char *s1 = "abcdefg";
    char *s2 = "cfg";
    char *result;
    
    int i, j;


    if (!(strstr(s1, s2)))
	result = strdup(s1);
    else {

    }


    printf("%s\n", result);

    return 0;
}
