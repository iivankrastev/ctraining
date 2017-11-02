#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*NOT WORKING*/


int main(int argc, char *argv[]){

    unsigned int num, mask;
    
    for (mask = 0x80000000u; mask; mask >>= 1) {	
	printf ("%d\n", !!(num & mask));

    }

    return 0;
}
