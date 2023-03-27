#include "main.h"
/**
 * _printf - a function that produces output according to a format
 * @format: character string that directs the format of the output
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
				case 'c': /* character conversion specifier */
					count += _putchar(va_arg(ap, int));
					i += 2;
					break;
				case 's': /* string conversion specifier */
					count += _puts(va_arg(ap, char *));
					i += 2;
					break;
				case '%': /* percent conversion specifier */
					count += _putchar('%');
					i += 2;
					break;
				case '\0': /* null byte check */
					return (-1);
				default: /* no conversion specifiers */
					count += _putchar(format[i]);
					i++;
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
