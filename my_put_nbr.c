/*
** my_put_nbr.c for my_put_nbr in /home/wery_a/rendu/BSQ/Test/v3
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan 16 15:51:11 2015 adrien wery
** Last update Fri Jan 16 18:04:14 2015 adrien wery
*/

#include "bsq.h"

int	my_open(char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    my_error("Error on file oppening !!");
  return (fd);
}

int	cal(int nb, int n)
{
  if (n > 9)
    {
      nb = n % 10;
      cal(nb, n / 10);
    }
  else
    nb = n;
  my_putchar(nb + 48);
  return (nb);
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
      cal(nb, nb);
    }
  else
    cal(nb, nb);
}
