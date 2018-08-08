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
    std::cout << "Dottie: Converged to " << find_fixed_point(([](double x)->double{return cos(x);}), 3) << '\n';
    std::cout << "x-tan(X): Converged to " << find_fixed_point(([](double x)->double{return x-tan(x);}), 2) << '\n';
    std::cout << "1 + 1/x: Converged to " << find_fixed_point(([](double x)->double{return  1 + 1/x;}), 30) << '\n';
    std::cout << "4x(1-x): Converged to " << find_fixed_point(([](double x)->double{return  4*x*(1-x);}), 0.1) << '\n';
}