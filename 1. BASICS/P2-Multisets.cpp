// Multisets Introduction --> Sorted But not Unique.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> ms;
    ms.insert(3);
    ms.emplace(5);
    ms.emplace(4);
    ms.emplace(6);
    ms.emplace(6);
    ms.insert(3);
    ms.insert(5);
    ms.insert(7);

    // Set Looks Like :
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    ms.erase(3); // Removed All 3's.
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    ms.erase(ms.find(6)); // Removed Only one '6'.
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    ms.erase(ms.find(4), ms.find(6)); // Remove 4 to 6.
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
}