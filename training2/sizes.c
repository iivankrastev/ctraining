#include <stdio.h>
#include <stdint.h>

int main (void)
{
    uint32_t a[4];

    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(a[0]));
    printf("%ld\n", sizeof(a) / sizeof(a[0]));
    
    return 0;
}

