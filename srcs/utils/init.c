/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:06:53 by ldick             #+#    #+#             */
/*   Updated: 2024/06/28 11:18:53 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

t_pipex	*init(char *argv[], char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (perror("malloc error"), NULL);
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		return (perror("read error"), free(pipex), NULL);
	pipex->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->fd_out < 0)
		return (perror("open error"), close(pipex->fd_in), free(pipex), NULL);
	pipex->path = ft_split(find_path(env), ':');
	if (!pipex->path)
		return (perror("split error"), close_two(pipex), free(pipex), NULL);
	pipex->command_1 = ft_split(argv[2], ' ');
	pipex->command_2 = ft_split(argv[3], ' ');
	if (!pipex->command_1 || !pipex->command_2)
		return (perror("split error"), close_two(pipex),
			split_error_free(pipex), NULL);
	pipex->env = env;
	return (pipex);
}
