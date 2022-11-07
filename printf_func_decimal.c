#include "main.h"

/**
* print_d - Function
* @d: Integer
* Description: Prints an Decimal
* Return: Number Chars and Cigits
*/
int print_d(va_list d)
{
int t[10];
int var1, op1, f, sum, count;

f = va_arg(d, int);
count = 0;
op1 = 1000000000;
t[0] = f / op1;
for (var1 = 1; var1 < 10; var1++)
{
op1 /= 10;
t[var1] = (f / op1) % 10;
}
if (f < 0)
{
_putchar('-');
count++;
for (var1 = 0; var1 < 10; var1++)
t[var1] *= -1;
}
for (var1 = 0, sum = 0; var1 < 10; var1++)
{
sum += t[var1];
if (sum != 0 || var1 == 9)
{
_putchar('0' + t[var1]);
count++;
}
}
return (count);
}
