#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct Stack {
    Node *top;
};

void Init(Stack &t);
int isEmpty(Stack t);
void Push(Stack &t, int x);
int Pop(Stack &t);

int main()
{
    Stack s;
    Init(s);
    int n;
    for (int i = 0; i < 5; i++)
    {
        cout << "Push: ";
        cin >> n;
        Push(s, n);
    }
    
    while (!isEmpty(s))
    {
        cout << Pop(s) << " ";
    }

    return 0;
}

void Init(Stack &t) {
    t.top = 0;
}

int isEmpty(Stack t) {
    return t.top == NULL ? 1 : 0;
}

void Push(Stack &t, int x) {
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        return;
    }
    p->data = x;
    p->pNext = NULL;
    if (t.top == NULL)
        t.top = p;
    else {
        p->pNext = t.top;
        t.top = p;
    }
    
}

int Pop(Stack &t) {
    if (t.top == NULL) {
        cout << "Stack empty";
        return 0;
    }
    int x;
    Node *p = t.top;
    t.top = t.top->pNext;
    p->pNext = NULL;
    x = p->data;
    delete p;
    return x;
}