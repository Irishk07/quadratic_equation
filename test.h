#ifndef TEST_H_
#define TEST_H_

#include "common.h"

const char MAX_HEAD_LEN = 100;

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
//! Opens file with tests and launches function run_one_test
//!
//! @param[in] filename - name of file with tests
//!
//! @return sum of errors
//......................................................................
int run_all_test(char *filename);

#endif //TEST_H_