/***************************************************************************
 * FILENAME:    do_oper.c
 * DESCRIPTION: File that codes what each operation does
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Mar2021
***************************************************************************/

#include "main.h"

void	begin(void *v_str)
{
	resume(v_str);
}

void	test(__attribute__((unused)) void *str)
{
	char	*command;
	char	*test_case;
	size_t	size;
	FILE	*test_file;

	return ; //The test option in the leetcode-cli stalls forever. Don't know why.

	if (app.current == -1)
		return ;

	test_case = NULL;
	test_file = fopen("test", "r");
	getline(&test_case, &size, test_file);
	asprintf(&command, "leetcode test leetcode/%04d"SUFFIX" -t %s\\n", app.current, test_case);
	// printf("%s", command);

	fclose(test_file);
	system(command);
	free(command);
}

char	*extract_file(char *file) {
	char *str; FILE *fh = fopen(file, "r"); fseek(fh, 0L, SEEK_END); long l = ftell(fh); str = calloc(l + 2, 1), rewind(fh); fread(str, l, 1, fh); return (str);
}

void	submit(__attribute__((unused)) void *str)
{
	char	*command;
	char	*answer;
	char	*record_str;
	time_t	end;

	if (app.current == -1)
		return ;

	asprintf(&command, "leetcode submit leetcode/%04d"SUFFIX" > submit", app.current);
	// printf("%s", command);
	system(command);
	free(command);

	answer = extract_file("submit");
	if (strstr(answer, "Accepted"))
	{
		printf("Well done this is a correct answer\n");

		time(&(end));
		printf("Took: %ld\n", (end - app.start_curr));
		asprintf(&record_str, "echo \"%04d %.10ld\" >> record", app.current, (end - app.start_curr));
		system(record_str);
		free(record_str);

		app.current = -1;
		time(&(app.start_curr));
	}
	else
	{
		printf("try again\n");
	}
}

void	escape(__attribute__((unused)) void *str)
{
	freeze(NULL);
	exit(EXIT_SUCCESS);
}

void	freeze(__attribute__((unused)) void *str)
{
	char	*pause_str;
	time_t	pause_t;
	long	prev_t;

	if (app.current == -1)
		return ;

	prev_t = cache_find(app.current);
	time(&(pause_t));
	asprintf(&(pause_str), "echo \"%04d %.10ld\" >> cache", app.current, (app.start_curr - pause_t + prev_t));
	system(pause_str);

	app.current = -1;
	time(&(app.start_curr));
	free(pause_str);
}

void	resume(void *str)
{
	long	prev;
	int		id = atoi(str);

	if (app.current != -1)
		freeze(NULL);

	open_url_id(id);
	open_problem_file(id);

	prev = cache_find(id);
	app.current = id;
	time(&(app.start_curr));

	app.start_curr += prev;
	return ;
}
