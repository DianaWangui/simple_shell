#include "main.h"
/**
 * stringmp - compares two str
 * @string1: first str
 * @string2: second str
 * return: function pointer
 */
int stringmp(const char *string1, const char *string2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		string1++;
		string2++;
	}
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}
