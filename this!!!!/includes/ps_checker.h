/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:16:14 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 18:59:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H
# include "operators.h"
# include "get_next_line.h"
# define OK 1
# define KO 0
# define ERROR -1

void	ok_exit(void);
void	ko_exit(void);
void	error_exit(void);
void	memory_error_exit(void);
t_stack	interpret_args(int c, char **v);

#endif