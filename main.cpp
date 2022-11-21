#include "FractalMaker.h"

char getFractal();

int getRecursions();

int main() {
    char fractal = getFractal();
    int numRecursions = getRecursions();
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
    return fractal;
}

// Asks user to indicate how many recursions they would like to see.
// Continue to loop until they select a valid integer, and then return it.
int getRecursions(){
    bool correctSelection = false;
    int recursions;
    cout << "Please indicate how many recursions you want." << endl;
    cout << "Valid range: 1 - 99" << endl;

    while (!correctSelection){
        cin >> recursions;
        if (recursions >= 1 && recursions <= 99) {
            correctSelection = true;
        } else{
            cout << "Error: Input was not valid. Please enter an integer between 1 and 99." << endl;
        }
    }

    return recursions;
}
