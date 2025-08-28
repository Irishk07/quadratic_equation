#ifndef PASS_ARG_H_
#define PASS_ARG_H_

#include "common.h"

#include <stdio.h>

enum cat_kinds {
    SITTING_CAT = 0,
    JUMPING_CAT = 1,
    LAST_CAT_ELEMENT
};

struct status_of_finding {
    char *this_is_cat [LAST_CAT_ELEMENT];
    const char *filename_test = NULL;
    bool find_help = false;
};

struct existing_flags {
    const char * flag;
    status (*function) (int * const argi, const char **argv, int argc, status_of_finding *elems_is_found);
    const char * description;
};

status args_help(int * const argi, const char **argv, int argc, status_of_finding *elems_is_found);

status args_test_file_name(int * const argi, const char **argv, int argc, status_of_finding *elems_is_found);

status args_cat_from_file(int * const argi, const char **argv, int argc, status_of_finding *elems_is_found);

status pass_args(int argc, const char **argv, status_of_finding *elems_is_found);

#endif // PASS_ARG_H_