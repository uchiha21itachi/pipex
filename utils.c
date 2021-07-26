#include "pipex.h"

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strndup(char *s1, size_t length)
{
	char		*p;
	size_t		i;

	i = 0;
	p = (char *)malloc((length + 1) * sizeof(char));
	p[length] = '\0';
	if (p == 0)
		return (NULL);
	else
	{
		while (i < length)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

char	*ft_strdup(char *s1)
{
	char		*p;
	size_t		length;
	size_t		i;

	i = 0;
	length = ft_strlen(s1);
	p = (char *)malloc((length + 1) * sizeof(char));
	p[length] = '\0';
	if (p == 0)
		return (NULL);
	else
	{
		while (i < length)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	x;

	x = 0;
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
		{
			x = *(unsigned char *)s1 - *(unsigned char *)s2;
			break ;
		}
	}
	return (x);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ans;
	int		len;

	len = ft_strlen(s1) + ft_strlen((char *)s2);
	ans = (char *)malloc(len + 1);
	if (!ans)
		return (NULL);
	while (*s1)
		*ans++ = *s1++;
	while (*s2)
		*ans++ = *s2++;
	*ans = '\0';
	if (*s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (ans - len);
}
