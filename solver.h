#ifndef SOLVER_H_
#define SOLVER_H_

#include "common.h"

const double EPS = 1e-9;

//......................................................................
//! Compares two double numbers
//!
//! @param[in] first_num - first double number
//! @param[in] second_num - second double number
//!
//! @return 1 if first number is equal to the second and 0 otherwise
//......................................................................
bool is_double_equal(double first_num, double second_num);

//......................................................................
//! Solves quadratic equation ax^2 + bx + c = 0
//!
//! @param[in] all_coeffs - pointer on array 
//!                                    with coefficients of equation
//! @param[out] res_of_solving - structure consisting of
//!                            a number of roots and array with roots
//......................................................................
void solve_sq(double *all_coeffs, solve_equation *res_of_solving);

//......................................................................
//! Checks whether the number is equal to NAN
//!
//! @param[in] x - number
//! 
//! @return true if NAN and false otherwise
//......................................................................
bool my_isnan(double x);


//......................................................................
//! Checks whether the number is equal to INF
//!
//! @param[in] x - number
//! 
//! @return true if INF and false otherwise
//......................................................................
bool my_isinf(double x);

#endif // SOLVER_H_