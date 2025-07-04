// Pascal Triangle - Particular Element (Brute).   TC : O(n+(n-r)+r)     SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int combi(int n, int r)
{
    int ans = 1;
    ans = fact(n) / (fact(n - r) * fact(r));
    return ans;
}

int pascal(int row, int col)
{
    int ans = combi(row - 1, col - 1);
    return ans;
}

int main()
{
    int row, col;
    cin >> row >> col;
    cout << pascal(row, col);
}