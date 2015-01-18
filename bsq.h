/*
** bsq.h for bsq in /home/wery_a/rendu/BSQ/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Jan 12 15:47:15 2015 adrien wery
** Last update Fri Jan 16 18:04:33 2015 adrien wery
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# define BUFF_SIZE 1024

typedef struct	s_bsq
{
  char		*s;
  int		x;
  int		y;
  int		len_x;
  int		len_y;
  int		x1;
  int		y1;
  int		x2;
  int		y2;
  int		size;
}		t_bsq;

void    my_putchar(char c);
int     my_str(char *s, int mode);
char    *my_memset(char *s, char c, int size);
void    my_error(char *s);
char	*my_malloc(int len);
void	my_put_nbr(int nb);
int	my_open(char *file);
int     main(int argc, char **argv);
int	get_len(int fd, t_bsq *bsq, char *buff);
void	get_tab(int fd, t_bsq *bsq, char *buff);
void	check_tab(char *s, int len_x, int len_y);
int	check_o(t_bsq bsq);
int	make_bsq(t_bsq bsq);
int	make_bsq_2(t_bsq *bsq);
void	display_bsq(t_bsq bsq);
