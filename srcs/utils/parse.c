/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:33:23 by ldick             #+#    #+#             */
/*   Updated: 2024/07/21 13:34:54 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	int		i;
	int		j;
	char	*path;

	path = "PATH";
	i = 0;
	while (env[i])
	{
		j = 0;
		while (path[j] && path[j] == env[i][j])
		{
			if (!path[j + 1])
				return (&env[i][j + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*cmdd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmdd = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(cmdd, 0) == 0)
			return (cmdd);
		free(cmdd);
		path++;
	}
	return (NULL);
}
