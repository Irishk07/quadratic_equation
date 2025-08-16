#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

const double EPS = 1e-9;
const int MAX_COUNT_ROOTS = 2;
const int MAX_LEN = 4 * 2; //For russian symbols in UTF-8

enum cnt_of_roots {
    ZERO = 0, 
    ONE = 1, 
    TWO = 2, 
    INF = 3
};

struct solve_equation {
    int count_roots;
    double roots[MAX_COUNT_ROOTS];
};

void draw_cat_1();
void welcome();
void in_put_coeff(double *coeff);
char sign(double coefficiant);
void remove_trash();
int check(double *coeff);
void draw_cat_2();
bool is_double_equal(double first_num, double second_num);
void solve_sq(double *coeff, solve_equation *res_of_solving);
void solve_lin(double *coeff, solve_equation *res_of_solving);
void out_put(solve_equation res_of_solving);

int main() 
{
    double coeff [] = {0, 0, 0};
    solve_equation res_of_solving = {0, {0, 0}};
    welcome();
    in_put_coeff(coeff);
    while (!check(coeff)) {
        in_put_coeff(coeff);
    }
    printf("Отлично! Приступим к решению :)\n");
    draw_cat_2();
    solve_sq(coeff, &res_of_solving);
    out_put(res_of_solving);
    return 0; 
}

void draw_cat_1() {
    printf("    |\\__/,|   (`\\\n");
    printf("  _.|o o  |_   ) )\n");
    printf("-(((---(((--------\n");
}

void welcome() {
    printf("Привет!\n");
    printf("Я твой помощник в решении квадратных уравнений\n");
    draw_cat_1();
}

void in_put_coeff(double *coeff) {
    assert(coeff != NULL);
    printf("Введи, пожалуйста, коэффициенты уравнения, которое ты хочешь решить\n");
    for (int i = 0; i < 3; ++i) {
        if (scanf("%lf", &coeff[i]) != 1 || (getchar() != '\n')) {
            printf("ERROR404: Попробуйте снова позже :(\n");
            exit(0);
        }
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

void draw_cat_2() {
    printf(" _._     _,-'\"\"`-._\n");
    printf("(,-.`._,'(       |\\`-/|\n");
    printf("    `-.-' \\ )-`( , o o)\n");
    printf("          `-    \\`_`\"'-\n");
}

bool is_double_equal(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

void solve_sq(double *coeff, solve_equation *res_of_solving) {
    assert(coeff != NULL && res_of_solving != NULL);
    if (is_double_equal(coeff[0], 0)) {
        solve_lin(coeff, res_of_solving);
        return;
    }
    double discr = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2];
    if (is_double_equal(discr, 0)) {
        double x = -coeff[1] / (2 * coeff[0]);
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
    else if (discr > 0) {
        double x1 = (-coeff[1] + sqrt(discr)) / (2 * coeff[0]);
        double x2 = (-coeff[1] - sqrt(discr)) / (2 * coeff[0]);
        res_of_solving -> count_roots = TWO;
        res_of_solving -> roots[0] = x1;
        res_of_solving -> roots[1] = x2;
    }
    else {
        res_of_solving -> count_roots = ZERO;
    }
}

void solve_lin(double *coeff, solve_equation *res_of_solving) {
    assert(coeff != NULL && res_of_solving != NULL);
    if (is_double_equal(coeff[1], 0) && !is_double_equal(coeff[2], 0)) {
        res_of_solving -> count_roots = ZERO;
    }
    else if (is_double_equal(coeff[1], 0) && is_double_equal(coeff[2], 0)) {
        res_of_solving -> count_roots = INF;
    }
    else {
        double x = -coeff[2] / coeff[1];
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
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