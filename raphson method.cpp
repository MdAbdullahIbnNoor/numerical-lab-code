#include <iostream>
#include <cmath>

using namespace std;

// Function to find the root
double func(double x) {
    return x * x * x - 2* x - 5; // You can replace this with your own function
}

// Derivative of the function
double func_derivative(double x) {
    return 3 * x * x - 2; // You need to compute the derivative of your function
}

// Newton-Raphson method
double newtonRaphson(double x, int maxIterations) {
    //double x = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double f = func(x);
        double f_prime = func_derivative(x);

        if (f_prime == 0) {
            cout << "Derivative is zero. Newton-Raphson method cannot converge." << endl;
            return 0;
        }

        double delta_x = f / f_prime;
        x = x - delta_x;

        if (abs(delta_x) < 1e-6) { // You can change the convergence criteria as needed
            return x;
        }
    }

    cout << "Newton-Raphson method did not converge within " << maxIterations << " iterations." << endl;
    return 0;
}

int main() {
    double initialGuess;
    int maxIterations;
    cout << "Enter the initial guess: ";
    cin >> initialGuess;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    double root = newtonRaphson(initialGuess, maxIterations);

    if (root != 0) {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}
