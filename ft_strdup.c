#include "libft.h"

char*		ft_strdup(const char* s)
{
	char*	str;
	int		i;

	i = -1;
	str = (char*)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	while (s[++i] != '\0')
		str[i] = s[i];
	return str;
}