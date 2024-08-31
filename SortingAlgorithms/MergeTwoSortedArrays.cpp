#include <iostream>
#include <vector>
using namespace std;
vector<int> MergeTwo(vector<int> &v1, int n, vector<int> &v2, int m)
{
    vector<int> v3(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (v1[i] <= v2[j])
        {
            v3[k++] = v1[i++];
        }
        else if (v1[i] >= v2[j])
        {
            v3[k++] = v2[j++];
        }
    }
    while (i < n)
    {
        v3[k++] = v1[i++];
    }
    while (j < m)
    {
        v3[k++] = v2[j++];
    }

    return v3;
}
int main()
{
    int n;
    cout << "Enter Size 1 : ";
    cin >> n;
    vector<int> v1(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    int m;
    cout << "Enter Size 2 : ";
    cin >> m;
    vector<int> v2(m);
    cout << "Enter Elements : ";
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    vector<int> v3 = MergeTwo(v1, n, v2, m);
    cout << "Merged Arr     : ";
    for (int i = 0; i < n + m; i++)
    {
        cout << v3[i] << " ";
    }
    return 0;
}