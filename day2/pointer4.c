#include <stdio.h>
#include <stdlib.h>

struct t{
    int a,b;
};


int main(void){
    
    struct t tt0, tt1, *pt; 
    
    pt=&tt0;
    
    pt->a=0;
    pt->b=1;

    pt=&tt1;
    pt->a=2;
    pt->b=3;

    printf("%d %d\n",tt0.a,tt0.b);
    printf("%d %d\n",tt1.a,tt1.b);  //Same thing
    return 0;
}
