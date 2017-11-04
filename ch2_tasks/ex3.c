/*
Exercise 2-3. Write the function htoi(s) , which converts a string of hexa-
decimal digits (including an optional 0x or 0X ) into its equivalent integer value.
The allowable digits are 0 through 9 , a through f , and A through F .
*/
#include <stdio.h>
#include <ctype.h>

unsigned long htoi(const char s[]);

int main(void)
{
        printf("%ld\n", htoi("0xFA9C"));
        printf("%ld\n", htoi("0xFFFF"));
        printf("%ld\n", htoi("0x1111"));
        printf("%ld\n", htoi("0xBCDA"));
        return 0;
}

unsigned long htoi(const char s[])
{
        unsigned long n = 0;
	int i, c;
	
        for (i = 0; s[i] != '\0'; i++) {
                c = tolower(s[i]);
                if (c == '0' && tolower(s[i+1]) == 'x')
                        i++;
                else if (c >= '0' && c <= '9')
                        n = 16 * n + (c - '0');
                else if (c >= 'a' && c <= 'f')
                        n = 16 * n + (c - 'a' + 10);
        }
        return n;
}
