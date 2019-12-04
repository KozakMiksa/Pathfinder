#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

int mx_strlen(const char *s)
{
    int counter = 0;
    while(*s != '\0')
    {
	counter++;
	s++;
    }
    return counter;
}

int mx_strcmp(const char *s1, const char *s2)
{
    while(*s1 != '\0')
    {
	if (*s1 != *s2)
	{
	    return *s1 - *s2;
	}
	s1++;
	s2++;
    }
    return *s1 - *s2;
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

char *mx_strcpy(char *dst, const char *src)
{
    char *s = dst;
    while(*src != '\0')
    {
	*dst = *src;
	dst++;
	src++;
    }
    *dst = '\0';
    return s;
}
char *mx_strdup(const char *str)
{
    char *s = mx_strcpy(mx_strnew(mx_strlen(str)), str);
    return s;
}

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for(int i = 0; i <= len2; i++)
    {
	s1[len1] = s2[i];
	len1++;
    }
    return s1;
}

char *mx_strjoin(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 == NULL)
    {
	return NULL;
    }
    if (s1 == NULL)
    {
	return mx_strdup(s2);
    }
    else if (s2 == NULL)
    {
	return mx_strdup(s1);
    }
    char *s = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    s = mx_strcpy(s, s1);
    return mx_strcat(s, s2);
}

void mx_strdel(char **str)
{
	free(*str);
	*str = NULL;
}

bool mx_isspace(char c) {
    if (c == ' ' || c =='\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v') {
        return true;
    }
    else {
        return false;
    }
}

bool mx_isdigit(char c) {
    if (c >= 48 && c <= 57) {
        return true;
    }
    else {
        return false;
    }
}

bool mx_isalpha(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return true;
    }
    else {
        return false;
    }
}

