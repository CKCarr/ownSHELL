#include "hshell.h"
/**
  * create_path_node - create a new path node
  * with the specified directory
  * Return: a pointer to the new node
  * or NULL if there was an error
 */
struct path_node *create_path_node(char *directory)
{
	struct path_node *node = malloc(sizeof(struct path_node));

	if (directory == NULL)
		return (NULL);
	if (node == NULL)
		fprintf(stderr, "Error: unsble to alocate memory\n");
	return (NULL);

	node->directory = strdup(directory);
	if (node->directory == NULL)
	{
		fprintf(stderr, "Error: unable to allocate memory\n");
		free(node);
		return (NULL);
	}
	node->next = NULL;

	return (node);
}
/**
  * free_path_list - free the memory allocated
  * for a path linked list
  * Return: Always 0
  */
void free_path_list(struct path_node *head)
{
	struct path_node *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->directory);
		free(head);
		head = tmp;
	}
}
/**
 * parse_path_directories - parse the PATH environment
 * variable and build a linked list of directories
 * Return: a pointer to the head of the linked list
 * or NULL if there was an error
 */
struct path_node *parse_path_directories()
{
	struct path_node *head, *tail, *new_node;
	char *path, *dir;

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return (NULL);
	}
	head = NULL;
	tail = NULL;
	dir  = strtok(path,":");
	while (dir != NULL)
	{
		new_node = create_path_node(dir);
		if (new_node == NULL)
		{
			free_path_list(head);
			return (NULL);
		}
		if (tail == NULL)
		{
			head = tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		dir = strtok(NULL, ":");
	}

	return (head);
}
