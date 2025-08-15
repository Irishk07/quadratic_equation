#include <stdio.h>
#include <math.h>
#include <assert.h>

const double EPS = 1e-9;
const int MAX_COUNT_ROOTS = 2;

enum cnt_of_roots {
    ZERO = 0, 
    ONE = 1, 
    TWO = 2, 
    INF = 3
};

struct solve_equation {
    int count_roots;
    double roots[MAX_COUNT_ROOTS];
};

void in_put(double *a, double *b, double *c);
void solve_sq(double a, double b, double c, solve_equation *res_of_solving);
void solve_lin(double b, double c, solve_equation *res_of_solving);
void out_put(solve_equation res_of_solving);
int compare(double first_num, double second_num);

int main() 
{
    double a = 0, b = 0, c = 0;
    solve_equation res_of_solving = {0, {0, 0}};
    in_put(&a, &b, &c);
    solve_sq(a, b, c, &res_of_solving);
    out_put(res_of_solving);
    return 0; 
}

void in_put(double *a, double *b, double *c) {
    scanf("%lf %lf %lf", a, b, c); 
}

void solve_sq(double a, double b, double c, solve_equation *res_of_solving) {
    //assert(res_of_solving != NULL);
    if (!compare(a, 0)) {
        double discr = b * b - 4 * a * c;
        if (compare(discr, 0)) {
            double x = -b / (2 * a);
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
    else {
        solve_lin(b, c, res_of_solving);
    }
}

void solve_lin(double b, double c, solve_equation *res_of_solving) {
    assert(res_of_solving != NULL);
    if (compare(b, 0) && !compare(c, 0)) {
        res_of_solving -> count_roots = ZERO;
    }
    else if (compare(b, 0) && compare(c, 0)) {
        res_of_solving -> count_roots = INF;
    }
    else {
        double x = -c / b;
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
}

int compare(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

void out_put(solve_equation res_of_solving) {
    switch (res_of_solving.count_roots) {
    case ZERO:
        printf("решений нет");
        break;
    case ONE:
        printf("x = %lg", res_of_solving.roots[0]);
        break;
    case TWO:
        printf("x1 = %lg, x2 = %lg", res_of_solving.roots[0], res_of_solving.roots[1]);
        break;
    case INF:
        printf("бесконечно много решений");
        break;
    default:
        assert(0);
        break;
    }
}
