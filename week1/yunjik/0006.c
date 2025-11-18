#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
    char eng[101];
    
    scanf("%100s", eng);
    char copy[101];
    char* p = eng;
    char* q = copy;
    while (*p != '\0') {
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';

    int i = 0, j = strlen(eng) - 1;
    while (i < j) {
        char temp = eng[i];
        eng[i] = eng[j];
        eng[j] = temp;
        i++; 
        j--;
    }

    if (strcmp(eng, copy) == 0)
        printf("1\n");
    else
        printf("0\n");

	return 0;
}