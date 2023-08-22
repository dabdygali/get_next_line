#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

	printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	fd = open("file", O_RDWR);
	printf("fd = %i\n", fd);
	line = get_next_line(fd);
	printf("1:  %s\n", line);
	line = get_next_line(fd);
	printf("2:  %s\n", line);
	line = get_next_line(fd);
	printf("3:  %s\n", line);
	line = get_next_line(fd);
	printf("4:  %s\n", line);
	line = get_next_line(fd);
	printf("5:  %s\n", line);
	line = get_next_line(fd);
	printf("6:  %s\n", line);
	line = get_next_line(fd);
	printf("7:  %s\n", line);
	line = get_next_line(fd);
	printf("8:  %s\n", line);
	line = get_next_line(fd);
	printf("9:  %s\n", line);
	close(fd);
	return (1);
}
