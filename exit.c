#include "shell.h"

int exiting(void)
{
	char input[100];

	while (1)
	{
		printf("#cisfun $ ");
		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
	}

	return 0;
}
