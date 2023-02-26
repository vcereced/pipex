/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:08:10 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/26 21:23:13 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	make_free(char **matriz)
{
	size_t	i;

	i = 0;
	while (matriz[i] != NULL)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

static char	*copy(char *str_program, char *str_path, char *program)
{
	size_t	j;

	j = 0;
	while (str_path[j++] != '\0')
	str_program = (char *)calloc(j + ft_strlen(program) + 2, sizeof(char));
	if (!(str_program))
	{
		perror("Error location memory line 43:");
		exit(-1);
	}
	j = ft_strlcpy(str_program, str_path, j + 1);
	str_program[j++] = '/';
	j = j + ft_strlcpy(&str_program[j], program, ft_strlen(program) + 1);
	str_program[j] = '\0';
	return (str_program);
}

static char	*matriz_cat_program(char**matriz_path, char*program)
{
	size_t	i;
	char	*str_program;

	i = 0;
	while (matriz_path[i] != NULL)
	{
		str_program = copy(str_program, matriz_path[i], program);
		if (!access(str_program, 0))
		{
			make_free(matriz_path);
			return (str_program);
		}
		free(str_program);
		i++;
	}
	make_free(matriz_path);
	return (NULL);
}

static char	*gen_str_path(char**env, char *path, t_struc pipex)
{
	size_t	i;
	char	**matriz_path;
	char	*program;

	program = pipex.matriz_command[0];
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], path, ft_strlen(path)) == 0)
			break ;
		i++;
	}
	if (!env[i])
	{
		exe_error(pipex);
		exit(errno);
	}
	matriz_path = ft_split(&env[i][ft_strlen(program) + 1], ':');
	return (matriz_cat_program(matriz_path, program));
}

t_struc	gen_command_and_path(t_struc pipex, char **argv, char **envp, int n)
{
	if (argv[n][0] == '.')
	{
		pipex.matriz_command = ft_split(argv[n], 0);
		pipex.str_path = ft_strdup(argv[n]);
		swap(pipex);
	}
	else
	{
		pipex.matriz_command = pipexsplit(argv[n]);
		pipex.str_path = gen_str_path(envp, "PATH", pipex);
	}
	return (pipex);
}
