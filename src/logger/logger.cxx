/*
 * Rockefeller
 * Copyright (C) 2022 Kanw
 * kanwkanw@pm.me
 *
 * Rockefeller is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Rockefeller is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.
 *
*/

#include <iostream>
#include <fstream>

#include "logger.hxx"

bool log_on;
bool log_tty;
bool log_f;
std::ofstream log_w;

void logl(std::string t, std::string a)
{
	if (log_on == 1)
	{
		if (log_tty == 1) { std::clog << t << a; }
		if (log_f == 1) { log_w << t << a; }
	}
}

void log(std::string t)
{
	logl (t, "");
}
