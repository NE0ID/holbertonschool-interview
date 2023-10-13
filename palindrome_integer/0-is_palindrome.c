#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * one_digit - return 1 if given number is one digit only
 *
 * @num: number to check
 *
 * Return: 1 if the number is a digit 0 if it's not a single digit
 */
int one_digit(unsigned long int num)
{
	if (num < 10)
		return (1);
	return (0);
}

/**
 * is_pal_rec - check recursively if a number is a palindrome
 *
 * @num: number to check
 * @cpy_num: copy of the number to check
 *
 * Return: 1 if it is 0 otherwise
 */
int is_pal_rec(unsigned long int num, unsigned long int* cpy_num)
{
	if (one_digit(num))
	{
		if (num == (*cpy_num) % 10)
			return (1);
	}

	if (!is_pal_rec(num / 10, cpy_num))
		return (0);

	*cpy_num /= 10;

	return (num % 10 == (*cpy_num) % 10); 
}

/**
 * is_palindrome: check if number is a palindrome
 *
 * @n: number to check
 *
 * Return: 1 on true, 0 on false
 */
int is_palindrome(unsigned long n)
{
	unsigned long int cpy_n = n;

	if (is_pal_rec(n, &cpy_n) == 1)
		return (1);
	return (0);
}
