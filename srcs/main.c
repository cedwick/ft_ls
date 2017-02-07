/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:05:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/07 15:16:58 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int		ls_cmp_filename(t_list *a, t_list *b)
{
	char *fa;
	char *fb;

	fa = ((t_lsarg *)(a->content))->filename;
	fb = ((t_lsarg *)(b->content))->filename;
	return (ft_strcmp(fa, fb));
}

static void		ft_lstfailput(t_list *l)
{
	int i;
	t_lsarg	*a;

	i = 0;
	while (l)
	{
		a = (t_lsarg *)(l->content);
		printf("link %i : ft_ls: %s: %s\n", i++, a->filename, strerror(a->err));
		l = l->next;
	}
}

int		main(int argc, char **argv)
{
	t_ls		ls;
	char		error;
	int			start;
	t_list		*lst;
	t_lsarg		*data;

	ft_bzero(&ls, sizeof(t_ls));
	ft_printf("{grn}welcome to project ft_ls{no}\n");
	if ((start = ls_parse_options(&ls, argv, argc, &error)) < 0)
	{
		printf("ft_ls: illegal option -- %c\n%s\n", error, USAGE);
		return (0);
	}
	if (start == argc)
		ft_printf("there's no argument");
	else
		ft_printf("arguments start at index %d && there are %10i args\n", start, argc - start);
	ls.count = argc - 1;
	ls_arg_to_list(&ls, argv, start, argc);
	ft_printf("\n\n***\nlist of fails sorted\n\n");
	ft_lstsort(ls.fails, ls_cmp_filename);
	ft_lstfailput(ls.fails);
	ft_printf("\n\n***\n{blu}let's try that ft_ls !!\n***{no}\n");
	lst = ls.args;
	while (lst)
	{
		data = (t_lsarg *)(lst->content);
		ls_core(&ls, data->filename, ls_ftolist(data->filename));
		lst = lst->next;
	}
	return (0);
}
