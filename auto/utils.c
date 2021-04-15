/***************************************************************************
 * FILENAME:    utils.c
 * DESCRIPTION: Utility Functions for Auto Leetcode.
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

/* Function was part of previous single header lib, hence why it is condesned */
char	*extract_file(char *file) {
	char *str; FILE *fh = fopen(file, "r");
	fseek(fh, 0L, SEEK_END);
	long l = ftell(fh);
	str = calloc(l + 2, 1);
	rewind(fh);
	fread(str, l, 1, fh);
	fclose(fh);
	return (str);
}

long	cache_find(int no)
{
	char	*cache_str;
	char	*needle;
	char	*found;
	long	res;
	FILE	*cache_file;

	res = 0;

	cache_str = extract_file("cache");
	asprintf(&(needle), "%04d ", no);
	found = strstr(cache_str, needle);
	free(needle);

	if (found != NULL)
	{
		// printf("This no was found in cache\n");
		res = atol(found + 4);

		memmove(found, strchr(found, '\n') + 1, strlen(strchr(found, '\n')) + 1);
		cache_file = fopen("cache", "w");
		fprintf(cache_file, "%s", cache_str);
		fclose(cache_file);
	}
	free(cache_str);
	return (res);
}

void	open_url_id(int problem_no)
{
	char	*url_com;
	char	*url;
	size_t	url_size;
	FILE	*tf;

	asprintf(&url_com, "leetcode show %d > temp 2>&1", problem_no);
	system(url_com);
	free(url_com);

	url = NULL;
	url_size = 0;
	tf = fopen("temp", "r");
	getline(&url, &url_size, tf);
	getline(&url, &url_size, tf);
	getline(&url, &url_size, tf);
	fclose(tf);

	asprintf(&url_com, OPEN_COM" %s", url);
	printf("THIS = %s", url_com);
	system(url_com);
	free(url_com);
	free(url);
}

void	open_problem_file(int id)
{
	char	*command;

	asprintf(&command, "touch leetcode/%04d"SUFFIX, id);
	system(command);
	free(command);

	asprintf(&command, IDE" leetcode/%04d"SUFFIX, id);
	system(command);
	free(command);
}

void	init_working(void)
{
	system("touch cache"); //Used for resume and pausing a given problem
	system("touch record"); //Database file
	system("touch submit"); //Result of submiting test

	system("touch test"); //Used to try the leetcode-cli test
	system(IDE" test");

	system("mkdir -p leetcode"); //Where the problems are
}