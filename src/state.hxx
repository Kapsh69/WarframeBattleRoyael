/*
 * WBR
 * Copyright (C) 2022 Kanw
 * kanwkanw@pm.me
 *
 * WBR is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * WBR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.
 *
*/

#ifndef WBR_STATE
#define WBR_STATE

#include <map>
#include <string>

class State
{
	public:
		void (*Controls)();
		void (*Logic)();
		void (*Render)();
		int engineFPS;
};

extern std::string curState;
extern std::map <std::string, State> state;

#endif
