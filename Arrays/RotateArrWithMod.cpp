#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &v, int k)
{
    int size = v.size();
    vector<int> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp[(i + k) % size] = v[i];
    }
    v = temp;
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
    rotate(v, m);
    cout << "Rotated Arr    : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}