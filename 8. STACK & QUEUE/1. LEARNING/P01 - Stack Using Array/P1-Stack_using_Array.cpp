#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int idx = -1;
    int st[10];

    void push(int x)
    {
        if (idx >= 9)
        {
            cout << "Stack Overflow.\n";
            return;
        }
        idx++;
        st[idx] = x;
    }

    void pop()
    {
        if (idx == -1)
        {
            cout << "Stack Already Empty.\n";
            return;
        }
        idx--;
    }

    int top()
    {
        if (idx == -1)
        {
            cout << "Stack Empty.\n";
            return 0;
        }
        return st[idx];
    }

    int size()
    {
        return idx + 1;
    }
};

int main()
{
    Stack s;
    s.pop();
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.push(5);
    s.pop();
    cout << s.size();
}