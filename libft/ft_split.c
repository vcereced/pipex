/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:41:49 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/15 00:11:02 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && i == 0)
			count++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**free_fail(char **array, unsigned int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

static char	**array_gen(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				j++;
				s++;
			}
			array[i++] = ft_substr(s - j, 0, j);
			if (!array[i - 1])
				return (free_fail(array, i));
		}
		else
			s++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)ft_calloc((count_words(s, c) + 1), sizeof (char *));
	if (!(array))
		return (NULL);
	array = array_gen(s, c, array);
	return (array);
}
/*int main (void)
{
	
	char ** str; 
	size_t i;
	size_t j;

	
	str = ft_split("xhelloxxxxxhello", 'x');
	i = 0;
	while(str[i] != NULL)
	{
		j = 0;
		while(str[i][j] != '\0')
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n",1);
		i++; 		
	}

	return (0);
}
*/