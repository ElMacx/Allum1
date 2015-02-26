/*
** cheat.c for Allum1 in /home/dulin_m/rendu/Allum1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Fri Feb 14 15:53:17 2014 maxime dulin
** Last update Sun Feb 16 18:50:08 2014 maxime dulin
*/

#include "allum.h"

int	cheat_code(t_list *list)
{
  if (list->pipe[list->pos][1] == '\0')
    list->pipe[list->pos][1] = '|';
  return (0);
}

int	calc_point(t_list *list)
{
  int	save;

  save = list->score1;
  list->score1 = list->score1 * 100 - (list->score2 * 10);
  list->score2 = list->score2 * 100 - (save * 10);
  return (0);
}
