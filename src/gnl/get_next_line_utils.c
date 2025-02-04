/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 02:19:45 by d             #+#    #+#                 */
/*   Updated: 2021/04/14 20:07:01 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_err(int fd, struct s_st *s)
{
	s->read[fd] = -1;
	if (s->re[fd])
	{
		free (s->re[fd]);
		s->re[fd] = (void *) 0;
	}
	if (s->tmp != NULL)
	{
		free (s->tmp);
		s->tmp = (void *) 0;
	}
	return (-1);
}

size_t	ft_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

size_t	ft_size(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_jsf(char *s1, char *s2, int f)
{
	char	*t;

	if (!s1 || !s2)
		return ((void *) 0);
	t = malloc(sizeof(char) * (ft_size(s1) + ft_size(s2) + 1));
	if (!t)
	{
		if (f == 1 || f == 3)
			free(s1);
		if (f == 2 || f == 3)
			free(s2);
		return ((void *) 0);
	}
	ft_strlcpy(t, s1, ft_size(s1) + 1);
	ft_strlcpy(t + ft_size(s1), s2, ft_size(s2) + 1);
	if (f == 1 || f == 3)
		free(s1);
	if (f == 2 || f == 3)
		free(s2);
	return (t);
}
