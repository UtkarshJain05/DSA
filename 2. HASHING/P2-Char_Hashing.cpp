// CHARACTER HASHING

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    int y = 'a';

    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int z = s[i];
        hash[z - y]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        int w = c;
        cout << hash[w - y];
    }
}
