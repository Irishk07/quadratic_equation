#include <locale.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "common.h"
#include "solver.h"
#include "in_out_put.h"
#include "cat.h"

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

    printf("Great! Let's get to the solution :)\n");
    print_cats(jumping_cat);

    solve_sq(all_coeffs, &res_of_solving);

    out_put(res_of_solving);

    return 0; 
}

void welcome() {
    printf("Hello!\n");
    printf("I am your assistant in solving quadratic equations\n");
    print_cats(sitting_cat);
}