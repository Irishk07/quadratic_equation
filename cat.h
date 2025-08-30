#ifndef CAT_H
#define CAT_H

#include "pass_arg.h"

const char sitting_cat [] = \
                            "    |\\__/,|   (`\\\n"
                            "  _.|o o  |_   ) )\n"
                            "-(((---(((--------\n";

const char jumping_cat [] = \
                            " _._     _,-'\"\"`-._\n"
                            "(,-.`._,'(       |\\`-/|\n"
                            "    `-.-' \\ )-`( , o o)\n"
                            "          `-    \\`_`\"'-\n";

status cats_ctor(status_of_finding *elems_is_found);

//......................................................................
//! Draws a cat
//!
//! @param[in] elem_is_found - structure that contains infromation
//!                            about cat
//! @param[in] num_cat
//......................................................................
void print_cats(status_of_finding elem_is_found, cat_kinds num_cat);

void cats_dtor(status_of_finding *elems_is_found);

#endif //CAT_H