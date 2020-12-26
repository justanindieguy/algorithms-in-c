#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int x);
double sineSeries(double x, int n);

int fact(int x) {
	if (x > 1)
		return x * fact(x - 1);
	return 1;
}

double sineSeries(double x, int n) {

	static int counter = 1, exp = 3;
	static double result = 0;
	double xPower = 1.0, nFact = 1.0;

	if (n % 2 == 0) {
		n++;
	}

	if (n == 1) {
		return x;
	} else {

		result = sineSeries(x, n - 2);

		counter++;

		xPower = pow(x, exp);
		nFact = fact(n);

		exp += 2;

		if (counter % 2 == 0) {
			return result - xPower / nFact;
		} else {
			return result + xPower / nFact;
		}

	}

}

int main() {
	double x = 0.7853;
	double result = sineSeries(x, 30);

	printf("The sine of %.4f is %lf", x, result);

	return 0;
}
