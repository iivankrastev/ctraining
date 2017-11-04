/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab . When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference?
*/

#include <stdio.h>

#define TABW 8
#define MAXLINE 1000

int mgetline(char line[],int lim);
void entab(char s[]);

int main(void)
{
	int len;
	char line[MAXLINE], t[MAXLINE];
  
	while((len = mgetline(line,MAXLINE)) > 0) {
    	entab(line);
		printf("%s", line);
	}

	return 0;
}


void entab(char s[]) {
	int i;
	int j;
	int tp = -1; 
	int sp = -1; 
	char c;
	
	for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
	s[j] = c;
		if (c == '\t') {
			tp = TABW - 1;
		} else
			tp++;

		if (c == ' ') {
			if (sp == -1)
				sp = tp;
		} else
			sp = -1;

		
		if (tp == TABW - 1) {
		
		    if (sp != -1) {
				int spacew = TABW - sp;
				j = j - spacew + 1;
				s[j] = '-';
				sp = -1;
			}	
		tp = -1;
		}
	}	

	s[j] = '\0';
	
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
  
