#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a;
    double b;
    double c;
    double x;
    cin >> a;
    cin >> b;
    cin >> c;
    if ((b * b - 4 * a * c) >= 0) {
        x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << x << endl;
        x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << x << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}