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

void syscall_open(void)
{
  char      *arg1;
  uint16_t  arg2;
  uint16_t  arg3;


  arg1 = (char *)(core.memory.vmem + core.regs.r1);
  arg2 = core.regs.r2;
  arg3 = core.regs.r3;

  core.regs.r0 = open(arg1, arg2, arg3);
  if (core.flagmode.noverbose == 0)
    fprintf(stdout, "[%sSYSCALL output%s]: %d\n", YELLOW, ENDC, core.regs.r0);
}

