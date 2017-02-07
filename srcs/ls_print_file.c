/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:48:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/07 16:27:03 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ls_print_file(t_ls *ls, char *filename, t_list *lst)
{
	t_lsarg	*data;

	if (ls->count)
		ft_printf("%s:\n", filename);
	while (lst)
	{
		data = (t_lsarg *)(lst->content);
		printf("%s\n", (data->err ? strerror(data->err) : data->filename));
		lst = lst->next;
	}
	return (1);
}
