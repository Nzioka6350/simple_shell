#include "shell.h"

int main(int ac, char **argv)
{
	char *prompt ="#cisfun $ ";
	char *lineptr = NULL, *copy_lptr = NULL;
	size_t n = 0;
	ssize_t readchars;
	const char *delim = " \n";
	int total_tokens = 0;
	char *tokens;
	int i;

	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		readchars = getline(&lineptr, &n, stdin);
		if (readchars == -1)
		{
			printf("Shell has terminated..\n");
			return (-1);
		}

		copy_lptr = malloc(sizeof(char) * readchars);
		if (copy_lptr == NULL)
		{
			perror("tsh: Error occured when allocating memory");
			return (-1);
		}
		strcpy(copy_lptr, lineptr);

		tokens = strtok(lineptr, delim);

		while (tokens != NULL)
		{
			total_tokens++;
			tokens = strtok(NULL, delim);
		}
		total_tokens++;

		argv = malloc(sizeof(char *) * total_tokens);

		tokens = strtok(copy_lptr, delim);

		for (i = 0; tokens != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(tokens));
			strcpy(argv[i], tokens);

			tokens = strtok(NULL, delim);
		}
		argv[i] = NULL;

		if (i > 0 && strcmp(argv[0], "exit") == 0)
		{
			printf("Shell is exiting...\n");
			break;
		}

		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}

		execution(argv);
		printf("%s",prompt);
	}

	free(lineptr);
	free(copy_lptr);

	return (0);
}
