#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
  * main - simple shell program.
  * Return: Always 0
  */
#define MAX_COMMAND_LENGTH 100
int main()
{
	char command[MAX_COMMAND_LENGTH];
	char *args[] = {command, NULL};
	int status;

	while (1)
	{
		printf("$ENTER_COMMAND: ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		if (fork() == 0)
		{
			/*This is the child process*/
			if( execve(command, args, (char *[]) {NULL}) == -1)

			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			/*This is the parent process*/
			wait(&status);
		}
	}
	return (0);
}
