#include <stdio.h>


int main (void){
    
    FILE *f;

    f = fopen("file","r+");

    fseek(f,5,SEEK_SET);
    fseek(f,1,SEEK_CUR);
    fputc('z',f);

    fclose(f);
}
