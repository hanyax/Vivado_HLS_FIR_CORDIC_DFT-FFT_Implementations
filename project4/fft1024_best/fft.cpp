#include "fft.h"
#include "ap_int.h"

int reverse_bits(unsigned int input) {
	ap_int<12> i, rev = 0;
	for (i = 0; i < M; i++) {
		rev = (rev << 1) | (input & 1);
		input = input >> 1;
	}
	return rev;
}

void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write your code here.
	ap_int<12> i, reverse_bit;
	DTYPE temp_R, temp_I;
	for (i = 0; i < SIZE; i++) {
		#pragma HLS pipeline
		#pragma HLS unroll factor = 4
		reverse_bit = reverse_bits(i);
		OUT_R[i] = X_R[reverse_bits(i)];
		OUT_I[i] = X_I[reverse_bits(i)];
	}
}

void fft_stage_one(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	ap_int<3> DFTpts = 2; // DFT = 2^stage = points in sub DFT
	ap_int<2> numBF = 1; // Buttery WIDTHS in sub-DFT
	ap_int<12> i;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	// Perform butterflies for j-th stage
	c = W_real[0];
	s = W_imag[0];
	// Compute butterflies that use same W**k
	DFTpts:for(i=0; i<SIZE; i += DFTpts) {
		#pragma HLS pipeline
		ap_int<12> i_lower = i + numBF;			//index of lower point in butterfly
		temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
		temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

		X_i = X_I[i];
		X_r = X_R[i];
		OUT_R[i_lower] = X_r - temp_R;
		OUT_I[i_lower] = X_i - temp_I;
		OUT_R[i] = X_r + temp_R;
		OUT_I[i] = X_i + temp_I;
	}
}

void fft_stage_two (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<4> DFTpts = 4; // DFT = 2^stage = points in sub DFT
	ap_int<3> numBF = 2; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<3> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 256;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		//#pragma HLS pipeline
		#pragma HLS unroll
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			#pragma HLS pipeline
			i_ori = j + (i<<2);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}
