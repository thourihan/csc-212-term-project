#ifndef CSC212_TERM_PROJECT_FRACTALMAKER_H
#define CSC212_TERM_PROJECT_FRACTALMAKER_H

#include <bits/stdc++.h>

using namespace std;

class FractalMaker {
public:
    void sierpinskiTriangle(int numRecursions);
    void hilbertCurve(int numRecursions);
    void kochSnowflake(int numRecursions);
private:
    void sierpinskiHelper(int numRecursions);
    void hilbertHelper(int numRecursions);
    void kochHelper(int numRecursions);
};

#endif
