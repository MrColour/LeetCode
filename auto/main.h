/***************************************************************************
 * FILENAME:    main.h
 * DESCRIPTION: General Header file for auto leetcode
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.30
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Mar2021
***************************************************************************/

#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct	s_app
{
	bool		exit;
	int			current;

	time_t		start_curr;
}				t_app;

typedef struct	s_oper
{
	char		*choice;
	void		(*fn)(void *);
}				t_oper;

extern t_app	app;

void	begin(void *str);
void	test(__unused void *str);
void	submit(__unused void *str);
void	escape(__unused void *str);
void	freeze(void *str);
void	resume(void *str);

void	open_problem_file(int id);
void	open_url_id(int problem_no);
long	cache_find(int no);

char	*extract_file(char *file);

#endif