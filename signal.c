#include "main.h"
/**
 * handlesignal - a function to handle signals
 * @signal: the number of the signal
 */
void signal_handler(int signal)
{
	char *prompt = "\n$ ";

	(void)signal;
	write(1, prompt, strlen(prompt));
	fflush(stdout);
}
