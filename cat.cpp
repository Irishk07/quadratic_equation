#include <stdio.h>
#include "cat.h"

#ifdef PRINT_CAT_FROM_FILE

void print_cats(const char *filename) {
    FILE *cat;
    cat = fopen(filename, "r");
    if (cat == NULL) {
        perror("Ошибка открытия файла\n");
    }
    int ch = '0';
    while ((ch = getc(cat)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
}

#else

void print_cats(const char *cat) {
    printf("%s", cat);
}

#endif