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

    triangle.setPosition(xPos, yPos);

    if (upsideDown){
        triangle.rotate(180.f);
    }
    window.draw(triangle);
}

/* ---------------------
   SIERPINSKI TRIANGLE
   --------------------*/

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

/* --------------------
     KOCH SNOWFLAKE
   -------------------*/

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
            drawTriangle(sf::Color(255, 255, 255), false, 0.75, 64, 0);
        }
        if (numRecursions >= 1){
            kochHelper(0, 0.75, 448, 512, true);
        }

        // end the current frame
        window.display();
        //TODO render does not save after window has closed
        // saveImage();
    }
}

void FractalMaker::kochHelper(int numRecursions, float scale, float xPos, float yPos, bool upsideDown) {
    // Return if we have recursed enough
    if (numRecursions == maxRecursions){
        return;
    }

    // Draw triangle
    //drawTriangle(sf::Color(255, 255, 255), upsideDown, scale, xPos, yPos);

    if (numRecursions==0){
        drawTriangle(sf::Color(255, 150, 200), upsideDown, scale, xPos, yPos);
    }else if (numRecursions==1){
        drawTriangle(sf::Color(150, 255, 200), upsideDown, scale, xPos, yPos);
    }else {
        drawTriangle(sf::Color(150, 150, 255), upsideDown, scale, xPos, yPos);
    }

    float xPosNew;
    float yPosNew;
    // Draw set 1 of 3 subtriangles
    // UPPER LEFT

    xPosNew = 64 - pow(2, numRecursions+1)+4;
    // n = 2, 72        64 + 32/pow(2,numRecursions);
    // 85
    yPosNew = 85;
    //yPos/8 + pow(8, numRecursions+1);

    kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, false);
    // UPPER RIGHT
     //512 - 128 - 64; = 304 + pow(2,numRecursions+1)+4; = 316 for n = 2
     //                = 392 + pow( 2, numRecursions +1)+4 = 404 for n = 3
                      //  = 480 + pow (2 numRecursions + 1) + 4 = 512 for n = 4
     xPosNew = 492;
    yPosNew = 85;
    kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, false);
    // DOWN
    xPosNew = 256 - 64;
    yPosNew = 256 + 64 + 16;
    //kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, false);


    // Draw set 2 of 3 subtriangles
    // UP
    xPosNew = 256 + 64;
    yPosNew = 256 - 64 - 16;
    //kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, upsideDown);
    // LOWER LEFT
    xPosNew = 128 + 64;
    yPosNew = 256 + 128 + 32;
    //kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, upsideDown);
    // LOWER RIGHT
    xPosNew = 512 - 64;
    yPosNew = 256 + 128 + 32;
    //kochHelper(numRecursions+1, scale/3, xPosNew, yPosNew, upsideDown);
}

void FractalMaker::hilbertCurve(int numRecursions) {
    cout << "Generating a hilbert curve with " << numRecursions << " recursions..." << endl;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0, 0, 0));

        float length = 480/(pow(2, numRecursions) - 1);
        float xPos = 16;
        float yPos = 496;
        int direction = 0;
        if (numRecursions == 1) {
            drawArc(xPos, yPos, length, direction);
        }
        if (numRecursions > 1) {
            hilbertHelper(numRecursions, xPos, yPos, length, direction, numRecursions);
        }

        // end the current frame
        window.display();
    }
}

void FractalMaker::drawArc(float &xPos, float &yPos, float length, int &direction){
    if(direction == 0) {
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(xPos, yPos)),
                        sf::Vertex(sf::Vector2f(xPos, yPos - length)),
                };
        xPos += length;
        window.draw(line, 6, sf::Lines);
    }
    else if(direction == 90 || direction == -270) {
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(xPos, yPos)),
                        sf::Vertex(sf::Vector2f(xPos + length, yPos)),
                };
        yPos -= length;
        window.draw(line, 6, sf::Lines);
    }
    else if(direction == 270 || direction == -90){
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(xPos, yPos)),
                        sf::Vertex(sf::Vector2f(xPos - length, yPos)),
                };
        yPos += length;
        window.draw(line, 6, sf::Lines);
    }
    else{
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(xPos, yPos)),
                        sf::Vertex(sf::Vector2f(xPos, yPos + length)),
                };
        xPos -= length;
        window.draw(line, 6, sf::Lines);
    }
}

void FractalMaker::hilbertHelper(float &xPos, float &yPos, float length, int &direction, int i) {
    if(i == 1) {
        return;
    }
    hilbertHelper(i, xPos, yPos, length, direction, i-1);
    direction = ((direction + 90) % 360);
    if(i == 2) {
        drawArc(xPos, yPos, length, direction);
    }
    sf::Vertex line1[] =
            {sf::Vertex(sf::Vector2f(xPos, yPos)),
             sf::Vertex(sf::Vector2f(xPos, yPos - length)),};
            yPos -= length;
    window.draw(line1, 6, sf::Lines);
    hilbertHelper(i, xPos, yPos, length, direction, i-1);
    direction = ((direction - 90) % 360);
    if(i == 2) {
        drawArc(xPos, yPos, length, direction);
    }
    sf::Vertex line2[] =
            {sf::Vertex(sf::Vector2f(xPos, yPos)),
             sf::Vertex(sf::Vector2f(xPos + length, yPos)),};
            xPos += length;
    window.draw(line2, 6, sf::Lines);
    hilbertHelper(i, xPos, yPos, length, direction, i-1);
    if(i == 2) {
        drawArc(xPos, yPos, length, direction);
    }
    sf::Vertex line3[] =
            {sf::Vertex(sf::Vector2f(xPos, yPos)),
             sf::Vertex(sf::Vector2f(xPos, yPos + length)),};
            yPos += length;
    window.draw(line3, 6, sf::Lines);
    hilbertHelper(i, xPos, yPos, length, direction, i-1);
    direction = ((direction - 90) % 360);
    drawArc(xPos, yPos, length, direction);
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
