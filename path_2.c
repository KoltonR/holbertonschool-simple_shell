#include "shell.h"

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

/*count number of files in PATH*/
	while (juanito[0][i] != '\0')
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
