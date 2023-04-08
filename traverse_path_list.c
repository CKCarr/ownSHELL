#include "hshell.h"
/**
  * traverse_path_list -iterates through each node of 
  * linked list and prints its contents.
  * Return: Always 0
  */
void traverse_path_list(struct path_node *head)
{
	struct path_node *node = head;

	if (head == NULL)
		return;
	if (node == NULL)
	{
		printf("%s\n", node->directory);

		node = node->next;
	}
}
