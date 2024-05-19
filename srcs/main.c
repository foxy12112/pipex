/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:53:39 by ldick             #+#    #+#             */
/*   Updated: 2024/05/19 18:01:37 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[])
{
	/*
		first check that there are four argumnts
		then check that the first and last arguments are filenames and the middle two are shell commands
		example:
		./pipex file1 "command1 " "command2" outputfile
	*/
	if (argc != 5)
	{
		ft_printf("error\n");
		return (1);
	}
}
