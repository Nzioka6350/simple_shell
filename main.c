#include "shell.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	char incmd[100];
	char *insert;
	char inpcmd[MAX_COMMAND_LENGTH];
	char args[MAX_COMMAND_LENGTH];
	 char *args[3];
    char *token;
    int i;

	while(1)
	{
		can_display();
		handle_inputs(incmd, sizeof(incmd));
		if(strcmp(incmd, "exit") ==0)
		{
			buldin_exiting();
		}
		else if (strcmp(incmd, "env") == 0)
		{
			_environ();
                }else if (strncmp(incmd, "setenv ", 7) == 0) {
            token = strtok(incmd + 7, " ");
            args[0] = token;

            i = 1;
            while (token != NULL && i < 3) {
                token = strtok(NULL, " ");
                args[i] = token;
                i++;
            }
	      if (args[0] != NULL && args[1] != NULL) {
                setenv_command(args[0], args[1]);
            } else {
                fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
            }
        } else if (strncmp(incmd, "unsetenv ", 9) == 0) {
            char *variable = incmd + 9;
            if (variable != NULL) {
                unsetenv_command(variable);
            } else {
                fprintf(stderr, "Usage: unsetenv VARIABLE\n");
            }
        } else {
			execution(incmd);
			arguments_exec(incmd);
		}
		shell_print("Enter anything:");
		insert = ourOwn_shellgetline();

		tokenize_cmd(insert, inpcmd, args);
		printf("First Word or Command: %s\n", inpcmd);
		printf("Arguments : %s\n", args);

		free(insert);
        }
	return (0);
}
