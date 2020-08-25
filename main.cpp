#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <stdio.h>

sf::RenderWindow win;

sf::Texture playrtex;
sf::Sprite playr;
sf::Texture plartex;
sf::Sprite plar;
sf::SoundBuffer bruhs;
sf::Sound bruh;
sf::Font sans;
sf::Text Hp;

sf::CircleShape bul;

sf::Text chose;
bool warframe = 0;

bool dec = 1;

int фрейм;

int bulposx;
int bulposy;

int oldx;
int oldy;

int tms = 0;
bool aaa = 0;

int tmsi=0;
bool frst = 0;
int xdiff;
            int ydiff;

class Фрейм
{
    public:
        std::string name;
        int hp = 100;
        sf::Texture tex;
        sf::RectangleShape spr;
        int x = 0, y = 0;
        bool ded = false;
} ;
std::vector<Фрейм> фреймы;


std::vector<Фрейм> players;

void Logic()
{
    if (dec != 1)
    {
        Hp.setString(std::to_string(фреймы[фрейм].hp));
        
        if (frst == true && aaa == false)
        {
            if (bulposx > oldx) { xdiff = bulposx-oldx; }
            else if (bulposx < oldx) { xdiff = oldx-bulposx; }
            else if (bulposx == oldx) { xdiff = 0; }
            
            if (bulposy > oldy) { ydiff = bulposy-oldy; }
            else if (bulposy < oldy) { ydiff = oldy-bulposy; }
            else if (bulposy == oldy) { ydiff = 0 ;}
            
            if (xdiff > ydiff)
            {
                tms = xdiff/ydiff;
                aaa = true;
            }
            else if (xdiff < ydiff)
            {
                tms = ydiff/xdiff;
                aaa = true;
            }
            else if (xdiff == ydiff)
            {
                tms = 0;
                aaa = false;
                frst = true;
            }
        }
        
        if (aaa == true && tms <= tmsi)
        {
            if (ydiff > xdiff) // x
            {
                if (oldx > bulposx)
                {
                    oldx-=1;
                }
                else if (oldx < bulposx)
                {
                    oldx+=1;
                }
            }
            else if (ydiff < xdiff)
            {
                if (oldy > bulposy)
                {
                    oldy-=1;
                }
                else if (oldy < bulposy)
                {
                    oldy+=1;
                }
            }
            tmsi = 0;
        }
        
        if (aaa == true)
        {
            if (ydiff > xdiff) // y
            { 
                if (oldy > bulposy)
                {
                    oldy-=1;
                }
                else if (oldy < bulposy)
                {
                    oldy+=1;
                }
            }
            else if (ydiff < xdiff)
            {
                if (oldx > bulposx)
                {
                    oldx-=1;
                }
                else if (oldx < bulposx)
                {
                    oldx+=1;
                }
            }
        }
        
        if (oldx >= players[1].x && oldx <= players[1].x+100 && oldy >= players[1].y && oldy <= players[1].y+300 && players[1].ded != true)
        {
            players[1].ded = true;
            aaa = false; frst = false; tms = 0; tmsi = 0;
        }
        
        
        if (aaa == true && oldx == bulposx && oldy == bulposy) { aaa = false; frst = false; tms = 0; tmsi = 0; }
        if (aaa == true) { tmsi+=1; }
    }
}
void Controls()
{
    if (dec == 1)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mpos = sf::Mouse::getPosition(win);
            bool yas = false;
            for (int i=0; i<6; i++)
            {
                if (mpos.x >= 200*i && mpos.x <= 200*i+200 && mpos.y >= 100 && mpos.y <= 400)
                {
                    players.resize(2);
                    
                    players[0].name = фреймы[i].name;
                    players[0].hp = фреймы[i].hp;
                    players[0].spr = фреймы[i].spr;
                    players[0].tex = фреймы[i].tex;
                    players[0].x =0;
                    players[0].y = 0;
                    
                    players[1].name = фреймы[5].name;
                    players[1].hp = фреймы[5].hp;
                    players[1].spr = фреймы[5].spr;
                    players[1].tex = фреймы[5].tex;
                    players[1].x = 400;
                    players[1].y = 200;
                    
                    players[0].spr.setTexture(&players[0].tex);
                    
                    players[1].spr.setTexture(&players[1].tex);
                    
                    фрейм = i;
                    yas = true;
                    break;
                }
            }
            if (yas == true)
            {
                dec = 0;
            }
        }
    }
    else
    {
        /*if (warframe == 0)
        {*/
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                players[0].y-=1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                players[0].y+=1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                players[0].x-=1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                players[0].x+=1;
            }
        /*}
        else
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                by = by-1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                by = by+1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                bx = bx-1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                bx = bx+1;
            }
        }*/

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (warframe == 0) { warframe = 1; }
            else if (warframe == 1) { warframe = 0; }
        }*/
        //if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            bruh.play();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mpos = sf::Mouse::getPosition(win);
            bulposx = mpos.x;
            bulposy = mpos.y;
            oldx = players[0].x;
            oldy = players[0].y;
            frst = true;
        }
    }
}
void Draw()
{
	win.clear(sf::Color(255, 196, 196));

    if (dec == 1)
    {
        win.draw(фреймы[0].spr);
        win.draw(фреймы[1].spr);
        win.draw(фреймы[2].spr);
        win.draw(фреймы[3].spr);
        win.draw(фреймы[4].spr);
        win.draw(фреймы[5].spr);
        win.draw(фреймы[6].spr);
        win.draw(chose);
    }
    else
    {
        if (aaa == true) { float xxxx = oldx; float yyyy = oldy; bul.setPosition(xxxx, yyyy); win.draw(bul); }
        
        int plsz = players.size();
        /*for (int j=0; j<plsz-1; plsz++)
        {
            players[j].spr.setPosition (players[j].x, players[j].y);
            win.draw(players[j].spr);
        }*/
        
        if (players[0].ded != true)
        {
        players[0].spr.setPosition (players[0].x, players[0].y);
        win.draw(players[0].spr);
        }
        if (players[1].ded != true)
        {
        players[1].spr.setPosition (players[1].x, players[1].y);
        win.draw(players[1].spr);
        }
        
        win.draw(Hp);
    }
	win.display();
}
void load()
{
    фреймы.resize(7);
    
    фреймы[0].name = "batman";
    фреймы[1].name = "Batmanframe";
    фреймы[2].name = "cat";
    фреймы[3].name = "harlamov";
    фреймы[4].name = "black";
    фреймы[5].name = "sans";
    фреймы[6].name = "warframe";
    
    фреймы[0].tex.loadFromFile("batman.png");
    фреймы[1].tex.loadFromFile("batmanframe.png");
    фреймы[2].tex.loadFromFile("cat.png");
    фреймы[3].tex.loadFromFile("incontrol.gif");
    фреймы[4].tex.loadFromFile("obama.jpg");
    фреймы[5].tex.loadFromFile("sans.jpg");
    фреймы[6].tex.loadFromFile("ploy.png");
    
    фреймы[0].spr.setTexture(&фреймы[0].tex);
    фреймы[1].spr.setTexture(&фреймы[1].tex);
    фреймы[2].spr.setTexture(&фреймы[2].tex);
    фреймы[3].spr.setTexture(&фреймы[3].tex);
    фреймы[4].spr.setTexture(&фреймы[4].tex);
    фреймы[5].spr.setTexture(&фреймы[5].tex);
    фреймы[6].spr.setTexture(&фреймы[6].tex);
    
    фреймы[0].spr.setSize(sf::Vector2f(100, 300));
    фреймы[1].spr.setSize(sf::Vector2f(100, 300));
    фреймы[2].spr.setSize(sf::Vector2f(100, 300));
    фреймы[3].spr.setSize(sf::Vector2f(100, 300));
    фреймы[4].spr.setSize(sf::Vector2f(100, 300));
    фреймы[5].spr.setSize(sf::Vector2f(100, 300));
    фреймы[6].spr.setSize(sf::Vector2f(100, 300));
    
    
    int yy = 0;
    
    фреймы[0].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[1].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[2].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[3].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[4].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[5].spr.setPosition(yy, 100);
    yy = yy+200;
    фреймы[6].spr.setPosition(yy, 100);
    yy = yy+200;
    
    sans.loadFromFile("sans.ttf");
    
    chose.setFont(sans);
    chose.setString("vibor\nframeov\nsans");
    chose.setCharacterSize(24);
    chose.setFillColor(sf::Color(0, 255, 255));
    chose.setPosition(0,0);
    
    Hp.setFont(sans);
    Hp.setString("aaa");
    Hp.setCharacterSize(24);
    Hp.setFillColor(sf::Color::White);
    Hp.setPosition(10,10);
    
    bul.setFillColor(sf::Color(0, 0, 0));
    bul.setRadius(5);
}

int main()
{
	load();
	win.create (sf::VideoMode(1280, 720), "Warframe: Battle Royael", sf::Style::Close);

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { win.close(); }
		}

		Controls();
		Logic();
		Draw();
        
	}

	return 0;
}
