/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:44:14 by rbourgea          #+#    #+#             */
/*   Updated: 2019/09/11 11:57:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		disp(int nb, char *str, char *result, int index)
{
	unsigned	int		nbr;
	unsigned	int		str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	if (nb < 0)
	{
		result[index++] = '-';
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= str_len)
		disp(nbr / str_len, str, result, index - 1);
	result[index] = str[nbr % str_len];
	return (index);
}

int		get_nb_len(int number, char *base)
{
	int		len;
	int		base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	while (number >= base_len)
	{
		++len;
		number /= base_len;
	}
	return (++len);
}

int		get_nb(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		s;
	int		i;
	int		res;
	int		neg;
	int		base_len;

	base_len = 0;
	while (base[base_len])
		++base_len;
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
				|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	neg = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
						(str[i] != '-' && str[i] != '+')))
		if (str[i] == '-')
			neg = -1;
		else if (str[i] != '+')
			res = (res * base_len) + (get_nb(str[i], base));
	return (res * neg);
}
