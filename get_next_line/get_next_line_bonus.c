/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:18:01 by mandre            #+#    #+#             */
/*   Updated: 2025/09/08 11:48:11 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	strlen_special(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	set_last_line_and_cut_static(char *left_c)
{
	size_t		i;

	i = 0;
	while (left_c[i] != '\n' && left_c[i] != '\0')
	{
		i++;
	}
	if (left_c[i] == '\n')
		i++;
	ft_memmove(left_c, left_c + i, ft_strlen(left_c + i));
}

char	*get_next_line(int fd)
{
	static char	left_c[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	line = NULL;
	if (*left_c[fd])
		line = ft_strdup(left_c[fd]);
	while (!ft_find_occurence(left_c[fd], '\n'))
	{
		bytes_read = read(fd, left_c[fd], BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), left_c[fd][0] = '\0', NULL);
		left_c[fd][bytes_read] = '\0';
		if (bytes_read == 0)
			return (left_c[fd][0] = '\0', line);
		tmp = line;
		line = ft_strjoin(tmp, left_c[fd]);
		if (!tmp || *tmp)
			free(tmp);
	}
	set_last_line_and_cut_static(left_c[fd]);
	return (line);
}

// int main(void)
// {
//     int fds[2];
//     int array_len;
// 	int index;
// 	// static int loops = 0;
// 	char *line = NULL;

//     array_len = sizeof(fds) / sizeof(fds[0]);
//     index = 0;
// 	fds[0] = open("nextline.txt", O_RDONLY);
// 	fds[1] = open("multiple_nl.txt", O_RDONLY);
// 	if (fds[0] == -1 || fds[1] == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
//     while (index < array_len)
//     {
//         while ((line = get_next_line(fds[index])))
//         {
//             printf("%s", line);
//             free(line);
//         }
//         printf("\n");    
//         index++;
//     }
//     printf("\n");    
// 	close(fds[0]);
// 	close(fds[1]);
// 	return (0);
// }