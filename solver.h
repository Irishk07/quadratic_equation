#ifndef SOLVER_H_
#define SOLVER_H_

#include "common.h"

void solve_sq(double *coeff, solve_equation *res_of_solving);
void solve_lin(double *coeff, solve_equation *res_of_solving);
bool is_double_equal(double first_num, double second_num);

#endif