#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
  * main - function that prints $ and waits for command
  * Return: 0 is success
  */
#define BUFFER_SIZE 1024

int main()
{
	char *line = NULL;
	ssize_t len;
	size_t	size = 0;
	printf("$ ");
/*getline reads user input*/
	len = getline(&line, &size, stdin);
	/*if user enters nothing getline returns -1*/
		if (len != -1)
		{
			/*if user enters command*/
			printf("%s", line);
		}
/*getline allocates memory*/
	free(line);
	line = NULL;

	return (0);
}
