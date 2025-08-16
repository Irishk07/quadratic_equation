#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

const double EPS = 1e-9;
const int MAX_COUNT_ROOTS = 2;
const int MAX_SIZE = 3;

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

void welcome();
void in_put_coeff(double *a, double *b, double *c);
char sign(double coeff);
int check(double a, double b, double c);
bool is_double_equal(double first_num, double second_num); 
void solve_sq(double a, double b, double c, solve_equation *res_of_solving);
void solve_lin(double b, double c, solve_equation *res_of_solving);
void out_put(solve_equation res_of_solving);

int main() 
{
    double a = 0, b = 0, c = 0;
    solve_equation res_of_solving = {0, {0, 0}};
    welcome();
    in_put_coeff(&a, &b, &c);
    while (!check(a, b, c)) {
        in_put_coeff(&a, &b, &c);
    }
    printf("Отлично! Приступим к решению :)\n");
    solve_sq(a, b, c, &res_of_solving);
    out_put(res_of_solving);
    return 0; 
}

void welcome() {
    printf("Привет!\n");
    printf("Я твой помощник в решении квадратных уравнений\n");
}

void in_put_coeff(double *a, double *b, double *c) {
    assert(a != NULL && b != NULL && c != NULL);
    printf("Введи, пожалуйста, коэффициенты уравнения, которое ты хочешь решить\n");
    if (scanf("%lf %lf %lf", a, b, c) != 3) {
        printf("ERROR404: Попробуйте снова позже :(\n");
        exit(0);
    }
}

char sign(double coeff) {
    return (coeff >= 0) ? '+' : '-';
}

int check(double a, double b, double c) {
    printf("Твоё уравнение выглядит так:\n");
    printf("%lgx^2 %c %lgx %c %lg = 0\n", a, sign(b), abs(b), sign(c), abs(c));
    printf("Всё верно?\n");
    while (true) {
        printf("Введи «Да» или «Нет»\n");
        char ans[MAX_SIZE] = {};
        scanf("%s", ans);
        if (!strcmp(ans, "Да")) {
            return 1;
        }
        else if (!strcmp(ans, "Нет")) {
            return 0;
        }
    }
}

bool is_double_equal(double first_num, double second_num) {
    return abs(first_num - second_num) < EPS ? 1 : 0;
}

void solve_sq(double a, double b, double c, solve_equation *res_of_solving) {
    assert(res_of_solving != NULL);
    if (is_double_equal(a, 0)) {
        solve_lin(b, c, res_of_solving);
        return;
    }
    double discr = b * b - 4 * a * c;
    if (is_double_equal(discr, 0)) {
        double x = -b / (2 * a);
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
    else if (discr > 0) {
        double x1 = (-b + sqrt(discr)) / (2 * a);
        double x2 = (-b - sqrt(discr)) / (2 * a);
        res_of_solving -> count_roots = TWO;
        res_of_solving -> roots[0] = x1;
        res_of_solving -> roots[1] = x2;
    }
    else {
        res_of_solving -> count_roots = ZERO;
    }
}

void solve_lin(double b, double c, solve_equation *res_of_solving) {
    assert(res_of_solving != NULL);
    if (is_double_equal(b, 0) && !is_double_equal(c, 0)) {
        res_of_solving -> count_roots = ZERO;
    }
    else if (is_double_equal(b, 0) && is_double_equal(c, 0)) {
        res_of_solving -> count_roots = INF;
    }
    else {
        double x = -c / b;
        res_of_solving -> count_roots = ONE;
        res_of_solving -> roots[0] = x;
    }
}

void out_put(solve_equation res_of_solving) {
    switch (res_of_solving.count_roots) {
    case ZERO:
        printf("У твоего уравнения нет решений :(\n");
        printf("решений нет");
        break;
    case ONE:
        printf("Я всё решил!\nКорень твоего уравнения:\n");
        printf("x = %lg", res_of_solving.roots[0]);
        break;
    case TWO:
        printf("Я всё решил!\nКорни твоего уравнения:\n");
        printf("x1 = %lg, x2 = %lg", res_of_solving.roots[0], res_of_solving.roots[1]);
        break;
    case INF:
        printf("Я всё решил!\nУ твоего уравнения бесконечно много решений :)\n");
        break;
    default:
        assert(0);
        break;
    }
}
