#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
  * main - function that uses fork + wait + execve
  * Return: Always 0
  */
int main()
{
	pid_t pid;
	int i, status;
	char *args[] ={"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit (1);
		}
		else if (pid == 0)
		{
			/*This is the child process*/
			execve("/bin/ls", args, NULL);
			perror("execve");
			exit(1);
		}
		else
		{
			/*This is the parent process*/
			wait(&status);
		}
	}
	return (0);
}
