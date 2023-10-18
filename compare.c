#include "main.h"
/**
 * stringmp - compares two str
 * @string1: first str
 * @string2: second str
 * Return: function pointer
 */
int stringmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}
