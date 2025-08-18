#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "cat.h"
#include "solver.h"
#include "in_out_put.h"

const int FIRST = 1;
const int SECOND = 1;

void welcome();

int main() {
    double coeff [] = {0, 0, 0};
    solve_equation res_of_solving = {0, {0, 0}};
    welcome();
    in_put_coeff(coeff);
    while (!check(coeff)) {
        in_put_coeff(coeff);
    }
    printf("Отлично! Приступим к решению :)\n");
    printf("%s", jumping_cat);
    solve_sq(coeff, &res_of_solving);
    out_put(res_of_solving);
    return 0; 
}

void welcome() {
    printf("Привет!\n");
    printf("Я твой помощник в решении квадратных уравнений\n");
    printf("%s", sitting_cat);
}