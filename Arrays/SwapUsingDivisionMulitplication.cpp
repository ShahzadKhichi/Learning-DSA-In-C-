#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    if (b == 0)
    {
        b = a;
        a = 0;
    }
    else if (a == 0)
    {
        a = b;
        b = 0;
    }
    a = a * b;
    b = a / b;
    a = a / b;
    cout << "Swaped        : " << a << " " << b << endl;
    return 0;
}