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
 */
paths_t *get_path(char **env)
{
	int i = 0, j = 0, num = -1, count = 0, num_dirs = 0;
	char **juanito;
	char **tmp2 = NULL;
	paths_t *head;
	char *comparation = "PATH";

	while (env[i] != NULL) /* look for PATH */
	{
		if (strncmp(env[i], comparation, 4) == 0) 
		{
			num = i;
			break;
		}
		i++;
	}
	if (num == -1) /* If not PATH found, exit*/
		return (NULL);
	juanito = &env[num];
	i = 0;
	while (juanito[0][i] != '\0')/*count number of files in PATH*/
		{
			if (juanito[0][i] == ':')
			{
				num_dirs++;
			}
			i++;
		}
		num_dirs++; /* add 1 to the last file*/

		tmp2 = malloc(sizeof(char *) * num_dirs); /*memory to tmp2*/
        if (!tmp2)
		return (NULL);

	i = 0; /* look for files in PATH, add a tmp*/
	while (juanito[0][i] != '\0') 
	{
		if (juanito[0][i] == ':') 
		{
			juanito[0][i] = '\0';
			tmp2[count++] = &juanito[0][j];
			j = i + 1;
		}
		i++;
	}
	tmp2[count++] = &juanito[0][j];
	tmp2[count] = NULL;

	head = NULL; /*linked list to files*/
	for (i = 0; tmp2[i]; i++)
		create_struct(&head, tmp2[i]);
	free(tmp2);
	return (head);
}
