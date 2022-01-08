#include <stdio.h>
#include <stdlib.h>

float array_avg_reduce(float arr[], int size) {
	float avg, sum = 0;
	int i;

	for (i = 0; i < size; ++i)
		sum += arr[i];
	avg = sum / size;
	return avg;
}

float * array_map(float arr[], int size, char option, int param) {
	float * new_arr;
	int i;
	new_arr = (float * ) malloc(size * sizeof(float));
	switch(option) {
	case '+':
		for (i = 0; i < size; ++i)
			* (new_arr + i) = * (arr + i) + param;
		break;
	case '-':
		for (i = 0; i < size; ++i)
			* (new_arr + i) = * (arr + i) - param;
		break;
	case '*':
		for (i = 0; i < size; ++i)
			* (new_arr + i) = * (arr + i) * param;
		break;
	case '/':
		for (i = 0; i < size; ++i)
			* (new_arr + i) =  * (arr + i) / param;
		break;
	default:
		return arr;
	}
	return new_arr;
}

int main(int argc, char * * argv) {
	unsigned int size, i;
	float * arr1, * arr2, param, avg;
	char ch;

	printf("Enter array size: ");
	scanf("%d", & size);
	arr1 = (float * ) malloc(size * sizeof(float));

	for (i = 0; i < size; i++)
		scanf("%f", (arr1 + i));

	avg = array_avg_reduce(arr1, size);
	printf("The avenger array is %.2f\n", avg);

	printf("Enter operation transform, use -, +, * or /: ");
	fseek(stdin, 0, SEEK_END);
	ch = getchar();

	printf("Enter parameter transformation: ");
	scanf("%f", & param);

	arr2 = array_map(arr1, size, ch, param);
	free(arr1);

	printf("New array is: ");
	for (i = 0; i < size; i++)
		printf("%.2f ", * (arr2 + i));
	free(arr2);
	puts("");
	printf("%d", sizeof(double));
	return 0;
}
