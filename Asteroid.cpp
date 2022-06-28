class Asteroid{
    public:
    sf::CircleShape c;
    sf::Vector2f pos;
    sf::Vector2f speed;
    void Draw();
    void Update();
    Asteroid();
    void spawn();
    float size;

};

Asteroid::Asteroid(){
c.setFillColor(sf::Color::Transparent);
c.setOutlineColor( sf::Color::White );
c.setOutlineThickness( -2 );

}

void Asteroid::Draw(){
window.draw(c);
}

void Asteroid::Update(){

    
pos.x += speed.x * delta;
pos.y += speed.y * delta;

if(pos.y < -200){
        pos.y = 1000;
    }
    if(pos.y > 1000){
        pos.y = -200;
    }
    if(pos.x < -200){
        pos.x = 1200;
    }
    if(pos.x > 1200){
        pos.x = -200;
    }
c.setPosition(pos);
float d = sqrt( pow(pos.x - bp.x, 2) + pow(pos.y - bp.y, 2) );
if(d < size){
    spawn();
}
 d = sqrt( pow(pos.x - player.post.x, 2) + pow(pos.y - player.post.y, 2) );
    if(d < size+16){
     spawn();
     score -= 100;
     zycia--;

     if(zycia < 1){
        gra = false;
     }
}
}

void Asteroid::spawn(){
    score += 10;
    b.pew( sf::Vector2f( 9999, 9999 ), 0 );
    resp:
    pos.x = (float)(rand()%1400 - 200);
    pos.y = (float)(rand()%1000 - 200);
    speed.x = (float)(rand()%400 - 200);
    speed.y = (float)(rand()%400 - 200);
    if(pos.x > 0 && pos.x < 800 && pos.y > 0 && pos.y < 600){
    goto resp;

    }
    size = rand()% 50 + 50;
    c.setRadius(size);
    c.setOrigin(size,size); 
}