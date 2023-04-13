#include "shell.h"
/**
 * parse_text_path - parse the input path
 * @str: string of the path
 * @parsed: string parsed, in chunks
 *
 * Return: void
 */
void parse_text_path(char *str, char **parsed)
{
	const char delimiters[] = "=:;";
	char *dest = NULL;
	int i;

	dest = strtok(str, delimiters);
	i = 0;
	while (dest)
	{
		parsed[i] = dest;
		dest = strtok(NULL, delimiters);
		i++;
	}
	parsed[i] = NULL;
	free(dest);
}
/**
 * create_struct - print nodes size
 * @head: node
 * @str: string
 *  Return: nodes head
 */
paths_t *create_struct(paths_t **head, char *str)
{
	paths_t *new_node = (paths_t *)malloc(sizeof(paths_t));

	if (!new_node)
		return (NULL);

	new_node->path = _strdup(str);
	if (!new_node->path)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
/**
 *   get_path - Function to generate the path
 *   @env: Receive the env of the shell
 *
 *   Return: string whit the path

*paths_t *get_path(char **env)
*{
*	char *path_var = "PATH=";
*	paths_t *head = NULL;
*	int i;
*
*	for (i = 0; env[i] != NULL; i++)
*	{
*		if (strncmp(env[i], path_var, 5) == 0)
*		{
*			char *path = env[i] + 5;
*			char *token = strtok(path, ":");
*			while (token != NULL)
*			{
*				create_struct(&head, token);
*				token = strtok(NULL, ":");
*			}
*			break;
*		}
*	}
*return (head);
*}
*/
