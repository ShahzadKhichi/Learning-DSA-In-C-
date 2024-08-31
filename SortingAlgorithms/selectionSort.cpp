#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &v, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        swap(v[i], v[min]);
    }
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
    selectionSort(v, n);
    cout << "Sorted Arr     : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}