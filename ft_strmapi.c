/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:22:33 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/16 17:43:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char 			*s_f;

	i = 0;
	if (!s)
		return (NULL);
	s_f = ft_strnew(ft_strlen(s));
	while ((int)i < ft_strlen(s) && s_f)
	{
		s_f[i] = f(i, s[i]);
		i++;
	}
	return (s_f);
}
