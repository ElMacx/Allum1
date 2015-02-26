/*
** create_pipe.c for Allum1 in /home/dulin_m/rendu/Allum1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Feb  5 10:39:43 2014 maxime dulin
** Last update Thu Feb 13 16:35:41 2014 maxime dulin
*/

#include "./My_lib/my.h"
#include "allum.h"

char	**create_pipe(int i, t_list *list)
{
  int	c;
  int	l;
  int	k;

  k = 1;
  l = 0;
  if ((list->pipe = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(0);
  list->pipe[i] = NULL;
  while (i > 0)
    {
      c = 0;
      if ((list->pipe[l] = malloc(sizeof(char) * (k + 1))) == NULL)
	exit(0);
      list->pipe[l][k] = '\0';
      while (c < k)
	{
	  list->pipe[l][c] = '|';
	  c++;
	}
      l++;
      k += 2;
      i--;
    }
  return (list->pipe);
}

int	print_tab(t_list *list)
{
  int	i;

  i = 0;
  while (list->pipe[i] != '\0')
    {
      my_printf("%s\n", list->pipe[i]);
      i++;
    }
  return (0);
}

int	check_number(t_list *list, int buf, char **av)
{
  list = list;
  if (buf == 49)
    suppr_al(list, 1, av);
  else if (buf == 50)
    suppr_al(list, 2, av);
  else if (buf == 51)
    suppr_al(list, 3, av);
  else if (buf == 52)
    suppr_al(list, 4, av);
  else if (buf == 53)
    suppr_al(list, 5, av);
  else if (buf == 54)
    suppr_al(list, 6, av);
  else if (buf == 55)
    suppr_al(list, 7, av);
  else if (buf == 56)
    suppr_al(list, 8, av);
  else if (buf == 57)
    suppr_al(list, 9, av);
  return (0);
}

int	suppr_al(t_list *list, int nb, char **av)
{
  int	i;
  int	j;

  j = my_strlen(list->pipe[list->pos]);
  i = 0;
  if (nb > j)
    return (0);
  while (i++ < nb)
    list->pipe[list->pos][j-- - 1] = '\0';
  list->player++;
  my_print(list, 1, av);
  if (list->mode == 0)
    {
      my_printf("Computer is thinking...\n");
      sleep(1);
      ia(list);
    }
  if (list->player % 2 == 0)
    list->score1 += nb;
  else
    list->score2 += nb;
  return (0);
}

int	player_stat(t_list *list)
{
  if (list->player == (list->player / 2 * 2))
    my_printf("\nIt's your turn %s\n", list->player1);
  else if (list->mode == 1 || list->mode == 2)
    my_printf("\nIt's your turn %s\n", list->player2);
  else
    my_printf("\nIt's the turn of IA\n");
  return (0);
}
