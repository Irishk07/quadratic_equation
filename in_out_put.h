#ifndef IN_OUT_PUT_H
#define IN_OUT_PUT_H

#include "common.h"

const int MAX_LEN = 4 * 2; //For russian symbols in UTF-8

void in_put_coeff(double *coeff);
char sign(double coefficiant);
void remove_trash();
int check(double *coeff);
void out_put(solve_equation res_of_solving);

#endif