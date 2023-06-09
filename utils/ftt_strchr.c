#include "../mini.h"

char	*ftt_strrchr(char *s, int c)
{
	size_t	slen;
	char	*a;

	a = (char *)s;
	slen = ftt_strlen(s);
	while (slen > 0 && a[slen] != (char)c)
		slen--;
	if (a[slen] == (char)c)
		return (a + slen);
	return (0);
}