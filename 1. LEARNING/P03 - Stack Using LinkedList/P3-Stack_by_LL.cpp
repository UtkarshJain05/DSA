// Stack Using LinkedList. -> TC:O(1)  SC:O(D)  {D-> Dynamic.}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Stack
{
public:
    Node *ptr = nullptr;
    int cnt = 0;

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = ptr;
        ptr = temp;
        cnt++;
    }

    void pop()
    {
        if (ptr == NULL)
        {
            cout << "Already empty!\n";
            return;
        }

        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
        cnt--;
    }

    int top()
    {
        if (ptr == NULL)
        {
            cout << "Stack Is Empty.!";
            return -1;
        }
        return ptr->data;
    }

    int size()
    {
        return cnt;
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