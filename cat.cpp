#include <stdio.h>
#include <errno.h>
#include "cat.h"

#ifdef PRINT_CAT_FROM_FILE

void print_cats(const char *filename) {
    FILE *cat = fopen(filename, "r");

    if (cat == NULL) {
        perror("File opening error\n");
    }

    int ch = '0';
    while ((ch = getc(cat)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");
    
    fclose(cat);
}

#else

void print_cats(const char *cat) {
    printf("%s", cat);
}

#endif