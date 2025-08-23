#ifndef COMMON_H_
#define COMMON_H_

const int MAX_COUNT_ROOTS = 2;
const int COUNT_COEFF = 3;

//......................................................................
//! @enum cnt_of_roots
//! @brief detected number of roots
//......................................................................
enum cnt_of_roots {
    ZERO = 0, 
    ONE = 1, 
    TWO = 2, 
    INF = 3
};

//......................................................................
//! @enum status
//! @brief function operation status
//......................................................................
enum status {
    SUCCESS = 0,
    IN_PUT_ERROR = 1,
    CHECK_ERROR = 2,
    KEEP_CHECK = 3,
    TEST_FAILED = 4
};

//......................................................................
//! @struct solve_equation
//! @brief consiste of a number of roots and array with roots
//......................................................................
struct solve_equation {
    int count_roots;                ///< number of roots
    double roots[MAX_COUNT_ROOTS];  ///< array of roots
};

#endif