#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "solver.h"
#include "in_out_put.h"
#include "cat.h"
#include "test.h"

//......................................................................
//! Greets the user and draws a sitting cat
//......................................................................
static void welcome();

int main() {
    int sum_error = 0;
    if ((sum_error = run_all_test()) != 0) {
        printf("%d tests are failed\n", sum_error / TEST_FAILED);
        return -1;
    }
    printf("ALL TESTS RIGHT\n");

    double all_coeffs [] = {0, 0, 0};
    solve_equation res_of_solving = {0, {0, 0}};

    welcome();

    int try_left = CNT_TRY;
    do {
        if (in_put_all_coeffs(all_coeffs) != SUCCESS || --try_left == 0) {
            printf("You tried to do it %d times!\n", CNT_TRY);
            printf("What's wrong with you....? :/");
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

static void welcome() {
    printf("Hello!\n");
    printf("I am your assistant in solving quadratic equations\n");

    print_cats(sitting_cat);
}