#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

void in_put(double *a, double *b, double *c);
void solve(double a, double b, double c, double *res);
void out_put(double *res);
int compare(double first_num, double second_num);
double discriminant(double a, double b, double c);
double first_root_qv(double a, double b, double d);
double second_root_qv(double a, double b, double d);
double root_lin(double b, double c);

int main() 
{
    double a = 0, b = 0, c = 0;
    double res[3] = {0, 0, 0};
    in_put(&a, &b, &c);
    solve(a, b, c, res);
    out_put(res);
    return 0; 
}

void in_put(double *a, double *b, double *c) {
    scanf("%lf %lf %lf", a, b, c); 
}

void solve(double a, double b, double c, double *res) {
    if (!compare(a, 0)) {
        double d = discriminant(a, b, c);
        if (compare(d, 0)) {
            double x = first_root_qv(a, b, d);
            res[0] = 1;
            res[1] = x;
        }
        else if (d > 0) {
            double x1 = first_root_qv(a, b, d);
            double x2 = second_root_qv(a, b, d);
            res[0] = 2;
            res[1] = x1;
            res[2] = x2;
        }
        else {
            res[0] = 0;
        }
    }
    else {
        if (compare(b, 0) && !compare(c, 0)) {
            res[0] = 0;
        }
        else if (compare(b, 0) && compare(c, 0)) {
            res[0] = 3;
        }
        else {
            double x = root_lin(b, c);
            res[0] = 1;
            res[1] = x;
        }
    }  
}

int compare(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

double discriminant(double a, double b, double c) {
    return (b * b - 4 * a * c);
}

double first_root_qv(double a, double b, double d) {
    return (-b + sqrt(d)) / (2 * a);
}

double second_root_qv(double a, double b, double d) {
    return (-b - sqrt(d)) / (2 * a);
}

double root_lin(double b, double c) {
    return (-c / b);
}

void out_put(double *res) {
    if (compare(res[0], 0)) {
        printf("решений нет");
    }
    else if (compare(res[0], 1)) {
        printf("x = %lg", res[1]);
    }
    else if (compare(res[0], 2)) {
        printf("x1 = %lg, x2 = %lg", res[1], res[2]);
    }
    else {
        printf("бесконечно много решений");
    }
}
