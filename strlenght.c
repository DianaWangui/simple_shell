#include "main.h"
/**
 * stringlength - length calculator
 * @string: string
 * return: length
 */
size_t stringlength(const char *string)
{
	size_t length = 0;

	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}
