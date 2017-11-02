#include <stdio.h>
#include <stdlib.h>

/*Example of labels usage*/

int main(int argc, char *argv[]){
    
    FILE *f1, *f2;
    int r, ret = 0;


    f1 = fopen("file", "r");
    
    if (!f1){
	ret = 1;
	goto fail_f1;
    }

    f2 = fopen("file2", "w+");

    if(!f2){
	ret = 2;
	goto fail_f2;
    }

    for (r = fgetc(f1); r >= 0; r = fgetc(f1)){
	fputc(r, f2);	
    }

    fclose(f2);
fail_f2:
    fclose(f1);
fail_f1:
    return ret;
}
