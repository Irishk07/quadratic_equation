#ifndef IN_OUT_PUT_H
#define IN_OUT_PUT_H

#include "common.h"

const int MAX_LEN = 3;

const int CNT_TRY = 5;

//......................................................................
//! Input all coefficients of equation
//!
//! @param[in] all_coeffs - pointer on array with
//!                                    coefficients of equation
//!
//! @return status of input coefficients
//......................................................................
status in_put_all_coeffs(double *all_coeffs);


//......................................................................
//! Asks if the input of coefficients is correct
//!
//! @param[in] all_coeffs - pointer on array with
//!                                    coefficients of equation
//!
//! @return 1 if all right and 0 if otherwise
//......................................................................
int check(double *all_coeffs);

//......................................................................
//! Output roots of equation
//!
//! @param[in] res_of_solving - structure consisting of
//!                            a number of roots and array with roots
//!
//! @return roots of equation
//......................................................................
void out_put(solve_equation res_of_solving);

#endif