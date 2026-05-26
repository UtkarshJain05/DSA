// Balanced Paranthesis -> TC:O(N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int n = s.size();
    stack<char> st;
    for (char it : s)
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.empty())
                return false;

            if ((it == ')' && st.top() == '(') ||
                (it == '}' && st.top() == '{') ||
                (it == ']' && st.top() == '['))
                st.pop();

            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{}()]";

    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}