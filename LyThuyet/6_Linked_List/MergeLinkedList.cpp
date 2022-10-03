#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void Init(List &l);
Node *GetNode(int x);
void addHead(List &l, Node *newNode);
void insertHead(List &l, int x);
void output(List l);
List Merge(List &l1, List &l2);

int main(int argc, char const *argv[])
{
    List list;
    Init(list);
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);

    List list2;
    Init(list2);
    insertHead(list2, 4);
    insertHead(list2, 5);
    insertHead(list2, 6);

    List MList;
    MList = Merge(list, list2);
    output(MList);
    output(list);
    output(list2);
    return 0;
}
/**
 * @brief Khởi tạo danh sách liên kết
 * 
 * @param l 
 */
void Init(List &l) {
    l.pHead = l.pTail = NULL;
}
/**
 * @brief Get the Node object
 * 
 * @param p 
 * @param x 
 * @return Node* 
 */
Node *GetNode(int x) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "Node error" << endl;
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
/**
 * @brief Thêm một node vào đầu danh sách
 * 
 * @param l 
 * @param newNode 
 */
void addHead(List &l, Node *newNode) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = newNode;
    else {
        newNode->pNext = l.pHead;
        l.pHead = newNode;
    }
}
/**
 * @brief Thêm Node với giá trị x vào đầu danh sách
 * 
 * @param l 
 * @param x 
 */
void insertHead(List &l, int x) {
    Node *newNode = GetNode(x);
    if (newNode == NULL) {
        cout << "Error" << endl;
        return;
    }
    addHead(l, newNode);
}
/**
 * @brief output List
 * 
 * @param l 
 */
void output(List l) {
    Node *p;
    p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}
/**
 * @brief Merge two linkedlist
 * 
 * @param l1 
 * @param l2 
 * @return List 
 */
List Merge(List &l1, List &l2) {
    List temp;
    Init(temp);
    //temp.pHead = l1.pHead;
    // addHead(temp, l1.pHead);
    Node *p = l1.pHead;
    while (p != NULL)
    {
        insertHead(temp, p->data);
        p = p->pNext;
    }
    Node *q = l2.pHead;
    while (q != NULL)
    {
        insertHead(temp, q->data);
        q = q->pNext;
    }
    
    return temp;
}