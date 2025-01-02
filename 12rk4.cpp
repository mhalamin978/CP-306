#include <iostream>
#include <cmath>
using namespace std;

// Function f1: Na decay
double f1(double Na, double ta) {
    return Na / ta; // Ensure ta > 0
}

// Function f2: Coupled equation
double f2(double Na, double Nb, double factor) {
    double ta = factor;
    double tb = 1.0;
    return (Nb / ta) - (Na / tb); // Ensure tb > 0
}

// Runge-Kutta 2nd Order Method
void rk2(double factor, double Na, double Nb, int n, double h) {
    double k1, k2, l1, l2;

    for (int i = 0; i < n; i++) {
        // Compute Runge-Kutta terms
        k1 = h * f1(Na, factor);
        k2 = h * f1(Na + k1 / 2, factor);

        l1 = h * f2(Na, Nb, factor);
        l2 = h * f2(Na + k1 / 2, Nb + l1 / 2, factor);

        // Update Na and Nb
        Na += k2;
        Nb += l2;

        // Print updated values
        cout << "Step " << i + 1 << ": Na = " << Na << ", Nb = " << Nb << endl;
    }
}

int main() {
    // Initial conditions
    double Na = 0.1;
    double Nb = 0.0;
    double factor = 1.0 / 20.0; // Ensure floating-point division
    int n = 100;           // Number of RK2 n
    double h = 0.1;           // Time step

    // Perform RK2 integration
    rk2(factor, Na, Nb, n, h);

    return 0;
}
