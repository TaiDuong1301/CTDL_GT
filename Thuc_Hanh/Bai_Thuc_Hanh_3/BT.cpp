#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct List
{
    Node *head, *tail;
};

void Init(List &l);
Node *GetNode(int x);
void addHead(List &l, Node *new_ele);
void Inserthead(List &l, int x);
void Separating_List(List &l1, List &l2, int x);

int removeNode(List &l, int k);

int main(int argc, char const *argv[])
{
    
    return 0;
}

void Init(List &l) {
    l.head = l.tail = NULL;
}

Node *GetNode(int x) {
    Node *p;
    p = new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}

void addHead(List &l, Node *new_ele) {
    if (l.head == NULL) {
        l.head = new_ele;
        l.tail = l.head;
    }
    else {
        new_ele->link = l.head;
        l.head = new_ele;
    }
}

void InsertHead(List &l, int x) {
    Node *new_ele = GetNode(x);
    if (new_ele == NULL)
        return;
    Node *p;
    p = l.head;
    while (p != NULL) {
        if (p->data == x)
        {
            cout << "Existing element";
            return;
        }
    }
    addHead(l, new_ele);
}

void Separating_List(List &l, List &l1, int x) {
    Node *p = l.head;
    while (p != NULL)
    {
        
    }
    
}

int removeNode(List &l, int k) {
    Node *p = l.head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == k)
            break;
        q = p;
        p = p->head;
    }
    if (p == NULL) {
        cout << "Khong tim kiem k";
        return 0;
    }
    else if (q == NULL) {
        return removeHead(l);
    }
    else
        return removeAfter(l, q);
}