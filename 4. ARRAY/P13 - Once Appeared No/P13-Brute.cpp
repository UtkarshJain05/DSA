// Once Appeared Number.(Brute) --> TC - O(N^2) ; SC - O(1).

#include <bits/stdc++.h>
using namespace std;

int uniqueno(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {

            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return arr[i];
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 3, 4, 4};
    cout << uniqueno(arr);
}