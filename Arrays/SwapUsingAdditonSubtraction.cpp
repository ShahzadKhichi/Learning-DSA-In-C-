#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Swaped        : " << a << " " << b << endl;
    return 0;
}