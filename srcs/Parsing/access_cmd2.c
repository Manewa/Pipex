/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <namalier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:04:52 by namalier          #+#    #+#             */
/*   Updated: 2024/09/23 17:53:26 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

// Full Path et name_only permettent de faire un char ** avec 
// 1) le path + nom sur pathcmd
// 2) seulement le nom et les flags ensuite sur cmd_flag
//
// Full path requiert un path entier en argument (/usr/bin/ls)
// name only ne prend que le "ls"
//
// pathcmd et cmd_flag sont donc parse pour etre utilisables avec execve
// Pour l'instant, seule la premiere node de la liste (premiere commande) ne peut etre recupere
// Il faut faire la meme avec les suivantes (Fait depuis le while dans access_cmd)
//
// AUCUNE ERREUR N'EST VRAIMENT BIEN GERE NI LEAKS NI MOTS D'ERREUR

list	*full_path_cmd(t_data *data, list *cmd, char **cmd_n_flags)
{
	char	**only_cmd;
	size_t	i;

	cmd->pathcmd = ft_strdup(cmd_n_flags[0]);
	if (!(cmd->pathcmd))
		ft_free_both(data, cmd);
	only_cmd = ft_split(cmd->pathcmd, '/');
	if (!only_cmd)
		ft_free_both(data, cmd);
	i = max_arg_double(only_cmd) - 1;
	cmd->cmd_flag[0] = ft_strdup(only_cmd[i]);
	i = 1;
	while (cmd_n_flags[i])
	{
		cmd->cmd_flag[i] = ft_strdup(cmd_n_flags[i]);
		if (!(cmd->cmd_flag[i]))
			ft_free_error(data);
		i++;
	}
	cmd->cmd_flag[i] = NULL;
	return (cmd);
}

char	*ft_cpypath(char *argv, char *path)
{
	size_t	i;
	size_t	j;
	char	*Cpath;

	i = 0;
	j = 0;
	Cpath = malloc((ft_strlen(argv) + ft_strlen(&path[i])) * sizeof(char));
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

char	*try_access(t_data *data, list *cmd, char *cmd_no_flag)
{
	size_t	i;

	i = 0;
	while (data->path[i])
	{
		cmd->pathcmd = ft_cpypath(cmd_no_flag, data->path[i]);
		if (!(cmd->pathcmd))
			ft_free_both(data, cmd);
		if (access(cmd->pathcmd, F_OK | X_OK) == -1)
		{
			free(cmd->pathcmd);
			i++;
		}
		else
			return (cmd->pathcmd);
	}
	ft_printf("Error\nCommand not found");
	exit(2);
}
void	name_only_cmd(t_data *data, list *cmd, char **cmd_n_flags)
{
	size_t	i;

	i = 0;
	while (cmd_n_flags[i])
	{
		cmd->cmd_flag[i] = ft_strdup(cmd_n_flags[i]);
		if (!(cmd->cmd_flag[i]))
			ft_free_both(data, cmd);
		i++;
	}
	cmd->cmd_flag[i] = NULL;
	cmd->pathcmd = try_access(data, cmd, cmd_n_flags[0]);	
}

list	*create_list(char *argv, t_data *data)
{
	list	*head;
	char	**cmd_n_flags;

	cmd_n_flags = ft_split(argv, ' ');
	head = malloc(sizeof(*head));
	if (!head)
	{
		ft_free_doubletab(cmd_n_flags);
		ft_free_error(data);
	}
	head->next = NULL;
	head->cmd_flag = malloc(max_arg_double(cmd_n_flags) * sizeof(char *));
	if (ft_strchr(cmd_n_flags[0], '/'))
		full_path_cmd(data, head, cmd_n_flags);
	else
		name_only_cmd(data, head, cmd_n_flags);
	size_t i = 0;
	while (head->cmd_flag[i])
	{
		printf("|%s|\n", head->cmd_flag[i]);
		i++;
	}
	printf("|%s|\n", head->pathcmd);
	return (head);
		
}

void	access_cmd(t_data *data, char **argv)
{
	size_t	i;
	size_t	j;
	list	*head;

	i = 3;
	j = 0;
	head = create_list(argv[2], data);
/*	while (argv[i + 1])
	{
		if (!ft_strchr(argv[i], '/'))
			access_fullpath(data, argv[i]);
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
	data->cmd[j] = NULL;*/
}
