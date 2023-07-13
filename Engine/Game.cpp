/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	int x = 400;
	int y = 300;
	int r = 255;
	int g = 255;
	int b = 255;
	int Crosshair_length = 4;

	const bool Up = wnd.kbd.KeyIsPressed(VK_UP);
	const bool Down = wnd.kbd.KeyIsPressed(VK_DOWN);
	const bool Right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	const bool Left = wnd.kbd.KeyIsPressed(VK_LEFT);
	const bool ColorChange = wnd.kbd.KeyIsPressed(VK_CONTROL);
	const bool AltShape = wnd.kbd.KeyIsPressed(VK_SHIFT);

	if (Up)
	{
		y -= 100;
	}

	if (Down)
	{
		y += 100;
	}

	if (Right)
	{
		x += 100;
	}
	
	if (Left)
	{
		x -= 100;
	}

	if (ColorChange)
	{
		g = 0;
		b = 0;
	}

	
	for (int i = 0; i < Crosshair_length; i++)
	{
		//Fuck this alt shape its cancer
		if (AltShape)
		{
			gfx.PutPixel(x + 5, y - i - 2, r, g, b);
			gfx.PutPixel(x - i + 5, y - 5, r, g, b);
			
			gfx.PutPixel(x - 8, y - i - 2, r, g, b);
			gfx.PutPixel(x - i - 5, y - 5, r, g, b);
			
			gfx.PutPixel(x + 5, y - i + 8, r, g, b);
			gfx.PutPixel(x - i + 5, y + 8, r, g, b);

			gfx.PutPixel(x - 8, y - i + 8, r, g, b);
			gfx.PutPixel(x - i - 5, y + 8, r, g, b);
		}
		else
		{
			gfx.PutPixel(x, y - i - 3, r, g, b);
			gfx.PutPixel(x - i - 3, y, r, g, b);

			gfx.PutPixel(x, y + i + 3, r, g, b);
			gfx.PutPixel(x + i + 3, y, r, g, b);
		}
	}
}
