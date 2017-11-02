#include <stdio.h>
#include <stdlib.h>

/* Opening one file and copy it's content to other which is not created*/

int main(int argc, char *argv[]){
    
    FILE *in,
	 *out;

    int r;

    if (argc < 3)
	return 1;
    
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w+");
    
    if (!in || !out){
	fclose(in);
	fclose(out);
    }

    for (r = fgetc(in); r >= 0; r = fgetc(in)){
	fputc(r,out);	//Takes int and prints to FILE *
    }

    fclose(in);
    fclose(out);

    return 0;
}
