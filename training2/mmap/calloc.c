#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

void *my_calloc(size_t nmemb, size_t size)
{
	char *mem;
	int fd;
	void *r = (void *)(&mem[1]);
	size_t len = nmemb * size;

	fd = open("/dev/zero", O_RDWR);

	mem = (void *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0 );
	if (mem == MAP_FAILED) {
		perror("mmap");
		r = NULL;
		goto exit;
	}
		
    	*mem = len;
exit:
	close(fd);
	return r;
}

int main (void) 
{

	char *p;
	int r = 0;
	
	p = (char *)my_calloc(4, sizeof(char));
	if (!p) {
		r = 1;
		goto exit;
	}

	printf("%ld\n", sizeof(p));

exit:
	return r;
}


