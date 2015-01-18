/*
** main.c for main in /home/wery_a/rendu/BSQ/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Jan 12 15:22:24 2015 adrien wery
** Last update Sun Jan 18 23:21:32 2015 adrien wery
*/

#include "bsq.h"

void    display_bsq(t_bsq bsq)
{
  int   x;
  int   y;

  y = 0;
  while (y < bsq.len_y)
    {
      x = 0;
      while (x < bsq.len_x)
        {
          if (y >= bsq.y && y < bsq.y + bsq.size &&
              x >= bsq.x && x < bsq.x + bsq.size)
            {
              my_str("\e[01;31m", 1);
              bsq.s[y * bsq.len_y + x] = 'x';
            }
          else if (bsq.s[y * bsq.len_y + x] == 'o')
            my_str("\e[01;32m", 1);
          else
            my_str("\e[01;33m", 1);
          my_putchar(bsq.s[y * bsq.len_y + x]);
          x += 1;
        }
      y += 1;
      my_putchar('\n');
    }
}

int	check_o(t_bsq bsq)
{
  int	x;
  int	y;

  x = bsq.x1;
  y = bsq.y1;
  if (bsq.s[y * bsq.len_y + x] == 'o')
    return (x);
  while (y <= bsq.y2)
    {
      if (bsq.s[y * bsq.len_y + bsq.x2] == 'o')
	return (bsq.x2);
      y += 1;
    }
  while (x < bsq.x2)
    {
      if (bsq.s[bsq.y2 * bsq.len_y + x] == 'o')
	return (x);
      x += 1;
    }
  return (-1);
}

int	make_bsq_2(t_bsq *bsq)
{
  int	xo;
  int	i;

  xo = -1;
  i = 0;
  bsq->x2 = bsq->x1 + 1;
  bsq->y2 = bsq->y1 + 1;
  while (bsq->x2 < bsq->len_x && bsq->y2 < bsq->len_y &&
	 (xo = check_o(*bsq)) == -1)
    {
      bsq->x2 += 1;
      bsq->y2 += 1;
      i += 1;
    }
  if (bsq->x2 - bsq->x1 > bsq->size)
    {
      bsq->size = bsq->x2 - bsq->x1;
      bsq->x = bsq->x1;
      bsq->y = bsq->y1;
    }
  if (xo <= 0)
    bsq->x1 += 1;
  else
    bsq->x1 = xo + 1;
  return (i);
}

int     make_bsq(t_bsq bsq)
{
  int   i;

  bsq.y1 = 0;
  while (bsq.y1 + bsq.size < bsq.len_y)
    {
      bsq.x1 = 0;
      while (bsq.x1 + bsq.size < bsq.len_x)
        i += make_bsq_2(&bsq);
      bsq.y1 += 1;
    }
  display_bsq(bsq);
  my_str("\e[01;39m", 1);
  my_str("\nSTEP = ", 1);
  my_put_nbr(i);
  my_str("\nPos = [", 1);
  my_put_nbr(bsq.y);
  my_str("][", 1);
  my_put_nbr(bsq.x);
  my_str("] ", 1);
  my_str("\nSize = ", 1);
  my_put_nbr(bsq.size);
  my_putchar('\n');
  free(bsq.s);
  return (0);
}

int	main(int argc, char **argv)
{
  t_bsq	bsq;
  char	*buff;
  int	fd;
  int	i;

  if (argc != 2)
    my_error("Need only one argument : the file !!!");
  buff = my_malloc(BUFF_SIZE);
  bsq.x = 0;
  bsq.y = 0;
  bsq.len_y = 0;
  bsq.x2 = 0;
  bsq.y2 = 0;
  bsq.size = 0;
  fd = my_open(argv[1]);
  i = get_len(fd, &bsq, buff);
  if (bsq.len_y < 3 || i < 10)
    my_error("File isn't accept !!!");
  fd = my_open(argv[1]);
  bsq.s = my_malloc(i + 1);
  get_tab(fd, &bsq, buff);
  check_tab(bsq.s, bsq.len_x, bsq.len_y);
  make_bsq(bsq);
  return (0);
}
