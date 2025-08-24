#include <stdio.h>
#include <string.h>

#include "pass_arg.h"

char flags_name [] = {...};//допустимые флаги

int pass_args(int argc, char **argv) {
    for (int argi = 1; argi < argc; ++argi) {

        char *argv_now = argv[argi];
        char *argv_now_one = argv_now;

        for (int fg = 0; flags_name[fg]; ++fg) {
            char *flag_now = flags_name[fg];

            int len_of_str = 0;
            while (*flag_now && *argv_now_one && (*flag_now == *argv_now_one)) {
                ++len_of_str;
                ++flag_now;
                ++argv_now_one;
            }

            int cnt_dash = 0;
            while (*argv_now_one == '-') {
                ++cnt_dash;
                ++argv_now_one;
            }

            if ((cnt_dash == 1 && len_of_str != 1) || (cnt_dash != 2)) {
                return argi;
            }

            //осталась запись вида -х или --ххх

            
        }

        

    }
}