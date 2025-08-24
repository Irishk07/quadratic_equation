#include "cat.h"

#include "colors.h"
#include "common.h"

#include <errno.h>
#include <stdio.h>

#ifdef PRINT_CAT_FROM_FILE

void print_cats(const char *filename) {
    FILE *cat = fopen(filename, "r");

    if (cat == NULL) {
        perror("File opening error\n");
    }

    int ch = 0;
    while ((ch = getc(cat)) != EOF) {
        color_printf(COLOR_YELLOW, "%c", ch);
    }

    printf("\n");
    
    fclose(cat);
}

#else

void print_cats(const char *cat) {
    color_printf(COLOR_YELLOW, "%s", cat);
}

#endif