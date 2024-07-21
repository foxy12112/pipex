/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:53:39 by ldick             #+#    #+#             */
/*   Updated: 2024/07/21 13:35:08 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **argv, char **env)
{
	t_pipex	*pipex;
	pid_t	pid1;
	pid_t	pid2;

	pipex = init(argv, env);
	if (!pipex)
		return (1);
	if (pipe(pipex->pipes) < 0)
		return (perror("pipe error"), freepipe(pipex), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork error"), freepipe(pipex), 1);
	if (pid1 == 0)
		ft_child_one(pipex);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork error"), freepipe(pipex), 1);
	if (pid2 == 0)
		ft_child_two(pipex);
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	freepipe(pipex);
	return (1);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc != 5)
	{
		perror("wrong number of arguments");
		return (127);
	}
	else
		pipex(argv, env);
	return (0);
}
