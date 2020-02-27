#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fft.h"
#include "hls_math.h"
#include "ap_int.h"

int reverse_bits(unsigned int input, int size) {
	ap_int<12> i, rev = 0;
	for (i = 0; i < log2(size); i++) {
		rev = (rev << 1) | (input & 1);
		input = input >> 1;
	}
	return rev;
}

void bit_reverse(DTYPE* X_R, DTYPE* X_I, int size) {
	//Write your code here.
	ap_int<12> i, reversed;
	DTYPE temp_R, temp_I;
	for (i = 0; i < size; i++) {
		reversed = reverse_bits(i, size);

		if (i <= reversed) {
			// Swap the real values
			temp_R = X_R[i];
			temp_I = X_I[i];
			X_R[i] = X_R[reversed];
			X_I[i] = X_I[reversed];
			X_R[reversed] = temp_R;
			X_I[reversed] = temp_I;
		}
	}
}

void fft(DTYPE* IN_R, DTYPE* IN_I, DTYPE* OUT_R, DTYPE* OUT_I, int size) {
#pragma HLS INTERFACE s_axilite port=return bundle=sqrt
#pragma HLS INTERFACE s_axilite port=size bundle=sqrt
#pragma HLS INTERFACE m_axi port=OUT_R offset=slave bundle=output
#pragma HLS INTERFACE m_axi port=OUT_I offset=slave bundle=output
#pragma HLS INTERFACE m_axi port=IN_R offset=slave bundle=input
#pragma HLS INTERFACE m_axi port=IN_I offset=slave bundle=input
#pragma HLS INTERFACE s_axilite port=OUT_R
#pragma HLS INTERFACE s_axilite port=OUT_I
#pragma HLS INTERFACE s_axilite port=IN_R
#pragma HLS INTERFACE s_axilite port=IN_I
	DTYPE X_R[1024], X_I[1024];
	memcpy(X_R, (const DTYPE*) IN_R, size * sizeof(DTYPE));
	memcpy(X_I, (const DTYPE*) IN_I, size * sizeof(DTYPE));

	DTYPE temp_R;		/*temporary storage complex variable*/
	DTYPE temp_I;		/*temporary storage complex variable*/
	ap_int<12> i,j,k;			/* loop indexes */
	ap_int<12> i_lower;		/* Index of lower point in butterfly */
	ap_int<12> step;
	ap_int<12> stage;
	ap_int<12> DFTpts;
	ap_int<12> numBF;			/*Butterfly Width*/

	/*=====================BEGIN BIT REBERSAL===========================*/
	// write your code here
	bit_reverse(X_R, X_I, size);
	/*++++++++++++++++++++++END OF BIT REVERSAL++++++++++++++++++++++++++*/

	/*=======================BEGIN: FFT=========================*/
	// Do M stages of butterflies
	float e, c, s, a;

	for (stage = 1; stage <= log2(size) ; stage+=1) { // Do M stages of butter
		DFTpts = 1 << stage; // DFT = 2^stage = points in sub DFT
		numBF = DFTpts / 2; // Butter
		k = 0;
		e = -6.283185307178 / DFTpts;
		a = 0.0;

		for (j = 0; j < numBF; j++) {
			c = hls::cos(a);
			s = hls::sin(a);
			a = a + e;
			for (i = j; i < size; i += DFTpts) {
				i_lower = i + numBF; // index of lower point in butter
				temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
				temp_I = X_I[i_lower] * c + X_R[i_lower] * s;
				X_R[i_lower] = X_R[i] - temp_R;
				X_I[i_lower] = X_I[i] - temp_I;
				X_R[i] = X_R[i] + temp_R;
				X_I[i] = X_I[i] + temp_I;
			}
		}
	}
	memcpy(OUT_R, (const DTYPE*) X_R, size * sizeof(DTYPE));
	memcpy(OUT_I, (const DTYPE*) X_I, size * sizeof(DTYPE));
}
/*=======================END: FFT=========================*/
