/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:18:10 by namalier          #+#    #+#             */
/*   Updated: 2024/09/20 16:37:32 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_free_error(t_data *data)
{
	size_t i;

	if (data->cmd)
		ft_free_doubletab(data->cmd);
	if (data->path)
		ft_free_doubletab(data->path);
	ft_printf("Error\n");
	exit(2);

}
