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

#include "init.hxx"
#include <window.hxx>

sf::RenderWindow win;
int win_width;
int win_height;
char win_style;
bool win_running;
sf::ContextSettings win_cs;
char win_lce = -1;
sf::View win_view;
std::string win_title = "WarframeBattleRoyael";
int win_msc;
float win_unit;

#include <info.hxx>
#include <main.hxx>


void init_window_defaults()
{
	win_width = sc_width/1.5;
	win_height = win_width/sc_ar;

	win_style = 7;
}

void init_window(int ww, int wh, char ws, std::string wt, int cdb, int csb, int caal, int cmv, int civ)
{
	win_width = ww;
	win_height = wh;
	win_style = ws;
	win_title = wt;

	win_cs.depthBits = cdb;
	win_cs.stencilBits = csb;
	win_cs.antialiasingLevel = caal;
	win_cs.majorVersion = cmv;
	win_cs.minorVersion = civ;

	if (win_width < 1 || win_height < 1 || win_width > sc_width || win_height > sc_height)
	{ init_window_defaults(); }

	if ((win_style == 7 || win_style == 8) == false)
	{ win_style = 7; }

	win.create (sf::VideoMode (win_width, win_height), wt, win_style, win_cs);

	if (win_style == 7)
	{ win.setPosition (sf::Vector2i (sc_width/2 - win_width/2 , sc_height/2 - win_height/2)); }
}

void init_window(int ww, int wh, char ws)
{
	std::string wt = WBR_NAME + ": " + WBR_RELEASE + '-' + WBR_BUILD;
	init_window (ww, wh, ws, wt , 24, 8, 3, 3, 0);
}

void init_window()
{
	init_window (1280, 720, 7);
}
