#include "FractalMaker.h"


char getFractal();

int getNumRecursions();




int main() {
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
    string numRecursions;
    cout << "Please indicate how many recursions you want." << endl;
    cout << "Valid range: 0 - 10" << endl;

    while (std::cin >> numRecursions){
        //cin >> numRecursions;
        try{
            // correctSelection = true;
            if(stoi(numRecursions) >= 0 && stoi(numRecursions) <= 11){
                break;
            }else{
                stoi("f");
            }

        } catch(...){
            cout << "Error: Input was not valid. Please enter an integer between 1 and 10." << endl;
        }

    }

    return stoi(numRecursions);
}
