#include <stdio.h>
int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	unsigned long long res;
	res = 1;
	for (int i = 2; i <= n; ++i)
		res = res * i;
	printf("n! =  %llu", res);
}