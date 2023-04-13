#include "hshell.h"
int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_env_var;
	char **env = environ;
	int name_len = strlen(name);
	int value_len = strlen(value);
	
	while (*env != NULL)
	{
		if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
		{
			if (overwrite)
			{
				int new_env_var_len = name_len + value_len + 1;
				new_env_var = malloc(new_env_var_len);
				if (new_env_var == NULL)
				{
					return -1;
				}
				sprintf(new_env_var, "%s=%s", name, value);
				free(*env);
				*env = new_env_var;
				return 0;
			}
			else
			{
				return 0;
			}
		}
		env++;
	}
	int new_env_var_len = name_len + value_len + 2;
	new_env_var = malloc(new_env_var_len);

	if (new_env_var == NULL)
	{
		return -1;
	}
	sprintf(new_env_var, "%s=%s", name, value);
	int environ_len = env - environ;
	environ = realloc(environ, sizeof(char *) * (environ_len + 2));

	if (environ == NULL)
	{
		free(new_env_var);
		return -1;
	}
	environ[environ_len] = new_env_var;
	environ[environ_len + 1] = NULL;

	return (0);
}
