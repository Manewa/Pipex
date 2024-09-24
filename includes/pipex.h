/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <namalier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:44:38 by namalier          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:44 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs.h"
# include "Libft/libft.h"
# include "structs.h"

/*********		pipex			*********/

void	get_path(char **envp, t_data *data);
int		max_arg_double(char **argv);
int		main(int argc, char **argv, char **envp);

/*********		access_cmd2		*********/

list	*full_path_cmd(list *cmd, char **cmd_n_flags);
char	*ft_cpypath(char *argv, char *path);
char	*try_access(t_data *data, list *cmd, char *cmd_no_flag);
int		name_only_cmd(t_data *data, list *cmd, char **cmd_n_flags);
list	*create_node(char *argv, t_data *data);
void	access_cmd(t_data *data, char **argv);


/*********		access_files	*********/

void	access_output(t_data *data, char *argv);
void	access_input(t_data *data, char *argv);

/*********		ft_error		*********/

void	ft_free_error(t_data *data);
void	ft_free_both(t_data *data, list *cmd);

/*********		lst				**********/

void	pipex_lstadd_back(list **lst, list *new);
list	*pipex_lstlast(list *lst);
void	pipex_lstfree(list **head);

# endif
