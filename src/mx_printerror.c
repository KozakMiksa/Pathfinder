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
        writbe(2, s, mx_strlen(s));
        exit(0);
    }
}

static void printerror_5(int i)
{
    char *s = mx_strjoin("error: line ", mx_itoa(i + 1));
    char *ss = mx_strjoin(s, " isn't valid");
    write(2, ss, mx_strlen(ss));
    exit(0);
}

static void error_4_5(char **arr)
{
    for(int i = 0; arr[0][i] != '\n'; i++)
    {
        if (mx_isdigit(arr[0][i]) == 0)
        {
            write(2, "error: line 1 isn't valid", 25);
            exit(0);
        }
    }
    for(int i = 1; arr[i] != NULL; i++)
    {
        int j = 0;
        for(j; arr[i][j] != '-'; j++)
        {
            if (mx_isalpha(arr[i][j]) == 0)
            {
                printerror_5(i);
            }
        }
        j++;
        for(j; arr[i][j] != ','; j++)
        {
            if (mx_isalpha(arr[i][j]) == 0)
            {
                printerror_5(i);
            }
        }
        j++;
        for(j; arr[i][j] != '\0'; j++)
        {
            if (mx_isdigit(arr[i][j]) == 0)
            {
                printerror_5(i);
            }
        }
    }   
}

void mx_printerror(int argc, char *argv)
{
    error_1_2_3(argc, argv);
    char *str_for_arr = mx_file_to_str(argv);
    char **arr = mx_strsplit(str_for_arr, '\n');
    char *str = mx_strnew(mx_strlen(str_for_arr));
    mx_strdel(str_for_arr);
    error_4_5(arr);
    int s = 0;
    for(int i = 1; arr[i] != NULL; i++)
    {
    	for(int j = 0; arr[i][j] != ','; j++)
    	{
    		while(mx_isalpha(arr[i][j]) == 1)
    		{
    			str[s++] = arr[i][j++];
    		}
    		str[s++] = ',';
    	}
    }
    mx_del_strarr(arr);
    arr = mx_strsplit(str, ',');
    
}
