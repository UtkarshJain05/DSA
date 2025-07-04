// Brute --> Count unique Elements.

#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int arr[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int count = st.size();
    return count;
}

int main()
{
    int arr[10] = {1, 1, 1, 2, 2, 5, 5, 6, 6, 7};
    cout <<"Unique Elements = " << remove_duplicate(arr, 10) << endl;
}