#ifndef HSHELL_H
#define HSHELL_H

/*GLOBAL LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*GLOBAL STRUCTURES*/

/**
  * struct path_node - struct for LinkList
  * nodes created for directory PATH
  * Return: Always 0
  */
struct path_node
{
        char *directory;
        struct path_node *next;
};

/**
  * create_path_node - create a new path node
  * with the specified directory
  * Return: a pointer to the new node
  * or NULL if there was an error
 */

/* GLOBAL VARIABLES*/
extern char **environ;

/*PROTOTYPES*/
struct path_node *create_path_node(char *directory);
void free_path_list(struct path_node *head);
struct path_node *parse_path_directories();
void traverse_path_list(struct path_node *head);







#endif /*HSHELL_H*/
