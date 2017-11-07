#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char *buf;
    FILE *f1, *f2;
    int i;

    buf =(char *)calloc(16, sizeof(char));

    f1 = fopen("file", "r");
    f2 = fopen("filemod", "w+");

    while(!feof(f1)){
	(void)fread(buf, sizeof(char), 16, f1);
    }

    for (i = 0; i < 16; i+=2)
	(void)fputc((int)(buf[i]),f2);

    fclose(f2);
    fclose(f1);
    free(buf);
}
