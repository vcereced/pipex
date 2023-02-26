/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:04:53 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/26 21:23:23 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	swap(t_struc pipex)
{
	pipex.matriz_command[0] = ft_strtrim(pipex.matriz_command[0], "./");
}

void	close_all_pipes(t_struc pipex)
{
	int	n;

	n = 0;
	while (n <= pipex.n)
	{
		close(pipex.matriz_pipes[n][STDIN_FILENO]);
		close(pipex.matriz_pipes[n][STDOUT_FILENO]);
		n++;
	}
}

t_struc	fork_proccess(t_struc pipex)
{
	pipex.pid = fork();
	if (pipex.pid == -1)
		msg_error("error forking");
	return (pipex);
}

t_struc	gen_new_pipe(t_struc pipex, int argc)
{
	if (pipex.n == 0)
	{
		pipex.matriz_pipes = (int **)malloc(sizeof(int) * argc - 4);
		if (!pipex.matriz_pipes)
			msg_error("error matriz pipes memory alocation");
	}
	pipex.matriz_pipes[pipex.n] = (int *)malloc(sizeof(int) * 2);
	if (pipe(pipex.matriz_pipes[pipex.n]) == -1)
		msg_error("Pipe");
	return (pipex);
}
