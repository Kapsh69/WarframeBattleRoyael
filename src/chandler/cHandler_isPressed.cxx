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

#include "chandler.hxx"
#include <window.hxx>

bool cHandler::isPOC(std::string kk, bool poc)
{
	bool s = false;

	if ( keys[kk].used == false )
	{
		if (keys[kk].special == 0)
		{
			if (sf::Keyboard::isKeyPressed(keys[kk].skey))
			{
				if ( keys[kk].pressed && poc ) { return 0; }
				keys[kk].pressed = s = 1;
			}
			else { keys[kk].pressed = s = 0; }
		}
		else if (keys[kk].special == 1)
		{
			if ( sf::Mouse::isButtonPressed (keys[kk].sbtn) )
			{
				if ( keys[kk].pressed && poc ) { return 0; }
				keys[kk].pressed = s = 1;
			}
			else { keys[kk].pressed = s = 0; }
		}
		else if (keys[kk].special == 2) { if (win_msc > 0) { return 1; } }
		else if (keys[kk].special == 3) { if (win_msc < 0) { return 1; } }
	}

	return s;
}

bool cHandler::isClicked(std::string kk) { return isPOC(kk, 1); }
bool cHandler::isPressed(std::string kk) { return isPOC(kk, 0); }
