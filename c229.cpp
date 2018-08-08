#include <cmath>
#include <iostream>
#include <functional>

double find_fixed_point(std::function<double(double)> f, double startValue) {
    double lastDelta = 3;
    double lastValue = startValue;
    while (lastDelta > 0.0000001) {
        lastDelta = fabs(lastValue - f(lastValue));
        lastValue = f(lastValue);
    }
    return lastValue;
}

int main() { 
    double lastValue;
    std::cin >> lastValue;
    std::cout << "Dottie: Converged to " << find_fixed_point(([](double x)->double{return cos(x);}), 3) << '\n';
}