
#include <iostream>

#include <cmath>

// Function to be integrated
double f(double x) {
    return  log(x); // Change this function to the one you want to integrate
}

// Trapezoidal rule for numerical integration
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower limit (a): ";
    std::cin >> a;
    std::cout << "Enter the upper limit (b): ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of subintervals (n) must be greater than 0." << std::endl;
        return 1;
    }

    double result = trapezoidalRule(a, b, n);

    std::cout << "Approximate integral: " << result << std::endl;

    return 0;
}
