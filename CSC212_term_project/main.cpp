#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

char getFractal();

int getNumRecursions();

int main() {

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

        sf::Vertex line[] =
                {       //connects two coordinates
                        sf::Vertex(sf::Vector2f(0.f, 512.f)),
                        sf::Vertex(sf::Vector2f(256.f, 0.f))
                };

        window.clear(sf::Color::Black);
        window.draw(line, 2, sf::Lines);

        // end the current frame
        window.display();
    }

    char fractal = getFractal();
    int numRecursions = getNumRecursions();

    FractalMaker fractalMaker;

    if (fractal == 's'){
        fractalMaker.sierpinskiTriangle(numRecursions);
    } else if (fractal == 'h'){
        fractalMaker.hilbertCurve(numRecursions);
    } else if (fractal == 'k'){
        fractalMaker.kochSnowflake(numRecursions);
    }

}

// Asks user to indicate which fractal they would like to produce.
// Continue to loop until they select a valid fractal, then return that fractal as a char.
char getFractal(){
    bool correctSelection = false;
    cout << "Please indicate which fractal you would like to produce." << endl;
    char fractal;

    while (!correctSelection){
        cout << "Options: [S]ierpinski Triangle, [H]ilbert Curve, [K]och Snowflake" << endl;
        cin >> fractal;

        if (toupper(fractal) == 'S'){
            correctSelection = true;
            cout << "Selected fractal: Sierpinski Triangle" << endl;
        } else if (toupper(fractal) == 'H'){
            correctSelection = true;
            cout << "Selected fractal: Hilbert Curve" << endl;
        } else if (toupper(fractal) == 'K'){
            correctSelection = true;
            cout << "Selected fractal: Koch Snowflake" << endl;
        } else{
            cout << "Error: Input was not valid. Please enter S, H, or K." << endl;
        }
    }
    return tolower(fractal);
}

// Asks user to indicate how many recursions they would like to see.
// Continue to loop until they select a valid integer, and then return it.
int getNumRecursions(){
    bool correctSelection = false;
    int numRecursions;
    cout << "Please indicate how many recursions you want." << endl;
    cout << "Valid range: 1 - 99" << endl;

    while (!correctSelection){
        cin >> numRecursions;
        if (numRecursions >= 1 && numRecursions <= 99) {
            correctSelection = true;
        } else{
            cout << "Error: Input was not valid. Please enter an integer between 1 and 99." << endl;
        }
    }

    return numRecursions;
}
