#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function for I1
double f1(double x) {
    return (cos(x) * log(sin(x))) / (1 + sin(x));
}

// Function for I2
double f2(double x) {
    return tan(x);
}

// Romberg integration function
double romberg(double (*f)(double), double a, double b, int maxSteps, double epsilon) {
    double R[maxSteps][maxSteps] = {0};
    int n = 1; // Initial number of intervals
    R[0][0] = (b - a) * (f(a) + f(b)) / 2.0; // Trapezoidal rule

    for (int i = 1; i < maxSteps; ++i) {
        double h = (b - a) / n;
        double sum = ;

        // Calculate the sum of function values at midpoints
        for (int k = 1; k <= n; ++k) {
            sum += f(a + (k - 0.5) * h);
        }

        // Refine the estimate using Simpson's rule
        R[i][0] = 0.5 * R[i - 1][0] + h * sum;

        // Apply Richardson extrapolation
        for (int j = 1; j <= i; ++j) {
            R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }

        n *= 2; // Double the number of intervals

        // Check for convergence
        if (i > 1 && fabs(R[i][i] - R[i - 1][i - 1]) < epsilon) {
            return R[i][i];
        }
    }

    return R[maxSteps - 1][maxSteps - 1];
}

int main() {
    cout << fixed << setprecision(10);

    // Integral I1
    double I1 = romberg(f1, M_PI / 4, M_PI / 2, 10, 1e-8);
    cout << "I1 = " << I1 << endl;

    // Integral I2
    // Handle singularities for tan(x) using sub-intervals
    double I2_part1 = romberg(f2, 0, M_PI / 2 - 1e-5, 10, 1e-8);
    double I2_part2 = romberg(f2, M_PI / 2 + 1e-5, 3 * M_PI / 2 - 1e-5, 10, 1e-8);
    double I2 = I2_part1 + I2_part2;

    cout << "I2 = " << I2 << endl;

    return 0;
}