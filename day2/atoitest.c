#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
int main(int argc, char *argv[]){
    
    int i;
    int sum =0;

    for(i=1;i<argc;i++){
	sum +=atoi(argv[i]);
    }
    printf("%d\n",sum);

    return 0;
}
*/

int main (void){
    
    int i;
    int sum =0;
    char *s = "kurec";
    /*
    for(i=0;s[i];i++){
	sum +=atoi(&s[i]);
    }
    */
    printf("String : %s\t Value: %d\n", s, atoi(s));

    return 0;
}

