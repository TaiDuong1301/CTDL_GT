#include <stdio.h>
#include <iostream>

typedef struct NODE
{
    int data;
    NODE *pNext;
};

typedef struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *GetNode(int x);
void Init(LIST &l);
void PrintList(LIST &l);
void AddHead(LIST &l, NODE *new_node);
void AddTail(LIST &l, NODE *new_node);
void AddAfter(LIST &l, NODE *prev_node, NODE *new_node);
NODE *Search(LIST &l, int x);
int removeHead(LIST &l);
int removeAfter(LIST &l, NODE *prev_node);
int removeNode(LIST &l, int key);
void removeList(LIST &l);
int CountNodes(LIST l);
NODE *PickHead(LIST &l);
void swapNode(LIST &l, NODE *prev_x, NODE *x, NODE *prev_y, NODE *y);
void doicho(LIST &l);
// void swap(NODE &a, NODE &b);

int main()
{
    LIST list;
    Init(list);

    AddHead(list, GetNode(1));
    AddHead(list, GetNode(2));
    NODE *temp = GetNode(3);
    AddHead(list, temp);
    AddHead(list, GetNode(4));

    PrintList(list);

    AddTail(list, GetNode(5));
    AddAfter(list, temp, GetNode(6));

    PrintList(list);

    // doicho(list);

    // PrintList(list);

}

NODE *GetNode(int x)
{
    NODE *new_node = new NODE;
    if (new_node == NULL)
    {
        printf("Error: Invalid node number");
        return NULL;
    }
    new_node->data = x;
    new_node->pNext = NULL;
    return new_node;
}

void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintList(LIST &l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

void AddHead(LIST &l, NODE *new_node) {
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = new_node;
    }
    else
    {
        new_node->pNext = l.pHead;
        l.pHead = new_node;
    }
}

void AddTail(LIST &l, NODE *new_node)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = new_node;
    }
    else 
    {
        l.pTail->pNext = new_node;
        l.pTail = new_node;
    }
}

void AddAfter(LIST &l, NODE *prev_node, NODE *new_node)
{
    if (prev_node != NULL)
    {
        new_node->pNext = prev_node->pNext;
        prev_node->pNext = new_node;
        if (prev_node == l.pTail)
        {
            l.pTail = new_node;
        }
    }
}

NODE *Search(LIST &l, int x)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

int removeHead(LIST &l)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    NODE *p = l.pHead;
    l.pHead = p->pNext;
    if (l.pHead == NULL)
    {
        l.pTail = NULL;
    }
    delete p;
    return 1;
}

int removeAfter(LIST &l, NODE *prev_node)
{
    if (prev_node != NULL && prev_node->pNext != NULL)
    {
        NODE *p = prev_node->pNext;
        prev_node->pNext = p->pNext;
        if (p == l.pTail)
        {
            l.pTail = prev_node;
        }
        delete p;
        return 1;
    }
    return 0;
}

int removeNode(LIST &l, int key)
{
    NODE *p = l.pHead;
    NODE *prev_node = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            break;
        }
        prev_node = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        printf("Can not find key");
        return 0;
    }
    else if (prev_node == NULL)
    {
        removeHead(l);
        return 1;
    }
    else 
    {
        removeAfter(l, prev_node);
        return 1;
    }
    
}

void removeList(LIST &l)
{
    NODE *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    l.pTail = NULL;
}

int CountNodes(LIST l)
{
    int count = 0;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

NODE *PickHead(LIST &l)
{
    NODE *p = NULL;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        p->pNext = NULL;
        if (l.pHead == NULL)
        {
            l.pTail = NULL;
        }
    }
    return p;
}

void swapNode(LIST &l, NODE *prev_x, NODE *x, NODE *prev_y, NODE *y)
{
    NODE *temp = y->pNext;
    if (prev_x == NULL)
    {
        y->pNext = x->pNext;
        x->pNext = temp;
        l.pHead = y;
    }
    else
    {
        y->pNext = x->pNext;
        x->pNext = temp;
        prev_x->pNext = y;
        prev_y->pNext = x;
    }

}

void doicho(LIST &l)
{
    NODE *temp = l.pHead->pNext;
    temp = temp->pNext;
    std::swap(temp, l.pHead);
}

// void swap(NODE &a, NODE &b){
//     NODE temp = a;
//     a = b;
//     b = temp;
// }