#ifndef CAT_H
#define CAT_H

#ifdef PRINT_CAT_FROM_FILE

//......................................................................
//! Draws a cat
//!
//! @param[in] filename - pointer on array with 
//!                                name of the file with cat
//......................................................................
void print_cats(const char *filename);

const char sitting_cat [] = "sitting_cat.txt";

const char jumping_cat [] = "jumping_cat.txt";

#else

//......................................................................
//! Draws a cat
//!
//! @param[in] cat - pointer on array with image of the cat
//......................................................................
void print_cats(const char *cat);

const char sitting_cat [] = "    |\\__/,|   (`\\\n"
                            "  _.|o o  |_   ) )\n"
                            "-(((---(((--------\n";

const char jumping_cat [] = " _._     _,-'\"\"`-._\n"
                            "(,-.`._,'(       |\\`-/|\n"
                            "    `-.-' \\ )-`( , o o)\n"
                            "          `-    \\`_`\"'-\n";

#endif //PRINT_CAT_FROM_FILE

#endif //CAT_H