void fft_stage_three (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<5> DFTpts = 8; // DFT = 2^stage = points in sub DFT
	ap_int<4> numBF = 4; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<4> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 128;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		//#pragma HLS pipeline
		#pragma HLS unroll
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			#pragma HLS pipeline
			i_ori = j + (i<<3);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_four (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<6> DFTpts = 16; // DFT = 2^stage = points in sub DFT
	ap_int<5> numBF = 8; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<5> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 64;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		//#pragma HLS pipeline
		#pragma HLS unroll factor = 4
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			#pragma HLS pipeline
			i_ori = j + (i<<4);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_five (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<7> DFTpts = 32; // DFT = 2^stage = points in sub DFT
	ap_int<6> numBF = 16; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<6> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 32;
	ap_int<11> i_ori, i_lower;

	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS unroll factor = 4
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i+=1) {
			#pragma HLS pipeline
			i_ori = j + (i<<5);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_six (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<8> DFTpts = 64; // DFT = 2^stage = points in sub DFT
	ap_int<7> numBF = 32; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<7> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 16;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS pipeline
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			i_ori = j + (i<<6);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c-X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_seven (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	ap_int<9> DFTpts = 128; // DFT = 2^stage = points in sub DFT
	ap_int<8> numBF = 64; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<8> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 8;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS pipeline
		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i+=1) {
			i_ori = j + (i<<7);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_eight (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<10> DFTpts = 256; // DFT = 2^stage = points in sub DFT
	ap_int<9> numBF = 128; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<9> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 4;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS pipeline

		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			i_ori = j + (i<<8);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			DTYPE temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			DTYPE temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_nine (DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write a code that computes any arbitary stages of the FFT
	//Write code that computes last stage of FFT
	ap_int<11> DFTpts = 512; // DFT = 2^stage = points in sub DFT
	ap_int<10> numBF = 256; // Buttery WIDTHS in sub-DFT
	ap_int<10> a = 0;
	ap_int<10> j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<11> i;
	ap_int<10> stride = 2;
	ap_int<11> i_ori, i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS pipeline

		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		DFTpts:for(i=0; i<stride; i += 1) {
			i_ori = j + (i<<9);
			i_lower = i_ori  + numBF;			//index of lower point in butterfly
			temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
			temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

			X_i = X_I[i_ori];
			X_r = X_R[i_ori];
			OUT_R[i_lower] = X_r - temp_R;
			OUT_I[i_lower] = X_i - temp_I;
			OUT_R[i_ori] = X_r + temp_R;
			OUT_I[i_ori] = X_i + temp_I;
		}
	}
}

void fft_stage_last(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
	//Write code that computes last stage of FFTg
	ap_int<12> DFTpts = 1024; // DFT = 2^stage = points in sub DFT
	ap_int<11> numBF = 512; // Buttery WIDTHS in sub-DFT
	ap_int<11> step = 512;
	ap_int<11> a, j;
	DTYPE s, c, X_i, X_r, temp_R, temp_I;
	ap_int<10> stride = 1; // = SIZE/DFTpts;
	a = 0;
	ap_int<12> i_lower;
	// Perform butterflies for j-th stage
	butterfly:for(j=0; j<numBF; j++) {
		#pragma HLS pipeline

		c = W_real[a];
		s = W_imag[a];
		a += stride;
		// Compute butterflies that use same W**k
		i_lower = j + numBF;			//index of lower point in butterfly
		temp_R = X_R[i_lower]*c- X_I[i_lower]*s;
		temp_I = X_I[i_lower]*c+ X_R[i_lower]*s;

		X_i = X_I[j];
		X_r = X_R[j];
		OUT_R[i_lower] = X_r - temp_R;
		OUT_I[i_lower] = X_i - temp_I;
		OUT_R[j] = X_r + temp_R;
		OUT_I[j] = X_i + temp_I;
	}
}

void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
#pragma HLS dataflow
	DTYPE Stage_R0[SIZE], Stage_I0[SIZE];
	DTYPE Stage_R1[SIZE], Stage_I1[SIZE];
	DTYPE Stage_R2[SIZE], Stage_I2[SIZE];
	DTYPE Stage_R3[SIZE], Stage_I3[SIZE];
	DTYPE Stage_R4[SIZE], Stage_I4[SIZE];
	DTYPE Stage_R5[SIZE], Stage_I5[SIZE];
	DTYPE Stage_R6[SIZE], Stage_I6[SIZE];
	DTYPE Stage_R7[SIZE], Stage_I7[SIZE];
	DTYPE Stage_R8[SIZE], Stage_I8[SIZE];
	DTYPE Stage_R9[SIZE], Stage_I9[SIZE];

#pragma HLS array_partition variable=Stage_R0 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I0 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R1 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I1 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R2 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I2 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R3 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I3 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R4 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I4 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R5 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I5 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R6 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I6 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R7 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I7 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R8 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I8 cyclic factor = 4
#pragma HLS array_partition variable=Stage_R9 cyclic factor = 4
#pragma HLS array_partition variable=Stage_I9 cyclic factor = 4

	bit_reverse(X_R, X_I, Stage_R0, Stage_I0);
	fft_stage_one(Stage_R0, Stage_I0, Stage_R1, Stage_I1);
	fft_stage_two(Stage_R1, Stage_I1, Stage_R2, Stage_I2);
	fft_stage_three(Stage_R2, Stage_I2, Stage_R3, Stage_I3);
	fft_stage_four(Stage_R3, Stage_I3, Stage_R4, Stage_I4);
	fft_stage_five(Stage_R4, Stage_I4, Stage_R5, Stage_I5);
	fft_stage_six(Stage_R5, Stage_I5, Stage_R6, Stage_I6);
	fft_stage_seven(Stage_R6, Stage_I6, Stage_R7, Stage_I7);
	fft_stage_eight(Stage_R7, Stage_I7, Stage_R8, Stage_I8);
	fft_stage_nine(Stage_R8, Stage_I8, Stage_R9, Stage_I9);
	fft_stage_last(Stage_R9, Stage_I9, OUT_R, OUT_I);
}
