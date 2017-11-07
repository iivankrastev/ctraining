#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char *buf_f1, *buf_f2;
    FILE *f1, *f2, *fx;
    int i, 
	j = 1;
    
    buf_f1 = (char *)calloc(16, sizeof(char));
    buf_f2 = (char *)calloc(16, sizeof(char));

    f1 = fopen("file1", "r");
    f2 = fopen("file2", "r");
    fx = fopen("filex", "w+");

    while(!feof(f1) && !feof(f2)){
	(void)fread(buf_f1, sizeof(char), 16, f1);
	(void)fread(buf_f2, sizeof(char), 16, f2);
    }

    for (i = 0; i < 16; i++){
	if (!(i&1)){
		(void)fputc((int)(buf_f2[j]),fx);
		j += 2;
	}
	else
	    (void)fputc((int)(buf_f1[i]),fx);
    }

    fclose(fx);
    fclose(f2);
    fclose(f1);
    free(buf_f2);
    free(buf_f1);
    
/*
    for (i = 0; i < 10; i++)
	printf ("%d\n", (i&1));
  */  
}
