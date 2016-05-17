/*
** string_equal.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Wed May 18 01:08:15 2016 Pierre-Emmanuel Jacquier
** Last update Wed May 18 01:08:15 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"

int		string_equals(const char *a, const char *b)
{
  while (*a == *b)
    {
      if (!*a)
	return (1);
      a++;
      b++;
    }
  return (0);
}
