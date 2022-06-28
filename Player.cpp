class Player
{
    public:
    sf::Sprite spr;
    sf::Vector2f post;
    float speed = 300;
    float ang = 0;
    Player();
    void HandleMovement();
    void Draw();
    void update();
    

};


Player::Player(){
    txt.loadFromFile("graphics/player.png");
    spr.setTexture(txt);
    spr.setOrigin(16,16);
    post.x = 400;
    post.y = 300;
}


void Player::HandleMovement(){
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ){
        post.x += cos(ang*M_PI/180.f) * speed * delta;
        post.y += sin(ang*M_PI/180.f) * speed * delta;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ){
        post.x -= cos(ang*M_PI/180.f) * speed * delta;
        post.y -= sin(ang*M_PI/180.f) * speed * delta;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ){
        ang+=delta*360;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ){
        ang-=delta*360;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ){
        b.pew(post,ang);    
    }

}



void Player::Draw(){
    window.draw(spr);
    b.Draw();
}



void Player::update(){
    HandleMovement();
    if(post.y < 0){
        post.y = 600;
    }
    if(post.y > 600){
        post.y = 0;
    }
    if(post.x < 0){
        post.x = 800;
    }
    if(post.x > 800){
        post.x = 0;
    }

    b.Update();
    spr.setPosition(post);
    spr.setRotation(ang+90);
}