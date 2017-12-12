#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/errno.h>
#include <string.h>
#include <stdio.h>

#pragma pack(1)
struct msg {
	char flag;
	char message[64];
};
#pragma pack()


int main (void)
{
	struct msg msg;
	int r = open("our_cdev", O_RDONLY);
	
	if (r < 0) return 1;
	
	if (read(r, &msg, sizeof(msg)) < 0)
		return 1;
	
	if (msg.flag)
		printf("%s", msg.message);

	close(r);
	
	return 0;
}
