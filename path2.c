#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * get_path - Function to generate the path
 * @env: Receive the env of the shell
 *
 * Return: string whit the path
 */


paths_t *get_path(char **env)
{
	char *path_var = getenv("PATH"); /*gets the value of PATH*/

	/*it it not found, exit*/
	if (!path_var)
		return (NULL);

	paths_t *head = NULL;

	char *dir = strtok(path_var, ":"); /* parse ':' */

	while (dir)
	{
		create_struct(&head, dir); /* add each file to list*/
		dir = strtok(NULL, ":");
	}
	return (head);
}
