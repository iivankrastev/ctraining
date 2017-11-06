#include "ringbuffer.h"

int main (void){

    short int i;
    ringbuf ring;

    if (init(&ring,16)){

	for (i = 0; i < 10; i++){
	    push(&ring,i);
	}

	print(&ring);
    }

    return 0;
}
