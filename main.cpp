#include <locale.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "cat.h"
#include "solver.h"
#include "in_out_put.h"

void welcome();

int main() {
    setlocale (LC_ALL, "");

    double all_coeffs [] = {0, 0, 0};
    solve_equation res_of_solving = {0, {0, 0}};

    welcome();

    do {
        if (in_put_all_coeffs(all_coeffs) != SUCCESS) {
            return -1;
        }
    } 
    while (!check(all_coeffs));

    printf("Отлично! Приступим к решению :)\n");
    print_cats("jumping_cat.txt");

    solve_sq(all_coeffs, &res_of_solving);

    out_put(res_of_solving);

    return 0; 
}

void welcome() {
    printf("Привет!\n");
    printf("Я твой помощник в решении квадратных уравнений\n");
}