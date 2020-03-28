#include<math.h>
#include "dft.h"
#include"coefficients256.h"

void firstLoop(int i, DTYPE c[SIZE], DTYPE s[SIZE]) {
	int j;
	for (j = 0; j < SIZE; j ++) {
#pragma HLS unroll factor=8
		// Utilize HLS tool to calculate sine and cosine values
		int index = (i * j) % SIZE;
		c[j] = cos_coefficients_table[index];
		s[j] = sin_coefficients_table[index];
	}
}

void secondLoop(DTYPE c[SIZE], DTYPE s[SIZE], DTYPE real_sample_in[SIZE], DTYPE imag_sample_in[SIZE], DTYPE temp_r_out[SIZE], DTYPE temp_i_out[SIZE]) {
	int j;
	for (j = 0; j < SIZE; j ++) {
#pragma HLS unroll factor=8
		DTYPE c_temp = c[j];
		DTYPE s_temp = s[j];
		DTYPE temp_r_in = real_sample_in[j];
		DTYPE temp_i_in = imag_sample_in[j];
		temp_r_out[j] = (temp_r_in * c_temp - temp_i_in * s_temp);
		temp_i_out[j] = (temp_r_in * s_temp + temp_i_in * c_temp);
	}
}

void thirdLoop(int i, DTYPE temp_r_out[SIZE], DTYPE temp_i_out[SIZE], DTYPE sum_r[SIZE], DTYPE sum_i[SIZE]) {
	int j;
	for (j = 0; j < SIZE; j ++) {
#pragma HLS unroll factor=8
		if (j==0) {
			sum_r[i]=temp_r_out[j];
			sum_i[i]=temp_i_out[j];
		} else {
			sum_r[i]+=temp_r_out[j];
			sum_i[i]+=temp_i_out[j];
		}
	}
}

void fourthPart(int i, DTYPE sum_r[SIZE], DTYPE sum_i[SIZE], DTYPE real_sample_out[SIZE], DTYPE imag_sample_out[SIZE]) {
	real_sample_out[i] = sum_r[i];
	imag_sample_out[i] = sum_i[i];
}

void dft (DTYPE real_sample_in[SIZE], DTYPE imag_sample_in[SIZE], DTYPE real_sample_out[SIZE], DTYPE imag_sample_out[SIZE]) {
	#pragma HLS array_partition variable=real_sample_in cyclic factor=8
	#pragma HLS array_partition variable=imag_sample_in cyclic factor=8
	#pragma HLS array_partition variable=real_sample_out cyclic factor=8
	#pragma HLS array_partition variable=imag_sample_out cyclic factor=8
	#pragma HLS array_partition variable=cos_coefficients_table cyclic factor=8
	#pragma HLS array_partition variable=sin_coefficients_table cyclic factor=8
	// Calculate each frequency domain sample iteratively
	for (int i = 0; i < SIZE; i ++) {
		#pragma HLS dataflow
		DTYPE c[SIZE], s[SIZE];
		DTYPE temp_r_out[SIZE], temp_i_out[SIZE];
		DTYPE sum_r[SIZE], sum_i[SIZE];
		firstLoop(i, c, s);
		secondLoop(c, s, real_sample_in, imag_sample_in, temp_r_out, temp_i_out);
		thirdLoop(i, temp_r_out, temp_i_out, sum_r, sum_i);
		fourthPart(i,sum_r,sum_i, real_sample_out, imag_sample_out);
	}
}

