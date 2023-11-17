#include "shell.h"

int main(void){
	char ap_comand[128];
	while (1){
		prompt();
		myuser_input(ap_command, sizepf(ap_command));
		ex_apcom(ap_comand);
	}
	return 0;
}
