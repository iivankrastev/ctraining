#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

static const char digits[16] = {
    '0', '1', '2', '3',
    '4', '5', '6', '7',
    '8', '9', 'a', 'b',
    'c', 'd', 'e', 'f'
};

void dump(FILE *stream, void *_obj, size_t n_elem){
    
    uint8_t *obj = (uint8_t *)_obj;
    size_t i;

    for (i = 0; i < n_elem; i++) {
	fprintf(stream, "%c", digits[obj[i] >> 4]);
	fprintf(stream, "%c", digits[obj[i] & 0x0fu]);
	if ((i & 0x0fu) == 0x0fu)
	    fprintf(stream, "\n");
	else
	    fprintf(stream, " ");
    }
    fprintf(stream, "\n");

    return;
}

int main (void) {

#pragma pack(1)
    struct test {
	uint32_t a;
	void *p;
    } t;
#pragma pack()
i
    uint32_t i;

    t.p = (void *)&t;

    for (i = 0; i < 1024; i ++){
	t.a = htonl(i);
	dump(stdout, &t, sizeof(struct test));
    }

    return 0;
}
