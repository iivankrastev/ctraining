#include <stdio.h>
#include <stdlib.h>

int sum(int num);
int count(int num);

int main(void){

    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("The sum of the digits of %d is : %d\n",a,sum(a));
    return 0;
}

int sum(int num){

    int t1 = abs(num);
    int t2 = t1/10;
    int s = 0;

    for(int i=0;i<count(num);i++){
        s=s+t1-(t2*10);
        t1 = t2;
        t2 = t2/10;
    }
    return s;
}

/*Counting the digits of the input number*/
int count(int num){
    int div = 10;
    int n = 1;

    while(num/div!=0){
        div = div*10;
        n++;
    }
    return n;
}
