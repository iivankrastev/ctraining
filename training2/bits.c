#include <stdint.h>
#include <stdio.h>
#include <string.h>

void setbit (uint32_t *i, int n, int val)
{
    /* val is 0 or 1 */
    uint32_t mask = 1u << n;
    
    if (val)	*i |= mask;
    else *i &= ~mask;

    return;
}
/* Return bits in range */
uint32_t getbits (uint32_t i, int from, int to)
{
    return (i >> from) & ((1u << (to - from + 1u)) - 1u);
}
/* More generic */
void setbool (uint32_t *i, int n, int val)
{
    int idx = n / 32;
    uint32_t mask = 1u << (n % 32);
    
    if (val)	i[idx] |= mask;
    else i[idx] &= ~mask;

    return;
}

int getbool (uint32_t *i, int n)
{
    int idx = n / 32;
    uint32_t mask = 1u << (n % 32);

    return !!(i[idx] & mask);
}

int main (void)
{
    uint32_t boolean[4];
    int j, k;

    /*
    (void)memset(boolean, 0 , sizeof(boolean));

    for (j = 0; j < 128; j++)
	setbool(boolean, j, 1);

    */

    /* Sieve of Erathosthenes */
/*
    for (j = 2; j < 128; j++)
	if (getbool(boolean, j)) 
	    for (k = 2 * j; k < 128; k += j)
		setbool(boolean, k, 0);

    for (j = 0; j < 128; j++)
	printf("%d\t%d\n", j, getbool(boolean, j));
*/
    return 0;
}

