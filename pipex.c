/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:59:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/27 15:38:57 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_proces(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		ft_error("could not open read file");
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(file, STDIN_FILENO);
	close(file);
	execute(envp, argv[2]);
}

static void do_execute(char *argv[], char **envp, pid_t	pid1)
{
	pid_t	pid2;
	pid2 = fork();
	if (pid2 == -1)
		ft_error("the fork could not be created");
	if (pid2 == 0)
		execute(envp, argv[3]);
	else
	{
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}

}

static void	parent_proces(int *fd, char **argv, char **envp, pid_t	pid1)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error("write file not opened");
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(file, STDOUT_FILENO);
	close(file);
	do_execute(argv,envp, pid1);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc != 5)
		ft_error("incorrect arguments");
	if (!envp)
		ft_error("there is not envp\n");
	if (pipe(fd) == -1)
		ft_error("The pipe could not be created");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("the fork could not be created");
	if (pid1 == 0)
		child_proces(fd, argv, envp);
	else
	{
		parent_proces(fd, argv, envp, pid1);
	}
	return (0);
}
