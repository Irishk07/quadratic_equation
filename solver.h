#ifndef SOLVER_H_
#define SOLVER_H_

#include "common.h"

const double EPS = 1e-9;

//......................................................................
//! Solves quadratic equation ax^2 + bx + c = 0
//!
//! @param[in] all_coeffs - pointer on array 
//!                                    with coefficients of equation
//! @param[out] res_of_solving - structure consisting of
//!                            a number of roots and array with roots
//......................................................................
void solve_sq(double *all_coeffs, solve_equation *res_of_solving);

#endif