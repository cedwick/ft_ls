/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:18:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/15 13:26:53 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list	*next_elem(t_list *lst, int ratio)
{
	while (lst && ratio--)
		lst = lst->next;
	return (lst);
}

static int		calc_rows(int ln, int ratio)
{
	int rows;

	if (!(rows = ln / ratio))
		rows = 1;
	else if (ln % ratio)
		rows++;
	return (rows);
}

static int		ls_dashc_helper(t_ls *ls, t_list *lst, int ratio, int max)
{
	int		rate;
	int		rows;
	int		stop;
	t_list	*tmp;

	rows = calc_rows(ft_lstlen(lst), ratio);
	stop = rows;
	while (lst && stop--)
	{
		tmp = lst;
		rate = ratio;
		while (rate--)
		{
			if (tmp)
				ls_print_helper(ls, (t_lsarg *)(tmp->content), -(max + 1));
			else
				ft_printf("%*c", max + 1, ' ');
			tmp = next_elem(tmp, rows);
		}
		lst = lst->next;
		write(1, "\n", 1);
	}
	return (1);
}

int				ls_print_c(t_ls *ls, t_list *lst)
{
	t_list			*tmp;
	int				max;
	int				val;

	tmp = lst;
	max = 0;
	while (tmp)
	{
		if ((val = ft_strlen(((t_lsarg *)tmp->content)->filename)) > max)
			max = val;
		tmp = tmp->next;
	}
	val = ls->console_width /(max + 1);
	ls_dashc_helper(ls, lst, val, max);
	return (1);
}
