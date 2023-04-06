#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
  * main - fork example
  * Return: Always 0
  */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	my_pid = getpid();
	printf("My PID is %u\n", my_pid);
	if (child_pid == 0)
	{
		printf(" (%u) NOoOoOoOoOoo!!\n", my_pid);
	}
	else
	{
		printf(" (%u) %u, I am your Father\n", my_pid, child_pid);
	}
	return (0);
}
