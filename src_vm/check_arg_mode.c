/*
** vmndh - Release v0.1
** Jonathan Salwan - http://twitter.com/JonathanSalwan
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "vmndh.h"

void check_arg_mode(char **argv)
{
  int i = 0;

  core.flagmode.arg = 0;
  while (argv[i] != NULL)
    {
      if (!strcmp(argv[i], "-arg"))
        {
          if (argv[i + 1] != NULL && argv[i + 1][0] != '\0')
            {
              core.flagmode.arg = 1;
              core.infobin.arg =  argv[i + 1];
            }
          else
            {
              fprintf(stderr, "%sSyntax%s: -arg <arg>\n", RED, ENDC);
              exit(EXIT_FAILURE);
            }
        }
      i++;
    }
}
