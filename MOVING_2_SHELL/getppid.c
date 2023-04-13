#include <stdio.h>
#include <unistd.h>
/**
  * main - function that prints parent process id
  * Return: 0 success 
  */
int main()
{
	pid_t parent_pid = getppid();
	printf("Parent PID: %d\n", parent_pid);
	return (0);
}
