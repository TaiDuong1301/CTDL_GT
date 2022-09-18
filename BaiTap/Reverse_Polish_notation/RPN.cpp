#include<iostream>
#include <stack>
#include <cmath>
#include <climits>
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
float scanNum(char c);
int isOperator(char c);
int isQperand(char c);
float operation(int a, int b, char op);

int main(int argc, char const *argv[])
{
    Stack s;
    Init(&s);

    string bt = "53+62/*35*+";


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

float scanNum(char c) {
    int value;
    value = c;
    return float(value - '0');
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return -1;
}

int isOperand(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    return -1;
}

float operation(int a, int b, char op) {
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return INT_MIN;
}