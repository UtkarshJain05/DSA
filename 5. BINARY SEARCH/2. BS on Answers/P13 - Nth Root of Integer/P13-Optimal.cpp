// Nth Root of a Number. --> TC: O(log(n) * r)  SC : O(1).

#include <bits/stdc++.h>
using namespace std;

int power(int x, int n, int r)
{
    long long val = 1;
    for (int i = 1; i <= r; i++)
    {
        val *= x;
        if (val > n)
            return 2;
    }
    if (val == n)
        return 1;
    return 0;
}

int fnc(int n, int r)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = power(mid, n, r);
        if (val == 1)
            return mid;

        else if (val == 0)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, r;
    cout << "Enter Number & Nth Root : ";
    cin >> n >> r;
    cout << fnc(n, r);
}