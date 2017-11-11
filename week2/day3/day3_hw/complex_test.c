#include <stdio.h>
#include "complex.h"

enum {
    SIN = 1,
    COS = 2,
    EXP = 3,
    LOG = 4
};

int main (void){

    complex z;
    int j = 0;
  
    printf ("Enter Re: \n");
    scanf ("%lf", &Re(z));
    printf ("Enter Im: \n");
    scanf ("%lf", &Im(z));
    
    printf ("Choose function:\n(1)-SIN\n(2)-COS\n(3)-EXP\n(4)-LOG\n");
    scanf ("%d", &j);

    switch (j){
	
	case SIN:
	    SINC(z);
	    break;
	case COS:
	    COSC(z);
	    break;
	case EXP:
	    EXPC(z);
	    break;
	case LOG:
	    LOGC(z);
	    break;
	default:
	    printf ("There's no such function");
    }

    printf ("(%lf %lf)\n", Re(z), Im(z) );

    return 0;
}
