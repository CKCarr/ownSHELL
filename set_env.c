#include "hshell.h"

/**
  * set_env - function that sets env
  * @name: string for env name
  * @value: string for env value
  * @overwrite: buf overwrite
  * Return: Always 0
  */
int set_env(const char *name, const char *value, int overwrite)
{
	char *buf = 0, **env = environ;
	int name_len = strlen(name), value_len = strlen(value);
	int result = 0, updated = 1;
	size_t buf_len = name_len + value_len + 2;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	if (overwrite < 0 || overwrite > 1)
	{
		overwrite = 0;
	}
	buf = malloc(buf_len);
	if (buf == NULL)
	{
		free(buf);
		return (-1);
	}
	snprintf(buf, buf_len, "%s=%s", name, value);
	while (*env != NULL)
	{
		if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
		{ /*Don't overwrite the environment variable*/
			if (!overwrite)
			{
				result = 0;
				updated = 1;
				break;
			} /*Overwrite the environment variable*/
			else
			{
				result = putenv(buf);
				updated = 1;
				break;
			}
		}
		env++;
	}
	if (!updated)
	{
		result = putenv(buf);
	}
	free(buf);
	return (result);
}

/**
 * _add_env_var - helper function to add a new
 *   environment variable to the environ array
 * @name: string for env name
 * @value: string for env value
 * Return: Always 0
 */
int _add_env_var(const char *name, const char *value)
{
	int i = 0;
	int name_len = strlen(name);
	int value_len = strlen(value);
	char *new_env_var, **new_environ, **env;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	new_env_var = malloc(name_len + value_len + 2);
	if (new_env_var == NULL)
	{ /*Error: unable to allocate memory*/
		return (-1);
	}
	sprintf(new_env_var, "%s=%s", name, value);
	new_environ = malloc(sizeof(char *) * (environ_size() + 2));
	if (new_environ == NULL)
	{ /*Error: unable to allocate memory*/
		free(new_env_var);
		return (-1);
	} /*Copy existing environ vars to the new array*/
	env = environ;
	while (*env != NULL)
	{
		new_environ[i++] = *env;
		env++;
	} /*Add the new environ var to the end of the new array*/
	new_environ[i++] = new_env_var;
	new_environ[i] = NULL;/*Add NULL termin8r to end new array*/
	environ = new_environ;/*global env var to point 2 new array*/

	free(new_env_var);

	return (0);
}

/**
 * _update_env_var - helper function to update an
 * existing environment variable in the environ array
 * @name: string for env name
 * @value: string for env value
 * @env: pointer to pointer of array environ strings
 * Return: Always 0
 */
int _update_env_var(char **env, const char *name, const char *value)
{
	int name_len = strlen(name);
	int value_len = strlen(value);
	char *new_env_var = malloc(name_len + value_len + 2);

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	if (new_env_var == NULL)
	{ /*Error: unable to allocate memory*/
		return (-1);
	}
	sprintf(new_env_var, "%s=%s", name, value);
/*Update the environment variable in the environ array*/
	if (*env != NULL)
	{
		free(*env);
	}
	*env = new_env_var;

	return (0);
}

/**
 * environ_size - helper function to get size of the environ array
 * Return: ALways 0
 */
int environ_size(void)
{
	char **env = environ;
	int size = 0;

	while (*env != NULL)
	{
		size++;
		env++;
	}
	return (size);
}
