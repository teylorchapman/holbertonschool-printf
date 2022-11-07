#include "main.h"

/**
 * check - Function
 * @format: Format Specifier predefined
 * Description: Checks Valid Format Specifier
 * Return: Pointer Valid or NULL
 */
int (*check(const char *format))(va_list)
{
	unsigned int i;
print_t p[] = { {"c", print_c}, {"s", print_s}, {"p", print_p}, {"d", print_d},
	{"i", print_i}, {NULL, NULL} };

for (i = 0; p[i].t != NULL; i++)
{
if (*(p[i].t) == *format)
		{
			break;
		}
}
return (p[i].f);
}
/**
 * _printf - Prints Anything
 * @format: List Argument Types Passed to Tunction
 * Descripction: Output Accord to Format
 * Return: Length Characters Printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list lst;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(lst, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check(&format[i + 1]);
		if (f != NULL)
		{
			count += f(lst);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(lst);
	return (count);
}
