
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
accum("abcd") // -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") // -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") // -> "C-Ww-Aaa-Tttt"

*/

char *accum(const char *source);
char *char_to_string(char c);
size_t sum_size(size_t len);

int main (void){

	//(void)accum("abcd");
	printf("%d\n", sum_size(4));

	return 0;
}

char *char_to_string(char c){

	char *s = (char *)malloc(2 * sizeof(char));
	s[strlen(s)] = c;
	s[strlen(s) + 1] = '\0';
	return s;
}

size_t sum_size(size_t len){

	size_t s = 0;
	while(len--)
		s += len;

	return s;
}


char *accum(const char *source){

	//char *s;
	int i, j;

	for (i = 0; i < strlen(source); i++){
		for (j = 0; j < (i+1); j++){
			if (j == 0)
				printf("%c", toupper(source[i]));
			else
				printf("%c", source[i]);
		}
		if (i != (strlen(source) - 1))
			printf("-");
	}

	return NULL;
}
