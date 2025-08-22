#include <assert.h>
#include <math.h>
#include "solver.h"
#include "common.h"

bool is_double_equal(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

double fix_minus_zero(double root) {
    if (is_double_equal(abs(root), 0)) {
        return 0;
    }
    return root;
}

void solve_sq(double *coeff, solve_equation *res_of_solving) {
    assert(coeff != NULL && res_of_solving != NULL);
    double a = coeff[0];
    double b = coeff[1];
    double c = coeff[2];
    if (is_double_equal(a, 0)) {
        solve_lin(coeff + 1, res_of_solving);
        return;
    }
    double discr = b * b - 4 * a * c;
    if (is_double_equal(discr, 0)) {
        double x = -b / (2 * a);
        x = fix_minus_zero(x);
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
    else if (discr > 0) {
        double x1 = (-b + sqrt(discr)) / (2 * a);
        double x2 = (-b - sqrt(discr)) / (2 * a);
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
    double b = coeff[0];
    double c = coeff[1];
    if (is_double_equal(b, 0) && !is_double_equal(c, 0)) {
        res_of_solving -> count_roots = ZERO;
    }
    else if (is_double_equal(b, 0) && is_double_equal(c, 0)) {
        res_of_solving -> count_roots = INF;
    }
    else {
        double x = -c / b;
        x = fix_minus_zero(x);
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
}