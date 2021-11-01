/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:35 by mdaan         #+#    #+#                 */
/*   Updated: 2021/11/01 15:51:41 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strcmp() function compares null-terminated strings s1 and s2 
**	to the NULL terminator
**
**	Returns:
**	0 if s1 == s2
**	>0 if s1 > s2
**	<0 if s1 < s2
**	(s1[char] - s2[char] on the first char that is different)
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(s1);
	i = 0;
	while ((s1[i] || s2[i]) && i < str_len)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
