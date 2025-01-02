#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
ofstream fout("15rk4.dat");

// f1 is for dx/dt
double f1(double x, double t, double v) {
    return v;
}

// f2 is for dv/dt
double f2(double x, double t, double v) {
    return -(9.8 / 10) * x + 2 * cos(x) * sin(5 * t);
}

// RK4 method
void rk4(double x, double v, double N, double h) {
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;

    for (double t = 0; t <= N; t += h) {
        // Calculate RK4 increments
        k1 = h * f1(x, t, v);
        l1 = h * f2(x, t, v);

        k2 = h * f1(x + k1 / 2, t + h / 2, v + l1 / 2);
        l2 = h * f2(x + k1 / 2, t + h / 2, v + l1 / 2);

        k3 = h * f1(x + k2 / 2, t + h / 2, v + l2 / 2);
        l3 = h * f2(x + k2 / 2, t + h / 2, v + l2 / 2);

        k4 = h * f1(x + k3, t + h, v + l3);
        l4 = h * f2(x + k3, t + h, v + l3);

        // Update x and v
        x += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        v += (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;

        // Write results to file
        fout << t << "    " << x << "    " << v << endl;
    }
}

int main() {
    rk4(5, 10,100 , 0.01);
    return 0;
}
