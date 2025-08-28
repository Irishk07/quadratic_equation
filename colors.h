#ifndef COLORS_H_
#define COLORS_H_

#define COLOR_RED "\x1b[91m"
#define COLOR_GREEN "\x1b[92m"
#define COLOR_YELLOW "\x1b[93m"
#define COLOR_BLUE "\x1b[94m"
#define COLOR_PURPLE "\x1b[95m"
#define COLOR_CYAN "\x1b[96m"
#define COLOR_RESET "\x1b[0m"

#define color_text(color, text) color text COLOR_RESET
#define color_printf(color, format, ...) printf(color_text(color, format), ##__VA_ARGS__)

#endif // COLORS_H_