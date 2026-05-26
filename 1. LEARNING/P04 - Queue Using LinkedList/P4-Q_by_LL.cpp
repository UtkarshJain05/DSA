// Queue Using LinkedList. -> TC:O(1)  SC:O(D)  {D-> Dynamic.}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Queue
{
public:
    Node *start = NULL, *end = NULL;
    int cnt = 0;

    void push(int x)
    {
        Node *temp = new Node(x);
        if (cnt == 0)
            start = end = temp;

        else
        {
            end->next = temp;
            end = temp;
        }
        cnt++;
    }

    void pop()
    {
        if (cnt == 0)
        {
            cout << "Queue Already Empty!\n";
            return;
        }
        Node *temp = start;
        start = start->next;
        delete temp;
        cnt--;
        if (cnt == 0)
            start = end = NULL;
    }

    int top()
    {
        if (cnt == 0)
        {
            cout << "Queue Empty!";
            return -1;
        }
        return start->data;
    }

    int size()
    {
        return cnt;
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