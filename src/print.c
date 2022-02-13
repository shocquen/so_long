#include "so_long.h"

void	*ft_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (NULL);
}