#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define UNUSED __attribute__((unused))

int main(UNUSED int argc, char **argv)
{
	FILE *file_stream;

	char *lineptr = NULL;
	size_t buff_size = 0;
	ssize_t bytesread = 0;

	size_t number;

	file_stream = fopen(*(argv + 1), "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: can't open file%s\n", *(argv + 1));
		exit(EXIT_FAILURE);
	}

	while((bytesread = getline(&lineptr, &buff_size, file_stream)) != -1)
	{
		*(lineptr + bytesread - 1) = '\0';
	/* if (bytesread == -1) */
	/* { */
	/* 	free(lineptr); */
	/* 	fclose(file_stream); */
	/* 	exit(EXIT_SUCCESS); */
	/* } */

		number = atoi(lineptr);
		if ((number & 1) == 0)
			printf("%s=%zu*%d\n", lineptr, number >> 1, 2);
		else
			printf("%s\n", lineptr);
	}
}
