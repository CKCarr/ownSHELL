#include "hshell.h"
/**
  * main - test set_env
  * Return: 0 always
  */
int main(void)
{
	char **env = environ;
// Add a new environment variable
	if (set_env("MY_VAR", "my_value", 1) == -1)
	{
		printf("Error: unable to set environment variable\n");
	}
// Change an existing environment variable
	if (set_env("PATH", "/my/new/path", 1) == -1)
	{
		printf("Error: unable to set environment variable\n");
	}
// Print the new environment variables
	env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	free_environ();

	return (0);
}
