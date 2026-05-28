// Postfix to Prefix -->  TC:O(2N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string postfix)
{
    int i = 0;
    stack<string> st;
    while (i < postfix.size())
    {
        char c = postfix[i];
        if (isalnum(c))
            st.push(string(1, c));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(c + t2 + t1);
        }

        i++;
    }
    return st.top();
}

int main()
{
    string postfix = "ABC/-AK/L-*";
    cout << "postfix Expression: " << postfix << endl;
    cout << "prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}