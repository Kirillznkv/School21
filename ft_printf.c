#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char*			itochar(int *a)
{
	int		length = 0;
	int		b = *a;
	char		*str;
	while (b > 0)
	{
		length++;
		b /= 10;
	}
	str = (char*)malloc((length + 1) * sizeof(char));
	str[length] = '\0';
	for (int i = length - 1; i >= 0; i--)
	{
		str[i] = (*a % 10) + '0';
		*a /= 10;
	}
	*a = length;
	return (str);
}

void			ft_print_value(const char *p, va_list *ap)
{
	if (*p == 'd')
	{
		int val = va_arg(*ap, int);
		char *c = itochar(&val);
		write(1, c, val);
		free(c);
	}
}

void			ft_printf(const char *str, ...)
{
	va_list		ap;
	int		i = 0;
	va_start(ap, str);
	for (const char *p = str; *p != '\0'; p += sizeof(char))
	{
		if (*p != '%')
		{
			write(1, p, 1);
			continue;
		}
		ft_print_value(++p, &ap);
	}
}

int			main(int argc, char **argv)
{
	ft_printf("shvbn%d%dkjdv%dkshj\n", INT32_MAX, 1111111, 2222222);
	return (0);
}
