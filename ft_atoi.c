/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:32:19 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/10 17:49:41 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(char c)
{
	if (c >= 0 && c <= 32)
		return (1);
	return (0);
}

static int		ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	unsigned long	toi;
	unsigned long	max_div_ten;
	int				i;
	int				sign;

	toi = 0;
	max_div_ten = (unsigned long)(9223372036854775807 / 10);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isnum(str[i]))
	{
		if ((toi > max_div_ten || (toi == max_div_ten && (str[i] - '0') > 7))
			&& sign == 1)
			return (-1);
		else if ((toi > max_div_ten || (toi == max_div_ten &&\
		(str[i] - '0') > 8)) && sign == -1)
			return (0);
		toi = toi * 10 + (str[i++] - '0');
	}
	return (toi * sign);
}
