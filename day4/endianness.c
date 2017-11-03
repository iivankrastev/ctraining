#include <stdio.h>

int l_endian1(void){

    unsigned int t = 0xdeadbeefu;
    
    if (*((unsigned char *)&t) == 0xefu)
	return 1;
    
    return 0;


}

int main (void){

    printf("%d\n",l_endian1());
    
}
