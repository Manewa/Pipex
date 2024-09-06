/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:08:21 by namalier          #+#    #+#             */
/*   Updated: 2024/09/06 17:18:08 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_cpypath(char *argv, char *path)
{
	size_t	i;
	size_t	j;
	char	*Cpath;

	i = 0;
	j = 0;
	Cpath = malloc((ft_strlen(argv) + ft_strlen(&path[i]) + 1) * sizeof(char));
	if (!Cpath)
		return(NULL);
	while (path[i])
	{
		Cpath[i] = path[i];
		i++;
	}
	Cpath[i++] = '/';
	while (argv[j])
		Cpath[i++] = argv[j++];
	Cpath[i] = '\0';
	return (Cpath);
}

char	*try_access(char **path, char *argv)
{
	size_t	i;
	char	*Cpath;

	i = 0;
	while (path[i])
	{
		Cpath = ft_cpypath(argv, path[i]);
		if (!Cpath)
			return (NULL);
		if (access(Cpath, F_OK | X_OK) == -1)
		{
			free(Cpath);
			i++;
		}
		else
			return (Cpath);
	}
	ft_printf("Error\nCommand not found");
	exit(2);
}

void	access_cmd(t_data *data, char **argv)
{
	size_t	i;
	size_t	j;

	i = 2;
	j = 0;
	while (argv[i + 1])
	{
		if (!ft_strchr(argv[i], '/'))
			data->cmd[j] = try_access(data->path, argv[i]);
		else
		{
			if (access(argv[i], F_OK | X_OK) == 0)
				data->cmd[j] = ft_strdup(argv[i]);
			else
			{
				ft_printf("Error\nCommand not found");
				exit (2);
			}
		}
		i++;
		j++;
	}
//	data->cmd[j] = malloc(1*sizeof(char));
	data->cmd[j] = NULL;
}
