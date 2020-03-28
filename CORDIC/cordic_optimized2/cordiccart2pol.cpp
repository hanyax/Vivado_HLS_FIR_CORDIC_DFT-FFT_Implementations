#include "cordiccart2pol.h"

data_t angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05};

void cordiccart2pol(data_t x, data_t y, data_t * r, data_t * theta) {
	data_t pi = 1.570796326794896;
	data_t c_x, c_y;
	acc_t angle;

	if (y > 0) {
		// rotate by -90
		c_x = y;
		c_y = -x;
		angle = pi;
	} else {
		// rotate by 90
		c_x = -y;
		c_y = x;
		angle = -pi;
	}

	for (int i = 0; i < NO_ITER; i++) {
		data_t tempX = c_x;
		if (c_y < 0) {
			c_x -=  c_y >> i;
			c_y += tempX >> i;
			angle -= angles[i];
		} else {
			c_x +=  c_y >> i;
			c_y -= tempX >> i;
			angle += angles[i];
		}
	}

	*r = c_x * (ap_fixed<16,3>) 0.607;
	*theta = angle;
}
