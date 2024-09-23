/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:44:38 by namalier          #+#    #+#             */
/*   Updated: 2024/09/20 16:39:26 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs.h"
# include "Libft/libft.h"
# include "structs.h"

/*********		pipex			*********/

char	**get_path(char **envp, t_data *data);
int		main(int argc, char **argv, char **envp);

/*********		access_cmd		*********/

char	*ft_cpypath(char *argv, char *path);
char	*try_access(char **path, char *argv);
void	access_cmd(t_data *data, char **argv);

/*********		access_files	*********/

void	access_output(t_data *data, char *argv);
void	access_input(t_data *data, char *argv);

/*********		ft_error		*********/

void	ft_free_error(char **str);

# endif
