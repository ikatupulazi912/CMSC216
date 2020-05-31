#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("bitch.txt",O_RDWR|O_CREAT, 0);
	const char* buf = "Dog";
	write(fd, buf, 3);

	return 1;
	


}
