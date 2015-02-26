/*
** my_selct.h for my_select in /home/dulin_m/rendu/my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan 14 11:19:56 2014 maxime dulin
** Last update Fri Feb 14 19:13:44 2014 maxime dulin
*/

#ifndef _MY_SELECT_H_
#define _MY_SELECT_H_
#define	BUFFER_SIZE 10

/*
** Mes includes
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses/curses.h>

/*
** Mes structures
*/

typedef struct	s_pam
{
  int	i;
  int	j;
  int	ln;
  int	ct;
}		t_pam;

typedef struct	s_param
{
  int	i;
  int	buffer;
  int	ret;
  char	*str;
}		t_param;

typedef struct	s_elem
{
  struct s_elem	*back;
  struct s_elem	*next;
  char		*value;
}		t_elem;

typedef struct	s_list
{
  int		mode;
  int		game;
  int		pos;
  int		len;
  int		score1;
  int		score2;
  char		*player1;
  char		*player2;
  t_elem	*first;
  t_elem	*current;
  char		**pipe;
  int		player;
}		t_list;

/*
** main.c
*/

void	create(t_list *list);
int	complete(char *, t_list *);
int	my_print(t_list *, int, char **);
int	main(int , char **, char **);
int	check_empty(t_list *);

/*
** gest_key.c
*/

void	writestr(char *);
int	analyze(int , t_list *, char *, char **);
int	gest_up(t_list *);
int	gest_down(t_list *);
int	my_round(t_list *, char **, char **);

/*
** get_env.c
*/

char	*get_env(char **, char *);

/*
** my_modif_select.c
*/

int	my_under();
int	my_under_end();
int	my_clear();

/*
** putstr_modif.c
*/

int	putstr_modif();

/*
** gest_opt.c
*/

int	gest_opt(int , char **);
int	gest_print(t_elem *, t_list *, int );
int	check_val(t_list *);
/*
** create_pite.c
*/

char	**create_pipe(int , t_list *);
int	print_tab(t_list *);
int	check_number(t_list *, int, char **);
int	suppr_al(t_list *, int, char **);
int	player_stat(t_list *);

/*
** menu.c
*/

void	menu(t_list *, int, char **);
int	my_exit();
int	my_end(t_list *);
int	menu2(t_list *);
void	menu3(t_list *, int, char *);

/*
** ia.c
*/

int	count_pipe(t_list *, int );
int	calc_xor(t_list *);
int	ia(t_list *);

/*
** check_delete.c
*/

void	check_delete(t_list *, int);
int	suppr_matche(t_list *, int, int);
int	check_last_hit(t_list *);

/*
** cheat.c
*/

int	cheat_code(t_list *);
int	calc_point(t_list *);

#endif
