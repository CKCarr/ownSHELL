#include "hshell.h"


int main()
{
	struct path_node *head = parse_path_directories();
	struct path_node *node = head;

	while (node != NULL)
	{
		printf("%s\n", node->directory);
		node = node->next;
	}
	// Free the memory used by the linked list
	while (head != NULL)
	{
		struct path_node *tmp = head->next;
		free(head->directory);
		free(head);
		head = tmp;
	}

	return 0;
}
