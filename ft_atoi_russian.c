/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:32:19 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/11 22:51:21 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

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
	long long	toi;
		/* предел 9 млрд - превышает инту в два раза, защита от переполнения */
	long long	max_div_ten;
		/* необходимо отсечь конец макс-числа, т.к. от него зависит результат:
		 * если на конце 8, то число отрицательное, вернуть 0;
		 * если на конце 7, то число положительное, вернуть -1; */
	int				i;
	int				sign;

	toi = 0;
	max_div_ten = (long long)(LLONG_MAX / 10);
		/* отсекаем один символ */
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
	/* приведение типов работает через числовую конверсию. в данном случае мы
	 * делаем из иерархически выше расположенного ul конверсию в ниже стоящий int,
	 * что происходит путем отсечения старших битов, и поэтому работает
	 * некорректно.
	 * принудительно приводить результат не надо, он будет приведет автоматически
	 * к типу функции (инт) */
}