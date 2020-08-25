#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

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

class Фрейм
{
    public:
        std::string name;
        int hp = 100;
        sf::Texture tex;
        sf::RectangleShape spr;
        int x = 0, y = 0;
} ;
std::vector<Фрейм> фреймы;



void Logic()
{
    Hp.setString(std::to_string(фреймы[фрейм].hp));
    if (bulposx > oldx)
    {
        oldx+=1;
    }
    else if (bulposx < oldx)
    {
        oldx-=1;
    }
    else if (bulposy > oldy)
    {
        oldy+=1;
    }
    else if (bulposy < oldy)
    {
        oldy-=1;
    }
    /*if (oldx == oldx) {}
    if (bulposy == oldy) {}*/
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
                if (mpos.x >= 200*i && mpos.x <= 200*i+200 && mpos.y >= 100 && mpos.y <= 400) { фрейм = i; yas = true; break; }
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
                фреймы[фрейм].y = фреймы[фрейм].y-1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                фреймы[фрейм].y = фреймы[фрейм].y+1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                фреймы[фрейм].x = фреймы[фрейм].x-1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                фреймы[фрейм].x = фреймы[фрейм].x+1;
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
            oldx = фреймы[фрейм].x;
            oldy = фреймы[фрейм].y;
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
        if (oldx != bulposx && oldy != bulposy) { bul.setPosition(oldx, oldy); win.draw(bul); }
        фреймы[фрейм].spr.setPosition (фреймы[фрейм].x, фреймы[фрейм].y);
        win.draw(фреймы[фрейм].spr);
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
