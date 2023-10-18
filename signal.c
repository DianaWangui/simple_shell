#include "main.h"
ssize_t stringlength(const char *string);
/**
 * handlesignal - a function to handle signals
 * @signal: the number of the signal
 */
void handle_signal(int signal)
{
	char *prompt = "\n$ ";

	(void)signal;
	write(1, prompt, stringlength(prompt));
	fflush(stdout);
}
