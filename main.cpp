#include "common.h"

#include "cat.h"
#include "colors.h"
#include "in_out_put.h"
#include "pass_arg.h"
#include "solver.h"
#include "test.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

//......................................................................
//! Greets the user and draws a sitting cat
//......................................................................
static void welcome();

int main(int argc, char **argv) {

    pass_args(argc, argv);

#ifndef NDEBUG

    if (argc != 2) {
        return -1;
    }

    int sum_error = 0;
    char *filename = argv[1];
    if ((sum_error = run_all_test(filename)) != 0) {
        //printf(COLOR_RED "%d tests are failed\n" COLOR_RESET, sum_error / TEST_FAILED);
        //printf(color_text(COLOR_RED, "%d tests are failed\n"), sum_error / TEST_FAILED);
        color_printf(COLOR_RED, "%d tests are failed\n", sum_error / TEST_FAILED);
        return -1;
    }
    color_print(COLOR_GREEN, "ALL TESTS RIGHT\n");

#endif

    double all_coeffs [] = {0.f, 0.f, 0.f};
    solve_equation res_of_solving = {0, {0.f, 0.f}};

    welcome();

    int try_left = CNT_TRY;
    do {
        if (in_put_all_coeffs(all_coeffs) != SUCCESS || --try_left == 0) {
            color_printf(COLOR_RED, "You tried to do it %d times!\n", CNT_TRY);
            color_print(COLOR_RED, "What's wrong with you....? :/\n");
            return -1;
        }
    }
    while (!check(all_coeffs));

    color_print(COLOR_CYAN, "Great! Let's get to the solution :)\n");
    print_cats(jumping_cat);

    solve_sq(all_coeffs, &res_of_solving);

    out_put(res_of_solving);

    return 0; 
}

static void welcome() {
    color_print(COLOR_PURPLE, "Hello!\n");
    color_print(COLOR_PURPLE, "I am your assistant in solving quadratic equations\n");

    print_cats(sitting_cat);
}