#include <stdio.h>

union int_char{
    int i;
    char c[4];
};

int main (void){
    
    union int_char t;

    t.i = 123456789;
    printf("%d\n", t.i);
    t.c[1] = 'a';
    printf("%d\n", t.i);
    
    return 0;
}
