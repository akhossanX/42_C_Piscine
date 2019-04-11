/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:58:12 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 16:32:47 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_base(char *str);
int		is_valid_str(char *str, char *base);
int		ft_pow(int nb, int pow);
int		convert(char *str, char *base, int radix, int s_len);

int		ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		res;
	int		s_len;
	int		radix;

	sign = 1;
	while (*str == '\t' || *str == ' ' || *str == '\v' || *str == '\r' ||\
			*str == '\n' || *str == '\f')
		str += 1;
	if (*str == '-')
	{
		sign = -1;
		str += 1;
	}
	else if (*str == '+')
		str += 1;
	radix = is_valid_base(base);
	s_len = is_valid_str(str, base);
	if (!(radix > 1) || !s_len)
		return (0);
	res = convert(str, base, radix, s_len);
	return (res * sign);
}

int		convert(char *str, char *base, int radix, int s_len)
{
	int		res;
	int		i;
	int		j;

	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (i < s_len)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		res += j * ft_pow(radix, s_len - i - 1);
		i++;
	}
	return (res);
}

int		is_valid_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (!(base[i] >= 32 && base[i] < 127) || base[i] == '-'\
				|| base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i);
}

int		is_valid_str(char *str, char *base)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '+' && str[i] != '-' && str[i] != '\t' &&\
		str[i] != ' ' && str[i] != '\v' && str[i] != '\r' && str[i] != '\n'\
		&& str[i] != '\f')
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
			if (!base[j])
				return (0);
		}
		i++;
	}
	return (i);
}

int		ft_pow(int nbr, int pow)
{
	if (!pow)
		return (1);
	return (nbr * ft_pow(nbr, pow - 1));
}
