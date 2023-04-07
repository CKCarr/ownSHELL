#include "hshell.h"
/**
  * print_path_directories - function that prints each 
  * directory contained in the PATH environment variable
  * Return: Always 0
  */
void print_path_directories(void)
{
	char *path = getenv("PATH");
	char *dir;
	char *saveptr;

	if (path == NULL)
	{
		printf("PATH enviroment variable not found");
		return;
	}
	/*strtok_r:splits PATH string into individual directories*/
	dir = strtok_r(path, ":", &saveptr);
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok_r(NULL, ":", &saveptr);
	}
}
int main(void)
{
	print_path_directories();
	return (0);
}
