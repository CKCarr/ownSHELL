#include "hshell.h"
/**
* _putenv - checks env variable strings.
* @str: str given to check
* Return: Always 0
*/
int _putenv(char *str)
{
        char *name_end = 0, old_var = 0;
        int result = 0;

        if (str == NULL || strlen(str) == 0 || strchr(str, '=') == NULL)
        {
                return -1;
        }/*Check if the environment variable already exists*/
        name_end = strchr(str, '=');
        if (name_end == str)
        {
        return -1;
        }
        *name_end = '\0'; /*temporarily remove the '=' to get the variable name*/
        *old_var = getenv(str);
        *name_end = '=';
        if (old_var != NULL)
        {
                /*Variable already exists, so overwrite it*/
                result = setenv(str, strchr(str, '=') + 1, 1);
                if (result != 0)
                {
                        return -1;/*failed to set the environment variable*/
                }
        }
        else /*Variable doesn't exist, so add it*/
        {
                result = setenv(str, strchr(str, '=') + 1, 0);
                if (result != 0)
                {
                        return -1;/*failed to set the environment variable*/
                }
        }
        return (0);
}
