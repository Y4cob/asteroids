#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
sf::RenderWindow window;
sf::Vector2f bp;
float delta, elapsed;
sf::Font font;
int score = 0;
sf::Text wynik,koniec;
bool gra = true;
int zycia = 3;
sf::Texture txt;
sf::RectangleShape r;
#include <math.h>
#include "Bullet.cpp"
Bullet b;
#include "Player.cpp"
Player player;
#include "Asteroid.cpp"




int main()
{
    
    std::vector <Asteroid> asteroids;
    int ac = 16;
    score = -10*ac;
    for( int i = 0; i < ac; i++ )
    {
        Asteroid tmp;
        tmp.spawn();
        asteroids.push_back( tmp );
    }

    window.create(sf::VideoMode(800, 600), "Asteroids");

if (!font.loadFromFile("graphics/PressStart2P-Regular.ttf"))
{
    std::cout<< "chuj z wyniku" << std::endl;
}
wynik.setFont(font);
wynik.setCharacterSize(30);
wynik.setPosition( 4,4 );
wynik.setFillColor(sf::Color::Green);
wynik.setPosition( 400-wynik.getLocalBounds().width/2, 8 );

koniec.setFont(font);
koniec.setCharacterSize(64);
koniec.setFillColor(sf::Color::Green);
koniec.setString("GAME OVER!");
koniec.setPosition( 400-koniec.getLocalBounds().width/2, 300-koniec.getLocalBounds().height/2 );


r.setSize( sf::Vector2f( 32, 32 ) );
r.setFillColor( sf::Color::White );
sf::Texture tmpp;
tmpp.loadFromFile( "graphics/zycie.png" );
r.setTexture( &tmpp );

    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        
        {
        
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }

        }
        if(gra == true){
        player.update();
        wynik.setPosition( 400-wynik.getLocalBounds().width/2, 8 );
        for( int i = 0; i < ac; i++ )
        {
            asteroids[i].Update();
        }
        wynik.setString(std::to_string (score));
        }

        window.clear();
        player.Draw();
        for( int i = 0; i < ac; i++ )
        {
            asteroids[i].Draw();
        }
        window.draw(wynik);
        if(!gra ){
            window.draw(koniec);
            koniec.setRotation( sin(elapsed) * 15);
        }

        for( int i = 0; i < zycia; i++ )
        {
             r.setPosition( 8+48*i, 8 );
            window.draw( r );
        }
        
        window.display();

        delta = deltaClock.restart().asSeconds();
        elapsed += delta;
    }

    return 0;
}