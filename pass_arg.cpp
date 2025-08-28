#include "pass_arg.h"

#include "cat.h"
#include "colors.h"
#include "common.h"
#include "test.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

const existing_flags FLAGS_NAME [] = {
    {"--help", &args_help, "Gives you information about existing flags and their descriptions"},
    {"--test_file_name", &args_test_file_name, "Starts testing the program"},
    {"--cats_from_file", &args_cat_from_file, "Replaces the standard output of cats with the output of cat from your file"}
};

status args_help(int * const, const char **, int, status_of_finding *elem_is_found) {
    size_t size = sizeof(FLAGS_NAME) / sizeof(FLAGS_NAME[0]);
    for (size_t fg = 0; fg < size; ++fg) {
        color_printf(COLOR_GREEN, "%s: %s\n", FLAGS_NAME[fg].flag, FLAGS_NAME[fg].description);
    }
    elem_is_found->find_help = true;

    return SUCCESS;
}

status args_test_file_name(int * const argi, const char **argv, int argc, status_of_finding *elems_is_found) {
    assert(argi);
    assert(argv);
    assert(elems_is_found);

    if (*argi + 1 < argc) {
        elems_is_found->filename_test = argv[++(*argi)];
        return SUCCESS;
    }

    return MISSING_FLAG_ARGUMENT;
}

status args_cat_from_file(int * const argi, const char **argv, int argc, status_of_finding *elems_is_found) {
    assert(argi);
    assert(argv);
    assert(elems_is_found);

    if (*argi + 2 < argc) {
        for (int num_cat = 0; num_cat < LAST_CAT_ELEMENT; ++num_cat) {
            elems_is_found->filename_cat[num_cat] = argv[++(*argi)];
        }
        *argi += LAST_CAT_ELEMENT;
        return SUCCESS;
    }
    color_print(COLOR_RED, "Missing flag with name of file\n");
    return MISSING_FLAG_ARGUMENT;
} 

status pass_args(int argc, const char **argv, status_of_finding *elems_is_found) {
    assert(argv);
    assert(elems_is_found);

    for (int argi = 1; argi < argc; ++argi) {
        const char * argv_now = argv[argi];

        size_t size = sizeof(FLAGS_NAME) / sizeof(FLAGS_NAME[0]);
        bool is_found = false;

        for (size_t fg = 0; fg < size; ++fg) {
            const char * fg_now = FLAGS_NAME[fg].flag;
            
            if (!strcmp(fg_now, argv_now)) {
                if (FLAGS_NAME[fg].function(&argi, argv, argc, elems_is_found) != SUCCESS) {
                    return MISSING_FLAG_ARGUMENT;
                }
                is_found = true;
                break;
            }
        }

        if (!is_found) {
            color_printf(COLOR_RED, "Unknown flag: %s\n", argv_now);
            return INVALID_FLAG;
        }
    }
    return SUCCESS;
}