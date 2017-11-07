#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char *buf;
    FILE *f1, *f2, *f3;
    int i;

    buf =(char *)calloc(16, sizeof(char));

    f1 = fopen("file", "r");
    f2 = fopen("fileodd", "w+");
    f3 = fopen("fileeven", "w+");

    while(!feof(f1)){
	(void)fread(buf, sizeof(char), 16, f1);
    }
    //Ne e mnogo vqrno
    for (i = 0; i < 16; i++)
	if (i%2)
	    (void)fputc((int)(buf[i]),f2);
	else
	    (void)fputc((int)(buf[i]),f3);


    fclose(f2);
    fclose(f1);
    free(buf);
}
