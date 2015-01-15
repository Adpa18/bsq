/*
** main.c for main in /home/wery_a/rendu/BSQ/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Jan 12 15:22:24 2015 adrien wery
** Last update Thu Jan 15 20:10:35 2015 adrien wery
*/

#include "bsq.h"

void	display_bsq(t_bsq bsq)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < bsq.len_y)
    {
      x = 0;
      while (x < bsq.len_x)
	{
	  if (y >= bsq.y && y < bsq.y + bsq.size &&
	      x >= bsq.x && x < bsq.x + bsq.size)
	    my_putchar('x');
	  else
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

int	make_bsq(t_bsq bsq)
{
  int	i;

  bsq.y1 = 0;
  while (bsq.y1 + bsq.size < bsq.len_y)
    {
      bsq.x1 = 0;
      while (bsq.x1 + bsq.size < bsq.len_x)
	i += make_bsq_2(&bsq);
      bsq.y1 += 1;
    }
  display_bsq(bsq);
  printf("%d\n", i);
  printf("[%d][%d] c = %d\n", bsq.x, bsq.y, bsq.size);
  free(bsq.s);
  return (0);
}

int	main(int argc, char **argv)
{
  t_bsq	bsq;
  char	*buff;
  int	fd;

  if (argc != 2)
    my_error("Need only one argument, the file !!!");
  buff = my_malloc(BUFF_SIZE);
  bsq.x = 0;
  bsq.y = 0;
  bsq.len_x = 0;
  bsq.len_y = 0;
  bsq.x2 = 0;
  bsq.y2 = 0;
  bsq.size = 0;
  if ((fd = open(argv[1], O_RDONLY)) < 0)
    my_error("Error on file oppening !!");
  bsq.s = my_malloc(get_len(fd, &bsq, buff) + 1);
  if ((fd = open(argv[1], O_RDONLY)) < 0)
    my_error("Error on file oppening !!");
  get_tab(fd, &bsq, buff);
  check_tab(bsq.s, bsq.len_x, bsq.len_y);
  make_bsq(bsq);
  return (0);
}
