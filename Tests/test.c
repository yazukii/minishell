#include "unistd.h"
#include "stdio.h"
# include <readline/readline.h>
# include <readline/history.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

void incrementStringPointer(char **str) {
		(*str)++; // Increment the pointer, but don't modify the content
}

int main() {
	char *str;

	str = malloc(sizeof (char) * 2);
	if (str != NULL)
	{
		str[0] = '0';
		printf("Modified string: %s\n", str);
	}
	return 0;
}
