#include <stdio.h>
#include <stdlib.h>

double iTaylorSeries(int x, int n) {

	double result = 1;

	for (; n > 0; n--) {
		result = 1 + (double)x / n * result;
	}

	return result;

}

double taylorSeries(int x, int n) {

	static double r = 1;

	if (n == 0)
		return r;
	r = 1 + (double)x / n * r;
	return taylorSeries(x, n - 1);

}

int main(void) {
	double result = iTaylorSeries(1, 20);
	printf("The result is: %lf", result);

	return 0;
}
