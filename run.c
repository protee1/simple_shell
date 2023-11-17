#include "shell.h"

/**
 *ex_apcomand - command executer
 */
void ex_apcomand(const char *command){
	pid_t child_pid = fork();
	if (child_pid == -1){
		perror("fork");
		exit (EXIT-FAILURE);
	}
	else if (child_pid == 0){
		execve(command, command, (char *)null);
		perror("execve");
		exit(EXIT-FAILURE);
	}
	else{
		wait(NULL);
}
