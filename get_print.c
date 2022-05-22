#include "main.h"

/**
 * get_print: This pin-points the exact printing function
 * @s: character which holds the conversion specifier
 * Description: The function iterates through the structs array
 * func_arr[] just to identify a match between the specifier passed to _printf and the 1st element of the struct,
 * through to the accurate printinting function
 * Return: a pointer to the matching printing function
 */

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'p', print_address},
		{'s', print_string}
		{'c', print_char},
		{'%', print_percent},
		{'i', print_int}
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'d', print_int},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
