/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:18:10 by namalier          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:46 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_free_error(t_data *data)
{

	if (data->path)
		ft_free_doubletab(data->path);
	ft_printf("Error\n");
	exit(2);

}

void	ft_free_both(t_data *data, list *cmd)
{
	ft_free_doubletab(data->path);
	pipex_lstfree(&cmd);
	exit(2);
}
