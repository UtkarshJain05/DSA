// Queue Using Stack. -> TC:O(N)  SC:O(2D)  {D -> Dynamic.}

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (s1.size() == 0 && s2.size() == 0)
        {
            cout << "Queue Already Empty!";
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int top()
    {
        if (s1.size() == 0 && s2.size() == 0)
        {
            cout << "Queue Empty!";
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size()
    {
        return s1.size() + s2.size();
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