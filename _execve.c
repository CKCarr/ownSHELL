#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
  * execve - allow process to exec another program
  * Return: Always 0
  */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL))
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
