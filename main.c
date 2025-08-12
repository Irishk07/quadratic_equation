#include <stdio.h>
#include <math.h>

int main(void) 
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    if (a != 0) {
        float d = b * b - 4 * a * c; //дискриминант
        if (d == 0) {
            float x = -b / (2 * a); //единственный корень
            printf("x = %f", x);
        }
        else if (d > 0) {
            float x1 = (-b + sqrt(d)) / (2 * a); //первый корень
            float x2 = (-b - sqrt(d)) / (2 * a); //второй корень
            printf("x1 = %f, x2 = %f", x1, x2);
        }
        else {
            printf("нет решений");
        }
    }
    else {
        if (b == 0 && c != 0) {
            printf("нет решений");
        }
        else if (b == 0 && c == 0) {
            printf("бесконечно много решений");
        }
        else {
            float x = -c / b; //единственный корень
            printf("x = %f", x);
        }
    }  
    return 0; 
}