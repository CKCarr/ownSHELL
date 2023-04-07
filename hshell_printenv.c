#include "hshell.h"
/**
  * _print_env - prints env builtin
  * Return: always 0 success
  */
void _print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
