/***************************************************************************
 * FILENAME:    main.c
 * DESCRIPTION: Main control program for auto leetcode.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.30
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Mar2021
***************************************************************************/

#include "main.h"

void	choices(char *input)
{
	t_oper	choices[] =
	{
		{"begin",	begin},
		{"test",	test},
		{"submit",	submit},
		{"close",	escape},
		{"pause",	freeze},
		{"resume",	resume},
	};

	size_t	i = 0;
	while (i < sizeof(choices) / sizeof(t_oper))
	{
		if (strncmp(choices[i].choice, input, strlen(choices[i].choice)) == 0)
		{
			// printf("doing %s\n", choices[i].choice);
			choices[i].fn(input + strlen(choices[i].choice));
			break ;
		}
		i++;
	}

	if (i >= sizeof(choices) / sizeof(t_oper))
		printf("Error on choice\n");
}

t_app	app;

int	main(int ac, char **args)
{
	char	read[256];

	// chdir(dirname(args[0]));
	chdir(args[0]);

	system("touch cache"); //Used for resume and pausing a given problem
	system("touch record"); //Database file
	system("touch submit"); //Result of submiting test

	system("touch test"); //Used to try the leetcode-cli test
	system("code test");

	system("mkdir -p leetcode"); //Where the problems are

	app.current = -1;

	if (ac >= 2)
	{
		begin(args[1]);
	}

	while (app.exit == false)
	{
		fgets(read, sizeof(read), stdin);
		choices(read);
	}
	remove("temp");
	return (0);
}