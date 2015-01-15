/*
** str.c for str in /home/wery_a/rendu/BSQ/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Jan 12 15:50:30 2015 adrien wery
** Last update Thu Jan 15 20:02:50 2015 adrien wery
*/

#include "bsq.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_str(char *s, int mode)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (mode == 1)
	my_putchar(s[i]);
      i += 1;
    }
  return (i);
}

char    *my_memset(char *s, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    s[i++] = c;
  return (s);
}

void	my_error(char *s)
{
  my_str(s, 1);
  write(1, "\n", 1);
  exit(EXIT_FAILURE);
}

char    *my_malloc(int len)
{
  char  *str;
  int   i;

  i = 0;
  if ((str = malloc(len)) == NULL)
    my_error("Malloc Failed");
  while (i < len)
    str[i++] = '\0';
  return (str);
}
