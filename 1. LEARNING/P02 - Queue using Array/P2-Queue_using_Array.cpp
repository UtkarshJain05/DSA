#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int start = -1, end = -1;
    int curr_size = 0;
    int len = 4;
    int q[4];

    void push(int x)
    {
        if (curr_size >= len)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (curr_size == 0)
            start = 0, end = 0;
        else
            end = (end + 1) % len;
        curr_size++;
        q[end] = x;
        return;
    }

    void pop()
    {
        if (curr_size == 0)
        {
            cout << "Queue Already Empty!" << endl;
            return;
        }
        if (curr_size == 1)
        {
            start = -1, end = -1;
        }
        else
            start = (start + 1) % len;
        curr_size--;
        return;
    }

    int top()
    {
        if (curr_size == 0)
        {
            cout << "Queue Empty!" << endl;
            return 0;
        }
        return q[start];
    }

    int size()
    {
        return curr_size;
    }
};

int main()
{
    Queue q;
    q.pop();
    q.push(3);
    q.push(4);
    cout << q.top() << endl;
    q.push(5);
    q.pop();
    cout << q.size() << endl;
}