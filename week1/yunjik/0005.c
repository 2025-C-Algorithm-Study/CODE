#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


struct submean {
	char sub[51];
	double point;
	char grade[3];
};

int main() {
	struct submean sm[20];
	for (int i = 0; i < 20; i++) {
		scanf("%s %lf %s", sm[i].sub, &sm[i].point, sm[i].grade);
	}

	double sum=0, pointsum=0;

	for (int j = 0;j < 20;j++) {
		if (sm[j].grade[0] == 'P')continue;

		double ppoint = 0;
		if (strcmp(sm[j].grade, "A+") == 0)ppoint = 4.5;
		else if (strcmp(sm[j].grade, "A0") == 0)ppoint = 4.0;
		else if (strcmp(sm[j].grade, "B+") == 0)ppoint = 3.5;
		else if (strcmp(sm[j].grade, "B0") == 0)ppoint = 3.0;
		else if (strcmp(sm[j].grade, "C+") == 0)ppoint = 2.5;
		else if (strcmp(sm[j].grade, "C0") == 0)ppoint = 2.0;
		else if (strcmp(sm[j].grade, "D+") == 0)ppoint = 1.5;
		else if (strcmp(sm[j].grade, "D0") == 0)ppoint = 1.0;
		else if (strcmp(sm[j].grade, "F") == 0)ppoint = 0.0;

		pointsum += sm[j].point;
		sum += sm[j].point * ppoint;
	}

	printf("%.6f\n", sum / pointsum);

	return 0;
}