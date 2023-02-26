/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:53:21 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/26 21:26:41 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct lis
{
	pid_t	pid;
	char	**matriz_command;
	char	*str_path;
	int		**matriz_pipes;
	int		fd_infile;
	int		fd_outfile;
	int		n;
	int		arg_index_bonus;
	int		wstatus2;
	int		statuscode2;
	int		arg_bonus;

}	t_struc;

void	checkarg(char **argv);
char	**pipexsplit(char *str);
void	swap(t_struc pipex);
void	msg_error(char *err);
int		msg(char *err);
t_struc	gen_command_and_path(t_struc pipex, char **argv, char **envp, int n);
void	exe_error(t_struc pipex);
void	close_all_pipes(t_struc pipex);
t_struc	gen_new_pipe(t_struc pipex, int argc);
t_struc	fork_proccess(t_struc pipex);

#endif