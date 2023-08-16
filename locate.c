#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TOKENS	100
#define PATH_MAX_LENGTH	1024

void	execution(char **argv)
{
	pid_t	pid = fork();

	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("tsh: Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("tsh: Fork failed");
	else
		wait(NULL);
}

int	main(void)
{
	char	*prompt = "#cisfun $";
	char	*lineptr = NULL, *copy_lptr = NULL;
	size_t	n = 0;
	ssize_t	readchars;
	const char *delim = " \n";
	char	*tokens[MAX_TOKENS];
	int	total_tokens = 0;
	int	i;

	while (1)
	{
		printf("%s", prompt);
		readchars = getline(&lineptr, &n, stdin);
		if (readchars == -1)
		{
			printf("Shell has terminated..\n");
			break;
		}

		copy_lptr = malloc(readchars);
		if (copy_lptr == NULL)
		{
			perror("tsh: Error occurred when allocating memory");
			return (-1);
		}
		strcpy(copy_lptr, lineptr);

		tokens[0] = strtok(lineptr, delim);
		total_tokens = 0;

		for (i = 0; tokens[i] != NULL && i < MAX_TOKENS - 1; i++)
		{
			total_tokens++;
			tokens[i + 1] = strtok(NULL, delim);
		}
		tokens[i] = NULL;

		if (total_tokens > 0)
		{
			if (strcmp(tokens[0], "exit") == 0)
				break;
			else
				execution(tokens);
		}

		printf("%s", prompt);

		free(copy_lptr);
	}

	free(lineptr);

	return (0);
}
