#include <stdio.h>
#include <math.h>

int main(void) 
{
    double a = 0, b = 0, c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);

    if (abs(a - 0) > 1e-9) {
        double d = b * b - 4 * a * c; //дискриминант
        if (abs(d - 0) < 1e-9) {
            double x = -b / (2 * a); //единственный корень
            printf("x = %lg", x);
        }
        else if (d > 0) {
            double x1 = (-b + sqrt(d)) / (2 * a); //первый корень
            double x2 = (-b - sqrt(d)) / (2 * a); //второй корень
            printf("x1 = %lg, x2 = %lg", x1, x2);
        }
        else {
            printf("нет решений");
        }
    }
    else {
        if (abs(b - 0) < 1e-9 && abs(c - 0) > 1e-9) {
            printf("нет решений");
        }
        else if (abs(b - 0) < 1e-9 && abs(c - 0) < 1e-9) {
            printf("бесконечно много решений");
        }
        else {
            double x = -c / b; //единственный корень
            printf("x = %lg", x);
        }
    }  
    return 0; 
}