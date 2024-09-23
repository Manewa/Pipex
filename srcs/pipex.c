/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:31:09 by namalier          #+#    #+#             */
/*   Updated: 2024/09/20 16:51:34 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_path(char **envp, t_data *data)
{
	size_t	i;
	char	*str;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		exit (2);
	str = ft_strdup(&envp[i][5]);
	if (!str)
		exit(2);
	data->path = ft_split(str, ':');
	free (str);
	if (!(data->path))
		exit(2);
}

int	max_arg(char **argv, t_data *data)
{
	while (argv[i])
		i++;
	data->max_arg = i;
	return (i);
}

int main(int argc, char **argv, char** envp)
{
	t_data	data;

	if (argc != 5)
		return (ft_printf("Error\nNot 5 args"), 0);
	get_path(envp, &data);
	access_input(&data, argv[1]);
	access_output(&data, argv[max_arg(argv, &data)]);
	access_cmd(&data, argv);
	ft_printf("%s\n%s\n", data.cmd[0], data.cmd[1]);
	return (0);
}
