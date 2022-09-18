#include<iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *next;
    DNode *prev;
};

struct List
{
    DNode *head;
    DNode *tail;
};

DNode *getNode(int x) {
    DNode *p;
    p = new DNode;
    if (p == NULL) {
        cout << "Failed to allocate DNode" << endl;
        return NULL;
    }
    p->data = x;
    p->next = p->prev = NULL;
    return p;
}

void addHead(List &l, DNode *newNode) {
    if (l.head == NULL) {
        l.head = l.tail = newNode;
    }
    else {
        newNode->next = l.head;
        l.head->prev = newNode;
        l.head = newNode;
    }
}

DNode *insertHead(List &l, int x) {
    DNode *new_ele = getNode(x);
    if (new_ele == NULL)
        return NULL;
    addHead(l, new_ele);
    return new_ele;
}

void addTail(List &l, DNode *newNode) {
    if (l.head == NULL)
        l.head = l.tail = NULL;
    else {
        l.tail->next = newNode;
        newNode->prev = l.tail;
        l.tail = newNode;
    }
}

DNode *insertTail(List &l, int x) {
    DNode *new_ele = getNode(x);
    if (new_ele == NULL)
        return NULL;
    addTail(l, new_ele);
    return new_ele;
}

void addAfter(List &l, DNode *q, DNode *newNode) {
    if (q != NULL) {
        DNode *p = q->next;
        newNode->next = p;
        newNode->prev = q;
        q->next = newNode;
        if (p == NULL) p->prev = newNode;
        else l.tail = newNode;
    }
}

DNode *insertAfter(List &l, DNode *q, int x) {
    DNode *new_ele = getNode(x);
    if (new_ele == NULL)
        return NULL;
    addAfter(l, q, new_ele);
    return new_ele;
}

void addBefore(List &l, DNode *q, DNode *newNode) {
    DNode *p = q->prev;
    if (q != NULL) {
        newNode->next = q;
        q->prev = newNode;
        newNode->prev = p;
        if (p != NULL) p->next = newNode;
        else l.head = newNode;
    }
}

DNode *insertBefore(List &l, DNode *q, int x) {
    DNode *new_ele = getNode(x);
    if (new_ele == NULL)
        return NULL;
    addBefore(l, q, new_ele);
    return new_ele;
}

int removeHead(List &l) {
    if (l.head == NULL)
        return 0;
    DNode *p = l.head;
    l.head = l.head->next;
    if (l.head == NULL)
        l.tail = NULL;
    else l.head->prev = NULL;
    delete p;
    return 1;
}

int removeTail(List &l) {
    if (l.tail == NULL)
        return 0;
    DNode *p = l.tail;
    l.tail = l.tail->prev;
    if (l.tail == NULL)
        l.head = NULL;
    else l.tail->next = NULL;
    delete p;
    return 1;
}

int removeAfter(List &l, DNode *q) {
    if (q == NULL)
        return 0;
    DNode *p = q->next;
    if (p != NULL) {
        q->next = p->next;
        if (p == l.tail)
            l.tail = q;
        else
            p->next->prev = q;
        delete p;
        return 1;
    }
    return 0;
}

int removeAfter(List &l, DNode *q) {
    if (q == NULL)
        return 0;
    DNode *p = q->prev;
    if (p != NULL) {
        q->prev = p->prev;
        if (p == l.head)
            l.head = q;
        else
            p->prev->next = q;
        delete p;
        return 1;
    }
    return 0;
}

int removeNode(List &l, int k) {
    DNode *p = l.head;
    while (p != NULL)
    {
        if (p->data == k)
            break;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    DNode *q = p->prev;
    if (q != NULL)
        return removeAfter(l, q);
    else
        return removeHead(l);
    
}