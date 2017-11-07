#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char *buf;
    FILE *f1, *f2;
    long l;

    buf =(char *)calloc(128, sizeof(char));

    f1 = fopen("filelong", "r");
    f2 = fopen("filenew", "w+");

    while(!feof(f1)){
	l = fread(buf, sizeof(char), 128, f1);
	printf("%ld\n", fwrite(buf, sizeof(char), l, f2));
    }

    fclose(f2);
    fclose(f1);
    free(buf);
}
