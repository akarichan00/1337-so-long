/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:55:36 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/08 10:44:23 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	fft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*fft_strjoin(char *s1, char *s2);
char	*ft_free(char **str);
int		read_file(int fd, char *buffer);
int		handle_errors_and_join(int *bytes_read, char **buffer, char **line,
			char **rest);
#endif