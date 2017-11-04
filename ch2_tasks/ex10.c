/*
Exercise 2-10. Rewrite the function lower , which converts upper case letters
to lower case, with a conditional expression instead of if-else .
*/

#include <stdio.h>

unsigned char llower(char);

int main(void) {
    
    int i = 0;
    char test[] = "AaaabBcD1234";
    puts(test);
    while(test[i] != '\0')
	putchar(llower(test[i++]));
    putchar('\n');
}

unsigned char llower(char x) {
    return (x >= 'A' && x <= 'Z') ? x = x - 'A' +'a' : x;
}
