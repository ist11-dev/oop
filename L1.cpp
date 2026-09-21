#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class a {
private:
    double x;
    double y;
    double z;
    double b;

public:
    a(double x, double y, double z, double b)
        : x(x), y(y), z(z), b(b) {
    }

    double calculate() {
        return pow(1 + y, 2) *
            ((pow(fabs(x + y), 0.3) / pow(b, 2) + z) /
                (1 + exp(-(x - z)) + pow(fabs(y), 0.43)));
    }
};

class b {
private:
    double x;
    double y;
    double z;

public:
    b(double x, double y, double z)
        : x(x), y(y), z(z) {
    }

    double calculate() {
        return x * ((y + atan(pow(fabs(x * x + z), 0.1))) /
            (2 * z + x + pow(sin(pow(y, 3)), 2)) +
            exp((x + z) / (z + 1)));
    }
};

int main() {

    cout << "1:" << endl;
    double x = 0.48 * 10;
    double y = 0.47 * 10;
    double z = -1.32 * 10;

    b objectB(x, y, z);
    double valueB = objectB.calculate();

    a objectA(x, y, z, valueB);
    double valueA = objectA.calculate();

    cout << "b = " << valueB << endl;
    cout << "a = " << valueA << endl;

    cout << endl;

    cout << "2:" << endl;
    for (x = -1; x <= 1; x += 0.2) {

        b objectB(x, y, z);
        double valueB = objectB.calculate();

        a objectA(x, y, z, valueB);
        double valueA = objectA.calculate();

        cout << setw(14) << "x = " << x << setw(14) << "b = " << valueB << setw(14) << "a = " << valueA << endl;

    }

    return 0;
}