/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <namalier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:18:07 by namalier          #+#    #+#             */
/*   Updated: 2024/09/23 16:19:17 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_data
{
		char	**path;
		int		max_arg;
		int		input_fd;
		int		output_fd;
}						t_data;

typedef struct	pipex_list
{
		char	*pathcmd;
		char	**cmd_flag;
		void	*next;
}						list;

#endif
