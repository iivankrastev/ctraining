#include <stdio.h>

void rcomment(int c);
void incomment(void);
void echo_quote(int c);

int main(void)
{
    int r;
	char c;

	FILE *f;

	f = fopen("cprogram", "r");
			if (!f)
				return 1;
	

	for (r = fgetc(f); r >= 0; r = fgetc(f))
		rcomment(r);

	fclose(f);
    return 0;
}

void rcomment(int c)
{
    int d;
    if( c == '/')
    {
        if((d=getchar())=='*')
         incomment();
        else if( d == '/') {
            putchar(c);
            rcomment(d);
        }
        else {
            putchar(c);
            putchar(d);
        }
    }
    else if( c == '\''|| c == '"')
        echo_quote(c);
    else
        putchar(c);
	
	return;
}

void incomment()
{
    int c,d;
     
    c = getchar();
    d = getchar();

    while(c!='*' || d !='/') {
        c =d;
        d = getchar();
    }
	
	return;
}

void echo_quote(int c)
{
    int d;

    putchar(c);
    
    while((d=getchar())!=c)
    {
        putchar(d);
        
        if(d = '\\')
            putchar(getchar());
    }
    putchar(d);

	return;
}
