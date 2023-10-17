#include "simple.h"
/**
 * puts_prompt -puts the prompt
 *
 *
 */
void puts_prompt(void)
{
	_puts(PROMPT);
}
/**
 * _puts - prints a string without a \n
 * @rst string to print
 * Return: void
 */
void _puts(char *rst)
{
	unsigned int length;

	length = _strlen(rst);

	write(STDOUT_FILENO, rst, length);
}

/**
   * _putchar - writes the character c to stdout
   * @c: The character to print
   *
   * Return: On success 1.
   * On error, -1 is returned, and errno is set appropriately.
   */
int _putchar(char c)
{
		return (write(1, &c, 1));
}

/**
  * _puts_int - writes an integer
  * @n: integer
  */
void _puts_int(int n)
{
	unsigned int length = 1, r;
	int temp_n = n;

	while (temp_n / 10)
	{
		length++;
		temp_n /= 10;
	}
	for (r = 0; r < length; r++)
	{
		_putchar((n / (MATH_pow(10, length - r - 1)) + '0'));
		n %= (MATH_pow(10, length - r - 1));
	}
}

/**
  * MATH_pow - exponent fnc
  * @base: base number
  * @exp: exponent number
  * Return: base^exp
  */
int MATH_pow(int base, int exp)
{
	int retint = 1;

	while (exp > 0)
	{
		retint *= base;
		exp--;
	}
	return (retint);
}
