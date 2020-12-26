#include <stdio.h>
#include <stdlib.h>

int iFib(int n);
int rFib(int n);
int mFib(int n);

int fibValues[10];

int iFib(int n) {
	int termZero = 0, termOne = 1, sum = 0, i;

	if (n <= 1) return n;

	for (i = 2; i <= n; i++) {
		sum = termZero + termOne;
		termZero = termOne;
		termOne = sum;
	}

	return sum;
}

int rFib(int n) {
	if (n <= 1) return n;
	return rFib(n - 2) + rFib(n - 1);
}

int mFib(int n) {
	if (n <= 1) {
		fibValues[n] = n;
		return n;
	} else {
		if (fibValues[n - 2] == -1)
			fibValues[n - 2] = mFib(n - 2);
		if (fibValues[n - 1] == -1)
			fibValues[n - 1] = mFib(n - 1);
		fibValues[n] = fibValues[n - 2] + fibValues[n - 1];
		return fibValues[n - 1] + fibValues[n - 2];
	}
}

int main(void) {
	int i;
	for (i = 0; i < 10; i++) {
		fibValues[i] = -1;
	}

	printf("The 6th fib is: %d\n", mFib(6));
	return 0;
}
