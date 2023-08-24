#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command.
 * @info: Structure containing potential arguments. Used to maintain
 * @path: Path to the file.
 *
 * This function checks if the given
 * path points to an existing executable file.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicates characters from a string within a range.
 * @pathstr: The source string to duplicate characters from.
 * @start: The starting index of the range.
 * @stop: The stopping index of the range.
 *
 * This function duplicates characters from a given range of the source string
 * into a static buffer and returns a pointer to it.
 *
 * Return: Pointer to the new buffer containing duplicated characters.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int m = 0, k = 0;

	for (k = 0, m = start; m < stop; m++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - Finds the full path of a command in the PATH string.
 * @info: Structure containing potential arguments. Used to maintain
 * @pathstr: The PATH string to search in.
 * @cmd: The command to find.
 *
 * This function searches for the full path of the given command within the
 * provided PATH string. It iterates through the different paths in PATH,
 * combines them with the command, and checks if the resulting path points to
 * an executable command.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int m = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}
