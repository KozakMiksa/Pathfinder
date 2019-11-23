#include "path.h"

static void error_1_2_3(int num, char *file)
{
    if (num != 2)
    {
        write(2,"usage: ./pathfinder [filename]", 30);
        exit(0);
    }
    int fd = open(file, O_RDONLY);
    if (0 > fd)
    {
	char *str = mx_strjoin(mx_strjoin("file ", file), " doesn't exist");
        close(fd);
        write(2, str, mx_strlen(str));
        exit(0);
    }
    char buf;
    int c = read(fd, &buf, 1);
    if (c <= 0)
    {
	char *s = mx_strjoin(mx_strjoin("error: file ", file), " is empty");
        close(fd);
        write(2, s, mx_strlen(s));
        exit(0);
    }
}

void mx_printerror(int argc, char *argv)
{
    error_1_2_3(argc, argv);
    
}
