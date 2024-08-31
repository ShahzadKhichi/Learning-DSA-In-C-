#include <iostream>
#include <vector>
using namespace std;
bool rotate(vector<int> &v)
{
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            count++;
        }
    }
    if (v[v.size() - 1] > v[0])
        count++;
    return count <= 1;
}
int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << rotate(v) << endl;
    return 0;
}