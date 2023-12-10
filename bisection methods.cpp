#include <iostream>
#include <cmath>

using namespace std;

// Function to find the root
double func(double x) {
    return x * x * x - 2 * x - 5; // You can replace this with your own function
}

// Bisection method with a fixed number of iterations
double bisection(double a, double b, int maxIterations) {
    if (func(a) * func(b) >= 0) {
        cout << "Bisection method may not converge with the given interval." << endl;
        return 0;
    }

    double c;
    for (int i = 0; i < maxIterations; ++i) {
        // Find midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root
        if (func(c) == 0.0)
            break;

        // Update the interval [a, b] based on the sign of the function at c
        if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double a, b;
    int maxIterations;
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    double root = bisection(a, b, maxIterations);

    if (root != 0) {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}
