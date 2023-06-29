/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:55:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 16:55:09 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substrs(char *s, unsigned int start, size_t len);
size_t	ft_strlens(const char *s);
char	*ft_strjoins(char *s1, char *s2);
char	*ft_strdups(char *s1);
char	*ft_frees(char **str);

#endif
