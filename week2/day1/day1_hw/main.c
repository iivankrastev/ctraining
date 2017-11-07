#include "fir.h"
#include <stdio.h>
#include <stdlib.h>

#define FIR_LEN 32

/*awk 'BEGIN { for(i = 0; i < 1000; i++) print i;}' |./fir*/

int main (void){
    
    ringbuf fir;
    short int i; 

    init(&fir, FIR_LEN);
    
    //print_coefs();

    
    while (!feof(stdin)){
	scanf("%hd", &i);
	push(&fir, i);
	filter32(&fir);
    }
    

    return 0;

}

