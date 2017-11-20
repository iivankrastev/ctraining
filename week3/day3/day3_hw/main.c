#include "tokenize.h"

int main(void) {

    char *s1 = "abcdefgcdefgcde";
    char *s2 = "e";
    char *t;

    tokenize (s1, s2, &t);

    return 0;
}
