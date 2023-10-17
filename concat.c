#include "main.h"
/**
 * stringcat - concatenator
 * @destination: string
 * @sourc: string
 * Return: (0) succcess / destination
 */
char *stringcat(char *destination, char *sourc)
{
	int a = 0;
	int c = 0;

	while (destination[a] != '\0')
		a++;
	while (sourc[c] != '\0')
	{
		destination[a] = sourc[c];
		a++;
		c++;
	}
	destination[a] = '\0';
	return (destination);
}
