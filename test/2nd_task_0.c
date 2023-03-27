#include <stdarg.h>
#include <stdio.h>

int _putchar(char c)
{
    return putchar(c);
}

int _puts(char *str)
{
    int count = 0;
    while (*str) {
        count += _putchar(*str);
        str++;
    }
    return count;
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += _puts(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

