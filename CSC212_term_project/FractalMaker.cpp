#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void drawTriangle(pair<float,float> &left, pair<float,float>, pair<float,float> &top, pair<float,float> &right, sf::RenderWindow &window){

}
void FractalMaker::kochSnowflake(int numRecursions) {
    cout << "Generating a koch snowflake with " << numRecursions << " recursions..." << endl;
}

void FractalMaker::hilbertCurve(int numRecursions) {
    cout << "Generating a hilbert curve with " << numRecursions << " recursions..." << endl;
}

void FractalMaker::sierpinskiTriangle(int numRecursions) {
    cout << "Generating a sierpinski triangle with " << numRecursions << " recursions..." << endl;
    sf::RenderWindow window(sf::VideoMode(512, 512), "My window");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        if (numRecursions == 1){
            sf::CircleShape triangle(256, 3);
            triangle.setPosition(0, 0);
            window.draw(triangle);
        } else if (numRecursions == 2){
            float x, y;
            sf::CircleShape triangle1(128, 3);
            x = 256-128;
            y= 0;
            triangle1.setPosition(x, y);
            sf::CircleShape triangle2(128, 3);
            x = 0;
            y = 256;
            triangle2.setPosition(x, y);
            sf::CircleShape triangle3(128, 3);
            x = 256;
            y= 256;
            triangle3.setPosition(x, y);

            window.draw(triangle1);
            window.draw(triangle2);
            window.draw(triangle3);
        }




        // end the current frame
        window.display();
    }

}

void FractalMaker::sierpinskiHelper(int numRecursions) {

}

void FractalMaker::hilbertHelper(int numRecursions) {

}

void FractalMaker::kochHelper(int numRecursions) {

}
