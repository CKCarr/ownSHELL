#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
  * main - fork and wait example
  * Return: Always 0
  */
int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for Me! Wait for Me!\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh!! Its all better Now!!\n");
	}
	return (0);
}
