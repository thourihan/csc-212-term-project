#ifndef CSC212_TERM_PROJECT_FRACTALMAKER_H
#define CSC212_TERM_PROJECT_FRACTALMAKER_H

#include <bits/stdc++.h>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

class FractalMaker {
public:
    sf::RenderWindow window{sf::VideoMode(512, 512), "Fractal Viewer"};
    void sierpinskiTriangle(int numRecursions);
    void hilbertCurve(int numRecursions);
    void kochSnowflake(int numRecursions);
    int maxRecursions;

private:
    void drawTriangle(sf::Color color, bool upsideDown, float scale, float xPos, float yPos);
    void kDrawTriangle(sf::Color color, bool leftR, bool rightR,float scale, float xpos, float ypos);
    void sierpinskiHelper(int numRecursions, float scale, float xPos, float yPos);
    void hilbertHelper(int numRecursions);
    void kochHelper(int numRecursions);
    void saveImage();
    string fileName = "output.png";
};

#endif
