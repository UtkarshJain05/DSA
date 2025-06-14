// Prime Number sqrt(n) Approach.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    if (n == 1)
        cout << "neither.";
    else
    {
        for (int i = 1; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                cnt++;
            }
        }
        if (cnt == 1)
            cout << "No. is Prime.";
        else
        {
            cout << "Composite.";
        }
    }
}