/*
** check_delete.c for Allum1 in /home/dulin_m/rendu/Allum1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Fri Feb  7 12:42:57 2014 maxime dulin
** Last update Fri Feb 14 15:32:45 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

void	check_delete(t_list *list, int xor)
{
  int	i;
  int	line;
  int	nb;
  int	delete;
  int	save;

  save = 100000;
  line = 0;
  i = -1;
  while (++i < list->len - 1)
    {
      nb = my_strlen(list->pipe[i]) ^ xor;
      if (my_strlen(list->pipe[i]) > 0)
	{
	  if (nb < save)
	    {
	      save = nb;
	      line = i;
	    }
	}
    }
  delete = my_strlen(list->pipe[line]) - save;
  if (save == 0)
    delete = 1;
  suppr_matche(list, delete, line);
}

int	check_last_hit(t_list *list)
{
  int	i;
  int	ct;

  ct = 0;
  i = 0;
  while (i < list->len - 1)
    {
      if (list->pipe[i][0] == '\0')
	  ct++;
      i++;
    }
  return (ct);
}

int	suppr_matche(t_list *list, int nb, int line)
{
  int	stop;
  int	j;
  int	k;
  int	ct;

  j = 0;
  stop = 0;
  while (list->pipe[line][0] == '\0' && stop < 500)
    {
      line++;
      if (line > list->len - 1)
	line = 0;
      stop++;
    }
  k = my_strlen(list->pipe[line]);
  ct = check_last_hit(list);
  if ((list->len - 1 - ct) == 1)
    nb = my_strlen(list->pipe[line]) - 2;
  if (my_strlen(list->pipe[line]) == 1)
    nb = 0;
  while (j++ <= nb)
    list->pipe[line][k-- - 1] = '\0';
  return (0);
}
