#include "common.h"

#include "cat.h"
#include "colors.h"
#include "in_out_put.h"
#include "pass_arg.h"
#include "solver.h"
#include "test.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//......................................................................
//! Greets the user and draws a sitting cat
//!
//! @param[in] elem_is_found - structure that contains infromation
//!                            about cat
//......................................................................
static void welcome(status_of_finding elems_is_found);

int main(int argc, const char **argv) {
    
    status_of_finding elems_is_found = {};
    cats_ctor(&elems_is_found);
    
    RETURN_IF_ERROR(pass_args(argc, argv, &elems_is_found),             cats_dtor(&elems_is_found));
    
    if (elems_is_found.find_help == true) {
        cats_dtor(&elems_is_found);
        return 0;
    }

    if (elems_is_found.filename_test != NULL) {
        int sum_error = 0;

        if ((sum_error = run_all_test(elems_is_found.filename_test)) > 0) {
            color_printf(COLOR_RED, "%d tests are failed\n", sum_error / TEST_FAILED);

            cats_dtor(&elems_is_found);
            return -1;
        }
        else if (sum_error == -1) {
            color_printf(COLOR_RED, "Invalid file with tests name\n");

            cats_dtor(&elems_is_found);
            return -1;
        }
        color_printf(COLOR_GREEN, "ALL TESTS RIGHT\n");

        cats_dtor(&elems_is_found);
        return 0;
    }

    double all_coeffs [] = {NAN, NAN, NAN};
    solve_equation res_of_solving = {0, {NAN, NAN}};

    welcome(elems_is_found);

    int try_left = CNT_TRY;
    do {
        if (in_put_all_coeffs(all_coeffs) != SUCCESS || --try_left == 0) {
            color_printf(COLOR_RED, "You tried to do it %d times!\n", CNT_TRY);
            color_printf(COLOR_RED, "What's wrong with you....? :/\n");

            cats_dtor(&elems_is_found);
            
            return -1;
        }
    }
    while (!check(all_coeffs));

    color_printf(COLOR_CYAN, "Great! Let's get to the solution :)\n");
    print_cats(elems_is_found, JUMPING_CAT);

    solve_sq(all_coeffs, &res_of_solving);

    out_put(res_of_solving);

    cats_dtor(&elems_is_found);

    return 0; 
}

static void welcome(status_of_finding elems_is_found) {
    color_printf(COLOR_PURPLE, "Hello!\n");
    color_printf(COLOR_PURPLE, "I am your assistant in solving quadratic equations\n");

    print_cats(elems_is_found, SITTING_CAT);
}