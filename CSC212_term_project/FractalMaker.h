#ifndef CSC212_TERM_PROJECT_FRACTALMAKER_H
#define CSC212_TERM_PROJECT_FRACTALMAKER_H

#include <bits/stdc++.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>

using namespace std;

class FractalMaker {
public:
    sf::RenderWindow window{sf::VideoMode(512, 512), "Fractal Viewer"};
    void sierpinskiTriangle(int numRecursions);
    void hilbertCurve(int numRecursions);
    void kochSnowflake(int numRecursions);
private:
    void drawTriangle(pair<float, float> &left, pair<float, float> &top, pair<float, float> &right, sf::Color color, bool upsideDown, float xPos, float yPos);
    void sierpinskiHelper(int numRecursions);
    void hilbertHelper(int numRecursions);
    void kochHelper(int numRecursions);
    //float scaleFinder(int numRecursions);
};

#endif
