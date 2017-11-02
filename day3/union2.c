#include <stdio.h>

union int_char{
    unsigned int i;
    float d;
};

int main (void){
    
    union int_char t;
    

    printf("%lu\n", sizeof(t));
    t.d = 0.0f;
    t.i = 0xffffffffu;
    printf("%f\n", t.d);    //prints hex 
    
    return 0;
}
