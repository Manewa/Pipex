/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:18:07 by namalier          #+#    #+#             */
/*   Updated: 2024/09/20 16:37:47 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_data
{
		char	**path;
		char	**cmd;
		int		max_arg;
		int		input_fd;
		int		output_fd;
}						t_data;

#endif
