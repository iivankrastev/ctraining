//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

//Promenlivite mogat da budat izrazi i zatova se slagat v skobi

#define XCHG(temp, a, b)\
    do{\
	(temp) = (a);\
	(a) = (b);\
	(b) = (temp);\
    }while(0)


int main(void){

    char t, a = 'a',
	    b = 'b';

  //  printf("a : %c\nb : %c\n",a,b);
    XCHG(t, a, b);
  //  printf("a : %c\nb : %c\n",a,b);

    return 0;
}

