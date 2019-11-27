#include "path.h"

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
