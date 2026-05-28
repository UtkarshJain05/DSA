// Prefix to Infix -->  TC:O(2N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string prefix)
{
    int n = prefix.size();
    int i = n - 1;
    stack<string> st;
    while (i >= 0)
    {
        char c = prefix[i];
        if (isalnum(c))
            st.push(string(1, c));

        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t1 + c + t2 + ")");
        }

        i--;
    }
    return st.top();
}

int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}
