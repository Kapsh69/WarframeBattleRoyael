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

#ifndef RF_WINDOW
#define RF_WINDOW

#include <SFML/Graphics.hpp>

extern sf::RenderWindow win;		// The window itself
extern int win_width;			// Window's current width
extern int win_height;			// Window's current height
extern char win_style;			// Window's style i.e. fullscreen (8), windowed(7)
extern bool win_running;		// Program's on/off switch
extern sf::ContextSettings win_cs;	// Window beautifuler
extern char win_lce;			// For keyboard input
extern sf::View win_view;		// Window's main view
extern std::string win_title;		// Window's title
extern int win_msc;			// Mouse Scrolled
extern float win_unit;

#endif
