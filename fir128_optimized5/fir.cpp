/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (data_t *y, data_t x) {
	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	// Write your code here
	static data_t shift_reg[N];

	#pragma HLS array_partition variable=c	cyclic  factor=2  dim=0
	#pragma HLS array_partition variable=shift_reg	cyclic  factor=2  dim=0

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


