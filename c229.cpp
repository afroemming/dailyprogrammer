#include <cmath>
#include <iostream>

int main() { 
    double lastValue;
    std::cin >> lastValue;
    double lastDelta = 3;
    int iterations = 0;
    while (lastDelta > 0.000001) {
        lastDelta = fabs(lastValue - cos(lastValue));
        lastValue = cos(lastValue);
        iterations++;
    }
    std::cout << "Dottie: Converged to " <<lastValue << " in " << iterations << " iterations.\n";
}