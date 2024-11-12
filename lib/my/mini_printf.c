/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** It's a mini printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int percent(const char *format, int i, va_list args)
{
    if ((format[i + 1] == 'i') || format[i + 1] == 'd') {
        my_put_nbr(va_arg(args, int));
    }
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(args, int));
    }
    if (format[i + 1] == 's') {
        my_putstr(va_arg(args, char *));
    }
    if (format[i + 1] == '%') {
        my_putchar('%');
    }
    if (format[i + 1] == 'x') {
        my_putnbr_base(va_arg(args, int), "0123456789abcdef");
    }
}

int mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; i <= my_strlen(format); i++) {
        if (format[i] == '%') {
            percent(format, i, args);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return 0;
}
