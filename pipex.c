/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:47:27 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/26 21:27:16 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	receive_from_pipe(t_struc pipex, char **argv, int argc, char *env[])
{
	pipex.fd_outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fd_outfile == -1)
		msg_error("Outfile");
	pipex = gen_command_and_path(pipex, argv, env, argc - 2);
	dup2(pipex.matriz_pipes[pipex.n][STDIN_FILENO], STDIN_FILENO);
	dup2(pipex.fd_outfile, STDOUT_FILENO);
	close(pipex.fd_outfile);
	close_all_pipes(pipex);
	execve(pipex.str_path, pipex.matriz_command, env);
	exe_error(pipex);
	exit(127);
}

static void	sent_to_pipe(t_struc pipex, char *argv[], char *envp[])
{
	pipex = gen_command_and_path(pipex, argv, envp, 2);
	pipex.fd_infile = open(argv[1], O_RDONLY);
	if (pipex.fd_infile == -1)
	{
		perror("pipex: input");
		exit(EXIT_SUCCESS);
	}
	dup2(pipex.fd_infile, STDIN_FILENO);
	dup2(pipex.matriz_pipes[0][STDOUT_FILENO], STDOUT_FILENO);
	close(pipex.fd_infile);
	close(pipex.matriz_pipes[0][STDIN_FILENO]);
	close(pipex.matriz_pipes[0][STDOUT_FILENO]);
	execve(pipex.str_path, pipex.matriz_command, envp);
	exe_error(pipex);
	exit(EXIT_SUCCESS);
}

static void	receive_from_send_to_pipe(t_struc pipex, char *argv[], char *envp[])
{
	pipex = gen_command_and_path(pipex, argv, envp, pipex.arg_index_bonus);
	dup2(pipex.matriz_pipes[pipex.n - 1][STDIN_FILENO], STDIN_FILENO);
	dup2(pipex.matriz_pipes[pipex.n][STDOUT_FILENO], STDOUT_FILENO);
	close_all_pipes(pipex);
	execve(pipex.str_path, pipex.matriz_command, envp);
	exe_error(pipex);
	exit(127);
}

static t_struc	pipe_and_fork(t_struc pipex, int argc, char **argv, char **env)
{
	pipex.n = 0;
	pipex.arg_index_bonus = 3;
	pipex.arg_bonus = argc - 5;
	pipex = gen_new_pipe(pipex, argc);
	pipex = fork_proccess(pipex);
	if (pipex.pid == 0)
		sent_to_pipe(pipex, argv, env);
	while (pipex.arg_bonus > 0 && pipex.pid != 0)
	{
		pipex.n++;
		pipex = gen_new_pipe(pipex, argc);
		pipex = fork_proccess(pipex);
		if (pipex.pid == 0)
			receive_from_send_to_pipe(pipex, argv, env);
		pipex.arg_index_bonus++;
		pipex.arg_bonus--;
	}
	pipex = fork_proccess(pipex);
	if (pipex.pid == 0)
		receive_from_pipe(pipex, argv, argc, env);
	close_all_pipes(pipex);
	return (pipex);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_struc	pipex;

	pipex.wstatus2 = 0;
	if (argc < 5)
		msg("nº argument wrong");
	pipex = pipe_and_fork(pipex, argc, argv, envp);
	waitpid(pipex.pid, &pipex.wstatus2, WUNTRACED);
	if (WIFEXITED(pipex.wstatus2))
	{
		pipex.statuscode2 = WEXITSTATUS(pipex.wstatus2);
		if (pipex.statuscode2 != 0)
			exit(pipex.statuscode2);
	}
	exit(EXIT_SUCCESS);
}
