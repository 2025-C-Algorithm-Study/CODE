#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	int eng[26][2];
	for (int i = 0;i < 26;i++) {
		eng[i][0] = 'a' + i;
		eng[i][1] = 0;
	}
	char arr[1000001];
	scanf("%1000000s", arr);

	for (int w = 0;arr[w] != '\0';w++) {
		arr[w] = tolower(arr[w]);
	}
	
	int N = strlen(arr);

	for (int j = 0;j < N;j++) {
		for (int k = 0;k < 26;k++) {
			if (arr[j] == eng[k][0]) {
				eng[k][1]++;
				break;
			}
		}
	}

	int big = eng[0][1];
	int max = 0;
	for (int a = 1;a < 26;a++) {
		if (eng[a][1] > big) {
			big = eng[a][1];
			max = a;
		}
	}

	int mmax = 0;
	for (int q = 0;q < 26;q++) {
		if (eng[q][1] == big) {
			mmax++;
		}
	}

	if (mmax > 1) {
		printf("?\n");
	}
	else
		printf("%c\n", toupper(eng[max][0]));
	
	
	return 0;
}