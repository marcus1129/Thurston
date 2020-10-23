#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

/*void draw_M(){
    ConvexShape polygon;
    polygon.setPointCount(10);
    //Upper line
    polygon.setPoint(0, Vector2f(200, 200));
    polygon.setPoint(1, Vector2f(280, 50));
    polygon.setPoint(2, Vector2f(320, 125));
    polygon.setPoint(3, Vector2f(360, 50));
    polygon.setPoint(4, Vector2f(440, 200));

    //Lower line
    polygon.setPoint(5, Vector2f(435, 200));
    polygon.setPoint(6, Vector2f(360, 55));
    polygon.setPoint(7, Vector2f(320, 130));
    polygon.setPoint(8, Vector2f(280, 55));
    polygon.setPoint(9, Vector2f(205, 200));

    polygon.setOutlineColor(Color::Blue);
    polygon.setFillColor(Color::Black);
    polygon.setOutlineThickness(5);
    window.draw(polygon);
}*/

void thurston(){

}

int main()
{
    RenderWindow window(VideoMode(800,600), "Thurston"/*, Style::Fullscreen*/);
    Event event;
    Image image;
    SoundBuffer buffer;
    Texture texture;
    Sprite sprite;
    Sound sound;
    image.loadFromFile("thurston.jpg");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    bool bonk = false;

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
            else if(event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Space){
                    if (!buffer.loadFromFile("Thurston.wav")){
                        return -1;
                    }
                    else{
                        buffer.loadFromFile("Thurston.wav");
                        sound.setBuffer(buffer);
                        bonk = true;
                    }
                }
                else{
                    break;
                }
            }
            window.clear();
            window.draw(sprite);
            if(bonk){
                sound.play();
                bonk = false;
            }
            window.display();
        }
    }
}
