// Queue Using Stack. -> TC:O(N)  SC:O(2D)  {D -> Dynamic.}

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue Already Empty!.\n";
            return;
        }
        s1.pop();
    }

    int top()
    {
        if (s1.empty())
        {
            cout << "Queue Empty!";
            return -1;
        }
        return s1.top();
    }

    int size()
    {
        return s1.size();
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    cout << q.size() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.top() << endl;
}