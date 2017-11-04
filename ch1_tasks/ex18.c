#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[],int lim);
int removetrail(char s[]);

int main(void)
{
	int len;
	char line[MAXLINE];
  
	while((len = mgetline(line,MAXLINE)) > 0)
		if(removetrail(line) > 0)
		printf("%s",line);

	return 0;
}

int removetrail(char s[])
{
	int i;
	int countert = 0;

	for(i=0; s[i] != '\n'; ++i)		
		;
	--i;

	for(i > 0; ((s[i] == ' ') || (s[i] =='\t'));--i) {
		countert++;
	;
	}   


	if( i >= 0) 
	{
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	printf("Removed %d tabs from end of line\n", countert);
	
	countert = 0;

	return i;
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
  
