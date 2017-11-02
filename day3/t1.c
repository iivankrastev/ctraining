#include <stdio.h>

int global;

void modify(int);

int main(void){

    modify(10);
    printf("%d\n",global);

    return 0;
}

