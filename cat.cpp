#include "cat.h"

#include "colors.h"
#include "common.h"
#include "pass_arg.h"

#include <errno.h>
#include <stdio.h>

void print_cats(status_of_finding elem_is_found, cat_kinds num_cat) {
    color_printf(COLOR_YELLOW, "%s", elem_is_found.this_is_cat[num_cat]);
}
