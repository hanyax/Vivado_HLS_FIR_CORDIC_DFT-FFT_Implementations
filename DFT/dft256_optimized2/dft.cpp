#include<math.h>
#include "dft.h"
#include"coefficients256.h"

void dft (DTYPE real_sample_in[SIZE], DTYPE imag_sample_in[SIZE], DTYPE real_sample_out[SIZE], DTYPE imag_sample_out[SIZE]) {
	int i, j;
	DTYPE w;
	DTYPE c, s;
	DTYPE temp_r, temp_i;
	// Calculate each frequency domain sample iteratively
	for (i = 0; i < SIZE; i += 1) {
		temp_r = 0;
		temp_i = 0;
		// Calculate the jth frequency sample sequentially
		for (j = 0; j < SIZE; j += 1) {
			// Utilize HLS tool to calculate sine and cosine values
			int index = (i * j) % SIZE;
			c = cos_coefficients_table[index];
			s = sin_coefficients_table[index];

			// Multiply the current phasor with the appropriate input sample and keep
			// running sum
			temp_r += (real_sample_in[j] * c - imag_sample_in[j] * s);
			temp_i += (real_sample_in[j] * s + imag_sample_in[j] * c);
		}

		real_sample_out[i] = temp_r;
		imag_sample_out[i] = temp_i;
	}
}
