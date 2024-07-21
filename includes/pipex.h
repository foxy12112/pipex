/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:36:55 by ldick             #+#    #+#             */
/*   Updated: 2024/07/21 13:46:45 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipes[2];
	char	**command_1;
	char	**command_2;
	char	**path;
	char	**env;
}			t_pipex;

char		*find_path(char **env);
t_pipex		*init(char *argv[], char **env);
void		close_two(t_pipex *pipex);
void		close_wait_free(t_pipex *pipex, pid_t pid1, pid_t pid2);
void		split_error_free(t_pipex *pipex);
void		ft_child_one(t_pipex *pipex);
void		freeall(char **list);
void		freepipe(t_pipex *pipex);
char		*find_cmd(char **path, char *cmd);
void		ft_child_one(t_pipex *pipex);
void		ft_child_two(t_pipex *pipex);

#endif