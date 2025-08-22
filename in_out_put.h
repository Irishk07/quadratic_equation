#ifndef IN_OUT_PUT_H
#define IN_OUT_PUT_H

#include "common.h"

const int MAX_LEN = 3;

const int CNT_TRY = 5;

status in_put_all_coeffs(double *all_coeffs);

int check(double *coeff);

void out_put(solve_equation res_of_solving);

#endif