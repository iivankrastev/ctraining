#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char *buf_f1, *buf_f2;
    FILE *f1, *f2, *fx;
    int i, j = 1;
    long len;

    f1 = fopen("file1", "r");
    f2 = fopen("file2", "r");
    fx = fopen("filex", "w+");

    fseek(f1, 0, SEEK_END);
    len = (ftell(f1) - 1);
    fseek(f1, 0, SEEK_SET);

    buf_f1 = (char *)malloc(len*sizeof(char));
    buf_f2 = (char *)malloc(len*sizeof(char));

    while(!feof(f1) && !feof(f2)){
	(void)fread(buf_f1, sizeof(char), len, f1);
	(void)fread(buf_f2, sizeof(char), len, f2);
    }

    for (i = 0; i < len; i++){
	if (!(i&1)){
	    (void)fputc((int)(buf_f2[j]),fx);
	    j += 2;	
	    if (j > len)
		break;
	}
	else{
	    if (i != len)
		(void)fputc((int)(buf_f1[i]),fx);
	}
    }
    
    printf("file1 length: %ld\n", ftell(f1));
    printf("file2 length: %ld\n", ftell(f2));
    printf("filex length: %ld\n", ftell(fx));
    
    fclose(fx);
    fclose(f2);
    fclose(f1);
    free(buf_f2);
    free(buf_f1);
}
