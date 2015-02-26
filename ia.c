/*
** ia.c for Allum1 in /home/dulin_m/rendu/Allum1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Thu Feb  6 20:23:41 2014 maxime dulin
** Last update Fri Feb 14 11:51:21 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

int	count_pipe(t_list *list, int i)
{
  int	j;
  int	ct;

  ct = 0;
  j = 0;
  while (list->pipe[i][j] != '\0')
    {
      if (list->pipe[i][j] == '|')
	ct++;
      j++;
    }
  return (ct);
}

int	calc_xor(t_list *list)
{
  int	i;
  int	nb;
  int	j;
  int	tmp[100];

  i = 0;
  j = 0;
  nb = 0;
  while (i < list->len - 1)
    {
      tmp[j] = count_pipe(list, i);
      j++;
      i++;
    }
  tmp[j] = -1;
  j = 0;
  while (tmp[j] != -1)
    {
      nb = nb ^ tmp[j];
      j++;
    }
  return (nb);
}

int	ia(t_list *list)
{
  int	nb;

  if (list->mode == 0)
    {
      nb = calc_xor(list);
      check_delete(list, nb);
    }
  list->player++;
  return (0);
}
