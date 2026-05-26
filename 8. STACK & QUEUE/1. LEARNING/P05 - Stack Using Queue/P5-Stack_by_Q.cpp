// Stack Using Queue. -> TC:O(N)  SC:O(D)  {D -> Dynamic.}

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    queue<int> q;

    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for(int i = 1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Already Empty!\n";
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack Is Empty!";
            return -1;
        }
        return q.front();
    }

    int size()
    {
        return q.size();
    }
};

int main()
{
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl;
}