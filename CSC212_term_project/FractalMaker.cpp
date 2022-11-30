#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Texture texture;
void FractalMaker::drawTriangle(sf::Color color, bool upsideDown,float scale, float xpos, float ypos) {
    pair<float, float> left = {0, 512};
    pair<float, float> top = {256, 0};
    pair<float, float> right = {512, 512};

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    // cast float pairs to Vector2f
    triangle.setPoint(0, sf::Vector2f(left.first, left.second));
    triangle.setPoint(1, sf::Vector2f(top.first, top.second));
    triangle.setPoint(2, sf::Vector2f(right.first, right.second));
    triangle.setFillColor(color);
    triangle.setScale(scale, scale);

    if (upsideDown){

        triangle.rotate(180.f);
        // 384 = 512 - 128 aka 3/4 of the way
        triangle.setPosition(xpos, ypos);
        //triangle.setScale(scale, scale);
    }
    window.draw(triangle);
}

void FractalMaker::sierpinskiTriangle(int numRecursions) {
    cout << "Generating a sierpinski triangle with " << numRecursions << " recursions..." << endl;

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

        if (numRecursions >= 0){

            drawTriangle(sf::Color(255, 255, 255), false, 1, 0,0);
        }
        if (numRecursions >= 1){

            drawTriangle(sf::Color(255, 0, 0), true, 0.5, 384, 512);
        }
        if( numRecursions >= 2){

            //get right triangle coordinate by taking 384 + 64 to get 448
            //get left triangle coordinate for x by taking 256 - 64 or 384 -128
            //get middle triangle coordinate for x by taking 384 - 64 get triangle coordinate for y by taking previous iteration and divide half
            drawTriangle(sf::Color(0, 255, 0), true, 0.25, 448, 512);
            drawTriangle(sf::Color(0, 255, 0), true, 0.25, 192, 512);
            drawTriangle(sf::Color(0, 255, 0), true, 0.25, 320, 256);
        }

        if( numRecursions >= 3){
            //get right triangle coordinate
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 480, 512);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 352, 512);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 416, 384);

            // 192 + 32 = 224  right right
            // 192/2 = 96 left left
            // 320 / 2 = 160 top top
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 224, 512);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 96, 512);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 160, 384);

            drawTriangle( sf::Color(0, 0, 255), true, 0.125, 288, 128);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 224, 256);
            drawTriangle(sf::Color(0, 0, 255), true, 0.125, 352, 256);


        }



        // end the current frame
        window.display();
        //code to save png file of result
        texture.create(window.getSize().x, window.getSize().y);
        texture.update(window);
        if (texture.copyToImage().saveToFile("output.png")){
            std::cout << "screenshot saved to " << "output.png" << std::endl;
            break;
        }
    }

}


void FractalMaker::sierpinskiHelper(int numRecursions) {
    // base case
    if (numRecursions <= 2){
        return;
    }
    // draw 3 upside down triangles
    pair<float, float> left = {0, 512};
    pair<float, float> top = {256, 0};
    pair<float, float> right = {512, 512};

    cout << "Drawing...";
    drawTriangle(sf::Color(0, 255, 0), true, 0.25, 448, 512);
    drawTriangle(sf::Color(0, 255, 0), true, 0.25, 192, 512);
    drawTriangle(sf::Color(0, 255, 0), true, 0.25, 320, 256);

    // recurse
    sierpinskiTriangle(numRecursions-1);
}


void FractalMaker::kochSnowflake(int numRecursions) {
    cout << "Generating a koch snowflake with " << numRecursions << " recursions..." << endl;
}

void FractalMaker::hilbertCurve(int numRecursions) {
    cout << "Generating a hilbert curve with " << numRecursions << " recursions..." << endl;
}



void FractalMaker::hilbertHelper(int numRecursions) {

}

void FractalMaker::kochHelper(int numRecursions) {

}
