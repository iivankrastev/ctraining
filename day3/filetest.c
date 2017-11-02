#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    FILE *f;
    int r;

    /*If there's no arguments -> exit*/
    if (argc < 2)
	return 1;
    
    /*The file is first argument and it opens it for read*/
    f = fopen(argv[1], "r");
    
    /*If file is empty or can't open it will return NULL -> exit*/
    if (!f)
	return 2;

    /*Read every char from the file and print it on stdout*/
    for (r = fgetc(f); r >= 0; r = fgetc(f)){
	
	if ((char)(r & 0xff) == '\n')	//taking the lower bits only with mask and cast 
	    fputc(' ',stdout);
	else
	    fputc(r,stdout);	//cast not needed
    }
    
    fprintf(stdout,"\n");

    fclose(f);

    return 0;
}
