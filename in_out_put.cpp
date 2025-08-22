#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "in_out_put.h"
#include "common.h"

//......................................................................
//! Input one coefficient of equation
//!
//! @param[in] all_coeffs - pointer on array with
//!                                    coefficients of equation
//! @param[in] num_coef - number of the next coefficient
//!
//! @return status of input coefficient
//......................................................................
static status in_put_one_coeff(double *all_coeffs, int num_coeff);

//......................................................................
//! Detects the sign of a number
//!
//! @param[in] coefficient
//!
//! @return sign of a number: '+' or '-'
//......................................................................
static char sign(double coefficient);

//......................................................................
//! Clears the input buffer
//......................................................................
static void remove_trash();


static void remove_trash() {
    while (getchar() != '\n') {
    }
}

static status in_put_one_coeff(double *all_coeffs, int num_coeff) {
    assert(all_coeffs != NULL);

    int try_left = CNT_TRY;
    while (try_left > 0) {
        printf("Enter the coefficient %c:\n", 'a' + num_coeff);

        if (scanf("%lf", all_coeffs) == 1 && (getchar() == '\n')) {
            break;
        }
        
        remove_trash();

        if (--try_left == 0) {
            return IN_PUT_ERROR;
        }
    }
    return SUCCESS;
}

status in_put_all_coeffs(double *all_coeffs) {
    assert(all_coeffs != NULL);

    printf("Please enter the coefficients of the equation you want to solve\n");
    printf("Enter each coefficient from a new line\n");

    for (int i = 0; i < COUNT_COEFF; ++i) {
        status res = in_put_one_coeff(&all_coeffs[i], i);
        if (res != SUCCESS) {
            return res;
        }
    }
    return SUCCESS;
}

static char sign(double coefficient) {
    return (coefficient >= 0) ? '+' : '-';
}

int check(double *all_coeffs) {
    assert(all_coeffs != NULL);

    printf("Your equation looks like this:\n");
    printf("%lgx^2 %c %lgx %c %lg = 0\n", all_coeffs[0], sign(all_coeffs[1]), abs(all_coeffs[1]), sign(all_coeffs[2]), abs(all_coeffs[2]));
    printf("Is everything right?\n");

    while (true) {
        printf("Enter <<Yes>> or <<No>>\n");

        char ans[MAX_LEN + 1] = {};
        static_assert(MAX_LEN == 3);
        scanf("%8s", ans);
        remove_trash();
        if (!strcmp(ans, "Yes")) {
            return 1;
        }
        else if (!strcmp(ans, "No")) {
            return 0;
        }
    }
}

void out_put(solve_equation res_of_solving) {
    switch (res_of_solving.count_roots) {
        case ZERO:
            printf("Your equation has no solutions :(\n");
            break;
        case ONE:
            printf("I've got it!\nThe root of your equation is:\n");
            printf("x = %lg\n", res_of_solving.roots[0]);
            break;
        case TWO:
            printf("I've got it!\nThe roots of your equation are:\n");
            printf("x1 = %lg, x2 = %lg\n", res_of_solving.roots[0], res_of_solving.roots[1]);
            break;
        case INF:
            printf("I've got it!\nYour equation has infinitely many solutions :)\n");
            break;
        default:
            assert(0);
            break;
    }
    printf("I'm waiting for you with new equations! Meow <3\n");
}