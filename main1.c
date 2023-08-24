#include "shell.h"
/**
 *main - main function call
 *
 *
 *Return: 0 ALWAYS success
 */
int main(void)
{
	char *msg;
	msg = "Hello, Betty!\n";
	cd_write(msg);
	return (0);
}

/**
  * cd_write - To call input strings
  * @str: message to be written
  */
void cd_write(const char *str)
{
	while (*str)
	{
	write(1, str, 1);
	str++;
	}
}
