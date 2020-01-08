#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
char *mx_strcmp(char *s1, char *s2)
{
    while(*s1 != '\0')
    {
	if (*s1 != *s2)
	{
	    return s1;
	}
	s1++;
	s2++;
    }
    return s1;
}

char *mx_strnew(const int size)
{
    if (size < 0)
    {
	return NULL;
    }
    char *s = (char *) malloc(size + 1);
    for(int i = 0; i < size + 1; i++)
    {
	s[i] = '\0';
    }
    return s;
}

char *mx_file_to_str(char *file) {
    if (!file) return NULL;
    int k = 0;
    char buf[1];

    int f = open(file, O_RDONLY);
    if (f < 0) return NULL;
    int n = read(f, buf, sizeof(buf));
    if (n <= 0) return NULL;
    while (n > 0) {
    	k++;
    	n = read(f, buf, sizeof(buf));
    }
    close(f);
    
    
    f = open(file, O_RDONLY);
    char *s = mx_strnew(k);
    char *p = s;
    int m = read(f, buf, sizeof(buf));
    while (m > 0) {
    	*s = *buf;
    	m = read(f, buf, sizeof(buf));
    	s++;
    }    
    close(f);
	return p;
}

int main(int argc, char *argv[]) {
	
	char *str1 = mx_file_to_str(argv[1]);
	char *str2 = mx_file_to_str(argv[2]);

	printf("%s\n", mx_strcmp(str1, str2));
	return 0;
}
