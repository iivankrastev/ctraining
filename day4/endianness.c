#include <stdio.h>

int l_endian1(void);
int l_endian2(void);

int main (void){

    printf("%d\n",l_endian2());
    
}

int l_endian1(void){

    unsigned int t = 0xdeadbeefu;
    
    if (*((unsigned char *)&t) == 0xefu)
	return 1;
    
    return 0;

}

int l_endian2(void){
    
    union endian_test{
	unsigned int i;
	unsigned char c[4];
    }t;

    t.i = 0xdeadbeefu;

    if (t.c[0] == 0xefu)
	return 1;

    return 0;

}