char *mx_file_to_str(const char *file) {
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

int mx_count_words(const char *str, char c)
{
	int count = 0;
	if (str == NULL)
	{
		return -1;
	}
	while(*str != '\0')
	{
		if (*str != c)
		{
			count++;
			while(*str != c && *str != '\0')
			{
				str++;
			}
                        if (*str == '\0')
			{
			    return count;
			}
		}
		str++;
	}
	return count;
}

void mx_del_strarr(char ***arr)
{
    char **p = *arr;
    while (*p != NULL)
    {
	    mx_strdel(p);
	    p++;
    }
    free(*arr);
    *arr = NULL;
}

int strlen_mod(const char *s, char c)
{
    int count = 0;
    while(*s != c && *s != '\0')
    {
	count++;
        s++;
    }
    return count;
}
char **mx_strsplit(const char *s, char c)
{
    if (s == NULL)
    {
	return NULL;
    }
    int size = mx_count_words(s, c);
    char **arr = malloc((size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
	while(*s == c && *s != '\0')
	{
	    s++;
	}
	arr[i] = mx_strnew(strlen_mod(s, c));
	int j = 0;
	while(*s != c && *s != '\0')
	{
	    arr[i][j] = *s;
	    s++;
	    j++;
	}
    }
    arr[size] = NULL;
    return arr;
}
char *mx_itoa(int number)
{
	int size = 1;
	int numbers = 1;
	long copy_n = number;
	if (copy_n < 0)
	{
		copy_n *= -1;
	}
	while(copy_n / numbers > 9)
	{
		numbers *= 10;
		size++;
	}
	char *s;
	if (number < 0)
	{
		s = malloc(size + 2);
		s[size + 1] = '\0';
		s[0] = '-';
		size = 1;
	}
	else
	{
		s = malloc(size + 1);
		s[size] = '\0';
		size = 0;
	}
	while(numbers != 0)
	{
		s[size] = copy_n / numbers + 48;
		copy_n %= numbers;
		numbers /= 10;
		size++;
	}
	return s;
}

int mx_atoi(char *s) {
	int m = 1;
	int n = 0;
	int i = 0;
	while (mx_isspace(s[i]) == 1) {
		i++;
	}
	if (s[i] == '-' || s[i] == '+' || mx_isdigit(s[i]) == 1) {
		if (s[i] == '-') {
			m = m * -1;
			i++;
			while (mx_isdigit(s[i]) == 1) {
				n = (10 * n) + s[i] - 48;
				i++;
			}
		}
		else {
			if (s[i] == '+')
				i++;
			while (mx_isdigit(s[i]) == 1) {
				n = (10 * n) + s[i] - 48;
				i++;
			}
		}
	}
	return n * m;
}

static void error_1_2_3(int num, char *f) {
    if (num != 2) {
        write(2,"usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    int fd = open(f, O_RDONLY);
    if (0 > fd) {
        char *ss = mx_strjoin("error: file ", f);
        char *s = mx_strjoin(ss, " does not exist\n");
        close(fd);
        write(2, s, mx_strlen(s));
        exit(0);
    }
    char buf;
    int c = read(fd, &buf, 1);
    if (c <= 0) {
        char *s = mx_strjoin(mx_strjoin("error: file ", f), " is empty\n");
        close(fd);
        write(2, s, mx_strlen(s));
        exit(0);
    }
}

static void printerror_5(int i) {
    char *s = mx_strjoin("error: line ", mx_itoa(i + 1));
    char *ss = mx_strjoin(s, " isn't valid\n");
    write(2, ss, mx_strlen(ss));
    exit(0);
}

static void error_4_5(char **arr) {
    for (int t = 0; arr[0][t] != '\0'; t++) {
        if (mx_isdigit(arr[0][t]) == 0) {
            write(1, "error: line 1 isn't valid\n", 26);
            exit(0);
        }
    }
    for (int i = 1; arr[i] != NULL; i++) {
        int j = 0;
        for (; arr[i][j] != '-'; j++)
            if (mx_isalpha(arr[i][j]) == 0)
                printerror_5(i);
        j++;
        for (; arr[i][j] != ','; j++)
            if (mx_isalpha(arr[i][j]) == 0)
                printerror_5(i);
        j++;
        for (; arr[i][j] != '\0'; j++)
            if (mx_isdigit(arr[i][j]) == 0)
                printerror_5(i);
    }   
}

static char *arr_to_str(char **arr, char *str_new) {
    char *str = mx_strnew(mx_strlen(str_new));
    //mx_strdel(&str_new);
    int s = 0;
    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != ',';) {
            str[s++] = arr[i][j++];
            if (mx_isalpha(arr[i][j]) != 1) {
                str[s++] = ',';
                if (arr[i][j] != ',')
                    j++;
            }
        }
    }
    return str;
}

static int arrlen(char **arr) {
    int count = 0;
    while(arr[count] != NULL)
    	count++;
    return count;
}

char **mx_deldub(char **arr1)
{
    char **arr2 = malloc((arrlen(arr1) + 1) * sizeof(char *));
    int c = 1;
    int len = mx_strlen(arr1[0]);
    arr2[0] = mx_strnew(len);
    for (int n = 0; n < len; n++)
    	arr2[0][n] = arr1[0][n];
    for (int i = 1; arr1[i] != NULL; i++) {
    	int j = 0;
    	for (; mx_strcmp(arr1[i], arr2[j]) != 0 && j < c - 1; j++);
    	if (j == c - 1 && mx_strcmp(arr1[i], arr2[j]) != 0) {
    		len = mx_strlen(arr1[i]);
    		arr2[c] = mx_strnew(len);
    		for (int n = 0; n < len; n++)
    			arr2[c][n] = arr1[i][n];
    		c++;
    	}
    }
    arr2[c] = NULL;
    return arr2;
}

char **mx_printerror(char *a) {
    //error_1_2_3(argc, argv);
    char *str = a;
    char **arr = mx_strsplit(str, '\n');
    error_4_5(arr);
    int island_size = mx_atoi(arr[0]);
    str = arr_to_str(arr, str);
    mx_del_strarr(&arr);
    arr = mx_strsplit(str, ',');
    mx_strdel(&str);
    char **err6 = mx_deldub(arr);
    mx_del_strarr(&arr);
    int i = 0;
    for (; err6[i] != NULL; i++);
    if (i != island_size) {
        write(2, "error: invalid number of islands\n", 33);
        exit(0);
    }
    return err6;
}

void mx_printstr(const char *s)
{
    write(1, s, mx_strlen(s));
}

void mx_printchar(char c)
{
    write(1, &c, 1);
}

void mx_print_strarr(char **arr, const char *delim)
{
    int i = 0;
    while(arr[i] != NULL)
    {
    mx_printstr(arr[i]);
    if (arr[i + 1] != NULL)
    {
        mx_printchar(*delim);
    }
    i++;
    }
    mx_printchar('\n');
}

void mx_printint(int n)
{
    int count = 1;
    long int nn = n;
    if (nn < 0)
    {
    nn = nn * -1;
    mx_printchar('-');
    }
    while(nn / count > 9)
    {
    count *= 10;
    }
    while(count >= 1)
    {
    mx_printchar(nn / count + 48);
    nn %= count;
    count /= 10;
    }
 }  

typedef struct rib
{
    char *island1;
    char *island2;
    int dist;
    struct rib *next;
} rib_t;

typedef struct path
{
    char *from;
    char *to;
    int distance;
    int value;
    struct path *next;
} path_i;

int hesh_f(char **arr, char *str)
{
    int num = 0;
    while (mx_strcmp(arr[num++], str) != 0);
    return num - 1;
}

rib_t *create_rib(char *island1, char *island2, int dist)
{
    rib_t *new_rib = malloc(sizeof(rib_t));
    new_rib->island1 = island1;
    new_rib->island2 = island2;
    new_rib->dist = dist;
    new_rib->next = NULL;
    return new_rib;
}

void link_rib(rib_t **node_r, char *island1, char *island2, int dist)
{
    rib_t *n = *node_r;
    rib_t *node = create_rib(island1, island2, dist);
    while (n->next != NULL)
        n = n->next;
    n->next = node;
    //node->next = NULL;
}
int superlen(char *str, int *c2) {
    int c1 = 0;
    while (*str != '-') {
        c1++;
        str++;
    }
    str++;
    while (*str != ',') {
        *c2++;
        str++;
    }
    return c1;
}
void separator(char *str, char *i1, char *i2, int *d) {
    while (*str != '-') {
        *i1 = *str;
        i1++;
        str++;
    }
    str++;
    while (*str != ',') {
        *i2 = *str;
        i2++;
        str++;
    }
    str++;
    *d = mx_atoi(str);
}
rib_t *inlists(char **arr) {
    rib_t *new = NULL;
    for (int i = 1; arr[i] != NULL; i++) {
        int c2 = 0;
        int c1 = superlen(arr[i], &c2);
        char *island1 = mx_strnew(c1);
        char *island2 = mx_strnew(c2);
        separator(arr[i] ,island1, island2, &c2);
        if (i == 1)
            new = create_rib(island1, island2, c2);
        else
            link_rib(&new, island1, island2, c2);
    }
    return new;
}

int main() {
    struct rib;
    char s[] = "4\nAaa-Bbb,5\nAaa-Ccc,3\nBbb-Ccc,4\nCcc-Eee,2";
    char **arr = mx_printerror(s);
    //mx_print_strarr(arr, "\n");
    char **arr1 = mx_strsplit(s, '\n');
    mx_print_strarr(arr1, "\n");
    rib_t *islands = inlists(arr1);
    while (islands->next != NULL) {
        mx_printstr(islands->island1);
        mx_printstr(islands->island2);
        mx_printchar('\n');
        //mx_printint(islands->dist);
        mx_printint(hesh_f(arr, islands->island1));
        mx_printchar(' ');
        mx_printint(hesh_f(arr, islands->island2));
        mx_printchar('\n');
        islands = islands->next;
    }
    mx_printstr(islands->island1);
    mx_printstr(islands->island2);
    mx_printchar('\n');
    mx_printint(hesh_f(arr, islands->island1));
    mx_printchar(' ');
    mx_printint(hesh_f(arr, islands->island2));
    mx_printchar('\n');
    
    //system("leaks -q pathfinder");
    return 0;
}