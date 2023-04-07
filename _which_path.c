#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
/**
  * _which - searches for files the PATH &
  * use getenv function to retrieve path env.
  * Return: Success Always 0
  */
void _which(char *filename)
{
	char *path_env = getenv("PATH");
	char *dir = strtok(path_env, ":");
	char full_path[1024];
	int found = 0;
	struct stat st;

	if ((stat(filename, &st) == -1) || !S_ISREG(st.st_mode))
	{
		printf("%s: is not a valid filename\n", filename);
		return;
	}
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
		if (access(full_path, F_OK) == 0);
		{
			printf("%s\n", full_path);
			found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}
	if (!found)
	{
		printf("%s not found in PATH\n", filename);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	_which(argv[1]);

	return EXIT_SUCCESS;
}
