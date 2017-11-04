/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parame-
ter?
*/

#include <stdio.h>

#define TABW 8
#define MAXLINE 1000

int mgetline(char line[],int lim);
void detab(char src[], char tar[]);

int main(void)
{
	int len;
	char line[MAXLINE], t[MAXLINE];
  
	while((len = mgetline(line,MAXLINE)) > 0) {
		detab(line, t);
		printf("%s",t);
	}

	return 0;
}

void detab(char src[], char tar[]) {
	int i;
	int j;
	int spacew;
	char c;
	
	for (i = 0, j = 0; (c = src[i]) != '\0'; i++) {
		if (c != '\t') {
			tar[j++] = c;
		} else { 
		spacew = TABW - j % TABW;
		
		while (spacew-- > 0)
			tar[j++] = '-';
 		}
	}
  
	tar[j] = '\0';

	return;
}

int mgetline(char s[],int lim) {
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c !='\n';++i)
		s[i] = c;

    if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
  
