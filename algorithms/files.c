#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
	int z;
	char info[20];
} POINT;

typedef struct student {
	float n1;
	float n2;
	float n3;
	char name[20];
} STUDENT;

void map() {
	FILE * f;
	char ch;
	point p;
	const int MAX_SIZE = 20;
	int i, n;
	char text[400];

	f = fopen("coordenates.dat", "w");
	if (!f) {
		puts("Can't open file or file doesn't exist.");
		exit(1);
	}

	do {
		printf("Enter x : ");
		scanf("%d", & p.x);

		printf("Enter y : ");
		scanf("%d", & p.y);

		printf("Enter z : ");
		scanf("%d", & p.z);

		printf("Enter informations: ");
		fseek(stdin, 0, SEEK_END);
		fgets(p.info, MAX_SIZE, stdin);

		fwrite( & p, sizeof(p), 1, f);

		puts("Do you want to add another point (y/n) : ");
		fseek(stdin, 0, SEEK_END);
		ch = getchar();

	} while (ch == 'y');
	printf("save on file...");
	fclose(f);

	f = fopen("coordenates.dat", "r");
	if (!f) {
		puts("Can't open file or file doesn't exist.");
		exit(1);
	}

	printf("\n\tx\ty\tz\tinfo\n");
	while (fread( & p, sizeof(p), 1, f) > 0)
		printf("\n\t%d\t%d\t%d\t%s", p.x, p.y, p.z, p.info);
	fclose(f);

}
void spredsheet() {
	FILE * f;
	char ch;
	point p;
	const int MAX_SIZE = 20;
	int i, n;
	char text[400];

	f = fopen("students.dat", "w");
	printf("inform a number of students:");
	scanf("%d", & n);
	student s[n];

	for (i = 0 ; i < n; i++) {
		printf("%d - Enter n1 n2 n3:" , i);
		scanf("%f%f%f", & s[i].n1, & s[i].n2, & s[i].n3);
		printf("%d - Enter name:" , i);
		fseek(stdin, 0, SEEK_END);
		fgets(s[i].name, MAX_SIZE, stdin);
		fprintf(f, "%f %f %f %s\n", s[i].n1, s[i].n2,  s[i].n3, s[i].name);
	}
	fclose(f);

	f = fopen("students.dat", "r");
	for (i = 0 ; i < n; i++) {
		fscanf(f, "%f%f%f", & s[i].n1, & s[i].n2, & s[i].n3);
		fprintf(stdout, "%f %f %f\t%s\n", s[i].n1, s[i].n2, s[i].n3, s[i].name);
	}
	fclose(f);
}
void book() {
	FILE * f;
	char ch;
	point p;
	const int MAX_SIZE = 20;
	int i, n;
	char text[400];

	f = fopen("text.dat", "w");
	printf("enter a text:");
	fseek(stdin, 0, SEEK_END);
	fgets(text, 400, stdin);
	fputs(text, f);
	fclose (f);

	f = fopen("text.dat", "r");
	char c;
	while((c = fgetc(f)) != EOF )
		printf("%c", c);
	fclose(f);

}

int main() {
	map();
  return 0;
}
