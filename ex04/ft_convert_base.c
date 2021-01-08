/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:39:50 by rbourgea          #+#    #+#             */
/*   Updated: 2019/09/11 11:58:41 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		disp(int nb, char *str, char *result, int index);
int		get_nb_len(int number, char *base);
int		get_nb(char c, char *base);
int		ft_atoi_base(char *str, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		number;
	int		last_index;

	if (!nbr || !base_from || !base_to)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	result = malloc(sizeof(char) * get_nb_len(number, base_to));
	last_index = disp(number, base_to, result,
	get_nb_len(number, base_to) - 1);
	result[last_index + 1] = '\0';
	return (result);
}
