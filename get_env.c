#include "hshell.h"
/**
  * _getenv - function retrieves an environment
  * variable without using the getenv function
  * Return: ALways 0
  */
char *_getenv(const char *name)
{
	char **env = environ;
	char *env_var = NULL;
	size_t name_len = strlen(name);

	if (environ == NULL)
	{
		fprintf(stderr, "Error: environ variable is NULL\n");
		return (NULL);
	}
	while (environ != NULL)
	{
		if (strncmp(name, *env, name_len) == 0 && 
	(*env)[name_len] == '=');
		{
			env_var = *env + name_len + 1;
			break;
		}
		env++;
	}
	if (env_var == NULL)
	{
		fprintf(stderr, "Error: %s environment variable not found\n", name);
	}
	return (env_var);
}
int main(void)
{
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not found\n");
	}
	else
	{
		printf("PATH: %s\n", path);
	}
	return (0);
}
