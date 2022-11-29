#ifndef CSC212_TERM_PROJECT_FRACTALMAKER_H
#define CSC212_TERM_PROJECT_FRACTALMAKER_H

#include <bits/stdc++.h>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

class FractalMaker {
public:
    sf::RenderWindow window;
    FractalMaker();
    void sierpinskiTriangle(int numRecursions);
    void hilbertCurve(int numRecursions);
    void kochSnowflake(int numRecursions);
private:
    void drawTriangle(pair<float, float> &left, pair<float, float> &top, pair<float, float> &right, sf::RenderWindow &window);
    void sierpinskiHelper(int numRecursions);
    void hilbertHelper(int numRecursions);
    void kochHelper(int numRecursions);
};

#endif
