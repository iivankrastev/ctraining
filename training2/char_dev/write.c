#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/errno.h>
#include <string.h>
#include <unistd.h>

#pragma pack(1)
struct msg {
	char flag;
	char message[64];
};
#pragma pack()


int main (void)
{
	struct msg msg;
	int r = open("our_cdev", O_RDWR);
	
	memset(&msg, 0, sizeof (msg));
	msg.flag = 1;
	strcpy(msg.message, "tragediq\n");
	
	if (r < 0) return 1;
	
	if (write(r, &msg, sizeof(msg)) < 0)
		return 1;
	
	close(r);
	
	return 0;
}

