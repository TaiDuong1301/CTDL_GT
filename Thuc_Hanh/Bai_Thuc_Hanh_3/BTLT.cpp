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
void InsertHead(List &l, int x);
void Separating_List(List &l1, List &l2, int x);
int removeNode(List &list, int k);
void Output(List list);
int removeHead(List &list);
int removeAfter(List &list, Node *q);


int main(int argc, char const *argv[])
{
    Node *p;
    List list;
    Init(list);
    // 8 4 3 9  5 7 6 2 1
    p = GetNode(8);
    addHead(list, p);
    p = GetNode(4);
    addHead(list, p);
    p = GetNode(3);
    addHead(list, p);
    p = GetNode(9);
    addHead(list, p);
    p = GetNode(5);
    addHead(list, p);
    p = GetNode(7);
    addHead(list, p);
    p = GetNode(6);
    addHead(list, p);
    p = GetNode(2);
    addHead(list, p);
    p = GetNode(1);
    addHead(list, p);

    Output(list);

    List l1;
    Init(l1);
    Separating_List(list, l1, 5);
    // addHead(l1, p);
    // Output(list);
    // Output(l1);

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
/**
 * @brief Hàm tách danh sách L thành hai danh sách khác nhau, 
 * trong đó danh sách L1 chứa các số nguyên lớn hơn x, 
 * danh sách L chứa các số còn lại.
 * 
 * @param l list
 * @param l1 list
 * @param x 
 */
void Separating_List(List &l, List &l1, int x) {
    Node *p = l.head;
    // Node *q = NULL;
    //Sort list
    while (p != NULL)
    {
        if (p->data > x) {
            InsertHead(l1, p->data);
        }
    
        p = p->link;
    }
    
}

/**
 * @brief Delete a node have key "k" 
 * 
 * @param list 
 * @param k 
 * @return int 
 */
int removeNode(List &list, int k) {
    Node *p = list.head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == k)
            break;
        q = p;
        p = p->link;
    }
    if (p == NULL) {
        cout << "Khong tim kiem k";
        return 0;
    }
    else if (q == NULL) {
        return removeHead(list);
    }
    else
        return removeAfter(list, q);
}

void Output(List list) {
    Node *p = list.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}
/**
 * @brief Delete first node from linked list
 * 
 * @param list 
 * @return int 
 */
int removeHead(List &list) {
    if (list.head == NULL)
        return 0;
    Node *p = list.head;
    list.head = p->link;
    if (list.head == NULL)
        list.tail = NULL; // list is empty
    delete p;
    return 1;
}
/**
 * @brief Delete a node p after node q
 * 
 * @param list 
 * @param q 
 * @return int 
 */
int removeAfter(List &list, Node *q) {
    if (q != NULL && q->link != NULL) {
        Node *p = q->link;
        q->link = p->link;
        if (p == list.tail)
            list.tail = q;
        delete p;
        return 1;
    }
    return 0;
}