/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:51:57 by ldick             #+#    #+#             */
/*   Updated: 2024/07/21 13:34:43 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	freepipe(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->fd_in > 0)
			close(pipex->fd_in);
		if (pipex->fd_out > 0)
			close(pipex->fd_out);
		freeall(pipex->path);
		freeall(pipex->command_1);
		freeall(pipex->command_2);
		free(pipex);
	}
}

void	close_two(t_pipex *pipex)
{
	close(pipex->fd_in);
	close(pipex->fd_out);
}

void	split_error_free(t_pipex *pipex)
{
	freeall(pipex->path);
	freeall(pipex->command_1);
	freeall(pipex->command_2);
	free(pipex);
}

void	close_wait_free(t_pipex *pipex, pid_t pid1, pid_t pid2)
{
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	freepipe(pipex);
}
