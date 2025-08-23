#include <stdio.h>
#include "test.h"
#include "solver.h"
#include "common.h"

status run_one_test(double a, double b, double c, int cnt_roots_test, double root1, double root2) {
    double all_coeffs_test [] = {a, b, c};
    solve_equation res_of_solving_test = {0, {0, 0}};
    solve_sq(all_coeffs_test, &res_of_solving_test);
    if (cnt_roots_test != res_of_solving_test.count_roots) {
        printf("FAILED: programm with coefficients a = %lg, b = %lg, c = %lg output cnt_roots = %d, but should be cnt_roots = %d\n", 
                a, b, c, res_of_solving_test.count_roots, cnt_roots_test);
        return TEST_FAILED;
    }
    else if (cnt_roots_test == 1 && !is_double_equal(res_of_solving_test.roots[0], root1)) {
        printf("FAILED: programm with coefficients a = %lg, b = %lg, c = %lg output x = %lg, but should be x = %lg\n", 
                a, b, c, res_of_solving_test.roots[0], root1);
        return TEST_FAILED;
    }
    else if (cnt_roots_test == 2 && !(is_double_equal(res_of_solving_test.roots[0], root1) && is_double_equal(res_of_solving_test.roots[1], root2))) {
        printf("FAILED: programm with coefficients a = %lg, b = %lg, c = %lg output x1 = %lg, x2 = %lg, but should be x1 = %lg, x2 = %lg\n", 
                a, b, c, res_of_solving_test.roots[0], res_of_solving_test.roots[1], root1, root2);
        return TEST_FAILED;
    }
    return SUCCESS;
}

int run_all_test() { 
    int error_sum = 0;

    //                       +-------+---------+-----+--------+-------+--------+
    //                       |   a   |    b    |  c  | nRoots |   x1  |   x2   |
    error_sum += run_one_test(      1,       -5,    6,     TWO,      2,       3); //2 3
    error_sum += run_one_test(      2,       -9,    4,     TWO,    0.5,       4); //0.5 4
    error_sum += run_one_test(      1,        4,    4,     ONE,     -2,       0); //-2
    error_sum += run_one_test(   1000,    -2000, 1000,     ONE,      1,       0); //1
    error_sum += run_one_test(      7,        8,  150,    ZERO,      0,       0); //no
    error_sum += run_one_test(    -18,      -68, -550,    ZERO,      0,       0); //no
    error_sum += run_one_test(      0,        5,   -8,     ONE,    1.6,       0); //1.6
    error_sum += run_one_test(1000000,        0,   -1,     TWO, -0.001,   0.001); //-0.001 0.001
    error_sum += run_one_test(      1, -1000000,    0,     TWO,      0, 1000000); //0 1000000
    error_sum += run_one_test(      0,        0,  -15,    ZERO,      0,       0); //no
    error_sum += run_one_test(      0,       -8,    0,     ONE,      0,       0); //0
    error_sum += run_one_test(      9,        0,    0,     ONE,      0,       0); //0
    error_sum += run_one_test(      0,        0,    0,     INF,      0,       0); //inf
    //                       +-------+---------+-----+--------+-------+--------+
    return error_sum;
}