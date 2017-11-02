#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {
   
    int r, sum = 0;
    char c;

    if (argc < 2)
	return 1;

    for (r = fgetc(stdin); r >= 0; r = fgetc(stdin)) {
	c = (char)(r & 0xff);
	if (argv[1][0] == c)
	    sum++;
    }
    
    printf("%d\n", sum);

    return 0;
}

/* echo "1 2 1 5 1"|./atoitest2 1  - input stream with 1 argument */

