#include "cat.h"

#include "colors.h"
#include "common.h"
#include "pass_arg.h"

#include <errno.h>
#include <stdio.h>

void print_cats(status_of_finding elem_is_found, cat_kinds num_cat) {
    if (elem_is_found.filename_cat[num_cat] != NULL) {
        FILE *cat = fopen(elem_is_found.filename_cat[num_cat], "r");

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
    else {
        color_printf(COLOR_YELLOW, "%s", cats[num_cat]);
    }
}
