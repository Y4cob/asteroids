class Bullet{
private :
sf::CircleShape c;
float speed = 450;
sf::Vector2f pos;
float ang;
public:
Bullet();
void Draw();
void Update();
void pew(sf::Vector2f p, float a);

sf::Vector2f getPos(){ std::cout << pos.x << "\n"; return this->pos;}
};


Bullet::Bullet(){
 ang = 0;
 c.setFillColor( sf::Color::White );
 c.setRadius( 4 );
 c.setOrigin( 4, 4);
}


void Bullet::Draw(){
window.draw(c);
}


void Bullet::Update(){
    pos.x += cos(ang*M_PI/180.f) * speed * delta;
    pos.y += sin(ang*M_PI/180.f) * speed * delta;
    bp = pos;
    c.setPosition( pos );
}


void Bullet::pew(sf::Vector2f p, float a){
    pos = p;
    ang = a;
    c.setPosition( pos );
    // std::cout << "Buller has been peewed!\n";
}