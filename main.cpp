#include <stdio.h>
#include <math.h>

const double eps = 1e-9;

void in_put(double *, double *, double *);
void solve(double, double, double, double *);
void out_put(double *);

int main(void) 
{
    double a = 0, b = 0, c = 0;
    double res[100];
    in_put(&a, &b, &c);
    solve(a, b, c, res);
    out_put(res);
    return 0; 
}

void in_put(double *a, double *b, double *c) {
    scanf("%lf %lf %lf", a, b, c); 
}

void solve(double a, double b, double c, double *res) {
    if (abs(a - 0) > eps) {
        double d = b * b - 4 * a * c;
        if (abs(d - 0) < eps) {
            double x = -b / (2 * a);
            res[0] = 1;
            res[1] = x;
        }
        else if (d > 0) {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            res[0] = 2;
            res[1] = x1;
            res[2] = x2;
        }
        else {
            res[0] = 0;
        }
    }
    else {
        if (abs(b - 0) < eps && abs(c - 0) > eps) {
            res[0] = 0;
        }
        else if (abs(b - 0) < eps && abs(c - 0) < eps) {
            res[0] = 3;
        }
        else {
            double x = -c / b;
            res[0] = 1;
            res[1] = x;
        }
    }  
}

void out_put(double *res) {
    if (res[0] - 0 < eps) {
        printf("решений нет");
    }
    else if (res[0] - 1 < eps) {
        printf("x = %lg", res[1]);
    }
    else if (res[0] - 2 < eps) {
        printf("x1 = %lg, x2 = %lg", res[1], res[2]);
    }
    else {
        printf("бесконечно много решений");
    }
}
