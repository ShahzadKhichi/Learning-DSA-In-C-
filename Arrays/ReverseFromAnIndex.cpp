#include <iostream>
#include <vector>
using namespace std;
void RevserArray(vector<int> &v, int n, int m)
{
    int s = m + 1, e = n - 1;
    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
}
int main()
{
    int n, m;
    cout << "Enter Size : ";
    cin >> n;
    cout << "Enter Index : ";
    cin >> m;
    vector<int> v(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    RevserArray(v, n, m);
    cout << "Reverse Arr    : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}