#include "in_out_put.h"

#include "colors.h"
#include "common.h"

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//......................................................................
//! Detects the sign of a number
//!
//! @param[in] ans - const pointer to the array being compared
//! @param[in] reference - const pointer to the reference array 
//!
//! @return integer indicating the result of the comparison
//......................................................................
static int string_compare_nocase(const char *s1, const char *s2);

//......................................................................
//! Clears the input buffer
//......................................................................
static void remove_trash();

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


static int string_compare_nocase(const char *s1, const char *s2) {
    while (*s1 && (tolower(*s1) == tolower(*s2))) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

static void remove_trash() {
    int ch = '\0';
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

static status in_put_one_coeff(double *all_coeffs, int num_coeff) {
    assert(all_coeffs != NULL);

    int try_left = CNT_TRY;
    while (try_left > 0) {
        color_printf(COLOR_BLUE, "Enter the coefficient %c:\n", 'a' + num_coeff);

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

    color_print(COLOR_BLUE, "Please enter the coefficients of the equation you want to solve\n");
    color_print(COLOR_RED, "Enter each coefficient from a new line\n");

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

    color_print(COLOR_CYAN, "Your equation looks like this:\n");
    color_printf(COLOR_CYAN, "%lgx^2 %c %lgx %c %lg = 0\n", all_coeffs[0], sign(all_coeffs[1]), abs(all_coeffs[1]), sign(all_coeffs[2]), abs(all_coeffs[2]));
    color_print(COLOR_CYAN, "Is everything right?\n");

    while (true) {
        color_print(COLOR_RED, "Enter <<Yes>> or <<No>>\n");

        char ans[MAX_LEN + 1] = {};
        static_assert(MAX_LEN == 3);
        scanf("%" "s", ans);
        
        int ch = 0;
        if (!string_compare_nocase(ans, "Yes") && ((ch = getchar()) == '\n' || ch == EOF)) { // string_compare_nocase (nocase)
            return 1;
        }
        else if (!string_compare_nocase(ans, "No") && ((ch = getchar()) == '\n' || ch == EOF)) {
            return 0;
        }
        else {
            remove_trash();
        }
    }
}

void out_put(solve_equation res_of_solving) {
    switch (res_of_solving.count_roots) {
        case ZERO:
            color_print(COLOR_GREEN, "Your equation has no solutions :(\n");
            break;
        case ONE:
            color_print(COLOR_GREEN, "I've got it!\nThe root of your equation is:\n");
            color_printf(COLOR_GREEN, "x = %lg\n", res_of_solving.roots[0]);
            break;
        case TWO:
            color_print(COLOR_GREEN, "I've got it!\nThe roots of your equation are:\n");
            color_printf(COLOR_GREEN, "x1 = %lg, x2 = %lg\n", res_of_solving.roots[0], res_of_solving.roots[1]);
            break;
        case INF:
            color_print(COLOR_GREEN, "I've got it!\nYour equation has infinitely many solutions :)\n");
            break;
        default:
            assert(0 && "Unknown number of roots");
            break;
    }
    color_print(COLOR_PURPLE, "I'm waiting for you with new equations! Meow <3\n");

    color_print(COLOR_RED, "P.S. for me: COMMIT ON GITHUB\n");
}