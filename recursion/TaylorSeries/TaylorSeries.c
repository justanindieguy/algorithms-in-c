#include <stdio.h>
#include <stdlib.h>

double e(int x, int n) {

	static double pow = 1, fact = 1;
	double result;

	if (n == 0)
		return 1;
	result = e(x, n - 1);
	pow = pow * x;
	fact = fact * n;
	return result + pow / fact;

}

int main() {
	double result = e(1, 5);
	printf("The result is: %lf", result);

	return 0;
}
