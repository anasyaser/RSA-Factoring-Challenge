#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define UNUSED __attribute__((unused))

FILE *file_stream(char *file_name)
{
	FILE *file_stream;

	file_stream = fopen(file_name, "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: can't open file%s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (file_stream);
}

char *get_line(FILE *file_stream)
{
	size_t buff_size = 0;
	char *lineptr = NULL;
	ssize_t bytesread = 0;

	bytesread = getline(&lineptr, &buff_size, file_stream);
	if (bytesread == -1)
	{
		free(lineptr);
		fclose(file_stream);
		exit(EXIT_SUCCESS);
	}
	return (lineptr);
}

void print_factors(char *num_str)
{
	unsigned long long int num = 0;
	unsigned int sum = 0;

	
}

int main(UNUSED int argc, char **argv)
{
	FILE *file_s;
	char *cur_line = NULL;


	file_s = file_stream(*(argv + 1));
	while (1)
	{
		cur_line = get_line(file_s);
		if (*cur_line == '\n')
		{
			free(cur_line);
			continue;
		}
		printf("Current line: %s\n", cur_line);
		free(cur_line);
	}
	fclose(file_s);
	return (0);
}
