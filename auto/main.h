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

#define _GNU_SOURCE

/* Note that unistd does not exist in ALL PLATFORMS some macro should be used */
#include <unistd.h> /* Needed only for chdir */
#include <stdio.h> /* printf family and FILE functions */
#include <stdlib.h> /* malloc family, exit, system */
// #include <libgen.h> /* dirname ¡¡Might not be needed!! */
#include <stdbool.h> /* bool */
#include <string.h> /* memmove, strstr, strchr, strlen, strncmp */
#include <time.h> /* time_t, time */

#define SUFFIX ".py3"
#define IDE "code"

#if defined(WIN32)
	#define OPEN_COM "start"
#elif __APPLE__
	#define OPEN_COM "open"
#elif __linux__
	#define OPEN_COM "xdg-open"
#endif

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
void	test(__attribute__((unused)) void *str);
void	submit(__attribute__((unused)) void *str);
void	escape(__attribute__((unused)) void *str);
void	freeze(void *str);
void	resume(void *str);

void	open_problem_file(int id);
void	open_url_id(int problem_no);
long	cache_find(int no);
void	init_working(void);

char	*extract_file(char *file);

#endif