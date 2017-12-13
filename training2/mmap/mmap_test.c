#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

int main (void)
{
	int fd, r = 0, j;
	off_t size;
	void *map;
	char *c, cmap;
	
	fd = open("mmap_test", O_RDWR);
	if (fd < 0) {
		perror("open");
		r = -1;
		goto bad0;
	}
	
	size = lseek(fd, 0, SEEK_END);
	if (size < 0) {
		perror("lseek");
		r = -1;
		goto bad1;
	}
	
	map = mmap(NULL, (size_t)size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED) {
		perror("mmap");
		r = -1;
		goto bad1;
	}
	
	if (munmap(map, (size_t)size) < 0) {
		perror("munmap");
		r = -1;
	}
bad1:
	close(fd);
bad0:
	return r;
}
