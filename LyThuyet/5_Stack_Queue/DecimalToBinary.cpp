#include <iostream>
using namespace std;

struct Stack
{
    int list[100];
    int top;
};

void Init(Stack &s);
int isEmpty(Stack &s);
int isFull(Stack &s);
void Push(Stack &s, int x); 
int Pop(Stack &s);

int main(int argc, char const *argv[])
{
    Stack s;
    int coso, so, sodu;
    cout << "Input so: ";
    cin >> so;
    cout << "Input coso: ";
    cin >> coso;
    Init(s);
    while (so != 0) {
        sodu = so % coso;
        Push(s, sodu);
        so = so / coso;
    }
    cout << "Result: ";
    while (!isEmpty(s)) {
        cout << Pop(s);
    }
    return 0;
}

void Init(Stack &s) {
    s.top = 0;
}
int isEmpty(Stack &s) {
    if (s.top == 0)
    {
        return 1;
    }
    return 0;
}
int isFull(Stack &s) {
    if (s.top >= 100)
    {
        return 1;
    }
    return 0;
}
void Push(Stack &s, int x) {
    if (!isFull(s))
    {
        s.list[s.top] = x;
        s.top++;
    }
    
}
int Pop(Stack &s) {
    int x;
    if (!isEmpty(s))
    {
        s.top--;
        x = s.list[s.top];
    }
    return x;
}