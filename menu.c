/*
** menu.c for allmum1 in /home/dulin_m/rendu/Allum1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Feb  5 15:27:30 2014 maxime dulin
** Last update Fri Feb 14 15:51:03 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

void	menu(t_list *list, int ac, char **av)
{
  char	buffer[11];
  int	ret;

  gest_opt(ac, av);
  list->game = 0;
  putstr_modif();
  my_printf("Welcome on Allum-1, the matche's game !\n");
  my_printf("Choose your game's mode :\n     1 VS AI = 1\n     1 VS 1 = 2\n");
  my_printf("     Special mode = 3\n");
  menu2(list);
  my_printf("Enter your name player 1 :\n");
  if ((ret = read(0, buffer, 10)) == -1)
    exit(0);
  buffer[ret] = '\0';
  if ((list->player1 = malloc(sizeof(char) * (my_strlen(buffer) + 1))) == NULL)
    exit(0);
  my_strcpy(list->player1, buffer);
  menu3(list, ret, buffer);
  if (my_strcmp(list->player1, list->player2) == 0)
    my_strcpy(list->player2, "Unknow\n");
  my_printf("Loading...\n");
  sleep(1);
  my_clear();
}

void	menu3(t_list *list, int ret, char *buffer)
{
  list->player2 = malloc(sizeof(char));
  if (list->mode == 1 || list->mode == 2)
    {
      my_printf("Enter your name player 2 :\n");
      if ((ret = read(0, buffer, 10)) == -1)
	exit(0);
      buffer[ret] = '\0';
      if ((list->player2 = malloc(sizeof(char) *
				  (my_strlen(buffer) + 1))) == NULL)
	exit(0);
      my_strcpy(list->player2, buffer);
    }
  if (list->player1[0] == '\0' || (list->player2[0] == '\0'
				   && list->mode != 0))
    {
      my_printf("Your mommy didn't give you a name ?\nI give you one !\n");
      if (list->player1[0] == '\0' && list->player2[0] == '\0'
	  && list->mode != 0)
  	my_printf("In fact two, because there are two slow guys !\n");
      if (*(list->player1) == '\0')
  	my_strcpy(list->player1, "Anita Showerr");
      if (*(list->player2) == '\0')
  	my_strcpy(list->player2, "Phil MyCockk");
    }
}

int	menu2(t_list *list)
{
  int	ret;
  char	buffer[3];

  if ((ret = read(0, buffer, 3)) == -1)
    exit(0);
  buffer[ret] = '\0';
  if (buffer[0] == '1' && buffer[2] == '\0')
    {
      my_printf("You choose the first mode, good luck !\n");
      list->mode = 0;
    }
  else if (buffer[0] == '2' && buffer[2] == '\0')
    {
      my_printf("You choose the second mode, good luck !\n");
      list->mode = 1;
    }
  else if (buffer[0] == '3' && buffer[2] == '\0')
    {
      my_printf("You choose the special mode, good luck !\n");
      list->game = 1;
      list->mode = 2;
    }
  else
    my_exit();
  return (0);
}

int	my_exit()
{
  my_printf("Learn to read the instructions !\n");
  exit(0);
  return (0);
}
