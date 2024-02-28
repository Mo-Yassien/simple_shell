#include "shell.h"

/**
 * inter - returns true if shell is interactive mode
 * @inform: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter(info_t *inform)
{
	return (isatty(STDIN_FILENO) && inform->readfd <= 2);
}

/**
 * delim - checks if character is a delimeter
 * @ch: the char to check
 * @del: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delim(char ch, char *del)
{
	while (*del)
		if (*del++ == ch)
			return (1);
	return (0);
}

/**
 *alpha - checks for alphabetic character
 *@ch: The character to input
 *Return: 1 if ch is alphabetic, 0 otherwise
 */

int alpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *atoi - converts a string to an integer
 *@sh: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int atoi(char *sh)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  sh[i] != '\0' && flag != 2; i++)
	{
		if (sh[i] == '-')
			sign *= -1;

		if (sh[i] >= '0' && sh[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (sh[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
