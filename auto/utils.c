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

long	cache_find(int no)
{
	char	*cache_str;
	char	*no_s;
	char	*found;
	long	res;
	FILE	*cache_file;

	res = 0;

	cache_str = extract_file("cache");
	asprintf(&(no_s), "%04d ", no);
	found = strstr(cache_str, no_s);
	free(no_s);

	if (found != NULL)
	{
		res = atol(found + 4);
		// printf("This no is found\n");

		memmove(found, strchr(found, '\n') + 1, strlen(strchr(found, '\n')) + 1);
		// printf("ret %ld\n", res);
		cache_file = fopen("cache", "w");
		// printf("string %s\n", cache_str);
		fprintf(cache_file, "%s", cache_str);
		fclose(cache_file);
	}
	return (res);
}