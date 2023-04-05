#include <stdio.h>
#include <unistd.h>
/**
  * main - function that prints the av without using ac
  * Return: success 0
  */
int main(int ac, char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
