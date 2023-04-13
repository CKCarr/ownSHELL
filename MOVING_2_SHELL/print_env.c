#include <stdio.h>
#include <stdlib.h>

extern char **environ;
/**
  * main - function access & prints env vars
  * Return: Always 0
  */
int main()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
