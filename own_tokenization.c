#include "shell.h"
/*
 *
 *
 *
 *
 */
void tokenize_cmd(char *cmdin, char *incmd, char *args)
{
	char *space = strchr(cmdin, ' ');
	if (space != NULL)
	{
		strncpy(incmd, cmdin, space - cmdin);
		incmd[space - cmdin] = '\0';
		strcpy(args, space + 1);
	} else
	{
		strcpy(incmd, cmdin);
		args[0] = '\0';
	}
}
