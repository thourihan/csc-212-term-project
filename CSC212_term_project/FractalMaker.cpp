#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


void FractalMaker::drawTriangle(sf::Color color, bool upsideDown, float scale, float xPos, float yPos) {
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
        triangle.setPosition(xPos, yPos);
        //triangle.setScale(scale, scale);
    }
    window.draw(triangle);
}

void FractalMaker::sierpinskiTriangle(int numRecursions) {
    cout << "Generating a sierpinski triangle with " << numRecursions << " recursions..." << endl;
    maxRecursions = numRecursions;
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

        window.clear(sf::Color(100, 100, 100));

        if (numRecursions >= 0){

            drawTriangle(sf::Color(30, 30, 30), false, 1, 0,0);
        }
        if (numRecursions >= 1){

            drawTriangle(sf::Color(255, 255, 255), true, 0.5, 384, 512);
        }
        if( numRecursions >= 2) {
            // Place left subtriangle
            sierpinskiHelper(2, 0.25, 192, 512);

            // Place top subtriangle
            sierpinskiHelper(2, 0.25, 320, 256);

            // Place right subtriangle
            sierpinskiHelper(2, 0.25, 448, 512);
        }

        // end the current frame
        window.display();
        //TODO render does not save after window has closed
        // saveImage();
    }

}


void FractalMaker::sierpinskiHelper(int numRecursions, float scale, float xPos, float yPos) {
    // Return if we have recursed enough
    if (numRecursions == maxRecursions){
        return;
    }
    // Draw triangle
    drawTriangle(sf::Color(255, 255, 255), true, scale, xPos, yPos);

    // Place left subtriangle
    float xPosLeft = xPos - 384 / pow(2, numRecursions);
    float yPosLeft = yPos;
    sierpinskiHelper(numRecursions+1, scale/2, xPosLeft, yPosLeft);


    // Place top subtriangle
    float xPosTop = xPos - 128 / pow(2, numRecursions);
    float yPosTop = yPos - 512 / pow(2, numRecursions);
    sierpinskiHelper(numRecursions+1, scale/2, xPosTop, yPosTop);

    // Place right subtriangle
    float xPosRight = xPos + 128 / pow(2, numRecursions);
    float yPosRight = yPos;
    sierpinskiHelper(numRecursions+1, scale/2, xPosRight, yPosRight);

}

void FractalMaker::kDrawTriangle(sf::Color color, bool leftR, bool rightR, float scale, float xPos, float yPos) {
    pair<float, float> left = {0, 512};
    pair<float, float> top = {256, 0};
    pair<float, float> right = {512, 512};
    //TODO before you judge tim read all my notes
    // some how make generating first triangle not static to these coordinates
    // cause intital triangle doesn't use set position and
    // will alaways take up screen unless we wanna keep my horrible kochsnowflake bool
    // bool for leftR rightR and koch snowflake are temp variables just wanted to try math


    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    // cast float pairs to Vector2f
    triangle.setPoint(0, sf::Vector2f(left.first, left.second));
    triangle.setPoint(1, sf::Vector2f(top.first, top.second));
    triangle.setPoint(2, sf::Vector2f(right.first, right.second));
    triangle.setFillColor(color);
    triangle.setScale(scale, scale);

    //TODO had to scale down triangle for koch snowflake so could see
    // bottom part found out have to offset all x coordinates by 64 to the right

    triangle.setPosition(xPos,yPos);

    //rotate triangle left not scalable yet
    if(leftR){
        triangle.rotate(270.f);

        triangle.setPosition(xPos,512);
    }
    //rotate triangle right not scalable yet
    if(rightR){
        triangle.rotate(90.f);

        triangle.setPosition(512,yPos);
    }

    window.draw(triangle);
}

void FractalMaker::kochSnowflake(int numRecursions) {
    cout << "Generating a koch snowflake with " << numRecursions << " recursions..." << endl;
    maxRecursions = numRecursions;
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
        window.clear(sf::Color(100, 100, 100));


        //base cases
        if (numRecursions >= 0){

            kDrawTriangle(sf::Color(255, 255, 255), false, false, 0.75, 64,0);
        }
        if (numRecursions >= 1){

            kDrawTriangle(sf::Color(255, 255, 255), false, false, 0.75, 448,512);
        }



        // end the current frame
        window.display();
        //TODO render does not save after window has closed
        // saveImage();
    }
}

void FractalMaker::hilbertCurve(int numRecursions) {
    cout << "Generating a hilbert curve with " << numRecursions << " recursions..." << endl;
}



void FractalMaker::hilbertHelper(int numRecursions) {

}

void FractalMaker::kochHelper(int numRecursions) {

}


void FractalMaker::saveImage() {
    //TODO render does not save after window has closed fix somehow
    sf::Texture texture;
    //RenderTexture rTexture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);

    if (texture.copyToImage().saveToFile(fileName))
    {
        std::cout << "screenshot saved to " << fileName << std::endl;

    }
}
