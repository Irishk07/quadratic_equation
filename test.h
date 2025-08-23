#ifndef TEST_H_
#define TEST_H_

#include "common.h"

//......................................................................
//! Tests the solution of the equation once
//!
//! @param[in] a - a-coefficient
//! @param[in] b - b-coefficient
//! @param[in] c - c-coefficient
//! @param[in] cnt_roots_test - right count of roots
//! @param[in] root1 - right first root
//! @param[in] root2 - right second root
//!
//! @return status of test 
//!
//! @note in case of incorrect decision prints an error
//......................................................................
status run_one_test(double a, double b, double c, int cnt_roots_test, double root1, double root2);

//......................................................................
//! Contains all tests for function run_one_test
//!
//! @return sum of errors
//......................................................................
int run_all_test();

#endif //TEST_H_