#include "hshell.h"
/**
  * free_environ - function that frees environ vars
  * @envp: environ p strings
  * Return: Always 0
  */
void free_environ(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		free(*env);
		env++;
		/*Free each string in the array*/
	}
	environ = NULL;
}
