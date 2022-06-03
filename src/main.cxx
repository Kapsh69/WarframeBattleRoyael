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

#include <init/init.hxx>
#include <log.hxx>
#include <main.hxx>
#include <window.hxx>
#include <state.hxx>

const std::string WBR_NAME = "WarframeBattleRoyael";
const std::string WBR_RELEASE = "New-Devel";
const std::string WBR_BUILD = "0";

int main()
{
	if ( init() )
	{
		logl ( "E> Error(s) Occurred during initiation\n" );
		return EXIT_FAILURE;
	}
	else
	{
		win_running = true;
		sf::Clock clock;
		while (win_running)
		{
			win_lce = -1;
			sf::Event e;
			while ( win.pollEvent (e) )
			{
				if ( e.type == sf::Event::Closed )
				{
					win_running = false;
					return EXIT_SUCCESS;
				}
				if ( e.type == sf::Event::Resized )
				{
					win_width = e.size.width;
					win_height = e.size.height;
					win_view.setCenter ( 0 + win_width/2 , 0 + win_height/2 );
					win_view.setSize ( win_width , win_height );
					win.setView ( win_view );
					win_unit = win_height/96;
				}
				if ( e.type == sf::Event::TextEntered )
				{
					win_lce = e.text.unicode;
				}
				if ( e.type == sf::Event::MouseWheelMoved )
				{
					win_msc -= e.mouseWheel.delta;
				}
			}
			//cHandler();
			//sHandler();
			if ( clock.getElapsedTime().asMilliseconds() >= (1000.f/state[curState].engineFPS) )
			{
			//	state[curState].Controls();
			//	state[curState].Logic();
				clock.restart();
			}
			//state[curState].Render();
		}
	}

	logl ( "\n" );
	return EXIT_SUCCESS;
}
