#ifndef COMMON_H_
#define COMMON_H_

const int MAX_COUNT_ROOTS = 2;
const int COUNT_COEFF = 3;

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

#endif