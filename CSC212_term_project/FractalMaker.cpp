#include "FractalMaker.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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
            sf::Vertex line1[] =
                    {
                            sf::Vertex(sf::Vector2f(0.f, 512.f)),
                            sf::Vertex(sf::Vector2f(256.f, 0.f))
                    };

            sf::Vertex line2[] =
                    {
                            sf::Vertex(sf::Vector2f(256.f, 0.f)),
                            sf::Vertex(sf::Vector2f(512.f, 512.f))
                    };

            sf::Vertex line3[] =
                    {
                            sf::Vertex(sf::Vector2f(0.f, 512.f)),
                            sf::Vertex(sf::Vector2f(512.f, 512.f))
                    };

            window.draw(line1, 2, sf::Lines);
            window.draw(line2, 2, sf::Lines);
            window.draw(line3, 2, sf::Lines);
        }




        // end the current frame
        window.display();
    }

}

