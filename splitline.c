#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  * splint_line - splits the line into array of
  *              tokens using strtok
  * Return: 0 success
  */
#define MAX_WORDS 100

char** split_line(char *str)
{
	char **words, *word;
	int i = 0;
/*allocate memory for the array of words*/
	words = malloc(MAX_WORDS * sizeof(char *));
	if (words == NULL)
	{
		printf("Error: unable to allocate memory for words array\n");
		exit(EXIT_FAILURE);
	}
/* Split string into words with strtok*/
	word = strtok(str, " ");
	while (word != NULL)
	{
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
/*set last element to NULL: end of array*/
	words[i] = NULL;

	return (words);
}

int main()
{
	char str[] = "Hello world! This is a test.";
	char **words = split_line(str);
	/*Print the array of words*/
	for (int i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
	}
	/*Free memory*/
	free(words);
	return 0;
}
