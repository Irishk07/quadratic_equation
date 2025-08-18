#ifndef IN_OUT_PUT_H
#define IN_OUT_PUT_H

#include "common.h"

const int MAX_LEN = 4 * 2; //For russian symbols in UTF-8
const int CNT_TRY = 5;

status in_put_one_coeff(double *coeff, int num_coeff);
status in_put_all_coeffs(double *all_coeffs);
char sign(double coefficiant);
void remove_trash();
int check(double *coeff);
void out_put(solve_equation res_of_solving);

#endif