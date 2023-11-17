#include "shell.h"

/**
 * ap_print - print message to user
 */
void ap_print(const char *msg){
	write(STDOUT_FILENO, msg, strlen(msg));
}

