#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * This function buffers chained commands
 * by reading input and storing it in a buffer.
 * It checks for semicolons to identify chained commands and handles comments.
 *
 * Return: Bytes read that is f
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t f = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		f = getline(buf, &len_p, stdin);
#else
		f = _getline(info, buf, &len_p);
#endif
		if (f > 0)
		{
			if ((*buf)[f - 1] == '\n')
			{
				(*buf)[f - 1] = '\0';
				f--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = f;
				info->cmd_buf = buf;
			}
		}
	}
	return (f);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * This function gets input from the user,
 * handling command chaining, history building, and more.
 * It returns the length of the current command line or -1 on EOF.
 *
 * @info: The parameter struct containing various shell-related information.
 *
 * Return: The number of bytes read or -1 on EOF.
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t m, j, len;
	ssize_t f = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (f == -1)
		return (-1);
	if (len)
	{
		j = m;
		p = buf + m;
		check_chain(info, buf, &j, m, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		m = j + 1;
		if (i >= len)
		{
			m = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

i	*buf_p = buf;
	return (f);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * This function reads data into a buffer and
 * updates the length variable accordingly.
 *
 * @info: The parameter struct containing various shell-related information.
 * @buf: The buffer to store the read data.
 * @i: The address of the size variable.
 *
 * Return: The number of bytes read.
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t f = 0;

	if (*i)
		return (0);
	f = read(info->readfd, buf, READ_BUF_SIZE);
	if (f >= 0)
		*i = f;
	return (f);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * This function reads the next line of input from STDIN,
 * handling buffer management,
 * newline parsing, and dynamic memory reallocation.
 *
 * @info: The parameter struct containing various
 * shell-related information.
 * @ptr: The address of the pointer to the buffer.
 * @length: The size of the preallocated buffer if not NULL.
 *
 * Return: The number of characters read or -1 on failure.
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t f = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	f = read_buf(info, buf, &len);
	if (f == -1 || (f == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - Handles the SIGINT signal (Ctrl-C)
 * @sig_num: The signal number (unused)
 *
 * This function is called when the SIGINT signal (Ctrl-C) is received.
 * It prints a newline followed by the shell
 * prompt to a new line and flushes the output buffer.
 *
 * @sig_num: The signal number (unused).
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
