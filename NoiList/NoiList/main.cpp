/**
 * @file VD2.cpp
 * @author Duong Van Tai
 * @brief
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<iostream>
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
void CreateListhead(List &l);
void PrintList(List l);
long SumEvenNumber(List l);
Node *Search(List l, int x);
List Noi(List &l1, List &l2);

int main() {
    List l;
    Init(l);
    CreateListhead(l);
    PrintList(l);

    List l2;
    Init(l2);
    CreateListhead(l2);
    PrintList(l2);

    PrintList(Noi(l, l2));

    return 0;
}
/**
 * @brief Khởi tạo
 *
 * @param l
 */
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
    addHead(l, new_ele);
}

void CreateListHead(List &l) {
    int x;
    do
    {
        cout << "Bat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: " << endl;
        cin >> x;
        if (x == -1)
            break;
        InsertHead(l, x);
    } while (x != -1);
    cout << "Da nhap du lieu xong" << endl;
}

void PrintList(List l) {
    Node *p;
    p = l.head;
    while (p != NULL)
    {
        cout << "Value: " << p->data << "\taddress: " << p << endl;
        p = p->link;
    }
    
}

long SumEvenNumber(List l) {
    Node *p;
    p = l.head;
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
    p = l.head;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

List Noi(List &list1, List &list2) {
    List temp = list1;
    temp.tail->link = list2.head;
    temp.tail = list2.tail;
    return temp;
}
