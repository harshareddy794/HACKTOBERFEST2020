#include <iostream>
using namespace std;

int main()
{
    float x1, y1, x2, y2, x3, y3;
    cout << "x1 : "; cin >> x1;

    cout << "y1 : "; cin >> y1;

    cout << "x2 : "; cin >> x2;

    cout << "y2 : "; cin >> y2;

    cout << "x3 : "; cin >> x3;

    cout << "y3 : "; cin >> y3;

    cout << "Centroid is : (" << (x1 + x2 + x3) / 3 << "," << (y1 + y2 + y3) / 3 << ")" << endl;

    return 0;
}