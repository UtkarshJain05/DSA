// Vectors Introduction.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Vector : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "v[3] = " << v[3] << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    v.emplace_back(5);
    for (auto i = v.begin(); i < v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    v.insert(v.begin(), 2, 200);
    vector<int> copy = {5, 6, 7, 8, 9};
    v.insert(v.end(), copy.begin() + 1, copy.end() - 1);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    v.clear();
    for (auto it : v)
    {
        cout << it << " ";
    }
    // This Loop will not Work as v is empty now.

    cout << "Is vector Empty : " << v.empty() << endl;
    cout << "Size of vector : " << v.size() << endl;
}