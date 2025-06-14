// Maps Introduction --> Key - Value pair.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 1st is key & 2nd is Value.
    map<int, int> m;
    map<int, pair<int, int>> mp;
    map<pair<int, int>, int> map;

    m[2] = 3;         // Key = 2, Value = 3.
    m.insert({1, 2}); // key = 1, Value = 2.
    // Keys are stored in Ascending Order.

    mp[3] = {2, 1};         // Key = 3, value = {2, 1}.
    mp.insert({2, {3, 4}}); // Ket = 2, Value = {3,4}.

    cout << mp[1].first << endl; // Key 1 is not there so value = 0.)

    map[{2, 3}] = 3;         // ket = {2,3}, Value = 3.
    map.insert({{1, 2}, 7}); // Key = {1,2} = 7.

    
    // Printing m
    cout << "\nm : \n";
    for (auto it : m)
    {
        cout << it.first << " --> " << it.second << endl;
    }

    // printing mp
    cout << "\nmp : \n";
    for (auto it : mp)
    {
        cout << it.first << " --> " << it.second.first << "," << it.second.second << endl;
    }

    // Printing map
    cout << "\nmap : \n";
    for (auto it : map)
    {
        cout << it.first.first << "," << it.first.second << " --> " << it.second << endl;
    }
    cout << endl;


    // Printing Single Element of m.
    cout << "m : " << m[1] << endl;

    auto i = m.find(2);
    cout << "m : " << (*i).second << endl;
    
    // Printing Single Element of mp.
    cout << "mp : " << mp[3].second << endl;

    auto it = mp.find(2);
    cout << "mp : " << (*it).second.first << "," << (*it).second.second << endl;

    // Printing Single Element of map.
    auto itt = map.find({2, 3});
    cout << "map : " << (*itt).second;
}