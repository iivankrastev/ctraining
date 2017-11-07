#include <stdio.h>


int main (void){
    
    FILE *f;
    f = fopen("file","r+");

    fseek(f,0,SEEK_SET);
    fputc('z',f);
    fseek(f,4,SEEK_SET);
    fputc('z',f);

    fclose(f);
}
