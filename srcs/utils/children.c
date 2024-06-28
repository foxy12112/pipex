/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:57:19 by ldick             #+#    #+#             */
/*   Updated: 2024/06/28 12:35:56 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_child_one(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipes[1], 1);
	close(pipex->pipes[0]);
	dup2(pipex->fd_in, 0);
	cmd = find_cmd(pipex->path, pipex->command_1[0]);
	if (!cmd)
	{
		freeall(pipex->command_1);
		perror("Command Error");
		exit(127);
	}
	execve(cmd, pipex->command_1, pipex->env);
	perror("Execve Error");
	free(cmd);
	freeall(pipex->command_1);
	exit(126);
}

void	ft_child_two(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipes[0], 0);
	close(pipex->pipes[1]);
	dup2(pipex->fd_out, 1);
	cmd = find_cmd(pipex->path, pipex->command_2[0]);
	if (!cmd)
	{
		freeall(pipex->command_2);
		perror("Command Error");
		exit(127);
	}
	execve(cmd, pipex->command_2, pipex->env);
	perror("Execve Error");
	free(cmd);
	freeall(pipex->command_2);
	exit(127);
}

void	print_double_pointers(char **double_ptr)
{
	int	i;

	i = 0;
	if (double_ptr == NULL)
	{
		printf("Null pointer.\n");
		return ;
	}
	while (double_ptr[i] != NULL)
	{
		fprintf(stderr, "Element %d: %s\n", i, double_ptr[i]);
		i++;
	}
}
