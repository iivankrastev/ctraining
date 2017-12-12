#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
	int r = open("our_cdev", O_RDONLY);
	off_t s;

	if (r < 0) return 1;
	
	s = lseek(r, 3, SEEK_SET);

	if (s < 0)
		return 1;

	printf("%ld\n", s);
	
	close(r);
	
	return 0;
}
