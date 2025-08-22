#ifndef SOLVER_H_
#define SOLVER_H_

#include "common.h"

const double EPS = 1e-9;

void solve_sq(double *coeff, solve_equation *res_of_solving);
void solve_lin(double *coeff, solve_equation *res_of_solving);
bool is_double_equal(double first_num, double second_num);
double fix_minus_zero(double root);

#endif