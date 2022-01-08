#include<stdio.h>

int val_sqr(int x) 
{
	   return x * x;	
} 

void ref_sqr(int *x)
{
	*x *= *x;
}

int main(int argc, char** argv)
{
	int n1 = 2, n2 = 2, ans;
	ref_sqr(&n2);
	printf("ref_sqr: 2^2 = %d\n", n2);
	ans = val_sqr(n1);
	printf("val_sqr: 2^2 = %d\n", ans);
	return 0;
}