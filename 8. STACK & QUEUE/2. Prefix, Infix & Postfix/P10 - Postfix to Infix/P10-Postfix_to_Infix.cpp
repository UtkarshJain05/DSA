// Postfix to Infix -->  TC:O(2N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s)
{
    int i = 0;
    stack<string> st;
    while (i < s.size())
    {
        if (isalnum(s[i]))
            st.push(string(1,s[i]));

        else
        {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push("(" + t2 + s[i] + t1 + ")");
        }
        i++;
    }
    return st.top();
}

int main()
{
    string postfix = "AB*C+";
    cout << "Postfix expression: " << postfix << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
