#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#define NO_ITER 16

#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_int<2> coef_t;
typedef ap_fixed<15,3> data_t;
typedef ap_fixed<15,3> acc_t;

void cordiccart2pol(data_t x, data_t y, data_t * r, data_t * theta);

#endif
