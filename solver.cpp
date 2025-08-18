#include <assert.h>
#include <math.h>
#include "solver.h"
#include "common.h"

const double EPS = 1e-9;

bool is_double_equal(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

void solve_sq(double *coeff, solve_equation *res_of_solving) {
    assert(coeff != NULL && res_of_solving != NULL);
    if (is_double_equal(coeff[0], 0)) {
        solve_lin(coeff, res_of_solving);
        return;
    }
    double discr = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2];
    if (is_double_equal(discr, 0)) {
        double x = -coeff[1] / (2 * coeff[0]);
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
    else if (discr > 0) {
        double x1 = (-coeff[1] + sqrt(discr)) / (2 * coeff[0]);
        double x2 = (-coeff[1] - sqrt(discr)) / (2 * coeff[0]);
        res_of_solving -> count_roots = TWO;
        res_of_solving -> roots[0] = x1;
        res_of_solving -> roots[1] = x2;
    }
    else {
        res_of_solving -> count_roots = ZERO;
    }
}

void solve_lin(double *coeff, solve_equation *res_of_solving) {
    assert(coeff != NULL && res_of_solving != NULL);
    if (is_double_equal(coeff[1], 0) && !is_double_equal(coeff[2], 0)) {
        res_of_solving -> count_roots = ZERO;
    }
    else if (is_double_equal(coeff[1], 0) && is_double_equal(coeff[2], 0)) {
        res_of_solving -> count_roots = INF;
    }
    else {
        double x = -coeff[2] / coeff[1];
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
}