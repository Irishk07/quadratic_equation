#include "solver.h"

#include "common.h"

#include <assert.h>
#include <math.h>
#include <string.h>

//......................................................................
//! Turns minus zero into zero
//!
//! @param[in] root - root of equation
//!
//! @return root
//......................................................................
static double fix_minus_zero(double root);

//......................................................................
//! Solves linear equation bx + c = 0
//!
//! @param[in] all_coeffs - pointer on array with 
//!                                    coefficients of equation
//! @param[out] res_of_solving - structure consisting of
//!                            a number of roots and array with roots
//......................................................................
static void solve_lin(double *all_coeffs, solve_equation *res_of_solving);


bool is_double_equal(double first_num, double second_num) {
    return fabs(first_num - second_num) < EPS;
}

bool my_isnan(double x) {
    /*
             +------+----------+----------+
             | sign | exponent | mantissa |
        Bites|  1   |    11    |    52    |
        Mean | 0/1  |     1    |   0/1    |
             +------+----------+----------+
    */

    long x_long = 0;
    memcpy(&x_long, &x, sizeof(x));
    long reference = 0x7FFL << 52;
    x_long = x_long & reference;
    if (x_long == reference) {
        return true;
    }
    return false;
}

bool my_isinf(double x) {
    /*
             +------+----------+----------+
             | sign | exponent | mantissa |
        Bites|  1   |    11    |    52    |
        Mean | 0/1  |     1    |     0    |
             +------+----------+----------+
    */

    long x_long = 0;
    memcpy(&x_long, &x, sizeof(x));
    long reference = 0x7FFL << 52;
    x_long = x_long & ~(0x1L << 63);
    if (x_long == reference) {
        return true;
    }
    return false;
}

static double fix_minus_zero(double root) {
    if (is_double_equal(abs(root), 0)) {
        return 0;
    }
    return root;
}

void solve_sq(double *all_coeffs, solve_equation *res_of_solving) {
    assert(all_coeffs != NULL);
    assert(res_of_solving != NULL);

    double a = all_coeffs[0];
    double b = all_coeffs[1];
    double c = all_coeffs[2];

    assert(!my_isnan(a));
    assert(!my_isnan(b));
    assert(!my_isnan(c));

    if (is_double_equal(a, 0)) {
        solve_lin(all_coeffs + 1, res_of_solving);
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
        double x1 = (-b - sqrt(discr)) / (2 * a);
        double x2 = (-b + sqrt(discr)) / (2 * a);
        res_of_solving -> count_roots = TWO;
        res_of_solving -> roots[0] = x1;
        res_of_solving -> roots[1] = x2;
    }
    else {
        res_of_solving -> count_roots = ZERO;
    }
}

static void solve_lin(double *all_coeffs, solve_equation *res_of_solving) {
    assert(all_coeffs != NULL);
    assert(res_of_solving != NULL);

    double b = all_coeffs[0];
    double c = all_coeffs[1];

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