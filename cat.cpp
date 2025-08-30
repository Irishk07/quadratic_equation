#include "cat.h"

#include "colors.h"
#include "common.h"
#include "pass_arg.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

status cats_ctor(status_of_finding *elems_is_found) {
    elems_is_found->this_is_cat[0] = strdup(sitting_cat);
    elems_is_found->this_is_cat[1] = strdup(jumping_cat);

    for (int i = 0; i < LAST_CAT_ELEMENT; ++i) { 
        if (elems_is_found->this_is_cat[i] == NULL) {
            return NOT_ENOUGH_MEMORY;
        }
    }

    return SUCCESS;
}

void print_cats(status_of_finding elems_is_found, cat_kinds num_cat) {
    color_printf(COLOR_YELLOW, "%s", elems_is_found.this_is_cat[num_cat]);
}

void cats_dtor(status_of_finding *elems_is_found) {
    for (int i = 0; i < LAST_CAT_ELEMENT; ++i) {
        free((void *)elems_is_found->this_is_cat[i]);
        elems_is_found->this_is_cat[i] = NULL;
    }
}