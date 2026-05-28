// Prefix to Postfix -->  TC:O(2N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string prefix)
{
    int n = prefix.size();
    stack<string> st;
    int i = n - 1;
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
            st.push(t1 + t2 + c);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}