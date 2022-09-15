#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct List
{
    Node *first, *last;
};

void Init(List &l);
Node *GetNode(int x);
void addFirst(List &l, Node *new_ele);
void InsertFirst(List &l, int x);
void CreateListFirst(List &l);
void PrintList(List l);
long SumEvenNumber(List l);
Node *Search(List l, int x);

int main() {
    List l;
    Init(l);
    CreateListFirst(l);
    PrintList(l);

    cout << "SumEvenNumber(l) = " << SumEvenNumber(l) << endl;

    int x;
    cout << "Nhap gia tri x can tim trong list: ";
    cin >> x;
    cout << Search(l, x);

    return 0;
}

void Init(List &l) {
    l.first = l.last = NULL;
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

void addFirst(List &l, Node *new_ele) {
    if (l.first == NULL) {
        l.first = new_ele;
        l.last = l.first;
    }
    else {
        new_ele->link = l.first;
        l.first = new_ele;
    }
}

void InsertFirst(List &l, int x) {
    Node *new_ele = GetNode(x);
    if (new_ele == NULL)
        return;
    addFirst(l, new_ele);
}

void CreateListFirst(List &l) {
    int x;
    do
    {
        cout << "Bat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: " << endl;
        cin >> x;
        if (x == -1)
            break;
        InsertFirst(l, x);
    } while (x != -1);
    cout << "Da nhap du lieu xong" << endl;
}

void PrintList(List l) {
    Node *p;
    p = l.first;
    while (p != NULL)
    {
        cout << "Value: " << p->data << "\taddress: " << p << endl;
        p = p->link;
    }
    
}

long SumEvenNumber(List l) {
    Node *p;
    p = l.first;
    long result = 0;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
            result += p->data;
        p = p->link;
    }
    return result;
}

Node *Search(List l, int x) {
    Node *p;
    p = l.first;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}