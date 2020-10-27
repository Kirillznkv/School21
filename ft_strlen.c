#include "unistd.h"

size_t			ft_strlen(const char* str)
{
	size_t		res;

	res = 0;
	while (str[res] != '\0')
		res++;
	return res;
}