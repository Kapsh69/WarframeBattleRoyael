#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

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

int frame;

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

int win_width = 1280;
int win_height = 720;
int sc_width;
int sc_height;

class Frame
{
    public:
        std::string name;
        int hp = 100;
        sf::Texture tex;
        sf::RectangleShape spr;
        int x = 0, y = 0;
        bool ded = false;
} ;
std::vector<Frame> frames;


std::vector<Frame> players;

void Logic()
{
    if (dec != 1)
    {
        Hp.setString(std::to_string(frames[frame].hp));
        
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
                    
                    players[0].name = frames[i].name;
                    players[0].hp = frames[i].hp;
                    players[0].spr = frames[i].spr;
                    players[0].tex = frames[i].tex;
                    players[0].x =0;
                    players[0].y = 0;
                    
                    players[1].name = frames[5].name;
                    players[1].hp = frames[5].hp;
                    players[1].spr = frames[5].spr;
                    players[1].tex = frames[5].tex;
                    players[1].x = 400;
                    players[1].y = 200;
                    
                    players[0].spr.setTexture(&players[0].tex);
                    
                    players[1].spr.setTexture(&players[1].tex);
                    
                    frame = i;
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
        // Arrows
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
        // WASD
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            players[0].y-=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            players[0].y+=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            players[0].x-=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            players[0].x+=1;
        }
        
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
        win.draw(frames[0].spr);
        win.draw(frames[1].spr);
        win.draw(frames[2].spr);
        win.draw(frames[3].spr);
        win.draw(frames[4].spr);
        win.draw(frames[5].spr);
        win.draw(frames[6].spr);
        win.draw(chose);
    }
    else
    {
        if (aaa == true) { float xxxx = oldx; float yyyy = oldy; bul.setPosition(xxxx, yyyy); win.draw(bul); }
        
        // int plsz = players.size();
        
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
    frames.resize(7);
    
    frames[0].name = "batman";
    frames[1].name = "Batmanframe";
    frames[2].name = "cat";
    frames[3].name = "harlamov";
    frames[4].name = "black";
    frames[5].name = "sans";
    frames[6].name = "warframe";
    
    frames[0].tex.loadFromFile("batman.png");
    frames[1].tex.loadFromFile("batmanframe.png");
    frames[2].tex.loadFromFile("cat.png");
    frames[3].tex.loadFromFile("incontrol.gif");
    frames[4].tex.loadFromFile("obama.jpg");
    frames[5].tex.loadFromFile("sans.jpg");
    frames[6].tex.loadFromFile("ploy.png");
    
    frames[0].spr.setTexture(&frames[0].tex);
    frames[1].spr.setTexture(&frames[1].tex);
    frames[2].spr.setTexture(&frames[2].tex);
    frames[3].spr.setTexture(&frames[3].tex);
    frames[4].spr.setTexture(&frames[4].tex);
    frames[5].spr.setTexture(&frames[5].tex);
    frames[6].spr.setTexture(&frames[6].tex);
    
    frames[0].spr.setSize(sf::Vector2f(100, 300));
    frames[1].spr.setSize(sf::Vector2f(100, 300));
    frames[2].spr.setSize(sf::Vector2f(100, 300));
    frames[3].spr.setSize(sf::Vector2f(100, 300));
    frames[4].spr.setSize(sf::Vector2f(100, 300));
    frames[5].spr.setSize(sf::Vector2f(100, 300));
    frames[6].spr.setSize(sf::Vector2f(100, 300));
    
    
    int yy = 0;
    
    frames[0].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[1].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[2].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[3].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[4].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[5].spr.setPosition(yy, 100);
    yy = yy+200;
    frames[6].spr.setPosition(yy, 100);
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
    
    sc_width = sf::VideoMode::getDesktopMode().width;
    sc_height = sf::VideoMode::getDesktopMode().height;
    
    if (!bruhs.loadFromFile("bruh.wav"))
    {
        std::cout << "BRUH\n";
    }
    else
    {
        bruh.setBuffer(bruhs);
    }
}

int main()
{
    load();
    win.create (sf::VideoMode(1280, 720), "Warframe: Battle Royael", sf::Style::Close);
    win.setPosition (sf::Vector2i ( sc_width/2 - win_width/2 , sc_height/2 - win_height/2 ));
    win.setFramerateLimit(350);

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

    return EXIT_SUCCESS;
}
