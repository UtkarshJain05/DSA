// Infix to Prefix -->  TC:O(N)  SC:O(2N).

#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    int i = 0;
    stack<char> st;
    string ans;

    // Step 1 -> reverse infix
    reverse(s.begin(), s.end());

    // Maintain order of Brackets
    for (auto &it : s)
    {
        if (it == '(')
            it = ')';
        else if (it == ')')
            it = '(';
    }

    // Step 2 -> Now Follow infix to Postfix with constraints.
    while (i < s.size())
    {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
            ans += s[i];

        else if (s[i] == '(')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }

    // left over Elements in st -> ans
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Step 3 -> Reverse ans.
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string exp = "(A-(B/C))*((A/K)-L)";
    cout << "Infix expression: " << exp << endl;
    cout << "Prefix expression: " << infixToPrefix(exp);
    return 0;
}