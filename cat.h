#ifndef CAT_H
#define CAT_H

#ifdef PRINT_CAT_FROM_FILE

void print_cats(const char *filename);

const char sitting_cat [] = "sitting_cat.txt";

const char jumping_cat [] = "jumping_cat.txt";

#else

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