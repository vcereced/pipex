/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:29:27 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/26 21:29:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	msg_error(char *err)
{
	perror(err);
	exit(errno);
}

void	exe_error(t_struc pipex)
{
	write(2, "pipex: ", 7);
	write(2, pipex.matriz_command[0], ft_strlen(pipex.matriz_command[0]));
	write(2, ": command not found\n", 20);
}
