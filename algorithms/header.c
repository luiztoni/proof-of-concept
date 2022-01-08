#include "header.h"

long fat(long n) {
	int i;
	long x = 1;
	for (i = 1; i <= n; i++) {
		x = x * i;
	}
	return x;
}
