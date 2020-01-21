/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.

	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir ( data_t *y, data_t x) {
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0,53};
	// Write your code here
	static data_t shift_reg[N];
	acc_t sum;
	int i;

	sum = 0;
	SHIFT_ACCUM_LOOP:
	for (i=N-1; i>=0; i--) {
		if (i == 0) {
			sum += x * c[0];
			shift_reg[0] = x;
		} else {
			shift_reg[i] = shift_reg[i-1];
			sum += shift_reg[i] * c[i];
		}
	}
	*y = sum;
}


