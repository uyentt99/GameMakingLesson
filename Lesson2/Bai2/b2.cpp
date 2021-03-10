#include <stdio.h>
int main() {
	long long n;
	do {
		printf("Enter a positive integer: ");
		scanf("%lld", &n);
		printf("Input number: %lld\n", n);
	} while (n <= 0);
}