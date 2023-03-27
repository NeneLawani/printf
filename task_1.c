#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: character string that directs the format of the output
 *
 * Return: the number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
        va_list ap;

        int i = 0, count = 0;

        va_start(ap, format);

        while (format[i] != '\0')
        {
                if (format[i] == '%')
                {
                        switch (format[i + 1])
                        {
                                case 'd': 
					count += _print_int(va_arg(ap, int));
					i += 2;
					break;
                                case 'i': 
                                        count += _print_int(va_arg(ap, int));
                                        i += 2;
                                        break;

                                default: 
                                        count += _putchar('%');
                                        count += _putchar(format[i + 1]);
                                        i += 2;
                                        break;
                        }
                        continue;
                }

                count += _putchar(format[i]);
                i++;
        }

        va_end(ap);

        return (count);
}

/**
 * _print_int - a function that prints an integer
 * @n: the integer to be printed
 *
 * Return: the number of digits printed
 */

int _print_int(int n)
{
        int digits = 0;

        if (n < 0)
        {
                digits += _putchar('-');
                n = -n;
        }

        if (n / 10)
                digits += _print_int(n / 10);

        digits += _putchar(n % 10 + '0');

        return (digits);
}

