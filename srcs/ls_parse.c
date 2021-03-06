/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:45:43 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/14 19:15:54 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ls_set_options(t_ls *ls, char opt)
{
	if (opt == 'l' && !(ls->opts & LS_L))
		ls->opts += LS_L;
	else if (opt == 'r' && !(ls->opts & LS_R))
		ls->opts += LS_R;
	else if (opt == 'a' && !(ls->opts & LS_A))
		ls->opts += LS_A;
	else if (opt == 't' && !(ls->opts & LS_T))
		ls->opts += LS_T;
	else if (opt == 'R' && !(ls->opts & LS_RR))
		ls->opts += LS_RR;
	else if (opt == 'C' && !(ls->opts & LS_CC))
		ls->opts += LS_CC - (ls->opts & LS_1 ? LS_1 : 0);
	else if (opt == '1' && !(ls->opts & LS_1))
		ls->opts += LS_1 - (ls->opts & LS_CC ? LS_CC : 0);
	else if (opt == 'o' && !(ls->opts & LS_O))
		ls->opts += LS_O + (ls->opts & LS_L ? 0 : LS_L);
	else if (opt == 'g' && !(ls->opts & LS_G))
		ls->opts += LS_G + (ls->opts & LS_L ? 0 : LS_L);
	else if (opt == 'G' && !(ls->opts & LS_GG))
		ls->opts += LS_GG;
	else if (opt == 'S' && !(ls->opts & LS_SS))
		ls->opts += LS_SS;
}

int				ls_parse_options(t_ls *ls, char **argv, int argc, char *error)
{
	int		index;
	int		stop;
	char	*tmp;

	stop = 1;
	index = 1;
	while (index < argc && (stop = ft_strcmp(argv[index], "--"))
			&& argv[index][0] == '-' && argv[index][1])
	{
		tmp = argv[index] + 1;
		while (*tmp && ft_strchr(OPTIONS, *tmp))
			ls_set_options(ls, *(tmp++));
		if (*tmp && (*error = *tmp))
			return (-1);
		index++;
	}
	return (!stop ? ++index : index);
}
