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

void cHandlerSetup(cHandler* ch)
{
	ch->keys["A"].skey = sf::Keyboard::A;
	ch->keys["B"].skey = sf::Keyboard::B;
	ch->keys["C"].skey = sf::Keyboard::C;
	ch->keys["D"].skey = sf::Keyboard::D;
	ch->keys["E"].skey = sf::Keyboard::E;
	ch->keys["F"].skey = sf::Keyboard::F;
	ch->keys["G"].skey = sf::Keyboard::G;
	ch->keys["H"].skey = sf::Keyboard::H;
	ch->keys["I"].skey = sf::Keyboard::I;
	ch->keys["J"].skey = sf::Keyboard::J;
	ch->keys["K"].skey = sf::Keyboard::K;
	ch->keys["L"].skey = sf::Keyboard::L;
	ch->keys["M"].skey = sf::Keyboard::M;
	ch->keys["N"].skey = sf::Keyboard::N;
	ch->keys["O"].skey = sf::Keyboard::O;
	ch->keys["P"].skey = sf::Keyboard::P;
	ch->keys["Q"].skey = sf::Keyboard::Q;
	ch->keys["R"].skey = sf::Keyboard::R;
	ch->keys["S"].skey = sf::Keyboard::S;
	ch->keys["T"].skey = sf::Keyboard::T;
	ch->keys["U"].skey = sf::Keyboard::U;
	ch->keys["V"].skey = sf::Keyboard::V;
	ch->keys["W"].skey = sf::Keyboard::W;
	ch->keys["X"].skey = sf::Keyboard::X;
	ch->keys["Y"].skey = sf::Keyboard::Y;
	ch->keys["Z"].skey = sf::Keyboard::Z;
	ch->keys["Num0"].skey = sf::Keyboard::Num0;
	ch->keys["Num1"].skey = sf::Keyboard::Num1;
	ch->keys["Num2"].skey = sf::Keyboard::Num2;
	ch->keys["Num3"].skey = sf::Keyboard::Num3;
	ch->keys["Num4"].skey = sf::Keyboard::Num4;
	ch->keys["Num5"].skey = sf::Keyboard::Num5;
	ch->keys["Num6"].skey = sf::Keyboard::Num6;
	ch->keys["Num7"].skey = sf::Keyboard::Num7;
	ch->keys["Num8"].skey = sf::Keyboard::Num8;
	ch->keys["Num9"].skey = sf::Keyboard::Num9;
	ch->keys["Escape"].skey = sf::Keyboard::Escape;
	ch->keys["LControl"].skey = sf::Keyboard::LControl;
	ch->keys["LShift"].skey = sf::Keyboard::LShift;
	ch->keys["LAlt"].skey = sf::Keyboard::LAlt;
	ch->keys["LSystem"].skey = sf::Keyboard::LSystem;
	ch->keys["RControl"].skey = sf::Keyboard::RControl;
	ch->keys["RShift"].skey = sf::Keyboard::RShift;
	ch->keys["RAlt"].skey = sf::Keyboard::RAlt;
	ch->keys["RSystem"].skey = sf::Keyboard::RSystem;
	ch->keys["Menu"].skey = sf::Keyboard::Menu;
	ch->keys["LBracket"].skey = sf::Keyboard::LBracket;
	ch->keys["RBracket"].skey = sf::Keyboard::RBracket;
	ch->keys["Semicolon"].skey = sf::Keyboard::Semicolon;
	ch->keys["Comma"].skey = sf::Keyboard::Comma;
	ch->keys["Period"].skey = sf::Keyboard::Period;
	ch->keys["Quote"].skey = sf::Keyboard::Quote;
	ch->keys["Slash"].skey = sf::Keyboard::Slash;
	ch->keys["Backslash"].skey = sf::Keyboard::Backslash;
	ch->keys["Tilde"].skey = sf::Keyboard::Tilde;
	ch->keys["Equal"].skey = sf::Keyboard::Equal;
	ch->keys["Hyphen"].skey = sf::Keyboard::Hyphen;
	ch->keys["Space"].skey = sf::Keyboard::Space;
	ch->keys["Enter"].skey = sf::Keyboard::Enter;
	ch->keys["Backspace"].skey = sf::Keyboard::Backspace;
	ch->keys["Tab"].skey = sf::Keyboard::Tab;
	ch->keys["PageUp"].skey = sf::Keyboard::PageUp;
	ch->keys["PageDown"].skey = sf::Keyboard::PageDown;
	ch->keys["End"].skey = sf::Keyboard::End;
	ch->keys["Home"].skey = sf::Keyboard::Home;
	ch->keys["Insert"].skey = sf::Keyboard::Insert;
	ch->keys["Delete"].skey = sf::Keyboard::Delete;
	ch->keys["Add"].skey = sf::Keyboard::Add;
	ch->keys["Subtract"].skey = sf::Keyboard::Subtract;
	ch->keys["Multiply"].skey = sf::Keyboard::Multiply;
	ch->keys["Divide"].skey = sf::Keyboard::Divide;
	ch->keys["Left"].skey = sf::Keyboard::Left;
	ch->keys["Right"].skey = sf::Keyboard::Right;
	ch->keys["Up"].skey = sf::Keyboard::Up;
	ch->keys["Down"].skey = sf::Keyboard::Down;
	ch->keys["Numpad0"].skey = sf::Keyboard::Numpad0;
	ch->keys["Numpad1"].skey = sf::Keyboard::Numpad1;
	ch->keys["Numpad2"].skey = sf::Keyboard::Numpad2;
	ch->keys["Numpad3"].skey = sf::Keyboard::Numpad3;
	ch->keys["Numpad4"].skey = sf::Keyboard::Numpad4;
	ch->keys["Numpad5"].skey = sf::Keyboard::Numpad5;
	ch->keys["Numpad6"].skey = sf::Keyboard::Numpad6;
	ch->keys["Numpad7"].skey = sf::Keyboard::Numpad7;
	ch->keys["Numpad8"].skey = sf::Keyboard::Numpad8;
	ch->keys["Numpad9"].skey = sf::Keyboard::Numpad9;
	ch->keys["Mouse1"].sbtn = sf::Mouse::Left;
	ch->keys["Mouse1"].special = 1;
	ch->keys["Mouse2"].sbtn = sf::Mouse::Right;
	ch->keys["Mouse2"].special = 1;
	ch->keys["Mouse3"].sbtn = sf::Mouse::Middle;
	ch->keys["Mouse3"].special = 1;
	ch->keys["Mouse4"].sbtn = sf::Mouse::XButton1;
	ch->keys["Mouse4"].special = 1;
	ch->keys["Mouse5"].sbtn = sf::Mouse::XButton2;
	ch->keys["Mouse5"].special = 1;
	ch->keys["MouseUp"].special = 2;
	ch->keys["MouseDown"].special = 2;
	ch->keys["None"].special = 3;

    ch->keysv.push_back("A");
	ch->keysv.push_back("B");
	ch->keysv.push_back("C");
	ch->keysv.push_back("D");
	ch->keysv.push_back("E");
	ch->keysv.push_back("F");
	ch->keysv.push_back("G");
	ch->keysv.push_back("H");
	ch->keysv.push_back("I");
	ch->keysv.push_back("J");
	ch->keysv.push_back("K");
	ch->keysv.push_back("L");
	ch->keysv.push_back("M");
	ch->keysv.push_back("N");
	ch->keysv.push_back("O");
	ch->keysv.push_back("P");
	ch->keysv.push_back("Q");
	ch->keysv.push_back("R");
	ch->keysv.push_back("S");
	ch->keysv.push_back("T");
	ch->keysv.push_back("U");
	ch->keysv.push_back("V");
	ch->keysv.push_back("W");
	ch->keysv.push_back("X");
	ch->keysv.push_back("Y");
	ch->keysv.push_back("Z");
	ch->keysv.push_back("Num0");
	ch->keysv.push_back("Num1");
	ch->keysv.push_back("Num2");
	ch->keysv.push_back("Num3");
	ch->keysv.push_back("Num4");
	ch->keysv.push_back("Num5");
	ch->keysv.push_back("Num6");
	ch->keysv.push_back("Num7");
	ch->keysv.push_back("Num8");
	ch->keysv.push_back("Num9");
	ch->keysv.push_back("Escape");
	ch->keysv.push_back("LControl");
	ch->keysv.push_back("LShift");
	ch->keysv.push_back("LAlt");
	ch->keysv.push_back("LSystem");
	ch->keysv.push_back("RControl");
	ch->keysv.push_back("RShift");
	ch->keysv.push_back("RAlt");
	ch->keysv.push_back("RSystem");
	ch->keysv.push_back("Menu");
	ch->keysv.push_back("LBracket");
	ch->keysv.push_back("RBracket");
	ch->keysv.push_back("Semicolon");
	ch->keysv.push_back("Comma");
	ch->keysv.push_back("Period");
	ch->keysv.push_back("Quote");
	ch->keysv.push_back("Slash");
	ch->keysv.push_back("Backslash");
	ch->keysv.push_back("Tilde");
	ch->keysv.push_back("Equal");
	ch->keysv.push_back("Hyphen");
	ch->keysv.push_back("Space");
	ch->keysv.push_back("Enter");
	ch->keysv.push_back("Backspace");
	ch->keysv.push_back("Tab");
	ch->keysv.push_back("PageUp");
	ch->keysv.push_back("PageDown");
	ch->keysv.push_back("End");
	ch->keysv.push_back("Home");
	ch->keysv.push_back("Insert");
	ch->keysv.push_back("Delete");
	ch->keysv.push_back("Add");
	ch->keysv.push_back("Subtract");
	ch->keysv.push_back("Multiply");
	ch->keysv.push_back("Divide");
	ch->keysv.push_back("Left");
	ch->keysv.push_back("Right");
	ch->keysv.push_back("Up");
	ch->keysv.push_back("Down");
	ch->keysv.push_back("Numpad0");
	ch->keysv.push_back("Numpad1");
	ch->keysv.push_back("Numpad2");
	ch->keysv.push_back("Numpad3");
	ch->keysv.push_back("Numpad4");
	ch->keysv.push_back("Numpad5");
	ch->keysv.push_back("Numpad6");
	ch->keysv.push_back("Numpad7");
	ch->keysv.push_back("Numpad8");
	ch->keysv.push_back("Numpad9");
	ch->keysv.push_back("Mouse1");
	ch->keysv.push_back("Mouse2");
	ch->keysv.push_back("Mouse3");
	ch->keysv.push_back("Mouse4");
	ch->keysv.push_back("Mouse5");
}
