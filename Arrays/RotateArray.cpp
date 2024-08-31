#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &v, int k)
{
    int size = v.size();
    int s = size - k;
    vector<int> last(k);
    for (int i = 0; i < k; i++)
    {
        last[i] = v[size - 1];
        size--;
    }
    size = v.size();
    vector<int> first(size - k);
    for (int i = 0; i < s; i++)
    {
        first[i] = v[i];
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i < k)
        {
            v[i] = last[i];
        }
        else
        {
            v[i] = first[j];
            j++;
        }
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
    rotate(v, m);
    cout << "Reverse Arr    : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}