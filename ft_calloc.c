#include "libft.h"

void*		ft_calloc(size_t n, size_t size)
{
	unsigned char*	s;

	s = (unsigned char*)malloc(n * size);
	ft_bzero(s, n * size);
	return (void*)s;
}

int main()
{
	unsigned char*	s;
	s = (unsigned char*)ft_calloc(3, sizeof(unsigned char));
	free(s);
	return 0;
}