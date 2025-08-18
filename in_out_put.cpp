#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "in_out_put.h"
#include "common.h"

void in_put_one_coeff(double *coeff, int num_coeff) {
    int try_left = CNT_TRY;
    while (try_left > 0) {
        printf("Введи коэффициент %c:\n", 'a' + num_coeff);
        if (scanf("%lf", coeff) != 1 || (getchar() != '\n')) {
            remove_trash();
            --try_left;
            if (try_left == 0) {
                printf("Ты попытался ввести коэффициент %d раз!\n", CNT_TRY);
                printf("Что с тобой не так....? :/");
                exit(0);
            }
            continue;
        }
        break;
    }
}

void in_put_all_coeffs(double *all_coeffs) {
    assert(all_coeffs != NULL);
    printf("Введи, пожалуйста, коэффициенты уравнения, которое ты хочешь решить\n");
    printf("Каждый коэффициент вводи с новой строки\n");
    for (int i = 0; i < COUNT_COEFF; ++i) {
        in_put_one_coeff(&all_coeffs[i], i);
    }
}

char sign(double coefficiant) {
    return (coefficiant >= 0) ? '+' : '-';
}

void remove_trash() {
    while (getchar() != '\n') {
    }
}

int check(double *coeff) {
    assert(coeff != NULL);
    printf("Твоё уравнение выглядит так:\n");
    printf("%lgx^2 %c %lgx %c %lg = 0\n", coeff[0], sign(coeff[1]), abs(coeff[1]), sign(coeff[2]), abs(coeff[2]));
    printf("Всё верно?\n");
    while (true) {
        printf("Введи «Да» или «Нет»\n");
        char ans[MAX_LEN + 1] = {};
        static_assert(MAX_LEN == 4 * 2);
        scanf("%8s", ans);
        remove_trash();
        if (!strcmp(ans, "Да")) {
            return 1;
        }
        else if (!strcmp(ans, "Нет")) {
            return 0;
        }
    }
}

void out_put(solve_equation res_of_solving) {
    switch (res_of_solving.count_roots) {
    case ZERO:
        printf("У твоего уравнения нет решений :(\n");
        break;
    case ONE:
        printf("Я всё решил!\nКорень твоего уравнения:\n");
        printf("x = %lg\n", res_of_solving.roots[0]);
        break;
    case TWO:
        printf("Я всё решил!\nКорни твоего уравнения:\n");
        printf("x1 = %lg, x2 = %lg\n", res_of_solving.roots[0], res_of_solving.roots[1]);
        break;
    case INF:
        printf("Я всё решил!\nУ твоего уравнения бесконечно много решений :)\n");
        break;
    default:
        assert(0);
        break;
    }
    printf("Жду тебя с новыми уравнениями! Мяу <3\n");
}