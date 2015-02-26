/*
** gest_opt.c for my_select in /home/dulin_m/rendu/PSU_2013_my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Sat Jan 18 13:20:53 2014 maxime dulin
** Last update Sun Feb 16 18:59:38 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

int	gest_opt(int ac, char **av)
{
  if (av[1] && av[1][0] == '-' && av[1][1] == 'h')
    {
      my_printf("\033[34mFICHIER AIDE\n\033[0m");
      my_printf("Rules :\nTo play, chose a the number of match's lines\n");
      my_printf("You can move with the arrow 'UP' and 'DOWN'");
      my_printf("\nEnter a number between 1 and 9 to retire matches\n");
      my_printf("The looser is one who takes the last match\n");
      my_printf("Explanations of modes :\nFirst mode : play with the AI");
      my_printf("\nSecond mode : play with an other guy");
      my_printf("\nThird mode : rules change, the one who take the last");
      my_printf(" matche win !\n");
      exit(0);
    }
  if (ac < 2 || ac >= 3 || (*av[1] < '0' || *av[1] > '9'))
    {
      my_putstr("Usage : ./allum1 [nb]\n");
      my_putstr("If you want some help : ./allum1 -h\n");
      exit(0);
    }
  if (my_getnbr(av[1]) >= 50 || my_getnbr(av[1]) == 0)
    {
      my_printf("Please enter a number between 1 and 49\n");
      exit(0);
    }
  return (0);
}

int	gest_print(t_elem *tmp, t_list *list, int ret)
{
  if (tmp == list->current && ret == 1)
    {
      my_under();
      writestr(list->current->value);
      my_under_end();
    }
  else
    writestr(tmp->value);
  return (0);
}

int	check_val(t_list *list)
{
  int	i;
  int	j;

  i = 0;
  while (i < list->len)
    {
      j = 0;
      while (list->pipe[i][j] != '\0')
	{
	  if (list->pipe[i][j] == '|')
	    return (0);
	  j++;
	}
      i++;
    }
  my_end(list);
  exit(0);
}

int	my_end(t_list *list)
{
  my_clear();
  putstr_modif();
  calc_point(list);
  if (list->mode == 1 || list->mode == 2)
    {
      if (list->player % 2 == 0)
	my_printf("%s is the winner, congratulations !\n\n", list->player1);
      else
	my_printf("%s is the winner, congratulations !\n\n", list->player2);
      my_printf("%s have a score of %d point\n", list->player2, list->score1);
      my_printf("%s have a score of %d point\n", list->player1, list->score2);
    }
  if (list->mode == 0)
    {
      if (list->player % 2 == 0)
	my_printf("%s is the winner, congratulations !\n\n", list->player1);
      else
	my_printf("AI is the winner, congratulations !\n\n");
    }
  exit(0);
}
