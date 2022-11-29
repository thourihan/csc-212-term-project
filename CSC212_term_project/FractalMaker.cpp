#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void FractalMaker::drawTriangle(pair<float, float> &left, pair<float, float> &top, pair<float, float> &right) {
    sf::ConvexShape shape;
    shape.setPointCount(3);
    // cast float pairs to Vector2f
    shape.setPoint(0, sf::Vector2f(left.first, left.second));
    shape.setPoint(1, sf::Vector2f(top.first, top.second));
    shape.setPoint(2, sf::Vector2f(right.first, right.second));
    window.draw(shape);
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

        if (numRecursions == 1){
            pair<float, float> left = {0, 512};
            pair<float, float> top = {256, 0};
            pair<float, float> right = {512, 512};
            drawTriangle(left, top, right);
        }

        // end the current frame
        window.display();
    }

}

void FractalMaker::sierpinskiHelper(int numRecursions) {

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

