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

#include <info.hxx>

int sc_width;
int sc_height;
float sc_ar;

#include <SFML/Window.hpp>

void init_info()
{
	sc_width = sf::VideoMode::getDesktopMode().width;
	sc_height = sf::VideoMode::getDesktopMode().height;

	float scwf = sc_width;
	float schf = sc_height;

	sc_ar = scwf/schf;
}