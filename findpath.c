/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:42:38 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/25 22:04:07 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// PATH ES IGUAL A CAMINO
int	ft_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(2);
}

static char	*findpath(char **envp, char *cmd)
{
	int		i;
	char	**lst_path;
	char	*path;
	char	*temp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	lst_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (lst_path[i])
	{
		path = ft_strjoin((temp = ft_strjoin(lst_path[i], "/")), cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	i = 0;
	while (lst_path[i])
		free(lst_path[++i]);
	free(lst_path);
	return (NULL);
}

void	execute(char **envp, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = findpath(envp, cmd[0]);
	if (!path)
		return ;
	if (execve(path, cmd, envp) == -1)
		ft_printf("no se pudo ejecutar el comando\n");
}
